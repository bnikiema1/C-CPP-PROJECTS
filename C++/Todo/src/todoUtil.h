// todoUtil.h
#ifndef TODO_UTIL_H
#define TODO_UTIL_H

#include <vector>
#include <string>

void ui();

struct TodoItem {
    int id;
    std::string task;
    bool completed;
    void display() const;
};

class TodoList {
private:
    std::vector<TodoItem> list;
    int nextId = 1;

public:
    void addTask(const std::string& task);
    void displayAll();
    void markCompleted(int id);
    void deleteTask(int id);
    void createFile(std::string fileName);
    void saveToFile(std::string fileName);
    void loadFromFile(std::string fileName);

};

#endif