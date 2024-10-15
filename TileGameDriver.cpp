#include <sstream>
#include <string>
#include <iostream>
#include "TileGame.h"
using namespace std;

TileGame::TileGame()
{
    //Assign each item in the array to the value of the index
    for(int i = 0; i < 10; i++)
    {
      tiles[i] = i;
    }

    //TODO: Mix the positions up
    srand(time(NULL));
    int temp[10];
    int used[10] = {11, 11, 11, 11, 11, 11, 11, 11, 11, 11};
    int thing;
    bool stuff = true;
    for (int i = 0; i < 10; i++) {
      stuff = true;
      while (stuff) {
        thing = rand() % 10;
        stuff = false;
        for (int j = 0; j < 10; j++) {
          if (thing == used[j]) {
            stuff = true;
          }
        }
      }
      temp[i] = thing;
      used[i] = thing;
    }
    for (int i = 0; i < 10; i++) {
      tiles[i] = temp[i];
    }
    /*for (int i = 0; i < 10; i++) {//debug cout loop
      cout << tiles[i] << ", ";
    }
    cout << endl;*/
}

int TileGame::findZero()
{
    int end;
    //TODO Return the position of the Zero
    for (int i = 0; i < 10; i++) {
      if (tiles[i] == 0) {
        end = i;
      }
    }
    return end;
}

void TileGame::moveRight()
{
    int zero = findZero();

    if(zero == 0)
    {
     return;
    }
    //TODO:  Swap the value to the left of the zero with the zero
    //Use the variable zero as the index of the zero
    tiles[zero] = tiles[zero - 1];
    tiles[zero - 1] = 0;

}
void TileGame::moveLeft()
{
    int zero = findZero();
    if(zero == 9){
      return;}
    //TODO:  Swap the value to the right of the zero with the zero
    //Use the variable zero as the index of the zero
    tiles[zero] = tiles[zero + 1];
    tiles[zero + 1] = 0;
}

void TileGame::swap()
{
    int zero = findZero();
    if(zero == 9 || zero == 0){
      return;}
    //TODO:  Swap the values on either Side of the 0
    //Use the variable zero as the index of the zero
    int placeholder = tiles[zero - 1];
    tiles[zero - 1] = tiles[zero + 1];
    tiles[zero + 1] = placeholder; 
}

bool TileGame::inOrder()
{
    //TODO: Check to see if the game is in order.  
    bool end = true;
    for (int i = 0; i < 10; i++) {
      if (tiles[i] != i) {
        end = false;
      }
    }
    return end;
}


//Returns the game as a string for display 
string TileGame::getDisplay()
{
  stringstream output;
  for(int i = 0; i < 10; i++)
  {
    if(tiles[i]>0)
      output << "[" << tiles[i] << "]" << " ";
    else
      output << "[ ]" << " ";
  }
  return output.str();
}

enum{QUIT, RIGHT, LEFT, SWAP };
int getChoice();
void displayWinner();

int main() {
  cout << "Tile Game";
  TileGame game;
  int choice;
  int chances = 0;

  do
  {
    cout << endl << game.getDisplay() << endl;
    choice = getChoice();
    switch (choice){
      case RIGHT:
        game.moveRight();
        break;
      case LEFT:
        game.moveLeft();
        break;
      case SWAP:
        game.swap();
        break;
    }
    chances ++;
  }while (!game.inOrder() && choice > 0 && chances < 50);
  
  if(game.inOrder())
  {
    displayWinner();
  }
  else{
    cout << "Better Luck Next Time";
  }

}

//Get Choice returns a the users choice
int getChoice()
{
    int choice;
    cout << "1. Shift Right\n2. Shift Left\n3. Swap\nChoose one: ";
    cin >> choice;
    return choice;
}

void displayWinner()
{
   cout << "\n****************************************\n";
    cout << "     YOU WIN!!\n";
    cout << "\n****************************************\n";
}
