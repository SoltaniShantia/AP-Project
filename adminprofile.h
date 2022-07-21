#ifndef ADMINPROFILE_H
#define ADMINPROFILE_H

#include <QWidget>


#include"adminmainmenu.h"

namespace Ui {
class AdminProfile;
}

class AdminProfile : public QWidget
{
    Q_OBJECT

public:
    explicit AdminProfile(AdminMainMenu * adminMainMenuMember, QWidget *parent = nullptr);
    ~AdminProfile();

private slots:

    void on_changeNumber_clicked();

    void on_applyChangeNumber_clicked();



    void on_applyChangePass_clicked();

    void on_changePassBtn_clicked();

    void on_backToMenu_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::AdminProfile *ui;
    AdminMainMenu * mainmenu;
};

#endif // ADMINPROFILE_H
