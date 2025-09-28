#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

void printMenu(); // prototype function to print calculator menu

int main()
{
    char retry; // declaring a variable that will continue or exit the loop

    do
    {   
        char operatorSign; //declaring variables
        double x, y;
        string a, b;

        system("cls"); // clearing the console and printing the menu
        printMenu();
        cin >> operatorSign;

        cout << "Enter a number"<<endl;
        cin >> a;
        cout << "Enter a number"<<endl;
        cin >> b;
        try { // to verify that the user input numbers and not characters or signs
            x = stod(a);
            y = stod(b);
            
            switch (operatorSign) // preform equation based on the operator sign that was stored from input
            {
            case '+':
                cout <<"Result: " << x + y <<endl;
                break;
            case '-':
                cout <<"Result: " << x - y <<endl;
                break;
            case '*':
                cout <<"Result: " << x * y <<endl;
                break;
            case '/':
                if(y == 0){
                    cout <<"Can't divide " << x <<" by " << y <<endl;
                    break;
                }else{
                    cout <<"Result: "<< x / y <<endl;
                    break;
                }
            default:
                cout << "Entered an invalid option!"<<endl;
                break;
            }
        }catch (const std::invalid_argument){

            cout <<"You must enter numeric values!"<<endl;
        }
        cout <<"Enter Y or y to exit:\n";

        cin.ignore(1000, '\n');
        cin >> retry; // determines if the while loop will exit or continue
        
    } while (retry != 'y' && retry != 'Y');
    
    cout << "\nExiting Basic Calculator"<<endl;
}

void printMenu(){

    cout <<"\t___Basic Calculator___"<< endl;
    cout << "Select: +"<<endl;
    cout << "Select: -"<<endl;
    cout << "Select: *"<<endl;
    cout << "Select: /"<<endl;
}