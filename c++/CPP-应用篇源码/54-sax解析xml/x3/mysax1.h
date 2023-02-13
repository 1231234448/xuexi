#ifndef MYSAX1_H
#define MYSAX1_H
#include <QtXml>
#include <QPlainTextEdit>


class MySax1 : public QXmlDefaultHandler
{
public:
    MySax1(QPlainTextEdit* edit);

    // QXmlErrorHandler interface
public:
    bool fatalError(const QXmlParseException &exception);

    // QXmlContentHandler interface
public:
    bool startElement(const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &atts);
    bool endElement(const QString &namespaceURI, const QString &localName, const QString &qName);
    bool characters(const QString &ch);

private:
    QPlainTextEdit* m_edit;
    QString m_t1;
    QString m_t2;
};

#endif // MYSAX1_H
