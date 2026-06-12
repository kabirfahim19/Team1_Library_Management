#include "Member.h"

/*
=================================================
DEFAULT CONSTRUCTOR
=================================================
*/

Member::Member()
    : User()
{
}

/*
=================================================
PARAMETERIZED CONSTRUCTOR
=================================================
*/

Member::Member(int id,
               string user,
               string pass)
               : User(id, user, pass)
{
}

/*
=================================================
MEMBER MENU
=================================================
*/

void Member::showMenu() const
{
    cout << "\n==========================";
    cout << "\n      MEMBER MENU";
    cout << "\n==========================";

    cout << "\n1. View Catalog";
    cout << "\n2. Borrow Item";
    cout << "\n3. Return Item";
    cout << "\n4. My Borrowed Items";
    cout << "\n0. Logout";

    cout << "\n==========================\n";
}

/*
=================================================
ROLE
=================================================
*/

string Member::getRole() const
{
    return "Member";
}

/*
=================================================
MEMBER LOGIN
=================================================
*/

bool Member::login(string user,
                   string pass) const
{
    return (username == user &&
            password == pass);
}