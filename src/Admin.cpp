#include "Admin.h"

/*
=================================================
DEFAULT ADMIN ACCOUNT
Username : admin
Password : admin123
=================================================
*/

Admin::Admin()
    : User(1, "admin", "admin123")
{
}

/*
=================================================
PARAMETERIZED CONSTRUCTOR
=================================================
*/

Admin::Admin(int id,
             string user,
             string pass)
             : User(id, user, pass)
{
}

/*
=================================================
ADMIN MENU
=================================================
*/

void Admin::showMenu() const
{
    cout << "\n==========================";
    cout << "\n       ADMIN MENU";
    cout << "\n==========================";

    cout << "\n1. Add Book";
    cout << "\n2. Add Magazine";
    cout << "\n3. Remove Item";
    cout << "\n4. Search Item";
    cout << "\n5. View Catalog";
    cout << "\n6. View Borrow Records";
    cout << "\n0. Logout";

    cout << "\n==========================\n";
}

/*
=================================================
ROLE
=================================================
*/

string Admin::getRole() const
{
    return "Admin";
}

/*
=================================================
ADMIN LOGIN
=================================================
*/

bool Admin::login(string user,
                  string pass) const
{
    return (username == user &&
            password == pass);
}