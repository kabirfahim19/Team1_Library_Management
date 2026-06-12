#ifndef MEMBER_H
#define MEMBER_H

#include "User.h"

class Member : public User
{
public:

    Member();

    Member(int id,
           string user,
           string pass);

    void showMenu() const override;

    string getRole() const override;

    bool login(string user,
               string pass) const;
};

#endif