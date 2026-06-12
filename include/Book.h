#ifndef BOOK_H
#define BOOK_H

#include "Item.h"
#include <iostream>
#include <string>

using namespace std;

class Book : public Item
{
private:
    string author;

public:

    // Default Constructor
    Book();

    // Parameterized Constructor
    Book(int id,
         string title,
         string authorName,
         bool status = true);

    // Setter
    void setAuthor(string authorName);

    // Getter
    string getAuthor() const;

    // Overridden Functions
    void display() const override;

    string getType() const override;
};

#endif