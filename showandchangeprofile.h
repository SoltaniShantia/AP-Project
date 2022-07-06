#ifndef SHOWANDCHANGEPROFILE_H
#define SHOWANDCHANGEPROFILE_H

#include <QWidget>

namespace Ui {
class ShowAndChangeProfile;
}

class ShowAndChangeProfile : public QWidget
{
    Q_OBJECT

public:
    explicit ShowAndChangeProfile(QWidget *parent = nullptr);
    ~ShowAndChangeProfile();

private:
    Ui::ShowAndChangeProfile *ui;
};

#endif // SHOWANDCHANGEPROFILE_H
