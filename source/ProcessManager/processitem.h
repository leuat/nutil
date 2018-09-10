#ifndef PROCESSITEM_H
#define PROCESSITEM_H


#include <QString>
#include <QPointF>
#include "source/IO/xmlanchor.h"

class ProcessItem {
public:
    QString m_inFile;
    QString m_outFile;

    QString m_outFolder;
    QString m_outFileSingle;

    QString m_filetype = "png";

    QString m_id;
    QString m_reportName;

    float m_angle;
    QPointF m_scale;

    XMLData m_xmlData;
    bool m_onlyThumbs=false;

    float m_pixelAreaScale;
    float m_atlasAreaScaled;

    ProcessItem() {

    }

    ProcessItem(QString inFile, QString outFile, float angle, QPointF scale, QString outFileSingle, QString outFolder) {
        m_inFile = inFile;
        m_outFile = outFile;
        m_angle = angle;
        m_scale = scale;
        m_outFolder = outFolder;
        m_outFileSingle = outFileSingle;
    }


};

#endif // PROCESSITEM_H
