#include <iostream>
#include <windows.h>
#include <cwchar>

#define fo(i, a, n) for (int i = a; i < (n); ++i)
using namespace std;

const int blue = 1;
const int red = 4;
const int green = 2;
const int white = 15; 

void clearScreen(int len){
	fo(i, 0, len){
		cout << "\b";
	}
	
	fo(i, 0, len){
		cout << " ";
	}
	
	fo(i, 0, len){
		cout << "\b";
	}
}

void changeColor(int color){
	HANDLE hconsole;
	hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hconsole, color);
}

void loadingScreen(){
	string closed = "_ _ _ _ _", opened = "* * * * *";
	int colors[] = {red, green, blue};
	
	int n = closed.size();
	cout << closed;
	fo(i, 0, 3){
		Sleep(2000);
		
		clearScreen(n);
		changeColor(colors[i]);
		
		cout << opened;
		
		Sleep(2000);
		
		clearScreen(n);
		changeColor(white);
		cout << closed;
	}
	
	clearScreen(n);
	changeColor(white);
}

void showText(){
	changeColor(red);
	cout << "CHUC MU";
	Sleep(1500);
	
	changeColor(green);
	cout << "NG NGAY ";
	Sleep(1500);
	
	
	changeColor(blue);
	cout << "20/10";
	Sleep(1500);
	
	changeColor(white);
}

int main() {
	cout << "\n\n\n";
	cout << "                 ";
	
	loadingScreen();
	showText();
	
	cout << "\n\n\n";
	Sleep(25000);
	return 0;
}

