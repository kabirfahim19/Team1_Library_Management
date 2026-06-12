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