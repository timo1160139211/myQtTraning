#include "usermodel.h"

User::User()
{

}

User::~User()
{
}
QString User::toString(){

    return this->username + " " + this->sex + " " + this->age + " " + this->password;
}
