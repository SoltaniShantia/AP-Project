#ifndef ENTERENEWPASS_H
#define ENTERENEWPASS_H

#include <QWidget>

namespace Ui {
class EntereNewPass;
}

class EntereNewPass : public QWidget
{
    Q_OBJECT

public:
    explicit EntereNewPass(QWidget *parent = nullptr);
    ~EntereNewPass();

private slots:
    void on_Confirmbtn_clicked();

private:
    Ui::EntereNewPass *ui;
};

#endif // ENTERENEWPASS_H
