#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

using namespace std;

class User
{
protected:
    int userId;
    string username;
    string password;

public:

    // Default Constructor
    User();

    // Parameterized Constructor
    User(int id,
         string user,
         string pass);

    // Setters
    void setUserId(int id);

    void setUsername(string user);

    void setPassword(string pass);

    // Getters
    int getUserId() const;

    string getUsername() const;

    string getPassword() const;

    // Pure Virtual Functions
    virtual void showMenu() const = 0;

    virtual string getRole() const = 0;

    virtual ~User();
};

#endif