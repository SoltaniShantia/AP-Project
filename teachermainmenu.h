#ifndef TEACHERMAINMENU_H
#define TEACHERMAINMENU_H

#include <QWidget>

namespace Ui {
class TeacherMainMenu;
}

class TeacherMainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherMainMenu(QWidget *parent = nullptr);
    ~TeacherMainMenu();

private slots:
    void on_pushButton_7_clicked();


    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::TeacherMainMenu *ui;
};

#endif // TEACHERMAINMENU_H
