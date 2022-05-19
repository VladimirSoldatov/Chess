#include<iostream>
using namespace std;

enum TypeFigure {
	Peshka = 1, Ladiya = 2, Kon = 3, Slon = 4, Queen = 5, King = 6
};
enum DeskCell { A = 1, B = 2, C = 3, D = 4, E = 5, F = 6, G = 7, H = 8 };
enum FigireColor {White=0, Black=1};

class Desk
{
	int size;
	int DeskTable[8][8];
public:
	Desk()
	{
		size = 8;
		for (int i = 0; i < size; i++) 
		{
			for (int j = 0; j < size; j++)
			{
				DeskTable[i][j] = 0;
			}
		}
	}
	~Desk() {
		cout << "End Game" << endl;
	}
};
 class Figure 
 {
	 char* name = 0;
	 char* color = 0;
	 int colorCode = 0;
 public:

	 virtual void setColor(const char* your_color, int your_code) = 0;
	 virtual void setName(const char* your_name) = 0;
	 virtual char * GetColor() = 0;
};
 class KonClass :Figure {
	 char* name;
	 char* color;
	 int colorCode;

 public:
	 KonClass(const char* your_name, const char* your_color, int yourColor)
	 {
		 name = new char[50];
		 color = new char[50];
		 strcpy_s(name, sizeof(your_name), your_name);
		 strcpy_s(color, sizeof(your_color), your_color);
		 colorCode = Black;
	 }
	 ~KonClass()
	 {
		 delete name;
		 delete color;
	 }
	 void setName(const char * your_name) 
	 {
		 strcpy_s(color, sizeof(your_name), your_name);
	 }
	 void setColor(const char* your_color, int your_code)
	 {
		 strcpy_s(color, sizeof(your_color), your_color);
		 colorCode = your_code;
	 }
	 char* GetColor()
	 {
		 return color;
	 }
 };
 class AbstractFabric {
 public:
	 virtual void createFigures() = 0;
 };
 class FabricBlackFigures {
 public:
	 void createFigures() 
	 {
		 KonClass blackLeftKon("Left Black Kon", "Black", 1);
		 KonClass blackRightKon("Right Black Kon", "Black", 1);
		 cout << "Black Kons created";
		

	}	  
 };
 class Game
 {
	 char* name;

 public:
	 Game() {
		 name = new char[50];
		 strcpy_s(name, sizeof("First"), "First");
	 }
	 ~Game() {
		 cout << "\nYour name " << name;
		 delete name;
	 }
	 void createFabric()
	 {
		 FabricBlackFigures blackFabric;
		 blackFabric.createFigures();
	 }
 };
int main() {
	Game game;
	return 0;
}
