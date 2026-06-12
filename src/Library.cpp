#include "Library.h"
#include <cctype>

/*
=================================================
CONSTRUCTOR
=================================================
*/

Library::Library()
{
    totalItems = 0;
    totalMembers = 0;
    totalRecords = 0;

    loadMembers();
    loadCatalog();
    loadBorrowRecords();
}

/*
=================================================
DESTRUCTOR
=================================================
*/

Library::~Library()
{
    for (int i = 0; i < totalItems; i++)
    {
        delete catalog[i];
    }
}

/*
=================================================
ADD BOOK
=================================================
*/

void Library::addBook()
{
    if (totalItems >= MAX_ITEMS)
    {
        cout << "\nCatalog is full.\n";
        return;
    }

    int id;
    string title;
    string author;

    cout << "\nEnter Book ID: ";

    while (!(cin >> id) || id <= 0 || id > 99999)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid ID. Enter 1-99999: ";
    }

    for (int i = 0; i < totalItems; i++)
    {
        if (catalog[i]->getItemId() == id)
        {
            cout << "\nError: Item ID already exists.\n";
            return;
        }
    }

    cin.ignore();

    cout << "Enter Title: ";
    getline(cin, title);

    if (title.empty() ||
        title.find_first_not_of(' ') == string::npos)
    {
        cout << "\nTitle cannot be empty.\n";
        return;
    }

    cout << "Enter Author: ";
    getline(cin, author);

    if (author.empty() ||
        author.find_first_not_of(' ') == string::npos)
    {
        cout << "\nAuthor cannot be empty.\n";
        return;
    }

    bool validAuthor = true;

    for (char c : author)
    {
        if (!isalpha(c) &&
            c != ' ' &&
            c != '.' &&
            c != '-' &&
            c != '\'')
        {
            validAuthor = false;
            break;
        }
    }

    if (!validAuthor)
    {
        cout << "\nInvalid author name.\n";
        return;
    }

    catalog[totalItems] =
        new Book(id, title, author, true);
    totalItems++;

    saveCatalog();

    cout << "\nBook Added Successfully.\n";
}

/*
=================================================
ADD MAGAZINE
=================================================
*/

void Library::addMagazine()
{
    if (totalItems >= MAX_ITEMS)
    {
        cout << "\nCatalog is full.\n";
        return;
    }

    int id;
    string title;
    int issue;

    cout << "\nEnter Magazine ID: ";

    while (!(cin >> id) || id <= 0 || id > 99999)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid ID. Enter 1-99999: ";
    }

    for (int i = 0; i < totalItems; i++)
    {
        if (catalog[i]->getItemId() == id)
        {
            cout << "\nError: Item ID already exists.\n";
            return;
        }
    }

    cin.ignore();

    cout << "Enter Title: ";
    getline(cin, title);

    if (title.empty() ||
        title.find_first_not_of(' ') == string::npos)
    {
        cout << "\nTitle cannot be empty.\n";
        return;
    }

    cout << "Enter Issue Number: ";

    while (!(cin >> issue) || issue <= 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid Issue Number: ";
    }

    catalog[totalItems] =
        new Magazine(id, title, issue, true);

    totalItems++;

    saveCatalog();

    cout << "\nMagazine Added Successfully.\n";
}

/*
=================================================
REMOVE ITEM
=================================================
*/

void Library::removeItem()
{
    int id;

    cout << "\nEnter Item ID: ";

    while (!(cin >> id) || id <= 0 || id > 99999)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid ID: ";
    }

    for (int i = 0; i < totalRecords; i++)
    {
        if (records[i].getItemId() == id)
        {
            cout << "\nCannot remove a borrowed item.\n";
            return;
        }
    }

    for (int i = 0; i < totalItems; i++)
    {
        if (catalog[i]->getItemId() == id)
        {
            delete catalog[i];

            for (int j = i; j < totalItems - 1; j++)
            {
                catalog[j] = catalog[j + 1];
            }

            totalItems--;

            saveCatalog();

            cout << "\nItem Removed Successfully.\n";
            return;
        }
    }

    cout << "\nItem Not Found.\n";
}

