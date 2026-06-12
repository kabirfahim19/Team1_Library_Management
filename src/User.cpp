#include "User.h"

/*
=================================================
DEFAULT CONSTRUCTOR
=================================================
*/

User::User()
{
    userId = 0;
    username = "";
    password = "";
}

/*
=================================================
PARAMETERIZED CONSTRUCTOR
=================================================
*/

User::User(int id,
           string user,
           string pass)
{
    userId = id;
    username = user;
    password = pass;
}

/*
=================================================
SETTERS
=================================================
*/

void User::setUserId(int id)
{
    userId = id;
}

void User::setUsername(string user)
{
    username = user;
}

void User::setPassword(string pass)
{
    password = pass;
}

/*
=================================================
GETTERS
=================================================
*/

int User::getUserId() const
{
    return userId;
}

string User::getUsername() const
{
    return username;
}

string User::getPassword() const
{
    return password;
}

/*
=================================================
DESTRUCTOR
=================================================
*/

User::~User()
{
}