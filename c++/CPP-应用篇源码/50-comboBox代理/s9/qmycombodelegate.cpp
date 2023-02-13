#include "qmycombodelegate.h"
#include <QDebug>

QMyComboDelegate::QMyComboDelegate(QObject* parent)
    :QStyledItemDelegate(parent)
{

}

QWidget *QMyComboDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QComboBox* box = new QComboBox(parent);
    box->addItems(lst);
    box->setEditable(true);
    return box;
}

void QMyComboDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString s = index.model()->data(index, Qt::EditRole).toString();
    static_cast<QComboBox*>(editor)->setCurrentText(s);
}

void QMyComboDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QString s = static_cast<QComboBox*>(editor)->currentText();
    model->setData(index, s, Qt::EditRole);
}

void QMyComboDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}

