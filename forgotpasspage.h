#ifndef FORGOTPASSPAGE_H
#define FORGOTPASSPAGE_H

#include <QWidget>
#include "enterenewpass.h"

namespace Ui {
class ForgotPassPage;
}

class ForgotPassPage : public QWidget
{
    Q_OBJECT

public:
    explicit ForgotPassPage(QWidget *parent = nullptr);
    ~ForgotPassPage();

private slots:
    void on_Confirmbtn_clicked();

private:
    Ui::ForgotPassPage *ui;
};

#endif // FORGOTPASSPAGE_H
