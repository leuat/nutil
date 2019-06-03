#ifndef REPORT_H
#define REPORT_H
#include <QString>
#include <QVector>
#include <QColor>
#include "source/data.h"
#include "source/ProcessManager/nutilprocess.h"
//#include "libxl.h"
#include "source/util/lmessage.h"
#include "source/util/atlaslabel.h"
#include "source/LBook/lbookxlnt.h".h"
#include "source/util/counter.h"
#include "source/ProcessManager/processitem.h"


class Report {
public:
    QString m_filename;
    QColor m_color = QColor(255,0,0);
    QVector<long> m_IDs;
    QVector<Area*> m_areasOfInterest;
    QString m_unit;
    float m_totalPixelArea = 0;
    float m_totalArea = 0;
    float m_regionPixelArea = 0;
    float m_regionArea = 0;

    Report() {}
    Report(QString filename, QStringList& ids, QColor c) {
        m_filename = filename;
        m_color = c;
        for (QString s : ids) {
            bool ok;
            long l = (long)s.simplified().toLong(&ok);
/*            if (l>100000)
                qDebug() << "FOUND " << l;
            if (!ok) {
                qDebug() << "NOT OK: " <<s.simplified() << " " << l;
            }*/
            m_IDs.push_back( l);
        }
    }

    void FindAreasOfInterest(QVector<NutilProcess*>& processes);
    void GenerateSheet(LBook* b);

};


class Reports {
public:

    LBook* m_book;
    QString m_filename;
    QVector<Report> m_reports;
    QVector<QVector<long>> getList();

    void Calculate(AtlasLabels* atlasLabels);
    void CreateBook(QString filename );
    void CreateSheets( QVector<NutilProcess*>& processes,AtlasLabels* atlasLabels);
    void CreateSummary(AtlasLabels* atlasLabels);
    void CreateCombinedList( QString filename, AtlasLabels* atlasLabels,QVector<NutilProcess*> processes,QVector<ProcessItem*> items, QString units);
    void CreateSliceReports(QString filename,  QVector<NutilProcess*> processes, QVector<ProcessItem*> items,AtlasLabels* labels, QString units);
    void CreateSliceReportsSummary(QString filename,  QVector<NutilProcess*> processes, QVector<ProcessItem*> items,AtlasLabels* labels);

    void Create3DSummary(QString filename , QVector<NutilProcess*> processes, QVector<ProcessItem*> items, float xyzSize);
    void Create3DSummaryJson(QString filename , QVector<NutilProcess*> processes, QVector<ProcessItem*> items, float xyzSize);
    void Create3DSliceJson(QString filename , QVector<NutilProcess*> processes, QVector<ProcessItem*> items, float xyzSize);

    void CreateNifti(QString filename , QVector<NutilProcess*> processes, QVector<ProcessItem*> items, int size);

};


#endif // REPORT_H
