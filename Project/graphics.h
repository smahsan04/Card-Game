#include<iostream>
#include <windows.h>

using namespace std;

void gotoxy(short x,short y)
{
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void LegendaryCard(int attack, int xp,int row, int col) {
	gotoxy(col,row++);
    cout << "***************";
    gotoxy(col,row++);
    cout << "*  Legendary  *";
    gotoxy(col,row++);
    cout << "*     .---.   *";
    gotoxy(col,row++);
    cout << "*    |o_o  |  *";
    gotoxy(col,row++);
    cout << "*    |:_/  |  *";
    gotoxy(col,row++);
    cout << "*   //   \\ \\\\ *";
    gotoxy(col,row++);
    cout << "*  (|     | ) *";
    gotoxy(col,row++);
    cout <<"* /'\\_   _/`/\ *";
    gotoxy(col,row++);
    cout << "* \\__)=(__//  *";
    gotoxy(col,row++);
    cout << "* Attack: " << attack << " *";
    gotoxy(col,row++);
    cout << "*   XP:   " << xp << " *";
    gotoxy(col,row++);
    cout << "***************" << endl;
    
}

void EpicCard(int attack, int xp,int row,int col) {
	gotoxy(col,row++);
    cout << "***************";
    gotoxy(col,row++);
    cout << "*    Epic     *";
    gotoxy(col,row++);
    cout << "*             *";
    gotoxy(col,row++);
    cout << "*   (\\__/)    *";
    gotoxy(col,row++);
    cout << "*   (o^_^o)   *" ;
    gotoxy(col,row++);
    cout << "*  /(   )\\    *" ;
    gotoxy(col,row++);
    cout << "*  ^^  ^^     *" ;
    gotoxy(col,row++);
    cout << "*             *";
    gotoxy(col,row++); 
    cout<<"*             *";
    gotoxy(col,row++);
    cout << "* Attack:" << attack << "  *" ;
    gotoxy(col,row++);
    cout << "*  XP:  " << xp << "   *" ;
   	gotoxy(col,row++); 
    cout << "***************" << endl;
}

void RareCard(int attack, int xp,int row,int col) {
	gotoxy(col,row++);
    cout << "***************" << endl;
    gotoxy(col,row++);
    cout << "*     Rare    *" << endl;
    gotoxy(col,row++);
    cout << "*             *" << endl;
    gotoxy(col,row++);
    cout << "*   /\\   /\\   *" << endl;
    gotoxy(col,row++);
    cout << "*  / o\\_/o \\  *" << endl;
    gotoxy(col,row++);
    cout << "* (    ^    ) *" << endl;
    gotoxy(col,row++);
    cout << "*  \\  ===  /  *" << endl;
    gotoxy(col,row++);
    cout << "*   |     |   *" << endl;
    gotoxy(col,row++);
    cout << "*             *" << endl;
    gotoxy(col,row++);
    cout << "* Attack: " << attack << " *" << endl;
    gotoxy(col,row++);
    cout << "*   XP: " << xp << "   *" << endl;
    gotoxy(col,row++);
    cout << "***************" << endl;
}

void NormalCard(int attack, int xp,int row,int col) {
	gotoxy(col,row++);
    cout << "***************" << endl;
    gotoxy(col,row++);
    cout << "*    Normal   *" << endl;
    gotoxy(col,row++);
    cout << "*             *" << endl;
    gotoxy(col,row++);
    cout << "*   \\\\___//   *" << endl;
    gotoxy(col,row++);
    cout << "*   | o o |   *" << endl;
    gotoxy(col,row++);
    cout << "*   |  ^  |   *" << endl;
    gotoxy(col,row++);
    cout << "*   | \\_/ |   *" << endl;
    gotoxy(col,row++);
    cout << "*   \\___/     *" << endl;
    gotoxy(col,row++);
    cout << "*             *" << endl;
    gotoxy(col,row++);
    cout << "* Attack:" << attack << "  *" << endl;
    gotoxy(col,row++);
    cout << "*   XP: " << xp << "   *" << endl;
    gotoxy(col,row++);
    cout << "***************" << endl;
}

void showcards(int defense1,int defense2,int attack1,int attack2,int extra1,int extra2)
{
	if(attack1 == 200)  //Checking Attack Power Of Player 1 card
	{
		
		if(attack2 == 200)
		{
			system("cls");
			NormalCard(attack1 + extra1,defense1,3,10);
			
			gotoxy(37,8);			//gotoxy(col,row);
			cout<<"VS";
			
			NormalCard(attack2 + extra2,defense2,3,50);
		}
		
		
		else if(attack2 == 300)
		{
			system("cls");
			NormalCard(attack1 + extra1,defense1,3,10);
			
			gotoxy(37,8);			//gotoxy(col,row);
			cout<<"VS";
			
			RareCard(attack2 + extra2,defense2,3,50);
		}
		
		
		else if(attack2 == 400)
		{
			system("cls");
			NormalCard(attack1 + extra1,defense1,3,10);
			
			gotoxy(37,8);			//gotoxy(col,row);
			cout<<"VS";
			
			EpicCard(attack2 + extra2,defense2,3,50);
		}
		
		
		else if(attack2 == 500)
		{
			system("cls");
			NormalCard(attack1 + extra1,defense1,3,10);
			
			gotoxy(37,8);			//gotoxy(col,row);
			cout<<"VS";
			
			LegendaryCard(attack2 + extra2,defense2,3,50);
		}
	}
	
	//****************************************************************************
	
	else if(attack1 == 300)
	{
		
		if(attack2 == 200)
		{
			system("cls");
			RareCard(attack1 + extra1,defense1,3,10);
			
			gotoxy(37,8);			//gotoxy(col,row);
			cout<<"VS";
			
			NormalCard(attack2 + extra2,defense2,3,50);
		}
		
		
		else if(attack2 == 300)
		{
			system("cls");
			RareCard(attack1 + extra1,defense1,3,10);
			gotoxy(37,8);			//gotoxy(col,row);
			cout<<"VS";
			RareCard(attack2 + extra2,defense2,3,50);
		}
		
		
		else if(attack2 == 400)
		{
			system("cls");
			RareCard(attack1 + extra1,defense1,3,10);
			
			gotoxy(37,8);			//gotoxy(col,row);
			cout<<"VS";
			
			EpicCard(attack2 + extra2,defense2,3,50);
		}
		
		
		else if(attack2 == 500)
		{
			system("cls");
			RareCard(attack1 + extra1,defense1,3,10);
			
			gotoxy(37,8);			//gotoxy(col,row);
			cout<<"VS";
			
			LegendaryCard(attack2 + extra2,defense2,3,50);
		}
	}
	
	//****************************************************************************
	
	else if(attack1 == 400)
	{
		
		
		if(attack2 == 200)
		{
			system("cls");
			EpicCard(attack1 + extra1,defense1,3,10);
			
			gotoxy(37,8);			//gotoxy(col,row);
			cout<<"VS";
			
			NormalCard(attack2 + extra2,defense2,3,50);
		}
		
		
		else if(attack2 == 300)
		{
			system("cls");
			EpicCard(attack1 + extra1,defense1,3,10);
			
			gotoxy(37,8);			//gotoxy(col,row);
			cout<<"VS";
			
			RareCard(attack2 + extra2,defense2,3,50);
		}
		
		
		else if(attack2 == 400)
		{
			system("cls");
			EpicCard(attack1 + extra1,defense1,3,10);
			
			gotoxy(37,8);			//gotoxy(col,row);
			cout<<"VS";
			
			EpicCard(attack2 + extra2,defense2,3,50);
		}
		
		
		else if(attack2 == 500)
		{
			system("cls");
			EpicCard(attack1 + extra1,defense1,3,10);
			
			gotoxy(37,8);			//gotoxy(col,row);
			cout<<"VS";
			
			LegendaryCard(attack2 + extra2,defense2,3,50);
		}
		
	}
	
	//****************************************************************************
	
	else if(attack1 == 500)
	{
		if(attack2 == 200)
		{
			system("cls");
			LegendaryCard(attack1 + extra1,defense1,3,10);
			
			gotoxy(37,8);			//gotoxy(col,row);
			cout<<"VS";
			
			NormalCard(attack2 + extra2,defense2,3,50);
		}
		
		
		else if(attack2 == 300)
		{
			system("cls");
			LegendaryCard(attack1 + extra1,defense1,3,10);
			
			gotoxy(37,8);			//gotoxy(col,row);
			cout<<"VS";
			
			RareCard(attack2 + extra2,defense2,3,50);
		}
		
		
		else if(attack2 == 400)
		{
			system("cls");
			LegendaryCard(attack1 + extra1,defense1,3,10);
			
			gotoxy(37,8);			//gotoxy(col,row);
			cout<<"VS";
			
			EpicCard(attack2 + extra2,defense2,3,50);
		}
		
		
		else if(attack2 == 500)
		{
			system("cls");
			LegendaryCard(attack1 + extra1,defense1,3,10);
			
			gotoxy(37,8);			//gotoxy(col,row);
			cout<<"VS";
			
			LegendaryCard(attack2 + extra2,defense2,3,50);
		}
	}
	//****************************************************************************
}


void ShowPlayerCards(int defense,int attack,int row,int col,int extra)
{
	if(attack == 200)
			NormalCard(attack + extra,defense,row,col++);
	
	else if(attack == 300)
		RareCard(attack + extra,defense,row,col++);
	
	else if(attack == 400)
		EpicCard(attack + extra,defense,row,col++);
	
	else if(attack == 500)
		LegendaryCard(attack + extra,defense,row,col++);
}


void result(string username);
bool display(string username);
int show_potion(string username);
int check_username(string username);
void updateStatus(int LINE,string newdata);