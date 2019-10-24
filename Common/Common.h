#pragma once
#include <QByteArray>
#include <QCryptographicHash>
#include <QDataStream>
#include <QHash>
#include <QList>
#include <QString>
namespace std
{
template <>
struct hash<QString>
{
    std::size_t operator()(const QString &str) const noexcept
    {
        return qHash(str);
    }
};
} // namespace std

//enum to Int. don't need namespace. is general use.
template <class T>
static int enumToInt(T t)
{
    static_assert(std::is_enum<T>::value, "T muse be enum");
    return static_cast<int>(t);
}

//int to enum. don't need namespace. is general use.
template <class T>
static T intToEnum(int v)
{
    static_assert(std::is_enum<T>::value, "T muse be enum");
    return static_cast<T>(v);
}

namespace TaoCommon
{
static QString toPercentString(const QString &str)
{
    return QString(str.toUtf8().toPercentEncoding());
}
static QString md5(const QString &str)
{
    QCryptographicHash hash(QCryptographicHash::Md5);
    hash.addData(str.toUtf8());
    return { hash.result().toHex() };
}
static QString md5(const QByteArray &content)
{
    QCryptographicHash hash(QCryptographicHash::Md5);
    hash.addData(content);
    return { hash.result().toHex() };
}


const int static headerLength = sizeof(quint32);

static QByteArray pack(const QByteArray &data)
{
    QByteArray header(headerLength, 0);
    QDataStream os(&header, QIODevice::WriteOnly);
    os << static_cast<quint32>(data.length());
    return header + data;
}
static QByteArrayList unpack(const QByteArray &data)
{
    QByteArrayList list;
    QDataStream inStream(data);
    int sum = data.size();
    int pos = 0;
    quint32 packageLen = 0;
    while (pos + headerLength < sum)
    {
        packageLen = 0;
        inStream >> packageLen;
        if (packageLen <= 0 || packageLen + headerLength > sum - pos)
        {
            break;
        }
        QByteArray subPackage = data.mid(pos + headerLength, packageLen);
        inStream.skipRawData(packageLen);
        list.append(subPackage);
        pos += headerLength + packageLen;
    }
    return list;
}
} // namespace TaoCommon
