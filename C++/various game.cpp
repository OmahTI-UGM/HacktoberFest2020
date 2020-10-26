#include<iostream>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<conio.h>
#include<time.h>
#include<windows.h>

using namespace std;

int choice;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
clock_t start;

int chooseInputCTW();
int chooseInputMS();
int chooseInputTTT();

//GLOBAL VARIABLE CUT THE WIRE
int wire = 0, totalWire = 0, color, wireColor[6];
int cut, answer, choose;
int tmpblue = 0, tmpred = 0, tmpyellow = 0, tmpwhite = 0, tmpblack = 0;
int lengthAlphanum, lengthNum;
int index, randnum;
char alphanum[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 
					'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
					'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
					'U', 'V', 'W', 'X', 'Y', 'Z'};
char num[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
string keygen = "";


//GLOBAL VARIABLE MINESWEEPER
char board[50][50];
char realBoard[50][50];
bool lose = false;
int flag = 0;
int maxrow, maxcol, maxmines;
int level;

//GLOBAL VARIABLE TIC TAC TOE
char player = 'X';
int turn = 0;
bool win = false;
char tile[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row, col;
char move;

//GAME CUT THE WIRE
void instructionsCutTheWire() {
	cout << "========================CUT THE WIRE=============================" << endl << endl;
	cout << "Cara Bermain :" << endl;
	cout << "o Permainan ini dimainkan 2 orang, satu orang bermain game, orang" << endl;
	cout << "  lain membaca buku petunjuk untuk mengarahkan pemain" << endl;
	cout << "o Orang yang bermain game tidak boleh membaca buku petunjuk, begitu" << endl;
	cout << "  juga pembaca petunjuk tidak boleh melihat gamenya" << endl;
	cout << "o Bom mempunyai 3-6 kabel di dalamnya, hanya SATU kabel yang harus" << endl;
	cout << "  dipotong agar bom dapat dijinakkan" << endl;
	cout << "o Kabel diurutkan dari yang paling atas" << endl << endl; 
	cout << "Tekan ENTER untuk mulai" << endl << endl;
	getch();
	system("cls");
}

void timer (int limit) {
	int duration = 0, temp = 0;
	while(!kbhit()) {
		duration = (clock() - start) / CLOCKS_PER_SEC;
		if (duration > temp) {
			SetConsoleCursorPosition(h, {35, 2});
			if (limit - duration < 10) {
				cout << limit - duration << " ";
			}
			else {
				cout << limit - duration;
			}
			SetConsoleCursorPosition(h, {0, 14});
		}
		temp = duration;
		
		if (duration > limit) {
			system("cls");
			cout << "========================CUT THE WIRE=============================" << endl << endl;
			cout << "                         WAKTU HABIS                             " << endl;
			getch();
			exit(0);
		}
	}
}

void randomKeygen() {
	srand(time(0));
	lengthAlphanum = sizeof(alphanum) - 1;
	lengthNum = sizeof(num) - 1;
	
	for (int i = 0; i < 5; i++) {
		index = rand() % lengthAlphanum;
		keygen += alphanum[index];
	}
	randnum = rand() % lengthNum;
	keygen += num[randnum];

	cout << "Serial Number : " << keygen << endl;
}

void changeWireColor() {
	switch (color) {
		case 1 :
			cout << "[]======red======[]" << endl;
			tmpred++;
			break;
		case 2 :
			cout << "[]=====blue======[]" << endl;
			tmpblue++;
			break;		
		case 3 :
			cout << "[]====yellow=====[]" << endl;
			tmpyellow++;
			break;
		case 4 :
			cout << "[]=====white=====[]" << endl;
			tmpwhite++;
			break;
		case 5 :
			cout << "[]=====black=====[]" << endl;
			tmpblack++;
			break;	
	}	
}

void makeWire() {
	int i = 0;
	srand(time(NULL));
	totalWire = rand() % 4 + 3;
	
	while (wire < totalWire) {
		color = rand() % 5 + 1;
		wireColor[i] = color;
		changeWireColor();
		wire++;
		i++;
	}
}

void changeInput(int choose) {
	switch (choose) {
		case 1 :
			answer = wireColor[0];
			break;
		case 2 :
			answer = wireColor[1];
			break;
		case 3 :
			answer = wireColor[2];
			break;
		case 4 :
			answer = wireColor[3];
			break;
		case 5 :
			answer = wireColor[4];
			break;
		case 6 :
			answer = wireColor[5];
			break;
	}
}

void wireChecker() {
	if (totalWire == 3) {
		if (tmpred == 0) {
			cut = wireColor[1];
		}
		else if (tmpblue > 1) {
			cut = wireColor[0];
		}
		else if (wireColor[2] == 4) {
			cut = wireColor[2];
		}
		else {
			cut = wireColor[2];
		}
	}
	else if (totalWire == 4) {
		if (tmpred > 1 and ((int)keygen[5] % 2 != 0)) {
			cut = wireColor[2];
		}
		else if (wireColor[3] == 3 and tmpred == 0) {
			cut = wireColor[0];
		}
		else if (tmpblue == 1) {
			cut = wireColor[0];
		}
		else if (tmpyellow > 1) {
			cut = wireColor[3];
		}
		else {
			cut = wireColor[1];
		}
	}
	else if (totalWire == 5) {
		if (wireColor[4] == 5 and ((int)keygen[5] % 2 == 0)) {
			cut = wireColor[3];
		}
		else if (tmpred == 1 and tmpyellow > 1) {
			cut = wireColor[0];
		}
		else if (tmpblack == 0) {
			cut = wireColor[1];
		}
		else {
			cut = wireColor[0];
		}
	}
	else if (totalWire == 6) {
		if (tmpyellow == 0 and ((int)keygen[5] % 2 != 0)) {
			cut = wireColor[2];
		}
		else if (tmpyellow == 1 and tmpwhite > 1) {
			cut = wireColor[3];
		}
		else if (tmpred == 0) {
			cut = wireColor[5];
		}
		else {
			cut = wireColor[3];
		}
	}
}

void playCutTheWire() {
	instructionsCutTheWire();	
	cout << "========================CUT THE WIRE=============================" << endl << endl;
	cout << "                      Sisa Waktu : " << endl;
	randomKeygen();
	makeWire();
	start = clock();
	wireChecker();
	
	SetConsoleCursorPosition(h, {0, 11});
	cout << "Pilih input :" << endl;
	SetConsoleCursorPosition(h, {0, 12});
	cout << "1. Potong kabel" << endl;
	SetConsoleCursorPosition(h, {0, 13});
	cout << "2. Kembali ke menu utama" << endl;
	SetConsoleCursorPosition(h, {35, 2});
	cout << 30;		
	SetConsoleCursorPosition(h, {0, 14});
	timer(30);
	
	chooseInputCTW();
	
	if (answer == cut) {
		cout << "Berhasil!!!" << endl;
	}
	else {
		cout << "Gagal!!!" << endl;
	}
}

//GAME TIC TAC TOE
void instructionsTicTacToe() {
	cout << "===========================TIC TAC TOE===========================" << endl << endl;
	cout << "Cara Bermain :" << endl;
	cout << "o Permainan akan dimulai dari pemain pertama dengan tanda 'X'" << endl;
	cout << "  dan akan berganti giliran ke pemain 'O'" << endl;
	cout << "o Setiap giliran, pemain diharuskan memilih kotak (baris, kolom)" << endl;
	cout << "  untuk menandai kotak tersebut" << endl;
	cout << "o Pemain yang terlebih dahulu menandai 3 kotak dalam satu garis" << endl;
	cout << "  baik itu horizontal, vertikal, maupun diagonal, dianggap menang" << endl << endl;
	cout << "Tekan ENTER untuk main";
	getch();
	system("cls");
}

void makeBoard() {
	cout << "===========================TIC TAC TOE===========================" << endl << endl;
	cout << "\t\t         0  " << "   1  " << "   2  " << endl;
	cout << "\t\t       _________________" << endl;
	cout << "\t\t      |     |" << "     " << "|     |" << endl;
	cout << "\t\t   0  |  " << tile[0][0] << "  |" << "  " << tile[0][1] << "  " << "|  " << tile[0][2] << "  |" << endl;
	cout << "\t\t      |_____|" << "_____" << "|_____|" << endl;
	cout << "\t\t      |     |" << "     " << "|     |" << endl;
	cout << "\t\t   1  |  " << tile[1][0] << "  |" << "  " << tile[1][1] << "  " << "|  " << tile[1][2] << "  |" << endl;
	cout << "\t\t      |_____|" << "_____" << "|_____|" << endl;
	cout << "\t\t      |     |" << "     " << "|     |" << endl;
	cout << "\t\t   2  |  " << tile[2][0] << "  |" << "  " << tile[2][1] << "  " << "|  " << tile[2][2] << "  |" << endl;
	cout << "\t\t      |_____|" << "_____" << "|_____|" << endl << endl;
}

void checkMove(char move) {
	switch (move) {
		case '1' :
			row = 0;
			col = 0;
			break;
		case '2' :
			row = 0;
			col = 1;
			break;
		case '3' :
			row = 0;
			col = 2;
			break;
		case '4' :
			row = 1;
			col = 0;
			break;
		case '5' :
			row = 1;
			col = 1;
			break;
		case '6' :
			row = 1;
			col = 2;
			break;
		case '7' :
			row = 2;
			col = 0;
			break;
		case '8' :
			row = 2;
			col = 1;
			break;
		case '9' :
			row = 2;
			col = 2;
			break;
		default :
			cin >> move;
			checkMove(move);
	}
}

void makeMove() {
	
	if (player == 'X') {
		cout << "Pemain 1 [X]" << endl;
		chooseInputTTT();

		while (tile[row][col] == 'X' || tile[row][col] == 'O' || !(int(move) > 48 && int(move) <= 57)) {
			cout << "Kotak sudah terisi, pilih kotak lain : ";
			cin >> move;
			checkMove(move);
		}
		
		if (tile[row][col] != 'X' and tile[row][col] != 'O') {
			tile[row][col] = 'X';
		}
		
		player = 'O';
		turn++;
	} else {
		cout << "Pemain 2 [O]" << endl;
		chooseInputTTT();
		
		while (tile[row][col] == 'X' || tile[row][col] == 'O' || !(int(move) > 48 && int(move) <= 57)) {
			cout << "Kotak sudah terisi, pilih kotak lain : ";
			cin >> move;
			checkMove(move);
		}
		
		if (tile[row][col] != 'X' and tile[row][col] != 'O') {
			tile[row][col] = 'O';
		}
		
		player = 'X';
		turn++;
	}
}

void winCheckerTicTacToe() {
	if (tile[0][0] == tile[1][1] && tile[1][1] == tile[2][2]) {
		win = true;
	}
	
	if (tile[0][2] == tile[1][1] && tile[1][1] == tile[2][0]) {
		win = true;
	}
	
	for (int i = 0; i < 3; i++){
		if (tile[i][0] == tile[i][1] && tile[i][1] == tile[i][2]) {
			win = true;
		}
	}
	
	for (int j = 0; j < 3; j++){
		if (tile[0][j] == tile[1][j] && tile[1][j] == tile[2][j]) {
			win = true;
		}
	}
	
	if (win == true) {
		system("cls");
		makeBoard();
			if (player == 'O') {
				cout << "Pemain 1 [X] menang";
			} else {
				cout << "Pemain 2 [O] menang";
			}
	} 
	
	if (turn == 9 && win == false) {
		system("cls");
		makeBoard();
		cout << "Permainan seri";
	}
}

void playTicTacToe() {
	instructionsTicTacToe();
	while (win != true && turn != 9){
		system("cls");
		makeBoard();
		makeMove();
		winCheckerTicTacToe();
	
	}
}

//GAME MINESWEEPER
void instructionsMinesweeper() {
	cout << "===========================MINESWEEPER GAME===========================" << endl << endl;
	cout << "Cara Bermain : " << endl;
	cout << "o Inputkan angka 1, lalu inputkan baris dan kolom untuk membuka kotak" << endl;
	cout << "o Inputkan angka 2, lalu inputkan baris dan kolom untuk memberikan" << endl;
	cout << "  tanda bendera (F)" << endl;
	cout << "o Ketika kotak yang dibuka ternyata bom (X), maka game akan berakhir" << endl;
	cout << "  dan artinya kamu noob" << endl;
	cout << "o Ketika kotak yang dibuka terdapat angka, itu menunjukkan jumlah" << endl;
	cout << "  bom yang ada di sekeliling kotak tersebut" << endl;
	cout << "o Untuk menandai kotak yang diduga adalah kotak berisi bom, gunakan" << endl;
	cout << "  tanda bendera" << endl;
	cout << "o Agar menang, semua bom harus ditandai dengan bendera, jangan salah" << endl;
	cout << "  memberikan tanda bendera ke kotak yang tidak berisi bom" << endl << endl;
	cout << "Tekan ENTER untuk main";
	getch();
	system("cls");
}

void chooseLevel() {
	cout << "===========================MINESWEEPER GAME===========================" << endl << endl;
	cout << "Pilih level :" << endl;
	cout << "1. Beginner" << endl;
	cout << "2. Intermediate" << endl;
	cout << "3. Advanced" << endl;
	cin >> level;
	
	switch (level) {
		case 1 :
			maxrow = 10;
			maxcol = 10;
			maxmines = 10;
			break;
		case 2 :
			maxrow = 15;
			maxcol = 15;
			maxmines = 30;
			break;
		case 3 :
			maxrow = 25;
			maxcol = 25;
			maxmines = 100;
			break;
	}
}

void incrementTileNum (int row, int col) {
	if (row >= 0 && row < maxrow && col >= 0 && col < maxcol) {
		if (realBoard[row][col] != 'X') {
			realBoard[row][col]++;
		}
	}
}

void randomPlaceMine() {
	int mine = 0;
	srand(time(NULL));

	for (int row = 0; row < maxrow; row++) {
		for (int col = 0; col < maxcol; col++) {
			realBoard[row][col] = '0';
		}
	}

    int row = 0;
    int col = 0;
    
 	while (mine < maxmines) {
        int row = rand() % maxmines;
        int col = rand() % maxmines;
		if (realBoard[row][col] == '0') {
            realBoard[row][col] = 'X';
            incrementTileNum (row - 1, col); 
            incrementTileNum (row + 1, col);
            incrementTileNum (row, col - 1);
            incrementTileNum (row, col + 1);
            incrementTileNum (row - 1, col - 1);
            incrementTileNum (row - 1, col + 1);
            incrementTileNum (row + 1, col - 1);
            incrementTileNum (row + 1, col + 1);
            mine++;
        }
    }
}

void userBoard() {
    for (int row = 0; row < maxrow; row++) {
		for (int col = 0; col < maxcol; col++) {
			board[row][col] = char(178);
		}
	}
}

void printBoard (char array[50][50]) {
	cout << "===========================MINESWEEPER GAME===========================" << endl << endl;
    cout << "   ";
    
    for (int col = 0; col < maxcol; col++) {
		cout << setw(3) << col;
	}

    cout << endl;
    
    for (int row = 0; row < maxrow; row++) {
        cout << setw(3) << row;
        for (int col = 0; col < maxcol; col++) {
			cout << setw(3) << array[row][col];
		}
		cout << endl;
    }
}

void openMultiTile (int row, int col) {
	if (row >= 0 && row < maxrow && col >= 0 && col < maxcol) {
		if (board[row][col] == char(178) && realBoard[row][col] != 'X') {
    		board[row][col] = realBoard[row][col];

	    	if (realBoard[row][col] == '0') {
	        	openMultiTile (row, col - 1);
	        	openMultiTile (row, col + 1);
	        	openMultiTile (row - 1, col - 1);
	        	openMultiTile (row + 1, col - 1);
	        	openMultiTile (row + 1, col + 1);
	        	openMultiTile (row - 1, col + 1);
	        	openMultiTile (row - 1, col);
	        	openMultiTile (row + 1, col);
	        }
    	}
	}
}

void openSingleTile () {
	int row, col;
	
	do {
		cin >> row >> col;
	} while (row < 0 || row > maxrow-1 || col < 0 || col > maxcol-1);

	if (realBoard[row][col] == 'X' ) {
        board[row][col] = 'X';
        lose = true;

        for (int row = 0; row < maxrow; row++) {
			for (int col = 0; col < maxcol; col++) {
				if (realBoard[row][col] == 'X') {
                    board[row][col] = 'X';
            	}
			}
		}
    } else {
    	openMultiTile (row, col);	
	}
}

void flagAdderRemover () {
	int row, col;
	
	do {
		cin >> row >> col;	
	} while (row < 0 || row > maxrow-1 || col < 0 || col > maxcol-1);

	if (board[row][col] == char(178)) {
    	board[row][col] = 'F';
    	flag++;

	} else if (board[row][col] == 'F') {
    	board[row][col] = char(178);
    	flag--;
    } 
}

void winCheckerMinesweeper() {
	if (lose) {
		system("cls");
		printBoard(board);
		cout << endl << "DUARRR!1!1!1 NUB, KAMU KALAH";
	} 
	
	if (flag == maxmines){
		cout << endl << "MANTOOOL!1!1!1, JAOG OPOP, GGWP BOSQUE";
	}
}

void playMinesweeper() {
	instructionsMinesweeper();
	chooseLevel();
	userBoard();
	randomPlaceMine();
	
	while (lose != true && flag != maxmines) {
		system("cls");
		printBoard(board);
		chooseInputMS();
		winCheckerMinesweeper();
	}
}

int makeChoice (int choice) {
	switch (choice) {
		case 1 : 
			system("cls");
			playCutTheWire();
			break;
		case 2 : 
			system("cls");
			playTicTacToe();
			break;
		case 3 :
			system("cls");
			playMinesweeper();
			break;
		case 4 :
			cout << "Yah, kok keluar sih :\'(" << endl;
			exit(0);
			break;
	}
}

int main() {
	cout << "===========================MINI GAMES===========================" << endl << endl;
	cout << "Selamat bermain :D" << endl;
	cout << "Pilih game :" << endl;
	cout << "1. Cut The Wire" << endl;
	cout << "2. Tic-Tac-Toe" << endl;
	cout << "3. Minesweeper" << endl;
	cout << "4. Exit" << endl;
	
	cout << "Oleh :" << endl;
	cout << "Ahmad Husain (19/439151/PA/18974)" << endl;
	cout << "Caroline Chan(19/442467/PA/19216)" << endl;
	
	cin >> choice;
	makeChoice(choice);
	
	return 0;
}

int chooseInputMS() {
	cout << endl << "Pilih input :" << endl;
	cout << "1. Buka kotak (baris, kolom)" << endl;
	cout << "2. Tandai kotak dengan bendera (baris, kolom)" << endl;
	cout << "3. Kembali ke menu utama" << endl;
	
	int input;
   	cin >> input;
   	
    switch (input) {
    	case 1 : 
			openSingleTile();
			break;
    	case 2 : 
			flagAdderRemover(); 
			break;
		case 3 :
			system("cls");
			return main();
    	default : 
			chooseInputMS();
			break;
    }
}

int chooseInputTTT() {
	char input;
	cout << "Pilih input : " << endl;
	cout << "1. Tandai kotak" << endl;
	cout << "2. Kembali ke menu utama" << endl;
	cin >> input;
	
	switch (input) {
		case '1' :
			cin >> move;
			checkMove(move);
			break;
		case '2' :
			system("cls");
			return main();
			break;
		default :
			chooseInputTTT();
			break;	
	}
}

int chooseInputCTW() {
	int inputCTW;
	cin >> inputCTW;
	switch (inputCTW) {
		case 1 :
			cin >> choose;
			changeInput(choose);
			break;
		case 2 :
			system("cls");
			return main();
			break;
		default :
			chooseInputCTW();
			break;
	}
}
