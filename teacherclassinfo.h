#ifndef TEACHERCLASSINFO_H
#define TEACHERCLASSINFO_H

#include <QWidget>
#include <QGroupBox>

namespace Ui {
class TeacherClassInfo;
}

class TeacherClassInfo : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherClassInfo(QWidget *parent = nullptr);
    ~TeacherClassInfo();
public slots:
    QGroupBox* watchClass();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_backToMenu_clicked();

private:
    Ui::TeacherClassInfo *ui;
    void goToClassInfo(QString className);
};

#endif // TEACHERCLASSINFO_H
