#include<iostream>
#include<vector>
using namespace std;
 
class TicTacToe{
        private:
        vector<vector<char>> board;
        char currentPlayer;
        bool gameOver;
        int moves;

        public:
        TicTacToe(){
            board = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
            currentPlayer = 'X';
            gameOver = false;
            moves = 0;
        }
        void displayBoard(){
            cout<<"-------------"<<endl;
            for(int i = 0; i<3; i++){
                cout<<"|";
                for(int j = 0; j<3; j++){
                    cout<<board[i][j]<<"|";
                }
                cout<<endl;
                cout<<"-------------"<<endl;
            }
        }
        void switchPlayer(){
            currentPlayer = (currentPlayer == 'X')?'O':'X';
        }
        void makeMove(int move){
            if(move < 1 || move > 9){
                cout<<"Invalid move" <<endl;
                return;
            }
            int row = (move - 1)/3;
            int col = (move - 1)%3;
            if(board[row][col]=='X' || board[row][col]=='O'){
                cout<<"Invalid move. Please Try Again!"<<endl;
                return;
            }
            board[row][col] = currentPlayer;
            moves++;
        }
        bool checkWinner(){
            for(int i = 0; i<3; i++){
                if(board[i][0]== currentPlayer && board[i][1]==currentPlayer && board[i][2]==currentPlayer){
                    return true;
                }
                if(board[0][i]==currentPlayer && board[1][i]==currentPlayer && board[2][i]==currentPlayer){
                    return true;
                }
            }
            if(board[0][0]==currentPlayer && board[1][1]==currentPlayer && board[2][2]==currentPlayer){
                return true;
            }
            if(board[0][2]==currentPlayer && board[1][1]==currentPlayer && board[2][0]==currentPlayer){
                return true;
            }
            return false;
        }
        void playGame(){
            while(!gameOver){
                displayBoard();
                cout<<"Player"<<currentPlayer<<"'s turn. Enter your move: "<<endl;
                int move;
                cin>>move;
                makeMove(move);
                if(checkWinner()){
                    cout<<"Player"<<currentPlayer<<"wins!"<<endl;
                    displayBoard();
                    gameOver = true;
                }
                else if(moves == 9){
                    cout<<"It's a tie!"<<endl;
                    displayBoard();
                }
                else{
                    switchPlayer();
                }
            }
        }
    };
int main(){
    TicTacToe game;
    game.playGame();
    return 0;
}
