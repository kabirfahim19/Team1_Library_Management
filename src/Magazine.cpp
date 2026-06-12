// Author: Iftekhar Fahim
#include "Magazine.h"

/*
=================================================
DEFAULT CONSTRUCTOR
=================================================
*/

Magazine::Magazine()
{
    issueNumber = 0;
}

/*
=================================================
PARAMETERIZED CONSTRUCTOR
=================================================
*/

Magazine::Magazine(int id,
                   string title,
                   int issue,
                   bool status)
                   : Item(id, title, status)
{
    issueNumber = issue;
}

/*
=================================================
SETTER
=================================================
*/

void Magazine::setIssueNumber(int issue)
{
    issueNumber = issue;
}

/*
=================================================
GETTER
=================================================
*/

int Magazine::getIssueNumber() const
{
    return issueNumber;
}

/*
=================================================
DISPLAY MAGAZINE INFORMATION
=================================================
*/

void Magazine::display() const
{
    cout << "\n============================";
    cout << "\n        MAGAZINE";
    cout << "\n============================";

    cout << "\nID            : " << itemId;
    cout << "\nTitle         : " << title;
    cout << "\nIssue Number  : " << issueNumber;

    cout << "\nAvailable     : ";

    if(available)
        cout << "Yes";
    else
        cout << "No";

    cout << endl;
}

/*
=================================================
RETURN ITEM TYPE
=================================================
*/

string Magazine::getType() const
{
    return "Magazine";
}