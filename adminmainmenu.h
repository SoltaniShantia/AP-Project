#ifndef ADMINMAINMENU_H
#define ADMINMAINMENU_H

#include <QWidget>

namespace Ui {
class AdminMainMenu;
}

class AdminMainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit AdminMainMenu(QWidget *parent = nullptr);
    ~AdminMainMenu();

private slots:
    void on_pushButton_5_clicked();


    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::AdminMainMenu *ui;
};

#endif // ADMINMAINMENU_H
