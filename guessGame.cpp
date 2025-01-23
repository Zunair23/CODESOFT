#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class guessingGame{
    private:
        int randomNumber;
        int attempts;

     public:
        guessingGame(){
        srand(static_cast<unsigned int>(time(0)));
        randomNumber = rand () % 100 + 1;
        attempts = 0;
         }
        
         void playGame(){
            cout<< "Welcome to the Number Guessing Game!"<<endl;
            cout<<"I have generated a random number between 1 and 100."<<endl;
            cout<<"Can you guess what it is?"<<endl;
            
            int UserGuess = 0;
                while(true){
                    cout<<"Enter your Guess:"<<endl;
                    cin>>UserGuess;
                    attempts++;
                
                if(UserGuess > randomNumber){
                    cout<<"To high. Try Again!"<<endl;
                }
                else if(UserGuess < randomNumber){
        
                    cout<<"To low. Try Again!"<<endl;
                }
                else{
                    cout<<"Congratulations! You guessed the right number!"<<attempts<<" attempts!"<<endl;
                    break;
                }
          }
        }
};
int main(){
    guessingGame game;
    game.playGame();
    return 0;
}