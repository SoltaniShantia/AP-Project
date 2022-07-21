#ifndef PERMISSION_H
#define PERMISSION_H
#include<QList>>
#include <QObject>

class Permission : public QObject
{
    Q_OBJECT
public:
    explicit Permission(QObject *parent = nullptr);

    QList<QString> get_permission();
    bool is_allowed(QString value);

signals:

private:
    QList<QString>  allowed_tasks ;

};

#endif // PERMISSION_H
