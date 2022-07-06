#ifndef STUDENTWATCHMESSAGECOMPLITLY_H
#define STUDENTWATCHMESSAGECOMPLITLY_H

#include <QWidget>

namespace Ui {
class StudentWatchMessageComplitly;
}

class StudentWatchMessageComplitly : public QWidget
{
    Q_OBJECT

public:
    explicit StudentWatchMessageComplitly(QWidget *parent = nullptr);
    ~StudentWatchMessageComplitly();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_backToMenu_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::StudentWatchMessageComplitly *ui;
};

#endif // STUDENTWATCHMESSAGECOMPLITLY_H
