#include "mysax1.h"
#include <QDebug>


MySax1::MySax1(QPlainTextEdit* edit)
{
    m_edit = edit;
}

bool MySax1::fatalError(const QXmlParseException &exception)
{
    qDebug() << exception.message();
    return false;
}

bool MySax1::startElement(const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &atts)
{
    if(atts.value("type")=="热菜"){
        m_t1 = qName;
        m_edit->appendPlainText(qName);
    }
    return true;
}

bool MySax1::endElement(const QString &namespaceURI, const QString &localName, const QString &qName)
{
    if(qName==m_t1){
        m_t1.clear();
        return true;
    }
    if(qName=="主料" && !m_t1.isEmpty())
        m_edit->appendPlainText(" -------- " + m_t2);
    return true;
}

bool MySax1::characters(const QString &ch)
{
    m_t2 = ch;
    return true;
}
