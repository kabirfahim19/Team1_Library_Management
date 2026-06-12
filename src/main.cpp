#include <iostream>
#include "Library.h"
#include "Admin.h"

using namespace std;

/*
=================================================
INPUT VALIDATION FOR MENU CHOICES
=================================================
*/

int getChoice(int minChoice, int maxChoice)
{
    int choice;

    while (!(cin >> choice) ||
           choice < minChoice ||
           choice > maxChoice)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid choice. Enter "
             << minChoice
             << "-"
             << maxChoice
             << ": ";
    }

    return choice;
}

/*
=================================================
MAIN
=================================================
*/

int main()
{
    Library library;
    Admin admin;

    int mainChoice;

    do
    {
        cout << "\n================================";
        cout << "\n   LIBRARY BORROWING SYSTEM";
        cout << "\n================================";
        cout << "\n1. Admin Login";
        cout << "\n2. Register Member";
        cout << "\n3. Member Login";
        cout << "\n0. Exit";
        cout << "\n\nEnter Choice: ";

        mainChoice = getChoice(0, 3);

        switch (mainChoice)
        {
        /*
        =========================================
        ADMIN LOGIN
        =========================================
        */
        case 1:
        {
            string username;
            string password;

            cout << "\nAdmin Username: ";
            cin >> username;

            cout << "Admin Password: ";
            cin >> password;

            if (admin.login(username, password))
            {
                cout << "\nAdmin Login Successful.\n";

                int adminChoice;

                do
                {
                    admin.showMenu();

                    cout << "\nEnter Choice: ";

                    adminChoice = getChoice(0, 6);

                    switch (adminChoice)
                    {
                    case 1:
                        library.addBook();
                        break;

                    case 2:
                        library.addMagazine();
                        break;

                    case 3:
                        library.removeItem();
                        break;

                    case 4:
                        library.searchItem();
                        break;

                    case 5:
                        library.viewCatalog();
                        break;

                    case 6:
                        library.viewBorrowRecords();
                        break;

                    case 0:
                        cout << "\nLogging Out...\n";
                        break;
                    }

                } while (adminChoice != 0);
            }
            else
            {
                cout << "\nInvalid Admin Credentials.\n";
            }

            break;
        }

        /*
        =========================================
        MEMBER REGISTRATION
        =========================================
        */
        case 2:
        {
            library.registerMember();
            break;
        }

        /*
        =========================================
        MEMBER LOGIN
        =========================================
        */
        case 3:
        {
            int memberId =
                library.loginMember();

            if (memberId != -1)
            {
                int memberChoice;

                do
                {
                    cout << "\n================================";
                    cout << "\n          MEMBER MENU";
                    cout << "\n================================";
                    cout << "\n1. View Catalog";
                    cout << "\n2. Borrow Item";
                    cout << "\n3. Return Item";
                    cout << "\n4. View My Borrowed Items";
                    cout << "\n0. Logout";
                    cout << "\n\nEnter Choice: ";

                    memberChoice =
                        getChoice(0, 4);

                    switch (memberChoice)
                    {
                    case 1:
                        library.viewCatalog();
                        break;

                    case 2:
                        try
                        {
                            library.borrowItem(memberId);
                        }
                        catch (ItemUnavailableException &e)
                        {
                            cout << endl
                                 << e.what()
                                 << endl;
                        }
                        break;

                    case 3:
                        library.returnItem(memberId);
                        break;

                    case 4:
                        library.viewMyBorrowedItems(memberId);
                        break;

                    case 0:
                        cout << "\nLogging Out...\n";
                        break;
                    }

                } while (memberChoice != 0);
            }

            break;
        }

        /*
        =========================================
        EXIT
        =========================================
        */
        case 0:
            cout << "\nThank You For Using The System.\n";
            break;
        }

    } while (mainChoice != 0);

    return 0;
}