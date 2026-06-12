# Library Management System

## Overview

This project is a console-based **Library Management System** developed in C++ using Object-Oriented Programming (OOP) principles.

The system allows administrators and members to manage library resources, including books, magazines, borrowing records, and member accounts.

---

## Features

Admin (Default)
Name: admin
password: admin123

### Administrator
- Add new books
- Add new magazines
- Remove items
- Search items
- View library catalog
- View borrowing records

### Member
- Login to the system
- Borrow items
- Return items
- View borrowed items

### System Features
- File-based data persistence
- User authentication
- Polymorphism using abstract classes
- Inheritance and encapsulation
- Borrow record management


## Requirements

- GCC/G++ Compiler
- GNU Make
- Linux, macOS, or Windows (with MinGW/MSYS2)

### Check Installation

```bash
g++ --version
mingw32-make --version
```

---

## Build Instructions

Since a Makefile is already provided, simply run:

```bash
mingw32-make
```

This command will compile all source files and generate the executable.

---

## Run the Program

After successful compilation:


### Windows

```bash
.\library.exe
```

> Replace `library` with the executable name specified in your Makefile if it differs.

---

## Clean Build Files

To remove object files and executable:

```bash
mingw32-make clean
```

---

## Rebuild the Project

```bash
mingw32-make clean
mingw32-make
```

---

## Data Files

The application automatically creates and updates data files used for:

- Members
- Books and magazines
- Borrow records

Do not delete these files while the program is running.

---
## Team Members & Contributions

| Member              | GitHub | Contribution |
|--------             |--------|--------------|
| Kabir Md Fahim      | kabirfahim19 | Main program flow, Admin features, repository setup |
| Hossain fahim       | hossain | Book and Magazine classes |
| Miraj               | MIRAJ-MD | Member class, borrow record management |
| ifthekar Fahim      | fa-him2002| File persistence (FileManager), Library core logic |

## OOP Concepts Used

- Inheritance: Book and Magazine inherit from Item; Admin and Member inherit from User
- Polymorphism: virtual functions of abstract Item and User classes overridden in derived classes
- Encapsulation: private data members with public getters/setters
- Abstraction: abstract base classes (Item, User)
- File Handling: FileManager handles saving/loading catalog, members, and borrow records
