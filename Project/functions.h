

int Play_game(Deck &obj,string user1,string user2,int line1,int line2)
{
	cout<<"\nPress Any Key To Continue !!";
	getch();
	system("cls");
	system("cls");
	int choice,choice1,choice2,toss,i = 0,j = 0,x = 0,y = 0;
	char option;
	int attack1 = 0,attack2 = 0;
	cout<<"\n\t\t\t\t\t Game Starts!";
	cout<<"\n\n\t\t\t\t\t******TOSS******\n\n ";
	toss = rand() % 2 + 1;
	if(toss == 1){
			cout<<"\n\n\t\t\t\t Player 1 Wins The Toss!\n\n";
		cout<<"\n\nPress anyting to continue!";
		getch();
		system("cls");
	}
	else if(toss == 2){
	cout<<"\n\n\t\t\t\t  Player 2 Wins The Toss!\n\n\t\t";
	cout<<"\n\nPress anyting to continue!";
	getch();
	system("cls");
	}
	
		
	while( i != 5 || j !=5 ) 
	{
		//****************************************************************************
		
		if(toss == 1)
		{
			cout<<"\t\t\t\t   Player 1  \n\n";
			cout<<"YOUR DECK:"<<endl;
			for(int x = 0; x < obj.player1_deck.size() ; x++)
			{
				ShowPlayerCards(obj.player1_deck[x][0],obj.player1_deck[x][1],5,x*15,attack1);
				cout<<"  ";		
				
			}
			
			cout<<"\n\nEnter The Card Number You Want To Pick ("<<0<<"-"<<4-i<<") : ";
			cin>>choice1;
			cout<<"\nYour Card With Xp : "<<obj.player1_deck[choice1][0]<<endl;
			cout<<"\n\nDo You Want To Use Potion (Press Y For Yes): ";
			cin>>option;
			
			if(option == 'Y')
			{
				choice = show_potion(user1);
				if(choice == 1)
				{
					obj.player1_deck[choice1][0] += 200;
					updateStatus(line1 + 7,"-1");
				}
				else if(choice == 2)
				{
					obj.player1_deck[choice1][0] += 100;
					updateStatus(line1 + 8,"-1");
				}
			
				else if(choice == 3)
				{
					obj.player1_deck[choice1][0] += 50;
					updateStatus(line1 + 9,"-1");
				}
				else if(choice == 4)
				{
					attack1 = 200;
					updateStatus(line1 + 11,"-1");
				}
				else if(choice == 5)
				{
					attack1 = 100;
					updateStatus(line1 + 12,"-1");
				}
				else if(choice == 6)
				{
					attack1 = 50;
					updateStatus(line1 + 13,"-1");
				}
					
				
			}
			system("cls");
			cout<<"\t\t\t\tPlayer 2\n\n "<<endl;
			cout<<"YOUR DECK:"<<endl;
			
			for(int y = 0 ; y < obj.player2_deck.size() ; y++)
			{
				ShowPlayerCards(obj.player2_deck[y][0],obj.player2_deck[y][1],5,y*15,attack2);
				cout<<"  ";
			}
			
			cout<<"\n\nEnter The Card Number You Want To Pick ("<<0<<"-"<<4-j<<") : ";
			cin>>choice2;
			cout<<"\nYour Card With Xp : "<<obj.player2_deck[choice2][0]<<endl;
			cout<<"\n\nDo You Want To Use Potion (Press Y For Yes): ";
			cin>>option;
			
			if(option == 'Y')
			{
				choice = show_potion(user2);
				if(choice == 1)
				{
					obj.player2_deck[choice2][0] += 200;
					updateStatus(line2 + 7,"-1");
				}
				else if(choice == 2)
				{
					obj.player2_deck[choice2][0] += 100;
					updateStatus(line2 + 8,"-1");
				}
			
				else if(choice == 3)
				{
					obj.player2_deck[choice2][0] += 50;
					updateStatus(line2 + 9,"-1");
				}
				else if(choice == 4)
				{
					attack2 = 200;
					updateStatus(line2 + 11,"-1");
				}
				else if(choice == 5)
				{
					attack2 = 100;
					updateStatus(line2 + 12,"-1");
				}
				else if(choice == 6)
				{
					attack2 = 50;
					updateStatus(line2 + 13,"-1");
				}
			}
			system("cls");			
			
			showcards(obj.player1_deck[choice1][0],obj.player2_deck[choice2][0],obj.player1_deck[choice1][1],obj.player2_deck[choice2][1],attack1,attack2);
			obj.player2_deck[choice2][0] -= (obj.player1_deck[choice1][1] + attack1);		// Xp - Attack Power
			obj.player1_deck[choice1][0] -= (obj.player2_deck[choice2][1] + attack2);
			
			
			if(obj.player2_deck[choice2][0] <= 0)		//Erasing card if xp becomes 0 
			{
				obj.player2_deck.erase(obj.player2_deck.begin() + choice2);
				cout<<"\n"<<5-j<<" Cards Left";
				j++;
			}
			
			if(obj.player1_deck[choice1][0] <= 0)		//Erasing card if xp becomes 0 
			{
				obj.player1_deck.erase(obj.player1_deck.begin() + choice1);
				cout<<"\n"<<5-i<<" Cards Left";
				i++;
			}
		}
		
		//****************************************************************************
		else if(toss == 2)
		{
			cout<<"\t\t\t\tPlayer 2\n\n  ";
			cout<<"YOUR DECK: "<<endl;
			for(int y = 0 ; y < obj.player2_deck.size() ; y++)
			{
				ShowPlayerCards(obj.player2_deck[y][0],obj.player2_deck[y][1],5,y*15,attack2);
				cout<<"  ";
			}
			
			cout<<"\n\nEnter The Card Number You Want To Pick ("<<0<<"-"<<4-j<<") : ";
			cin>>choice2;
			cout<<"\nYour Card With Xp : "<<obj.player2_deck[choice2][0]<<endl;
			cout<<"\n\nDo You Want To Use Potion (Press Y For Yes): ";
			cin>>option;
						
			if(option == 'Y')
			{
				choice = show_potion(user2);
				if(choice == 1)
				{
					obj.player2_deck[choice2][0] += 200;
					updateStatus(line2 + 7,"-1");
				}
				else if(choice == 2)
				{
					obj.player2_deck[choice2][0] += 100;
					updateStatus(line2 + 8,"-1");
				}
			
				else if(choice == 3)
				{
					obj.player2_deck[choice2][0] += 50;
					updateStatus(line2 + 9,"-1");
				}
				else if(choice == 4)
				{
					attack2 = 200;
					updateStatus(line2 + 11,"-1");
				}
				else if(choice == 5)
				{
					attack2 = 100;
					updateStatus(line2 + 12,"-1");
				}
				else if(choice == 6)
				{
					attack2 = 50;
					updateStatus(line2 + 13,"-1");
				}
			}
			
			system("cls");
			
			cout<<"\t\t\tPlayer 1 Turn !! "<<endl;
			cout<<"YOUR DECK:"<<endl;
			for(int x = 0 ; x < obj.player1_deck.size() ; x++)
			{
				ShowPlayerCards(obj.player1_deck[x][0],obj.player2_deck[x][1],5,x*15,attack1);
				cout<<"  ";
			}
			
			cout<<"\n\nEnter The Card Number You Want To Pick ("<<0<<"-"<<4-i<<") : ";
			cin>>choice1;
			cout<<"\nYour Card With Xp : "<<obj.player1_deck[choice1][0]<<endl;
			cout<<"\n\nDo You Want To Use Potion (Press Y For Yes): ";
			cin>>option;
			
			if(option == 'Y')
			{
				choice = show_potion(user1);
				if(choice == 1)
				{
					obj.player1_deck[choice1][0] += 200;
					updateStatus(line1 + 7,"-1");
				}
				else if(choice == 2)
				{
					obj.player1_deck[choice1][0] += 100;
					updateStatus(line1 + 8,"-1");
				}
			
				else if(choice == 3)
				{
					obj.player1_deck[choice1][0] += 50;
					updateStatus(line1 + 9,"-1");
				}
				else if(choice == 4)
				{
					attack1 = 200;
					updateStatus(line1 + 11,"-1");
				}
				else if(choice == 5)
				{
					attack1 = 100;
					updateStatus(line1 + 12,"-1");
				}
				else if(choice == 6)
				{
					attack1 = 50;
					updateStatus(line1 + 13,"-1");
				}
				
			}
			
			system("cls");
			
			showcards(obj.player2_deck[choice2][0],obj.player1_deck[choice1][0],obj.player2_deck[choice2][1],obj.player1_deck[choice1][1],attack2,attack1);
			
			obj.player1_deck[choice1][0] -= (obj.player2_deck[choice2][1]+ attack2);		// Xp - Attack Power
			obj.player2_deck[choice2][0] -= (obj.player1_deck[choice1][1] + attack1);
			
			if(obj.player2_deck[choice2][0] <= 0)		//Erasing card if xp becomes 0 
			{
				obj.player2_deck.erase(obj.player2_deck.begin() + choice2);
				cout<<"\n"<<5-j<<" Cards Left";
				j++;
			}
			
			if(obj.player1_deck[choice1][0] <= 0)		//Erasing card if xp becomes 0 
			{
				obj.player1_deck.erase(obj.player1_deck.begin() + choice1);
				cout<<"\n"<<5-i<<" Cards Left";
				i++;
			}
		}
		//****************************************************************************
		attack1 = 0;
		attack2 = 0;
		
		if(toss == 1)
			toss = 2;
		else if(toss == 2)
			toss  = 1;
			
		if(i == 5){
			cout<<"\nPress Any Key To Continue !! ";
			getch();
			break;
		}
		
		else if(j == 5){
			cout<<"\nPress Any Key To Continue !! ";
			getch();
			break;
		}	
			
		
		cout<<"\nPress Any Key To Continue !! ";
		getch();
		system("cls");
	}
	
	if(obj.player1_deck.empty())
	{
		cout<<"\nPlayer 2 Wins !!";
		result(user2);
		return 2;
	}
	
	else if(obj.player2_deck.empty())
	{
		cout<<"\nPlayer 1 Wins !! ";
		result(user1);
		return 1;
	}
}

