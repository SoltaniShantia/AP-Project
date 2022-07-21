#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>
#include "forgotpasspage.h"
#include "adminmainmenu.h"

namespace Ui {
class LoginPage;
}

class LoginPage : public QWidget
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = nullptr);
    ~LoginPage();

    int isUserValid();

private slots:
    void on_showPass_clicked(bool checked);

    void on_forgotPass_clicked(bool checked);

    void on_Loginbtn_clicked();

private:
    Ui::LoginPage *ui;
};

#endif // LOGINPAGE_H
