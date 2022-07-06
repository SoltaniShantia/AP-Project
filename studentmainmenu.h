#ifndef STUDENTMAINMENU_H
#define STUDENTMAINMENU_H

#include <QWidget>

namespace Ui {
class StudentMainMenu;
}

class StudentMainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit StudentMainMenu(QWidget *parent = nullptr);
    ~StudentMainMenu();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::StudentMainMenu *ui;
};

#endif // STUDENTMAINMENU_H
