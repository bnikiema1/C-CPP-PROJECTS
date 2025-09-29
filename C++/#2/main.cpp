#include <iostream>
using namespace std;
#include "util.h"

int main(){
    
    int wins = 0;
    int loses = 0;
    int range = 100;
    int min = 0;
    int playing = 1;

    while(playing){
        system("cls");
        int maxGuesses = 10;
        int attempts = 0;
        int randomNum = randomRange(min,range);
        cout << "\tI'am thinking of a number between 0 - 100,\n\tSee if you can guess it in 5 guesses good Luck!" << endl;
        
        while (attempts < maxGuesses){
            try
            {   int guess;

                cout <<"\nEnter a Number: ";
                cin >> guess;
                attempts++; 
                
                if (guess < randomNum){
                    cout <<"\n Your guess was low try higher!";
                }else if (guess > randomNum){
                    cout <<"\n Your guess was too high try lower";
                }else{
                    cout << "\nYou got it right! Only took you: " << attempts <<" guesses" << endl;
                    wins ++;
                    break;
                }
            
            }
            catch(const std::invalid_argument)
            {
                cout <<"\nTry entering a number";
            }
        }
        if(maxGuesses == attempts){
            cout <<"\n\nBetter luck next time the number was: " << randomNum << endl;
            loses ++;
        }
        char playagain;
        cout <<"Wins: " << wins <<" Loses: "<< loses << endl;
        cout <<"Want to play again? [y/n]: ";
        fflush(stdin);

        cin >> playagain;
        if(playagain == 'y' || playagain == 'Y') continue;
        else {
            cout << "\nThanks for playing";
            playing = 0;
        }
    }

    return 0;
}
