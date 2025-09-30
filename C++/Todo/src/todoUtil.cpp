#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include "todoUtil.h"
#include <list>

namespace fs = std::filesystem;
// Todo class methods
void TodoItem::display() const { 
    std::cout << id << ". " << (completed ? "[X] " : "[ ] ") << task << std::endl;
}

void TodoList::addTask(const std::string& task) {
    list.push_back(TodoItem{nextId++, task, false});
}

void TodoList::displayAll() {
    for(const auto& item : list) {
        item.display();
    }
}

void TodoList::markCompleted(int id) {
    for(auto& item : list) {
        if(item.id == id) {
            item.completed = true;
            break;
        }
    }
}

void TodoList::deleteTask(int id) {
    for(auto it = list.begin(); it != list.end(); ++it) {
        if(it->id == id) {
            list.erase(it);
            break;
        }
    }
}

void TodoList::createFile(std::string fileName){
    fs::path file = fileName;
    if(fs::exists(file)){
        std::cout<< fileName <<": is already in the directory."<< std::endl;
        std::cout<<"Retrieving todo list tasks."<< std::endl;
        TodoList::loadFromFile(fileName);

        return;
    }
    std::ofstream outfile(fileName);
    if(!outfile){
        std::cout <<"Unable to access file." << std::endl;
        return;
    }
    std::cout <<fileName <<": Has been created!"<<std::endl;
}

void TodoList::saveToFile(std::string fileName){
    std::ofstream file(fileName);

    for (const auto& item : list){
        file << item.id << "|" << item.task << "|" << item.completed <<"\n";
    }
}

void TodoList::loadFromFile(std::string fileName){
    std::ifstream file(fileName);
    if(!file.is_open()) return;

    std::string line;
    while(std::getline(file, line)){
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);

        int id = std::stoi(line.substr(0, pos1));
        std::string task = line.substr(pos1 + 1, pos2 - pos1 - 1);
        bool completed = std::stoi(line.substr(pos2 + 1));

        list.push_back(TodoItem{id, task, completed});
        nextId = std::max(nextId, id + 1);
    }

}

// UI menu
void ui(){
    std::cout <<"\tWelcome TODO APP"<<std::endl;
    std::cout <<"Add Task: 1"<<std::endl;
    std::cout <<"Display List: 2"<<std::endl;
    std::cout <<"Remove Task: 3"<<std::endl;
    std::cout <<"Mark Complete: 4"<<std::endl;
    std::cout <<"Exit: 5"<<std::endl;
    
}