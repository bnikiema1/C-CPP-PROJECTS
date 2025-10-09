
#include <iostream>
#include "todoUtil.h"

int main(int argc, char* argv[]) { // pass file name and extension when running app
    
    TodoList manager;
    char *fileName;
    if( argc == 1){
        std::cout <<"Enter a csv file name  when running "<< std::endl;
        return 1;
    }
    fileName = argv[1];
    
    manager.createFile(fileName);
    system("cls");
    int loop = 1;
    while(loop){
        std::string task;
        int option;
        int id;

        ui();

        try{
            std::cin >> option;

            if (option == 1){
                std::cout<<"Enter a task"<< std::endl;

                std::cin >> task; // getline() function seems to keep geting skipped and saves an empty todoitem in to the todolist class  i dont know why.


                manager.addTask(task);
                std::cout << std::endl <<"task has been added!"<<std::endl;
            }else if (option == 2){
                manager.displayAll();
            }else if (option == 3){
                std::cout << "Enter the id of task you want to remove: ";
                std::cin >> id;
                manager.deleteTask(id);
                std::cout<< std::endl <<" Task has been removed!"<<std::endl;
            }else if (option == 4){
                std::cout << "Enter the id of task you've completed: ";
                std::cin >> id;
                manager.markCompleted(id);
                std::cout<< std::endl <<" Completed!"<<std::endl;
                }else if (option == 5){
                    std::cout<<"Saving files...exiting"<<std::endl;
                    manager.saveToFile(fileName);
                    break;
                }else{
                    continue;
            }
        }catch(std::invalid_argument()){
            std::cout <<"Enter an number form 1-5";
        }
    }
    return 0;
}