#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(550,250);
    this->setWindowTitle("Прайс-лист");

    //Setup label, lineEdit, pushButton
    label = new QLabel("Код");
    label_2 = new QLabel("Название товара");
    label_3 = new QLabel("Цена   ");
    label_4 = new QLabel("Строка состояния:");
    label_5 = new QLabel;
    label_6 = new QLabel;

    lineEdit = new QLineEdit();
    lineEdit_2 = new QLineEdit();
    lineEdit_3 = new QLineEdit();

    lineEdit_4 = new QLineEdit();
    lineEdit_5 = new QLineEdit();
    lineEdit_6 = new QLineEdit();

    lineEdit_7 = new QLineEdit();
    lineEdit_8 = new QLineEdit();
    lineEdit_9 = new QLineEdit();

    lineEdit_10 = new QLineEdit();
    lineEdit_11 = new QLineEdit();
    lineEdit_12 = new QLineEdit();

    lineEdit_13 = new QLineEdit();
    lineEdit_14 = new QLineEdit();
    lineEdit_15 = new QLineEdit();

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
    layout->addWidget(lineEdit, 1, 0);
    layout->addWidget(lineEdit_2, 1, 1);
    layout->addWidget(lineEdit_3, 1, 2);
    layout->addWidget(pushButton_3, 1, 3);
    layout->addWidget(lineEdit_4, 2, 0);
    layout->addWidget(lineEdit_5, 2, 1);
    layout->addWidget(lineEdit_6, 2, 2);
    layout->addWidget(lineEdit_7, 3, 0);
    layout->addWidget(lineEdit_8, 3, 1);
    layout->addWidget(lineEdit_9, 3, 2);
    layout->addWidget(lineEdit_10, 4, 0);
    layout->addWidget(lineEdit_11, 4, 1);
    layout->addWidget(lineEdit_12, 4, 2);
    layout->addWidget(lineEdit_13, 5, 0);
    layout->addWidget(lineEdit_14, 5, 1);
    layout->addWidget(lineEdit_15, 5, 2);
    layout_m->addLayout(layout);
    layout_1->addWidget(label_4);
    layout_1->addWidget(label_5);
    layout_1->addWidget(pushButton_2);
    layout_m->addLayout(layout_1);


    this->setLayout(layout_m);

    file = new QFile("/home/anna/program/txt.dat");
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
      //задаем какие-то значения b.title и b.text
      b.code = lineEdit->text().toInt();
      b.name = lineEdit_2->text();
      b.cost = lineEdit_3->text().toInt();
out << b;
      b.code = lineEdit_4->text().toInt();
      b.name = lineEdit_5->text();
      b.cost = lineEdit_6->text().toInt();
out << b;
      b.code = lineEdit_7->text().toInt();
      b.name = lineEdit_8->text();
      b.cost = lineEdit_9->text().toInt();
out << b;
      b.code = lineEdit_10->text().toInt();
      b.name = lineEdit_11->text();
      b.cost = lineEdit_12->text().toInt();

      out << b;
      b.code = lineEdit_13->text().toInt();
      b.name = lineEdit_14->text();
      b.cost = lineEdit_15->text().toInt();

      out << b;
     label_5->setText("Сериализация прошла успешно");  //сериализуем наш объект
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
    lineEdit->setText("");
    lineEdit_2->setText("");
    lineEdit_3->setText("");
    lineEdit_4->setText("");
    lineEdit_5->setText("");
    lineEdit_6->setText("");
    lineEdit_7->setText("");
    lineEdit_8->setText("");
    lineEdit_9->setText("");
    lineEdit_10->setText("");
    lineEdit_11->setText("");
    lineEdit_12->setText("");
    lineEdit_13->setText("");
    lineEdit_14->setText("");
    lineEdit_15->setText("");

}
