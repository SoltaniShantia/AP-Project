#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QFile>
#include <QString>
#include <QList>
#include <QVector>

class FileManager
{
private:
    QString dirPath = "../data_resources/";
    QString filename;
    QList<QString> data;

    void init();

public:
    FileManager();

    FileManager(QString dirPath);

    ~FileManager();

    const QString &getDirPath() const;

    void create(QString filename = "users.txt");

    // loads all data in file into a list in class to have easier access
    void loadData();

    // write the whole data into file
    // NOTE: use it after appending, deleting, or updating to submit the changes into file
    void write();

    void append(QString record);

    void deleteRecord(int index);

    // update a record in data
    void update(int index, QString newValue);

    QVector<QString> parse(QString str, char delimiter = '\t');

    QString getRecord(int index);

    const QString &getFilename() const;

    void setFilename(const QString &filename = "users.txt");

    const QList<QString> &getData() const;
};

#endif // FILEMANAGER_H