void result(string username)
{
	cout<<"\nRESULT !! ";
	display(username);
}



int check_username(string username)
{
	int count,found = 0,line = 1;
	string user;
	
	fstream Players,file;
	Players.open("Count.txt", ios :: in);
	file.open("Account.txt", ios :: in);
	
	if( !(Players.is_open() && file.is_open()) )
	{
		cout<<"\nFile Not Opened Successfully !! ";
		return 0;
	}
	Players>>count;
	if(count == 0 )
	{
		cout<<"\nNo Account Created !! \n";
		return 0;
	}
	
	while(!file.eof())
	{
		getline(file,user);
		if(user == username)
		{
			found++;
			return line;
		}
		line++;
	}
	if(found == 0)
		return 0;
}

int show_potion(string username)
{
	int choice,k = 0;
	string user;
	string val;
	int freq[7] = {0};
	fstream file;
	file.open("Account.txt", ios :: in);
	
	if( !file.is_open())
	{
		cout<<"\nFile Not Opened Successfully !! ";
		return 0;
	}
	
	int i = 0;
	string s[6];			
	s[0] = "Healing Special Potion : ";
	s[1] = "Healing Rare Potion : ";
	s[2] = "Healing Normal Potion : ";
	s[3] = "Attacking Special Potion : ";
	s[4] = "Attacking Rare Potion : ";
	s[5] = "Attacking Normal Potion : ";
	
	
	while(!file.eof())
	{
		getline(file,user);
		if(user == username)
		{
		//Printing Attacking And Healing Potions Available 
			for(int j = 0 ; j < 11 ; j++)
			{
				if(j < 8)
				{
					getline(file,val);
					
				}
					
			if(j > 7)
			{
					//file>>val;
					getline(file,val);
					cout<<"\n"<<s[i]<<val;
					if(val == "0")
					{
						freq[k] = 1;
						k++;
					}
					else
						k++;
					i++;
				}
			}
			
			cout<<"\nEnter Choice [1-3] : ";
			cin>>choice;
			
			if(freq[1] == 1 && freq[2] == 1 && freq[3] == 1 && freq[4] == 1 && freq[5] == 1 && freq[6] == 1)
			{
				cout<<"\nYou Don't Have Any Potion Available !!";
				cout<<"\nPress Any Key To Continue !!";
				getch();
				return 0;
			}
			if(freq[1] == 1 && choice == 1)
			{
				cout<<"\nYou Do Not Have Any Special Healing Potion !! ";
				cout<<"\nPress Any Key To Continue !!";
				getch();
				return 0;
			}
			else if(freq[2] == 1 && choice == 2)
			{
				cout<<"\nYou Do Not Have Any Rare Healing Potion !! ";
				cout<<"\nPress Any Key To Continue !!";
				getch();
				return 0;
			}
			else if(freq[3] == 1 && choice == 3)
			{
				cout<<"\nYou Do Not Have Any Normal Healing Potion !! ";
				cout<<"\nPress Any Key To Continue !!";
				getch();
				return 0;
			}
			
			if(freq[4] == 1 && choice == 4)
			{
				cout<<"\nYou Do Not Have Any Special Attacking Potion !! ";
				cout<<"\nPress Any Key To Continue !!";
				getch();
				return 0;
			}
			else if(freq[5] == 1 && choice == 5)
			{
				cout<<"\nYou Do Not Have Any Rare Attacking Potion !! ";
				cout<<"\nPress Any Key To Continue !!";
				getch();
				return 0;
			}
			else if(freq[6] == 1 && choice == 6)
			{
				cout<<"\nYou Do Not Have Any Normal Attacking Potion !! ";
				cout<<"\nPress Any Key To Continue !!";
				getch();
				return 0;
			}
			else
			{
				cout<<"\nPress Any Key To Continue !!";
				getch();
				return choice;
			}
		}
	}	
}

