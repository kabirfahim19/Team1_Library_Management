// Author: Hossain Fahim
#include "FileManager.h"

/*
=================================================
CHECK FILE EXISTENCE
=================================================
*/

bool FileManager::fileExists(string fileName)
{
    ifstream file(fileName);

    return file.good();
}

/*
=================================================
CLEAR FILE
=================================================
*/

void FileManager::clearFile(string fileName)
{
    ofstream file(fileName);

    file.close();
}