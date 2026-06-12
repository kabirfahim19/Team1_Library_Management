#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

using namespace std;

class Item
{
protected:
    int itemId;
    string title;
    bool available;

public:

    Item();

    Item(int id,
         string t,
         bool status = true);

    void setItemId(int id);

    void setTitle(string t);

    void setAvailability(bool status);

    int getItemId() const;

    string getTitle() const;

    bool isAvailable() const;

    virtual void display() const = 0;

    virtual string getType() const = 0;

    virtual ~Item();
};

#endif