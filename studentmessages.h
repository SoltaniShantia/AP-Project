#ifndef STUDENTMESSAGES_H
#define STUDENTMESSAGES_H

#include <QWidget>
#include <QGroupBox>

namespace Ui {
class studentMessages;
}

class studentMessages : public QWidget
{
    Q_OBJECT

public:
    explicit studentMessages(QWidget *parent = nullptr);
    ~studentMessages();

private:
    QGroupBox* showMessages(int i);

private slots:
    void on_pushButton_clicked();

    void on_backToMenu_clicked();

    //void on_msgbtn1_clicked();

    void on_pushButton_3_clicked();

    void on_msgBtn_clicked(QString title);
private:
    Ui::studentMessages *ui;
};

#endif // STUDENTMESSAGES_H
