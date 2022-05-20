#include<iostream>
#define _WIN32_WINNT 0x0500

#include <windows.h>

using namespace std;

enum TypeFigure {
	Peshka = 1, Ladiya = 2, Kon = 3, Slon = 4, Queen = 5, King = 6
};
enum DeskCell { A = 1, B = 2, C = 3, D = 4, E = 5, F = 6, G = 7, H = 8 };
enum FigireColor {White=0, Black=1};

class Desk
{
	static int count;
	int size;
	static Desk* p_instance;
	int DeskTable[8][8];
	
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
	Desk(const Desk&);
	Desk& operator=(Desk&);
	


public:
	static Desk * GetInstatces() {
		if (!p_instance) {
			p_instance = new Desk();
			cout << "Create Desk" << endl;
		}
		else {
			cout << "Use old instances";
		}
		return p_instance;

	}
	void get_values() {
		cout << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << DeskTable[i][j] <<"\t";
			}
			cout << endl<<endl << endl << endl;
		}
	}
	void set_monitor() {
		HWND hWindowConsole = GetConsoleWindow();
		RECT r;
		GetWindowRect(hWindowConsole, &r); 
		MoveWindow(hWindowConsole, r.left, r.top, 800, 600, TRUE);
	}
	~Desk() {
		cout << "End Game" << endl;
	}
};
Desk* Desk::p_instance = NULL;
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
		 name = new char[100];
		 color = new char[50];
		 strcpy_s(name, sizeof(your_name)*2, your_name);
		 strcpy_s(color, sizeof(your_color), your_color);
		 colorCode = Black;
		 cout << name << " created" <<endl;
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
	
		

	}
	 void creatDesk() {
		 Desk::GetInstatces();
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
		 cout << "Your name " << name << endl;
		 delete name;
	 }
	 void createFabric()
	 {
		 FabricBlackFigures blackFabric;
		 blackFabric.createFigures();
	 }
	 void create_desk() {
		 Desk * my_desk = Desk::GetInstatces();
	 }
 };
int main() {
	Game game;
	game.createFabric();
	game.create_desk();
	Desk* my_desk = Desk::GetInstatces();
	my_desk->get_values();
	my_desk->set_monitor();

	return 0;
}