bool display(string username)
{
	int count,found = 0;
	string user;
	string s[13];
	cout<<"YOUR PROGRESS: "<<endl<<endl;
	s[0] = "Password : ";
	s[1] = "ID : ";
	s[2] = "Level : ";
	s[3] = "Price : ";
	s[4] = "Number Of Matches Won : ";
	s[5] = "Healing Potions Owned Are : ";
	s[6] = "Special Potion : ";
	s[7] = "Rare Potion : ";
	s[8] = "Normal Potion : ";
	s[9] = "Attacking Potions Owned Are : ";
	s[10] = "Special Potion : ";
	s[11] = "Rare Potion : ";
	s[12] = "Normal Potion : ";
	
	fstream Players,file;
	Players.open("Count.txt", ios :: in);
	file.open("Account.txt", ios :: in);
	
	if( !(Players.is_open() && file.is_open()) )
	{
		cout<<"\nFile Not Opened Successfully !! ";
		return false;
	}
	Players>>count;
	if(count == 0 )
	{
		cout<<"\nNo Account Created !! \n";
		return false;
	}
				
	while(!file.eof())
	{
		getline(file,user);
		if(user == username)
		{
			found++;
			cout<<"\nUsername : "<<user<<endl;
			for(int i = 0 ; i <  14 ; i++)
			{
				getline(file,user);
				cout<<s[i]<<user<<endl;
			}
		}	
	}
	
	if(found == 0)
	{
		cout<<"\nAccount Not Found !! ";
		return false;
	}
	return true;
}