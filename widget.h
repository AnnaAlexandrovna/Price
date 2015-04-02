#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QLayout>
#include <QPushButton>
#include <QFile>
#include <QWindow>
namespace Ui {
class Widget;
class Toy;
}


class Toy
{
public:
    int code;
    QString name;
    int cost;
public:
    friend QDataStream &operator <<(QDataStream &stream, const Toy &toy)
{
    stream << toy.code;
    stream << toy.name;
    stream << toy.cost;
    return stream;
    }
    friend QDataStream &operator >>(QDataStream &stream, Toy &toy)
    {
        stream >> toy.code;
        stream >> toy.name;
        stream >> toy.cost;
        return stream;
    }

};
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget      *ui;
    QFile           *file;
    QLineEdit       *lineEdit, *lineEdit_2, *lineEdit_3, *lineEdit_4, *lineEdit_5,
                    *lineEdit_6, *lineEdit_7, *lineEdit_8, *lineEdit_9, *lineEdit_10, *lineEdit_11, *lineEdit_12, *lineEdit_13, *lineEdit_14, *lineEdit_15;
    QGridLayout     *layout;
    QHBoxLayout     *layout_1;
    QVBoxLayout     *layout_m;
    QLabel          *label, *label_2, *label_3, *label_4, *label_5, *label_6;
    QPushButton     *pushButton, *pushButton_2, *pushButton_3;

private slots:
    void input();
    void findMax();
    void clear();
};
#endif // WIDGET_H