/*
=================================================
SEARCH ITEM
=================================================
*/
void Library::searchItem()
{
    int id;

    cout << "\nEnter Item ID: ";

    while (!(cin >> id) || id <= 0 || id > 99999)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid ID: ";
    }

    for (int i = 0; i < totalItems; i++)
    {
        if (catalog[i]->getItemId() == id)
        {
            catalog[i]->display();
            return;
        }
    }

    cout << "\nItem Not Found.\n";
}

/*
=================================================
VIEW CATALOG
RUNTIME POLYMORPHISM
=================================================
*/

void Library::viewCatalog()
{
    if (totalItems == 0)
    {
        cout << "\nNo Items Available.\n";
        return;
    }

    cout << "\n=========== CATALOG ===========\n";

    for (int i = 0; i < totalItems; i++)
    {
        catalog[i]->display();
    }
}

/*
=================================================
VIEW BORROW RECORDS
=================================================
*/

void Library::viewBorrowRecords()
{
    if (totalRecords == 0)
    {
        cout << "\nNo Borrow Records Found.\n";
        return;
    }

    cout << "\n======= BORROW RECORDS =======\n";

    for (int i = 0; i < totalRecords; i++)
    {
        records[i].display();
    }
}

/*
=================================================
REGISTER MEMBER
=================================================
*/

void Library::registerMember()
{
    if (totalMembers >= MAX_MEMBERS)
    {
        cout << "\nMember limit reached.\n";
        return;
    }

    int id;
    string username;
    string password;

    cout << "\nEnter Member ID: ";

    while (!(cin >> id) || id <= 0 || id > 99999)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid ID. Enter 1-99999: ";
    }

    for (int i = 0; i < totalMembers; i++)
    {
        if (members[i].getUserId() == id)
        {
            cout << "\nError: Member ID already exists.\n";
            return;
        }
    }

    cout << "Enter Username: ";
    cin >> username;

    if (username.length() < 3 ||
        username.length() > 20)
    {
        cout << "\nUsername must be 3-20 characters.\n";
        return;
    }

    for (int i = 0; i < totalMembers; i++)
    {
        if (members[i].getUsername() == username)
        {
            cout << "\nError: Username already exists.\n";
            return;
        }
    }

    cout << "Enter Password: ";
    cin >> password;

    bool hasDigit = false;

    for (char c : password)
    {
        if (isdigit(c))
        {
            hasDigit = true;
            break;
        }
    }

    if (password.length() < 6 || !hasDigit)
    {
        cout << "\nPassword must be at least 6 characters and contain a digit.\n";
        return;
    }

    members[totalMembers] =
        Member(id, username, password);

    totalMembers++;

    saveMembers();

    cout << "\nRegistration Successful.\n";
}

/*
=================================================
MEMBER LOGIN
=================================================
*/

int Library::loginMember()
{
    string username;
    string password;

    cout << "\nUsername: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    for (int i = 0; i < totalMembers; i++)
    {
        if (members[i].getUsername() == username &&
            members[i].getPassword() == password)
        {
            cout << "\nLogin Successful.\n";

            return members[i].getUserId();
        }
    }

    cout << "\nInvalid Username or Password.\n";

    return -1;
}

/*
=================================================
BORROW ITEM
=================================================
*/

void Library::borrowItem(int memberId)
{
    if (totalRecords >= MAX_RECORDS)
    {
        cout << "\nBorrow record limit reached.\n";
        return;
    }

    int itemId;

    cout << "\nEnter Item ID to Borrow: ";

    while (!(cin >> itemId) || itemId <= 0 || itemId > 99999)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid Item ID: ";
    }

    int borrowCount = 0;

    for (int i = 0; i < totalRecords; i++)
    {
        if (records[i].getMemberId() == memberId)
            borrowCount++;
    }

    if (borrowCount >= 5)
    {
        cout << "\nBorrow limit reached.\n";
        return;
    }

    for (int i = 0; i < totalRecords; i++)
    {
        if (records[i].getMemberId() == memberId &&
            records[i].getItemId() == itemId)
        {
            cout << "\nYou already borrowed this item.\n";
            return;
        }
    }

    for (int i = 0; i < totalItems; i++)
    {
        if (catalog[i]->getItemId() == itemId)
        {
            if (!catalog[i]->isAvailable())
            {
                throw ItemUnavailableException();
            }

            catalog[i]->setAvailability(false);

            records[totalRecords] =
                BorrowRecord(memberId, itemId);

            totalRecords++;

            saveCatalog();
            saveBorrowRecords();

            cout << "\nItem Borrowed Successfully.\n";
            return;
        }
    }

    cout << "\nItem Not Found.\n";
}

