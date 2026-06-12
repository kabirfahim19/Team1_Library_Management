#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

using namespace std;

/*
=================================================
CUSTOM EXCEPTION
=================================================
*/

class ItemUnavailableException
    : public exception
{
public:

    const char* what() const noexcept override
    {
        return "Item is already borrowed!";
    }
};

#endif