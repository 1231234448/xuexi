#ifndef QMYCOMBODELEGATE_H
#define QMYCOMBODELEGATE_H
#include <QStyledItemDelegate>
#include <QComboBox>


class QMyComboDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    QMyComboDelegate(QObject* parent=0);

    // QAbstractItemDelegate interface
public:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;
    void setEditorData(QWidget *editor, const QModelIndex &index) const Q_DECL_OVERRIDE;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const Q_DECL_OVERRIDE;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;

    QStringList lst;
};

#endif // QMYCOMBODELEGATE_H