/*
=================================================
RETURN ITEM
=================================================
*/

void Library::returnItem(int memberId)
{
    int itemId;

    cout << "\nEnter Item ID to Return: ";

    while (!(cin >> itemId) || itemId <= 0 || itemId > 99999)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid Item ID: ";
    }

    int recordIndex = -1;

    for (int i = 0; i < totalRecords; i++)
    {
        if (records[i].getMemberId() == memberId &&
            records[i].getItemId() == itemId)
        {
            recordIndex = i;
            break;
        }
    }

    if (recordIndex == -1)
    {
        cout << "\nYou did not borrow this item.\n";
        return;
    }

    bool found = false;

    for (int i = 0; i < totalItems; i++)
    {
        if (catalog[i]->getItemId() == itemId)
        {
            catalog[i]->setAvailability(true);
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nItem Not Found.\n";
        return;
    }

    for (int j = recordIndex;
         j < totalRecords - 1;
         j++)
    {
        records[j] = records[j + 1];
    }

    totalRecords--;

    saveCatalog();
    saveBorrowRecords();

    cout << "\nItem Returned Successfully.\n";
}

/*
=================================================
VIEW MY BORROWED ITEMS
=================================================
*/

void Library::viewMyBorrowedItems(int memberId)
{
    bool found = false;

    cout << "\n===== MY BORROWED ITEMS =====\n";

    for (int i = 0; i < totalRecords; i++)
    {
        if (records[i].getMemberId() == memberId)
        {
            cout << "Item ID : "
                 << records[i].getItemId()
                 << endl;

            found = true;
        }
    }

    if (!found)
    {
        cout << "\nNo Borrowed Items Found.\n";
    }
}

/*
=================================================
SAVE MEMBERS
=================================================
*/

void Library::saveMembers()
{
    ofstream file("data/members.txt");

    if (!file)
    {
        cout << "\nError Saving Members.\n";
        return;
    }

    for (int i = 0; i < totalMembers; i++)
    {
        file
            << members[i].getUserId()
            << "|"
            << members[i].getUsername()
            << "|"
            << members[i].getPassword()
            << endl;
    }

    file.close();
}

/*
=================================================
LOAD MEMBERS
=================================================
*/

void Library::loadMembers()
{
    ifstream file("data/members.txt");

    if (!file)
    {
        return;
    }

    int id;
    string username;
    string password;
    char delimiter;

    while (file >> id)
    {
        file >> delimiter;

        getline(file, username, '|');
        getline(file, password);

        // Validation
        if (id <= 0 || id > 99999)
        {
            continue;
        }

        if (username.length() < 3 ||
            username.length() > 20)
        {
            continue;
        }

        bool hasDigit = false;

        for (char c : password)
        {
            if (isdigit(c))
            {
                hasDigit = true;
                break;
            }
        }

        if (password.length() < 6 || !hasDigit)
        {
            continue;
        }

        if (totalMembers >= MAX_MEMBERS)
        {
            break;
        }

        members[totalMembers] =
            Member(id, username, password);

        totalMembers++;
    }

    file.close();
}

/*
=================================================
SAVE CATALOG
=================================================
FORMAT:

Book|101|C++ Programming|Bjarne Stroustrup|1

Magazine|201|Science Today|15|1
=================================================
*/

