#ifndef TEACHERPROFILE_H
#define TEACHERPROFILE_H

#include <QWidget>

namespace Ui {
class teacherProfile;
}

class teacherProfile : public QWidget
{
    Q_OBJECT

public:
    explicit teacherProfile(QWidget *parent = nullptr);
    ~teacherProfile();

private slots:
    void on_applychng_clicked();

    void on_chngNumber_clicked();

    void on_chngPass_clicked();

    void on_applychng_2_clicked();

    void on_backToMenu_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::teacherProfile *ui;
};

#endif // TEACHERPROFILE_H
