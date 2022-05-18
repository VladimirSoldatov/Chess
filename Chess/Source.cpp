#include<iostream>
using namespace std;

enum TypeFigure {
	Peshka = 1, Ladiya = 2, Kon = 3, Slon = 4, Queen = 5, King = 6
};
enum DeskCell { A = 1, B = 2, C = 3, D = 4, E = 5, F = 6, G = 7, H = 8 };
class Game
{
	char* name;
public:
	Game() {
		cout << "Say your name\n";
		name = new char[50];
		cin >> name;
		cout << name << endl;;
	}
	~Game() {
		cout << "\nYour name " << name ;
		delete name;
	}
};
class Desk
{
	int DeskTable[8][8];
public:

	Desk();
};
 class Figure 
 {
	 char* name = 0;
	 char* color = 0;
 public:

	
	 virtual char * GetColor() = 0;
};
 class KonClass :Figure {
	 char* name;
	 char* color;
 public:
		KonClass(const char* your_name, const char* your_color) 
		{
			name = new char[50];
			color = new char [50];
			strcpy_s(name, sizeof(your_name), your_name);
			strcpy_s(color, sizeof(your_color), your_color);
		}
		~KonClass() 
		{
		delete name;
		delete color;
		}
 public:
		char* GetColor() 
		{
			return color;
		}
 };
int main() {
	Game game;
	return 0;
}