void Library::saveCatalog()
{
    ofstream file("data/catalog.txt");

    if (!file)
    {
        cout << "\nError Saving Catalog.\n";
        return;
    }

    for (int i = 0; i < totalItems; i++)
    {
        Book *book =
            dynamic_cast<Book *>(catalog[i]);

        Magazine *magazine =
            dynamic_cast<Magazine *>(catalog[i]);

        if (book != nullptr)
        {
            file
                << "Book|"
                << book->getItemId()
                << "|"
                << book->getTitle()
                << "|"
                << book->getAuthor()
                << "|"
                << book->isAvailable()
                << endl;
        }
        else if (magazine != nullptr)
        {
            file
                << "Magazine|"
                << magazine->getItemId()
                << "|"
                << magazine->getTitle()
                << "|"
                << magazine->getIssueNumber()
                << "|"
                << magazine->isAvailable()
                << endl;
        }
    }

    file.close();
}

/*
=================================================
LOAD CATALOG
=================================================
*/

void Library::loadCatalog()
{
    ifstream file("data/catalog.txt");

    if (!file)
    {
        return;
    }

    string type;

    while (getline(file, type, '|'))
    {
        if (totalItems >= MAX_ITEMS)
        {
            break;
        }

        if (type == "Book")
        {
            string idStr;
            string title;
            string author;
            string availableStr;

            getline(file, idStr, '|');
            getline(file, title, '|');
            getline(file, author, '|');
            getline(file, availableStr);

            int id = stoi(idStr);

            bool available =
                (availableStr == "1");

            // Validation
            if (id <= 0 || id > 99999)
            {
                continue;
            }

            if (title.empty() ||
                title.find_first_not_of(' ') == string::npos)
            {
                continue;
            }

            if (author.empty() ||
                author.find_first_not_of(' ') == string::npos)
            {
                continue;
            }

            catalog[totalItems] =
                new Book(
                    id,
                    title,
                    author,
                    available);

            totalItems++;
        }
        else if (type == "Magazine")
        {
            string idStr;
            string title;
            string issueStr;
            string availableStr;

            getline(file, idStr, '|');
            getline(file, title, '|');
            getline(file, issueStr, '|');
            getline(file, availableStr);

            int id = stoi(idStr);

            int issue =
                stoi(issueStr);

            bool available =
                (availableStr == "1");

            // Validation
            if (id <= 0 || id > 99999)
            {
                continue;
            }

            if (title.empty() ||
                title.find_first_not_of(' ') == string::npos)
            {
                continue;
            }

            if (issue <= 0)
            {
                continue;
            }

            catalog[totalItems] =
                new Magazine(
                    id,
                    title,
                    issue,
                    available);

            totalItems++;
        }
    }

    file.close();
}

/*
=================================================
SAVE BORROW RECORDS
=================================================
*/

void Library::saveBorrowRecords()
{
    ofstream file("data/borrow.txt");

    if (!file)
    {
        cout << "\nError Saving Borrow Records.\n";
        return;
    }

    for (int i = 0; i < totalRecords; i++)
    {
        file
            << records[i].getMemberId()
            << "|"
            << records[i].getItemId()
            << endl;
    }

    file.close();
}

/*
=================================================
LOAD BORROW RECORDS
=================================================
*/

void Library::loadBorrowRecords()
{
    ifstream file("data/borrow.txt");

    if (!file)
    {
        return;
    }

    string memberIdStr;
    string itemIdStr;

    while (getline(file, memberIdStr, '|'))
    {
        getline(file, itemIdStr);

        if (totalRecords >= MAX_RECORDS)
        {
            break;
        }

        int memberId =
            stoi(memberIdStr);

        int itemId =
            stoi(itemIdStr);

        bool memberExists = false;
        bool itemExists = false;

        // Check member exists
        for (int i = 0; i < totalMembers; i++)
        {
            if (members[i].getUserId() == memberId)
            {
                memberExists = true;
                break;
            }
        }

        // Check item exists
        for (int i = 0; i < totalItems; i++)
        {
            if (catalog[i]->getItemId() == itemId)
            {
                itemExists = true;
                break;
            }
        }

        if (!memberExists || !itemExists)
        {
            continue;
        }

        bool duplicate = false;

        for (int i = 0; i < totalRecords; i++)
        {
            if (records[i].getMemberId() == memberId &&
                records[i].getItemId() == itemId)
            {
                duplicate = true;
                break;
            }
        }

        if (duplicate)
        {
            continue;
        }

        records[totalRecords] =
            BorrowRecord(
                memberId,
                itemId);

        totalRecords++;
    }

    file.close();
}