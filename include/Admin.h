#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"

class Admin : public User
{
public:

    Admin();

    Admin(int id,
          string user,
          string pass);

    void showMenu() const override;

    string getRole() const override;

    bool login(string user,
               string pass) const;
};

#endif