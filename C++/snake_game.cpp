#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
bool gameover;
const int width = 25, height = 20;
int x, y, tx, ty, score;
enum Arah {Stop=0, Kiri, Kanan, Atas, Bawah};
Arah dir;
int tailX[500], tailY[500], tail;


void Start(){
	gameover = false;
	dir = Stop;
	x = width/2; y = height/2;
	tx = rand() % width;
	ty = rand() % height;
	score = 0;
}

void Map(){
	system("cls");
	// Dinding bag. atas
	for(int i=0; i < width+2; i++)
		cout << "-";
		cout << endl;
	
	// Dinding bag. Kanan & Kiri
	for(int i=0; i < height; i++){
		for(int j=0; j<width; j++){
		if(j==0)
			cout << "|";
		if(i==y && j==x)
			cout << "O";
		else if(i==ty && j==tx)
			cout << "@";
		else{
			bool print = false;
			for (int k = 0; k < tail; k++){
				if (tailX[k] == j && tailY[k] == i){
					cout << "o";
					print = true;
				}
			}
			if (!print)
				cout << " ";
			}
		
		if(j==width-1)
			cout << "|";
		}
	cout << endl;
	}
	
	// Dinding bag.bawah
	for(int i=0; i<width+2; i++)
		cout << "-";
		cout << endl;
		
	cout << "Score : " << score << endl;
}

void Input(){
	if (_kbhit()){
		switch (_getch()){
		case 'w':
			dir = Atas;
			break;
		case 'a':
			dir = Kiri;
			break;
		case 's':
			dir = Bawah;
			break;
		case 'd':
			dir = Kanan;
			break;
		case 'e':
			gameover = true;
			break;
		}
	}
}

void Progress1(){
	int backX = tailX[0];
	int backY = tailY[0];
	int tempX, tempY;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < tail; i++){
		tempX = tailX[i];
		tempY = tailY[i];
		tailX[i] = backX;
		tailY[i] = backY;
		backX = tempX;
		backY = tempY;
	}
	
	switch(dir){
	case Atas:
		y--;
		break;
	case Kiri:
		x--;
		break;
	case Bawah:
		y++;
		break;
	case Kanan:
		x++;
		break;
	default:
		break;
	}
	
	if (x >= width){
		x=0;
	}else if(x < 0){
		x = width-1;
	}
	
	if (y >= height){
		y=0;
	}else if(y < 0){
		y=height-1;
	}
		
	for(int i=0; i<tail; i++)
		if(tailX[i] == x && tailY[i] == y)
			gameover = true;
	
	if (x == tx && y == ty){
		score += 10;
		tx = rand() % width;
		ty = rand() % height;
		tail++;
	}
}

void Progress2(){
	int backX = tailX[0];
	int backY = tailY[0];
	int tempX, tempY;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < tail; i++){
		tempX = tailX[i];
		tempY = tailY[i];
		tailX[i] = backX;
		tailY[i] = backY;
		backX = tempX;
		backY = tempY;
	}
	
	switch(dir){
	case Atas:
		y--;
		break;
	case Kiri:
		x--;
		break;
	case Bawah:
		y++;
		break;
	case Kanan:
		x++;
		break;
	default:
		break;
	}
	
	if (x > width-1 || x < 0 || y > height-1 || y < 0)
		gameover = true;
		
	for(int i=0; i<tail; i++)
		if(tailX[i] == x && tailY[i] == y)
			gameover = true;
	
	if (x == tx && y == ty){
		score += 10;
		tx = rand() % width;
		ty = rand() % height;
		tail++;
	}
}

int main(){

    cout<<"\tMain Menu\n";
    cout<<"\t===========\n";
    cout<<"\n\t1.Casual\n\n";
    cout<<"\t2.Blockade\n\n";
    cout<<"\tPlease Enter Option: ";

    int opt;
    cin >> opt;
	switch(opt){
		case 1:
			Start();
			while (!gameover){
				Map();
				Input();
				Progress1();
				Sleep(1);
			}			
		case 2:
			Start();
			while (!gameover){
				Map();
				Input();
				Progress2();
				Sleep(1);
			}
		default:
			cout<<"\n\n\t\tUnvalid Input!!! Please Retry";
	}
}