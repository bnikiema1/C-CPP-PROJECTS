#include <fstream>
#include <iostream>
#include <string>
#include "todoUtil.h"

using namespace std;
int main(int argc, char *argv[])
{
    char *fileName;
    if(argc != 1){
        fileName = argv[1];
        cout << "File name: " << fileName <<endl;
    }else{
        cout <<"Enter a file name when running program"<< endl;
        return 1;
    }
    createFile(fileName);
    writeFile(fileName, 0, "Write CSV", false, "high");
    return 0;
}

