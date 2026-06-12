#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <fstream>
#include <string>

#include "Book.h"
#include "Magazine.h"
#include "Member.h"
#include "BorrowRecord.h"
#include "Exception.h"

using namespace std;

class Library
{
private:

    static const int MAX_ITEMS = 100;
    static const int MAX_MEMBERS = 100;
    static const int MAX_RECORDS = 500;

    // Runtime Polymorphism
    Item* catalog[MAX_ITEMS];

    Member members[MAX_MEMBERS];

    BorrowRecord records[MAX_RECORDS];

    int totalItems;
    int totalMembers;
    int totalRecords;

public:

    Library();

    ~Library();

    /*
    ============================================
    ADMIN FUNCTIONS
    ============================================
    */

    void addBook();

    void addMagazine();

    void removeItem();

    void searchItem();

    void viewCatalog();

    void viewBorrowRecords();

    /*
    ============================================
    MEMBER FUNCTIONS
    ============================================
    */

    void registerMember();

    int loginMember();

    void borrowItem(int memberId);

    void returnItem(int memberId);

    void viewMyBorrowedItems(int memberId);

    /*
    ============================================
    FILE FUNCTIONS
    ============================================
    */

    void saveMembers();

    void loadMembers();

    void saveCatalog();

    void loadCatalog();

    void saveBorrowRecords();

    void loadBorrowRecords();
};

#endif