#include "widget.h"
#include "ui_widget.h"
#include <qtextcodec.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    QTextCodec::setCodecForCStrings( QTextCodec::codecForName("utf8"));
    ui->setupUi(this);
    this->resize(550,180);
    this->setWindowTitle("Прайс-лист");

    for (int i=0; i<8; i++)
        lineEdit[i] = new QLineEdit();

    label = new QLabel("Код");
    label_2 = new QLabel("Название товара");
    label_3 = new QLabel("Цена   ");
    label_4 = new QLabel("Строка состояния:");
    label_5 = new QLabel;
    label_6 = new QLabel;

    pushButton = new QPushButton("Добавить записи");
    connect(pushButton,SIGNAL(clicked()), this, SLOT(input()));

    pushButton_3 = new QPushButton("Очистить поля");
    connect(pushButton_3,SIGNAL(clicked()), this, SLOT(clear()));

    pushButton_2 = new QPushButton("Фильтрация");
    connect(pushButton_2,SIGNAL(clicked()), this, SLOT(findMax()));

    //Setup Layout
    layout_m = new QVBoxLayout;
    layout = new QGridLayout;
    layout_1 = new QHBoxLayout;

    layout_m->setMargin(5);
    layout->addWidget(label, 0,0);
    layout->addWidget(label_2, 0, 1);
    layout->addWidget(label_3, 0, 2);
    layout->addWidget(pushButton, 0, 3);
    layout->addWidget(pushButton_3, 1, 3);
    int k=0;
    for (int i=1; i<3; i++)
        for (int j=0; j<3; j++)
        {
            layout->addWidget(lineEdit[k],i,j);
            k++;
        }

    layout_m->addLayout(layout);
    layout_1->addWidget(label_4);
    layout_1->addWidget(label_5);
    layout_1->addWidget(pushButton_2);
    layout_m->addLayout(layout_1);


    this->setLayout(layout_m);

    file = new QFile("./price.dat");
    if (file->exists())
    {
       label_5->setText("Файл уже создан. Перезаписать?");
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::input()
{
    file->open(QIODevice::WriteOnly);
    QDataStream out(file);

    {
      Toy b;
        for (int i=0; i<8; i++)
        {
            b.code = lineEdit[i]->text().toInt();
            b.name = lineEdit[++i]->text();
            b.cost = lineEdit[++i]->text().toInt();
            out << b;
        }
     label_5->setText("Запись прошла успешно");  //сериализуем наш объект
     file->close();
    }

}

void Widget::findMax()
{
    int max = 0; QString result;
    file->open(QIODevice::ReadOnly);
    QDataStream in(file);
    {
        Toy b;
        while(!file->atEnd())
      {
            in >> b;
            if (max < b.cost)
            {
                max = b.cost;
                result = b.name;
            }
      }
     label_5->setText("Самый дорогой товар: " +result);  //сериализуем наш объект
     file->close();
    }

}

void Widget::clear()
{
    for (int i=0; i<7; i++)
        lineEdit[i]->setText("");
}
