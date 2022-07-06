#ifndef ADMINCLASSINFO_H
#define ADMINCLASSINFO_H

#include <QWidget>
#include <QGroupBox>

namespace Ui {
class AdminClassInfo;
}

class AdminClassInfo : public QWidget
{
    Q_OBJECT

public:
    explicit AdminClassInfo(QWidget *parent = nullptr);
    ~AdminClassInfo();

public slots:
    QGroupBox* watchClass();
private slots:
    void on_backToMenu_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::AdminClassInfo *ui;

    void goToClassInfo(QString className);
};

#endif // ADMINCLASSINFO_H
