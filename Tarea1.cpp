#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

//Initial Important Variables
char tablero[31] = {'X','N','N','N','N','N','S','N','L','N','N','N','N','S','N','N','L','N','N','N','N','N','N','N','L','N','N','N','N','S','N'}; //You add another one (X) in the begging to skip 0
string player1, player2;
int i = 0;

class SnakesLadders{ //Class for defining all methods to be used
  private:
  string name;
  int playerpoints;
  int dice;
  int newplayerpoints;
  public:
    SnakesLadders() {
      playerpoints = 1;
      newplayerpoints = 1;
    }
    int roll(int player){ //Roll the Dice
      srand(time(0) + player);
      int dice = rand()%6+1;
      return dice;
    }
    int pointsNow(){ //Points Before the New Turn
      playerpoints = newplayerpoints;
      return playerpoints;
    }
    int pointsThen(int player){ //Points with the New Roll
      newplayerpoints = playerpoints + roll(player);
      if (landedIn(player) == 'S'){ //Evaluate if Player fell in Snake or Ladder Tile
        newplayerpoints -= 3;
      }
      else if (landedIn(player) == 'L'){
        newplayerpoints += 3;
      }
      return newplayerpoints;
    }
    void setName(string n){ //Set Player Name
      name = n;
    }
    string getName(){ //Get Player Name
      return name;
    }
    char landedIn(int player){ //Get Tile Value from this Roll
      char tile = tablero[playerpoints + roll(player)];
      return tile;
    }
};

class MyGame: public SnakesLadders{ //Inheritance from SnakesLadders to get all methods
  public:
  void start(){
    srand(time(0));
    //Welcome Message
    cout << "Welcome to Snakes and Ladders!" << endl;
    //Player One
    cout << "Introduce The Name of Player 1: "; cin >> player1;
    SnakesLadders p1, p2;
    p1.setName(player1);
    //Player Two
    cout << "Introduce The Name of Player 2: "; cin >> player2;
    p2.setName(player2);
    cout << "Great, Thanks!" << endl;
    cout << "Lets Start!" << endl;
    char op;
    cout << "Press C to Continue Next Turn, or E to End the Game: "; cin>> op;
      while(true){
        if (op == 'C'){
        i = i + 1;
            int A = 1;
            int B = 2;
            //Player 1 Data
            cout <<  "Player Name: " << p1.getName() << "\nTurn Number: " << i << "\nCurrent Points: " << p1.pointsNow() << "\nDice Roll: " << p1.roll(A) << "\nThe Player Landed in: " << p1.landedIn(A) << "\nThe Player Now Has: " << p1.pointsThen(A) << " Points" << endl;;
            cout << "**********************************" << endl;
            //Player 2 Data
            cout <<  "Player Name: " << p2.getName() << "\nTurn Number: " << i << "\nCurrent Points: " << p2.pointsNow() << "\nDice Roll: " << p2.roll(B) << "\nThe Player Landed in: " << p2.landedIn(B) << "\nThe Player Now Has: " << p2.pointsThen(B) << " Points" << endl;
            cout << "**********************************" << endl;
            //Evaluate if Someone won
              if((p1.pointsThen(A) >= 30) and (p2.pointsThen(B) >= 30)){
                cout<<"Both Players Won in Turn " << i << '!'<< endl;
                cout<<"-----GAME OVER-----" <<endl;
                break;
                } 
              else if(p1.pointsThen(A) >= 30){
                cout<< p1.getName() << " Won the Game in Turn " << i << '!'<< endl;
                cout<<"-----GAME OVER-----" <<endl;
                break;
                }
              else if(p2.pointsThen(B) >= 30){
                cout<< p2.getName() << " Won the Game in Turn " << i << '!'<< endl;
                cout<<"-----GAME OVER-----" <<endl;
                break;
                }
              //Evaluate if User Wants to Keep Playing
              cout << "Continue Playing or End Game? "; cin>> op;
              }
        else if(op == 'E'){
          cout << "You Ended the Game" << endl;
          break;
          }
        else{
          cout << "Invalid Option, Press C to Continue Next Turn, or E to End the Game: "; cin>> op;
        }
      }
    }
};

int main() { //Main Code - Call MyGame Method
  MyGame SnakesAndLadders;
  SnakesAndLadders.start();
  return 0;
}