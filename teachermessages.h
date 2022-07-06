#ifndef TEACHERMESSAGES_H
#define TEACHERMESSAGES_H

#include <QWidget>
#include <QGroupBox>

namespace Ui {
class teacherMessages;
}

class teacherMessages : public QWidget
{
    Q_OBJECT

public:
    explicit teacherMessages(QWidget *parent = nullptr);
    ~teacherMessages();

private:
    QGroupBox* showMessages(int i);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_backToMenu_clicked();

    void on_pushButton_5_clicked();

    void on_msgBtn_clicked(QString title);

    void on_pushButton_3_clicked();

private:
    Ui::teacherMessages *ui;
};

#endif // TEACHERMESSAGES_H
