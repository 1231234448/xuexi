#ifndef MYSAX2_H
#define MYSAX2_H
#include <QtXml>
#include <QPlainTextEdit>
#include <QDebug>
#include <QStack>

class MySax2 : public QXmlDefaultHandler
{
public:
    MySax2(QPlainTextEdit* edit);

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
    QStack<QString> m_stack;
    QString m_text;
};

#endif // MYSAX2_H
