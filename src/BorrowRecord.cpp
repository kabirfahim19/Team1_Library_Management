#include "BorrowRecord.h"

/*
=================================================
DEFAULT CONSTRUCTOR
=================================================
*/

BorrowRecord::BorrowRecord()
{
    memberId = 0;
    itemId = 0;
}

/*
=================================================
PARAMETERIZED CONSTRUCTOR
=================================================
*/

BorrowRecord::BorrowRecord(int member,
                           int item)
{
    memberId = member;
    itemId = item;
}

/*
=================================================
SETTERS
=================================================
*/

void BorrowRecord::setMemberId(int member)
{
    memberId = member;
}

void BorrowRecord::setItemId(int item)
{
    itemId = item;
}

/*
=================================================
GETTERS
=================================================
*/

int BorrowRecord::getMemberId() const
{
    return memberId;
}

int BorrowRecord::getItemId() const
{
    return itemId;
}

/*
=================================================
DISPLAY RECORD
=================================================
*/

void BorrowRecord::display() const
{
    cout << "Member ID : "
         << memberId
         << " | Item ID : "
         << itemId
         << endl;
}