#include "Book.h"

/*
=================================================
DEFAULT CONSTRUCTOR
=================================================
*/

Book::Book()
{
    author = "";
}

/*
=================================================
PARAMETERIZED CONSTRUCTOR
=================================================
*/

Book::Book(int id,
           string title,
           string authorName,
           bool status)
           : Item(id, title, status)
{
    author = authorName;
}

/*
=================================================
SETTER
=================================================
*/

void Book::setAuthor(string authorName)
{
    author = authorName;
}

/*
=================================================
GETTER
=================================================
*/

string Book::getAuthor() const
{
    return author;
}

/*
=================================================
DISPLAY BOOK INFORMATION
=================================================
*/

void Book::display() const
{
    cout << "\n============================";
    cout << "\n          BOOK";
    cout << "\n============================";

    cout << "\nID        : " << itemId;
    cout << "\nTitle     : " << title;
    cout << "\nAuthor    : " << author;

    cout << "\nAvailable : ";

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

string Book::getType() const
{
    return "Book";
}