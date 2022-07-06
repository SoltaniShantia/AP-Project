#ifndef TEACHERWATCHMESSAGECOMPLITLY_H
#define TEACHERWATCHMESSAGECOMPLITLY_H

#include <QWidget>

namespace Ui {
class teacherWatchMessageComplitly;
}

class teacherWatchMessageComplitly : public QWidget
{
    Q_OBJECT

public:
    explicit teacherWatchMessageComplitly(QWidget *parent = nullptr);
    ~teacherWatchMessageComplitly();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_backToMenu_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::teacherWatchMessageComplitly *ui;
};

#endif // TEACHERWATCHMESSAGECOMPLITLY_H
