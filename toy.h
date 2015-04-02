#ifndef TOY_H
#define TOY_H
#include <QString>
#include <QDataStream>

class Toy
{
public:
    qint32 code;
    QString name;
    qint32 cost;
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

#endif // TOY_H

