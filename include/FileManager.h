#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>

using namespace std;

class FileManager
{
public:

    static bool fileExists(string fileName);

    static void clearFile(string fileName);
};

#endif