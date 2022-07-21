#include<QList>
#include "Permission.h"

Permission::Permission(QObject *parent)
    : QObject{parent}
{

}

QList<QString> Permission::get_permission()
{
    return this->allowed_tasks ;
}

bool Permission::is_allowed(QString value)
{
    for (const QString &task:allowed_tasks )
    {
        if (task == value)
            return true;
    }
    return false;
}
