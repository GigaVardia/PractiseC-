#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ctime>

// TIC TAC TOE 
using namespace std;

void Board(void); // dafis gamotana
void drawResultBoard(void); // satamasho dafis ekranze gamotanis funqcia
void FillBoardX(); // motamashe avsebs x it
void FillBoard0(); // motamashe avsebs 0 it
void FillBoardComputer0(void); // computeri avsebs 0 it 
void FillBoardComputerX(void); // computeri avsebs nulit
void checkGameOverFullBoard(void); // amowmebs morcha tu ara tamashi dafis gavsebit
void checkGameOver(void); // amowmebs morcha tu ara tamashi

char gameBoard[9]; // tamashis dafa
bool GameOver = false; // tu gaxdeba true tamashi dasruldeba

int main()
{
    char choose; // x an 0
    int count = 0; // aq inaxeba tu ramdenjer airchia motamashem x an 0
    
    srand(time(0));
    Board(); 
    
    for (int i = 0; i < 9; i++) { // dafis carieli adgilebit shevseba
    	gameBoard[i] = '_';
	}
    
    cout << "Enter x or 0:" << endl;
	
	while (true) {
		cin >> choose;
		choose = toupper(choose);
		if (choose == 'X' || choose == '0') break;
	}
	
	if (choose == 'X') {
		while (GameOver == false) {
			cout << "Enter the number: ";
			FillBoardX(); // motamashis mier archeul adgilze ismeva x
			drawResultBoard(); // xdeba dafis ekranzee gamotana
			checkGameOverFullBoard(); // amowmebs morcha tu ara tamashi
			if (GameOver == true) break; // tu tamarchi morcha mtavrdeba cikli
			FillBoardComputer0(); // computeri avsebs 0 it 
			checkGameOver(); // amowmebs morcha tu ara tamashi
			drawResultBoard(); // ise ekranze gamotana
		}
	} else if(choose == '0') {
		while (GameOver == false) {
			FillBoardComputerX(); // compiuteri avsebs x it
			drawResultBoard();
			cout << "Enter the number: ";
			FillBoard0(); // motamashis mier archeul adgilze ismeva x
			checkGameOverFullBoard(); // amowmebs morcha tu ara tamashi
			checkGameOver(); // amowmebs morcha tu ara tamashi
			if (GameOver == true) break; // tu tamarchi morcha mtavrdeba cikli
		}
	} else cout << "ERROR";
	
    cout << "Game Over!!!";
  
    return 0;
}

void Board(void) { // dafis insturqciis daxatva
	cout << "Tic Tac Toe: " << endl;
	
	for (int i = 1; i < 10; i++) {
		cout << i << " ";
		if (i % 3 == 0) cout << endl;
	}
}

void FillBoardX() { // motamashes sheyavs x
	int playerChoose;
	
	do {
		cin >> playerChoose;
	} while (gameBoard[playerChoose - 1] != '_');
	
	gameBoard[playerChoose - 1] = 'X';
}

void FillBoard0() { // motamashes sheyavs 0
	int playerChoose;
	
	do {
		cin >> playerChoose;
	} while (gameBoard[playerChoose - 1] != '_');
	
	gameBoard[playerChoose - 1] = '0';
}

void drawResultBoard(void) { // dafis gamotana ekranze
	for (int i = 0; i < 9; i++) { 
    	cout << gameBoard[i] << " ";
		if (((i + 1) % 3) == 0) cout << endl;
	}
	cout << endl;
}

void FillBoardComputer0(void) { // compiuters sheyavs 0
	int computerChoose;
	do {
		computerChoose = rand() % 9;
	} while (gameBoard[computerChoose] != '_');

	gameBoard[computerChoose] = '0';
}

void checkGameOverFullBoard(void) { // shemowmeba savsea tu ara dafa
	int ctn = 0;
	for (int i = 0; i < 9; i++) {
		if (gameBoard[i] != '_') ctn++;
	}
	if (ctn == 9) GameOver = true;
}

void checkGameOver(void) { // shemowmeba tamashi dasrulda tu ara
	if ((gameBoard[0] == gameBoard[1]) && (gameBoard[0] == gameBoard[2]) && (gameBoard[1] == gameBoard[2])) { // pirveli striqoni
		if (gameBoard[0] != '_') GameOver = true;
	}
	
	if ((gameBoard[3] == gameBoard[4]) && (gameBoard[3] == gameBoard[5]) && (gameBoard[4] == gameBoard[5])) { // meore striqoni
		if (gameBoard[3] != '_') GameOver = true;
	}
	
	if ((gameBoard[6] == gameBoard[7]) && (gameBoard[6] == gameBoard[8]) && (gameBoard[7] == gameBoard[8])) { // mesame striqoni
		if (gameBoard[6] != '_') GameOver = true;
	}
	
	
	if ((gameBoard[0] == gameBoard[3]) && (gameBoard[0] == gameBoard[6]) && (gameBoard[0] == gameBoard[6])) { // pirveli sveti
		if (gameBoard[0] != '_') GameOver = true;
	}
	
	if ((gameBoard[1] == gameBoard[4]) && (gameBoard[1] == gameBoard[7]) && (gameBoard[4] == gameBoard[7])) { // meore sveti
		if (gameBoard[1] != '_') GameOver = true;
	}
	
	if ((gameBoard[2] == gameBoard[5]) && (gameBoard[2] == gameBoard[8]) && (gameBoard[5] == gameBoard[8])) { // mesame sveti
		if (gameBoard[2] != '_') GameOver = true;
	}
	
	if ((gameBoard[0] == gameBoard[4]) && (gameBoard[0] == gameBoard[8]) && (gameBoard[4] == gameBoard[8])) { // mtavari diagonali
		if (gameBoard[0] != '_') GameOver = true;
	}
	
	if ((gameBoard[2] == gameBoard[4]) && (gameBoard[2] == gameBoard[6]) && (gameBoard[4] == gameBoard[6])) { // aramtavari diagonali
		if (gameBoard[2] != '_') GameOver = true;
	}
}

void FillBoardComputerX(void) { // compiuteri avsebs x it
	int computerChoose;
	do {
		computerChoose = rand() % 9;
	} while (gameBoard[computerChoose] != '_');

	gameBoard[computerChoose] = 'X';
}


