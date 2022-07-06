#ifndef SENDASSERTIONADMIN_H
#define SENDASSERTIONADMIN_H

#include <QWidget>

namespace Ui {
class sendAssertionAdmin;
}

class sendAssertionAdmin : public QWidget
{
    Q_OBJECT

public:
    explicit sendAssertionAdmin(QWidget *parent = nullptr);
    ~sendAssertionAdmin();

private:
    Ui::sendAssertionAdmin *ui;
};

#endif // SENDASSERTIONADMIN_H
