#include<iostream>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<ctime>
#include<windows.h>
#include<conio.h>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

#include "graphics.h"
#include "user.h"
#include "shop.h"
#include "cards.h"
#include "functions.h"

int main()
{
	int player_index,count = 0;
	srand(time(NULL));
    Deck C;
	vector <User_Details> user;
	Shop S;
	string username,password;
	//Main Menu 
	while(1)
	{
		int option;
				
		system("cls");
		cout<<"\t\t\t\t\tCARD GAME\n\n1-Create Account\t2-Start A Match\t 3-Enter Shop\t4-See Account Details\t5-Exit\n";
		cout<<"\nChoose An Option [1-5] : ";
		cin>>option;
		system("cls");
		switch(option)
		{
			case 1:
				{
					cout<<"\nEnter Username : ";
					getline(cin>>ws,username);
					cout<<"\nEnter Password : ";
					getline(cin>>ws,password);
					
					user.push_back(User_Details());
					user[count].setdata(username,password);
					count++;
					cout<<"\nAccount Created !!";
					cout<<"\n\nPress Any Key To Continue : ";
					getch();
					break;
				}
			case 2:
				{
					string username1,username2;
					int option,line1,line2,winner;
						cout<<"\n\n\t\t\t\tPlayer vs Player (PvP mode)";
					cout<<"\n\n\nPlayer 1 ";
					cout<<"\n\nEnter Your Username : ";
					getline(cin>>ws,username1);
					
					line1 = check_username(username1);
					if(line1 > 0)
						cout<<"\nAccount Detected! \n";
					else
					{
						cout<<"\nPlayer 1 Account Not Found !! ";
						cout<<"\n\nPress Any Key To Continue : ";
						getch();
						break;
					}
					
					cout<<"\nPlayer 2 ";
					cout<<"\nEnter Your Username : ";
					getline(cin>>ws,username2);
					
					line2 = check_username(username2);
					if(line2 > 0)
						cout<<"\nAccount Detected! \n";
					else
					{
						cout<<"\nPlayer 2 Account Not Found !! ";
						cout<<"\n\nPress Any Key To Continue : ";
						getch();
						break;
					}
					C.fill_deck();
					C.shuffle();
					C.deal();
					winner = Play_game(C,username1,username2,line1,line2);
					if(winner == 1)
					{
						user[0].reward(line1);
						user[0].setwins(line1);
						//result(username1);
					}
					else if(winner == 2)
					{
						user[0].reward(line2);
						user[0].setwins(line2);
						//result(username2);
					}
					cout<<"\n\nPress Any Key To Continue : ";
					getch();
					break;						
				}
			case 3:
				{
					cout<<"\nEnter Username : ";
					getline(cin>>ws,username);
					if(check_username(username) == 0){
						cout<<"\nAccount Not Found !!";
						cout<<"\n\nPress Any Key To Continue : ";
						getch();
						break;	
					}
					
					S.display(username);
					break;
				}
		
			case 4:
				{
					string username;
					cout<<"\nEnter Username : ";
					getline(cin>>ws,username);
					display(username);
					cout<<"\n\nPress Any Key To Continue : ";
					getch();
					
					break;
				}
				case 5:{
					return 0;
					break;
				}
			default:
				{
					cout<<"\nInvalid Option !! ";
					cout<<"\n\nPress Any Key To Continue : ";
					getch();
				}
		}
	}
	return (0);
}





void updateStatus(int LINE,string newdata)
{
	string d;
	int val;
	int line = 1,num;
	char oldname[] = "Account.txt";
	char newname[] = "temp.txt";
	
	fstream file;
	file.open("Account.txt",ios :: in);
	fstream temp;
	temp.open("temp.txt",ios :: app);
	
	vector <string> data;
	while(!file.eof())
	{
		if(newdata == "")
		{
			if(line == LINE)
			{
				file>>d;
				val = stoi(d);
				val++;
				d = to_string(val);
				data.push_back(d);
				line++;
			}
			else
			{
				getline(file,d);
				data.push_back(d);
				line++;
			}
		}
		
		else if(newdata == "-1")
		{
			if(line == LINE)
			{
				file>>d;
				val = stoi(d);
				val--;
				d = to_string(val);
				data.push_back(d);
				line++;
			}
			else
			{
				getline(file,d);
				data.push_back(d);
				line++;
			}
		}
		
		else
		{
			if(line == LINE)
			{
				file>>d;
				data.push_back(newdata);
				line++;
			}
			else
			{
				getline(file,d);
				data.push_back(d);
				line++;
			}
		}
	}
	
	for(int i = 0 ; i < data.size(); i++)
	{
		if(i == LINE)
		{
			temp<<data[i];
			continue;
		}
		temp<<data[i]<<endl;
	}
	file.close();
	temp.close();
	remove("Account.txt");
	if(rename("temp.txt","Account.txt") != 0)
	{
		cout<<"\nError Renaming File !! ";
	}
	else
	{
		cout<<"Updated Status!!";
		cout<<"\nPress Any Key To Continue !!";
		getch();
	}
}