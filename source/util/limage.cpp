#include "limage.h"


QImage& LImage::image()
{
    return m_image;
}

void LImage::Load(QString filename)
{
    m_image = QImage(filename);

}

void LImage::FindAreas(QColor testColor, Counter* counter, QVector<Area>* m_areas)
{


    m_index = QImage(QSize(m_image.width(), m_image.height()),QImage::Format_RGB32);


    m_index.fill(unset);
    for (int i=0;i<m_index.width();i++)
        for (int j=0;j<m_index.height();j++)
            m_index.setPixel(i,j, unset.rgba());


    counter->Init(m_image.width()*m_image.height());

    for (int i=0;i<m_image.width();i++)
        for (int j=0;j<m_image.height();j++) {
            counter->Tick();

            if (QColor(m_index.pixel(i,j)) == unset) {

                if (QColor(m_image.pixel(i,j)) == testColor) {
                    Area area;
                    FillArea(area, i,j, testColor);
                    area.CalculateStatistics();
                    m_areas->append(area);


                }
            }
        }

    qSort(m_areas->begin(), m_areas->end());

}

void LImage::FillArea(Area &area, int i, int j, QColor& testColor)
{
    // First test if this is unset
    if (QColor(m_index.pixel(i,j)) == unset) {
        m_index.setPixel(i,j,set.rgba());
        if (QColor(m_image.pixel(i,j)) == testColor) {
            area.m_points.append(QPoint(i,j));
//            qDebug() << "Appending: "<< i << " , " << j;
            if (i+1<m_index.width())
                FillArea(area, i+1, j, testColor);
            if (i-1>=0)
               FillArea(area, i-1, j, testColor);
            if (j+1<m_index.height())
                FillArea(area, i, j+1, testColor);
            if (j-1>=0)
                FillArea(area, i, j-1, testColor);
        }
    }
}

/*void LImage::GenerateAreaReport(QString outExcelFile,Counter *counter)
{
//    for (Area a : m_areas)
  //      qDebug() <<" Area size: " << a.m_pixelArea << " center pixel " << a.m_center;

    Book* book = xlCreateBook(); // xlCreateXMLBook() for xlsx
    if (counter!=nullptr)
        counter->Init(m_areas.count());
    if(book)
    {
        Sheet* sheet = book->addSheet(L"Report");
        if(sheet)
        {
            sheet->writeStr(1,0, L"Pixel count");
            sheet->writeStr(1,1, L"Area (not yet defined)");

            sheet->writeStr(1, 2, L"object_area_units");
            sheet->writeStr(1, 3, L"Center X");
            sheet->writeStr(1, 4, L"Center Y");
            for (int i=0;i<m_areas.count();i++) {
                sheet->writeNum(2+i,0, m_areas[i].m_pixelArea);
                sheet->writeNum(2+i,3, m_areas[i].m_center.x());
                sheet->writeNum(2+i,4, m_areas[i].m_center.y());
                if (counter)
                    counter->Tick();
            }
        }
        wchar_t* arr = new wchar_t[outExcelFile.size()+1];
        outExcelFile.toWCharArray(arr);
        arr[outExcelFile.size()]=0;

        book->save(arr);
        delete[] arr;
        book->release();
    }

}
*/
void LImage::SaveAreasImage(QString filename,Counter *counter, QVector<Area>* m_areas)
{
    QRgb off = QColor(255,255,255,255).rgba();


    for (int i=0;i<m_index.width();i++)
        for (int j=0;j<m_index.height();j++)
            m_index.setPixel(i,j, off);


    if (counter!=nullptr)
        counter->Init(m_areas->count());

    for (Area& a: *m_areas) {
        QRgb on = QColor(0,0,0,255).rgba();
        if (a.atlasLabel != nullptr) {
//            if (rand()%100>90)
  //              qDebug() << a.atlasLabel->color;
            on = QColor(a.atlasLabel->color.x(), a.atlasLabel->color.y(), a.atlasLabel->color.z(),255).rgba();
        }

        if (counter)
            counter->Tick();
        for (QPointF qp: a.m_points)
            m_index.setPixel(qp.x(), qp.y(), on);
    }

    m_index.save(filename);

}

void LImage::Anchor(QString filenameStripped, QString atlasFile, QString labelFile, AtlasLabels& labels,Counter *counter, QVector<Area>* m_areas)
{
    QImage refImage;
//    refImage.load(atlasDir + filenameStripped +".png" );
    refImage.load(atlasFile );

    if (counter!=nullptr)
        counter->Init(m_areas->count());

    for (Area& a: *m_areas) {
        if (counter)
            counter->Tick();
        QPointF p = a.m_center;
        p.setX(p.x()/(float)m_image.width());
        p.setY(p.y()/(float)m_image.height());

        QRgb idxVal = refImage.pixel(p.x()*refImage.width(),p.y()*refImage.height() );
        QColor col = QColor(idxVal);
        AtlasLabel* al = labels.getFromColor(QVector3D(col.red(), col.green(), col.blue()));
        if (al!=nullptr) {
            a.atlasLabel = al;
 //           qDebug() << "Found atlas : " << a.atlasLabel->color << " and name " << a.atlasLabel->name;
         }
        else qDebug() << "Error in label file: could not find atlas color " << QColor(idxVal);

    }

}



