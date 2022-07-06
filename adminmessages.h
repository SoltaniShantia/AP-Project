#ifndef ADMINMESSAGES_H
#define ADMINMESSAGES_H

#include <QWidget>
#include <QGroupBox>

namespace Ui {
class adminMessages;
}

class adminMessages : public QWidget
{
    Q_OBJECT

public:
    explicit adminMessages(QWidget *parent = nullptr);
    ~adminMessages();

private:
    QGroupBox* showMessages(int i);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_backToMenu_clicked();

    void on_pushButton_7_clicked();

    void on_msgBtn_clicked(QString title);

    void on_pushButton_6_clicked();

private:
    Ui::adminMessages *ui;
};

#endif // ADMINMESSAGES_H
