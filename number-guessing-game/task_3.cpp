#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){
    srand(static_cast<unsigned int>(time(0)));
    int secretNumber = rand() % 100 + 1;
    int userGuess;

    cout<<"==================================\n";
    cout<<"WELCOME TO NUMBER GUESSING GAME!\n"  ;
    cout<<"==================================\n";
    cout<<"Guess a number between 1-100: \n";

    do{
        cout<<"Guess the number:";
        cin>>userGuess;

        if(userGuess == secretNumber){
            cout<<"Congratulations! You guessed the right Number.\n\n";
        }else if(abs(userGuess-secretNumber)<=2){
            cout<<"Almost there! Try again.\n\n";            
        }else if(abs(userGuess-secretNumber)<=5){
            cout<<"You are close! Try again.\n\n";  
        }else if(userGuess<secretNumber){
            cout<<"Too low. Try again!\n\n";
        }else{
            cout<<"Too high. Try again!\n\n";
        }
    }while(userGuess!=secretNumber);
    cout<<"==================================\n";
    return 0;
}