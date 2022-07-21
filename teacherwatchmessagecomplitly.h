#ifndef TEACHERWATCHMESSAGECOMPLITLY_H
#define TEACHERWATCHMESSAGECOMPLITLY_H

#include <QWidget>
#include<QString>

#include"dist/json/json.h"
#include"teachermainmenu.h"

namespace Ui {
class teacherWatchMessageComplitly;
}

class teacherWatchMessageComplitly : public QWidget
{
    Q_OBJECT

public:
    explicit teacherWatchMessageComplitly(QString title , QString message , QString senderUsername , TeacherMainMenu * member, QWidget *parent = nullptr);
    ~teacherWatchMessageComplitly();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_backToMenu_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::teacherWatchMessageComplitly *ui;

    TeacherMainMenu * mainmenu;

    Json::Value dataHolder;
    Json::Reader dataReader;
    QString filePath = "../data_resources/notifications" ;

};

#endif // TEACHERWATCHMESSAGECOMPLITLY_H
