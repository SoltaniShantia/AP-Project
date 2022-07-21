#ifndef AUTH_H
#define AUTH_H

#include <QString>


class Auth
{
public:
    Auth();

    ~Auth();

    static QString formUserData(QString username, QString password, QString firstname, QString lastname, QString nationalCode, QString phoneNumber, QString role, bool hashPass = true);

    static QString formUserData(QString teacherusername, QString lesson);

    // if int > -1 means that the member exists
    static int validStudent(QString studentusername, QString lesson);

    static int canLogin(QString username, QString password);

    // if int > -1 means that the member exists
    static int isHintValid(QString username, QString phoneNumber);

    static void updateCredential(int rowIndex, int itemIndex, QString newValue, bool shouldHash = false);

    static int findUser(QString username);

    static QString getUserRole(QString username);

    static bool isValidIranianNationalCode(const char *input);
};


#endif // AUTH_H
