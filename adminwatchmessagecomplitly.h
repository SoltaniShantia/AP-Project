#ifndef ADMINWATCHMESSAGECOMPLITLY_H
#define ADMINWATCHMESSAGECOMPLITLY_H

#include <QWidget>

namespace Ui {
class adminWatchMessageComplitly;
}

class adminWatchMessageComplitly : public QWidget
{
    Q_OBJECT

public:
    explicit adminWatchMessageComplitly(QWidget *parent = nullptr);
    ~adminWatchMessageComplitly();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_backToMenu_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::adminWatchMessageComplitly *ui;
};

#endif // ADMINWATCHMESSAGECOMPLITLY_H
