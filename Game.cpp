#include <iostream>
#include <string>
#include <fstream>

using namespace std;

char gameboard[4][4];

void initialize_gameboard(char gameboard[4][4]); // Function declaration
void print_gameboard(char gameboard[4][4]);
int prompt_user();
int num;
void askForBattleShip(char gameboard[4][4]);
void askForAllBattleShips(char gameboard[4][4]);
void startShooting(char gameboard[4][4]);
void takeshot(char gameboard[4][4]);
void checkifallarehit(char gameboard[4][4]);


const char noship = '0'; //point without ship
const char ship = '1'; //point with a ship
const char hit = 'h'; //tried and hit ship
const char miss = 'f'; //tried and missed ship


int main()
{
	cout << "Battleship" << endl;
  initialize_gameboard(gameboard);




while (true){
	
    cout<<"Enter 1 to position the battleships.\n";
	cout<<"Enter 2 to start playing.\n";
	cout<<"Enter 4 to quit.\n";
	cin>>num;
	
if (num == 1) {
		askForAllBattleShips(gameboard);
	} else if (num == 2) {
		startShooting(gameboard);
	} else if (num == 4) {
		cout<<"bye!bye!\n";
  		exit;
  		break;
	} 
		else {
		
	} 
}
}

void askForBattleShip(char gameboard[4][4])
{
    int x,y, ok=0;
    
    do
    {
		cout <<"Please enter a battle ship" << endl;     
		cout<<"please enter x coordinate.\n";
		cin>>x;
		cout<<"please enter y coordinate.\n";
		cin>>y;
	
	if (gameboard[x][y]==noship)
	{ 
			gameboard[x][y]=ship;
			ok=1;
	}
	else	
		cout<< "That coordinate was already taken!!\n";
			
	} while (ok==0);
	
	ok=0;
	
	do
	{
		cout<<"please enter 2nd x coordinate.\n";
		cin>>x;
		cout<<"please enter 2nd y coordinate.\n";
		cin>>y;
		
		if (gameboard[x][y]==noship)
		{
				gameboard[x][y]=ship;
				ok=1;
		}
			
		else	
			cout<< "That coordinate was already taken!!\n";
			
	}  while (ok==0);
	
}

void askForAllBattleShips(char gameboard[4][4]){
  for(int i = 0; i < 3 ; i ++) {
    askForBattleShip(gameboard);
  }
	print_gameboard(gameboard);
}

void initialize_gameboard(char gameboard[4][4]){ // Function Definition
  for(int i = 0; i < 4; i++) { //row
    for(int j = 0; j < 4; j++){ // column
      gameboard[i][j] = noship;
    }
  }
}

void print_gameboard(char gameboard[4][4]){
  for(int i = 0; i < 4; i++) { //row
    for(int j = 0; j < 4; j++){ // column
      cout << gameboard[i][j];
    }
    cout << endl;
  }
}

void startShooting(char gameboard[4][4])
 {
  for(int i = 0 ; i < 12; i++) 
      takeshot(gameboard);
      
    for(int i = 0; i < 4; i++)
	{  //row
    	for(int j = 0; j < 4; j++)
     	 cout << gameboard[i][j];
     	 cout << endl;
    }  

}

void takeshot(char gameboard[4][4]) {
  int x,y;
  cout << "Please enter shot x value" << endl;
  cin >>x;
  cout << "Please enter shot y value" << endl;
  cin >>y;

  if(gameboard[x][y] == ship) 
	{
  		gameboard[x][y]=hit;
  			cout<<"hit.\n";
  			
	}else if (gameboard[x][y]==noship)
	
		{
			gameboard[x][y]=miss;
				cout<<"miss.\n";
		}
	 
		
    cout << endl;
}
