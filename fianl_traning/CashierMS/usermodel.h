#ifndef USERMODEL_H
#define USERMODEL_H

#include <QString>

namespace Ui {
class User;
}

class User
{


public:
    explicit User();
    ~User();

public:
    int id;
    QString sex;
    QString age;
    QString username;
    QString password;

    QString toString();
};
#endif // USERMODEL_H
