#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <random>
#include <limits>


class Bank
{
    public:
        int accountID;
        std::string accountHolder;
        double balance;
        std::vector<std::tuple<std::string,int>> history;
        
        Bank(std::string name){
            this->accountHolder = name;
            this->balance = 0.0;
            this->accountID = generateID();
        }

        void viewAccount(){
            std::cout <<"Account ID: "<< this->accountID << ", Account Holder: " <<  this->accountHolder <<
            ", Account balance: $" << this->balance<<". \n";
        }

        void deposit(){
            double amount;
            std::cout<<"Deposit: ";
            if(!(std::cin >> amount)){
                std::cout <<"Error must enter a number.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return;
            }
            balance += amount;
            history.push_back(std::tuple("Deposit", amount));
            
        }

        void withdrawal(){
            double amount;
            std::cout<<"Withdrawal: ";
            if(!(std::cin >> amount)){
                std::cout<<"Error must enter a number.\n\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                return;
            }
            if(!(balance - amount >= 0)){
                std::cout<<"Insufficent fund.\n\n";
                return;
            }
            balance -= amount;
            history.push_back(std::tuple("Withdrawal", amount));
        }

        void transactionHistory(){
            for(const auto& [op, amt]: history){
                std::cout << op <<": $"<< amt << ", ";
            }
            std::cout <<'\n';
        }

        int generateID(){
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution <> dis(1, 10000);

            return dis(gen);
        }
};


int main(){
    system("cls");

    std::string placeHolder;

    std::cout <<"Welcome to the National Bank!\nTo open an account please provide your name: ";
    if(!(std::cin >> placeHolder)){
        std::cout << "\nError couldn't procces correctly.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1;
    }

    Bank account = Bank(placeHolder);

    std::cout << "\nAccount has been successfully created!\n";

    int loop = 1;

    while (loop){
        int option;
        std::cout<<"\n\t\tAccount Holder: " << account.accountHolder <<"\n\n";
        std::cout << "----Options----\n"<<"1. view account\n"<<"2. Deposit\n"<<"3. Withdrawal\n"<<"4. View Transaction history\n"<<"5. Exit\n"<<"Enter 1-5: ";

        if(!(std::cin >> option)){
            std::cout <<"\nMust enter a number\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        switch (option)
        {
        case 1:
            system("cls");
            std::cout<<'\n';
            account.viewAccount();
            break;
        case 2:
            system("cls");
            std::cout<<'\n';
            account.deposit();
            break;
        case 3:
            system("cls");
            std::cout<<'\n';
            account.withdrawal();
            break;
        case 4: 
            system("cls");
            std::cout<<'\n';
            account.transactionHistory();
            break;
        case 5:
            std::cout<<'\n';
            std::cout<< "Exitng program!";
            loop = 0;
            break;
        
        default:
        std::cout <<" Must input a number from 1-5.\n";
            break;
        }
    }


    return 0;

}
