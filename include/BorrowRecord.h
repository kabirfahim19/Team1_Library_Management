#ifndef BORROWRECORD_H
#define BORROWRECORD_H

#include <iostream>

using namespace std;

class BorrowRecord
{
private:
    int memberId;
    int itemId;

public:

    // Default Constructor
    BorrowRecord();

    // Parameterized Constructor
    BorrowRecord(int member,
                 int item);

    // Setters
    void setMemberId(int member);

    void setItemId(int item);

    // Getters
    int getMemberId() const;

    int getItemId() const;

    // Display Record
    void display() const;
};

#endif