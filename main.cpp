#include <iostream>
#include <cstdlib>
using namespace std;

class connectfour{
  public:
    int board[6][7];
    void displayboard();
    void resetboard();
    void userturn(int);
    // bool check4win();
    void AIturn();
};

int main() {
  int piece;
  connectfour a;
  cout << "The Belle Vegas Connect 4 Rules" << endl;
  cout << "1. A random number game will determine who will go first" << endl;
  cout << "2. You select which row you would like to drop your piece down" << endl;
  cout << "3. Turns will alternate between player until a winner is determined. Four pieces in row vetically, horizontally, or diagonally is consider a win.\n" << endl;
  cout << "Choose a number between 1-9 as your piece: ";
  cin >> piece;
  a.resetboard();
  a.displayboard();
  // while(!a.check4win()){
    a.userturn(piece); 
    a.AIturn();
    a.userturn(piece); 
    a.AIturn();
  // };
}

void connectfour::displayboard(){
    // Sets up row numbers
    for(int num = 1; num < 8; num++){
      cout << "  " << num << " ";
    }
    cout << endl;

    // Sets up board
    for (int x = 0; x < 6; x++){
      cout << "| ";
        for (int y = 0; y < 7; y++){
            cout<<board[x][y];
            cout<<" | ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void connectfour::resetboard(){
  // Sets all of the array spots to 0
  for(int i = 0; i < 6; i++){
    for(int j = 0; j < 7; j++){
      board[i][j] = 0;
    }
  }
}

void connectfour::userturn(int piece){
  int choice, temp;
  cout << "What column would you like you're piece to go to?: ";
  cin >> choice;
  if(board[5][choice] == 0){
    board[5][choice] = piece;
  }else{
    //Moves pieces to next empty spot
      for(int i = 5; i > -1; i--){
        if(board[i][choice] == 0){
          board[i][choice] = piece;
          break;
        }
    }
  }
  displayboard();
}



void connectfour::AIturn(){
  int ai1 = ((rand() % 7) + 1);
  if(board[5][ai1] == 0){
    board[5][ai1] = 9;
  }else{
    //Moves pieces to next empty spot
      for(int i = 5; i > -1; i--){
        if(board[i][ai1] == 0){
          board[i][ai1] = 9;
          break;
        }
    }
  }
  displayboard();
}
