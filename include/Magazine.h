#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "Item.h"
#include <iostream>
#include <string>

using namespace std;

class Magazine : public Item
{
private:
    int issueNumber;

public:

    // Default Constructor
    Magazine();

    // Parameterized Constructor
    Magazine(int id,
             string title,
             int issue,
             bool status = true);

    // Setter
    void setIssueNumber(int issue);

    // Getter
    int getIssueNumber() const;

    // Overridden Functions
    void display() const override;

    string getType() const override;
};

#endif