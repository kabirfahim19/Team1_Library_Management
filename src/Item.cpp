#include "Item.h"

/*
=================================================
DEFAULT CONSTRUCTOR
=================================================
*/

Item::Item()
{
    itemId = 0;
    title = "";
    available = true;
}

/*
=================================================
PARAMETERIZED CONSTRUCTOR
=================================================
*/

Item::Item(int id,
           string t,
           bool status)
{
    itemId = id;
    title = t;
    available = status;
}

/*
=================================================
SETTERS
=================================================
*/

void Item::setItemId(int id)
{
    itemId = id;
}

void Item::setTitle(string t)
{
    title = t;
}

void Item::setAvailability(bool status)
{
    available = status;
}

/*
=================================================
GETTERS
=================================================
*/

int Item::getItemId() const
{
    return itemId;
}

string Item::getTitle() const
{
    return title;
}

bool Item::isAvailable() const
{
    return available;
}

/*
=================================================
DESTRUCTOR
=================================================
*/

Item::~Item()
{
}