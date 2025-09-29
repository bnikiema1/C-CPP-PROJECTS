#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>
#include "todoUtil.h"

using namespace std;
namespace fs = filesystem;


int createFile(char *fileName)
{
    if(fs::exists(fileName)){
        cout << fileName <<" Has been located!"<< endl;
        return 0;
    }

    ofstream file1(fileName);

    if(!file1){
        cout <<"Error opening file!" << endl;
        return 1;
    }
    file1 <<"ID, Task, Completed, priority"<<endl; // going to use a csv file to save tasks
    file1.close();
    cout <<fileName <<": Has been successfully created!"<<endl;
    return 0;
}

int writeFile(const char* file, int id, const char* task, bool completed, const char* priority) {
    ofstream outFile(file, ios::app);
    if(!outFile){
        cout << "Can't access the file: " << file << endl;
        return -1;
    }
    outFile<<id <<", "<< task <<", "<< completed <<", "<< priority<<endl;
    outFile.close();
    cout <<"Write successfully"<<endl;

    return 0;
}