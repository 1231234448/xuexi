#include "mysax2.h"

MySax2::MySax2(QPlainTextEdit* edit)
{
    m_edit = edit;
}


bool MySax2::fatalError(const QXmlParseException &exception)
{
    qDebug() << exception.message();
    return false;
}

bool MySax2::startElement(const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &atts)
{
    m_stack.push(qName);
    return true;
}

bool MySax2::endElement(const QString &namespaceURI, const QString &localName, const QString &qName)
{
    m_stack.pop();
    if(qName=="备注"){
        QString s = m_stack.top() + " --- " + m_text;
        m_edit->appendPlainText(s);
    }
    return true;
}


bool MySax2::characters(const QString &ch)
{
    m_text = ch;
    return true;
}
