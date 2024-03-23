class Shop{
	private:
		vector <int> attack_potion;
		vector <int> healing_potion;
		vector <int> chest;
	public:
		Shop()
		{
		    healing_potion.push_back(2002);		//Heal HP By 200
			attack_potion.push_back(2001);		//Increase Attack Power By 200
			healing_potion.push_back(1002);		//Heal HP By 100
			attack_potion.push_back(1001);		//Increase Attack Power By 100
			healing_potion.push_back(502);		//Heal HP By 50
			attack_potion.push_back(501);		//Increase Attack Power By 50
			chest.push_back(healing_potion[0]);
			chest.push_back(healing_potion[1]);
			chest.push_back(healing_potion[2]);
			chest.push_back(attack_potion[0]);
			chest.push_back(attack_potion[1]);
			chest.push_back(attack_potion[2]);
			for(int i = 0 ;i < 14 ;i++)
			{
				chest.push_back((100*(i+1)) + 200);
			}
		}
		
		int display(string username)
		{
			int available;
			char ch;
			string s;
			system("cls");
			cout<<"\t\t\t\t\t     SHOP"<<endl<<endl;
			cout<<"Select from the following:"<<endl<<endl;
			cout<<"1.Press 'B' to Buy Attack Or Healing Potions!"<<endl;
			cout<<"2.Press C to check if there are any chests avaialable!"<<endl;
	
			cin>>ch;
			int line;
			line = check_username(username);
			
			if(ch == 'C')
			{
				available = rand() % 40 + 1;
				if((available % 5) == 0)
				{
					char ch;
					cout<<"\n\n\t\tLucky!\nChest Available\n\nPress 'O' To Open Chest : ";
					cin>>ch;
					if(ch == 'O')
					{
						int i;
						i = rand() % 20 ;
						if(i > 5)
						{
							string val;
							cout<<"\nYou Got "<<chest[i]<<" Price \n\n";
							val = to_string(chest[i]);
							updateStatus(line + 4,val);
						}
						else if(i < 6)
						{
							if(chest[i] % 10 == 2)
							{
								cout<<"\nYou Got A Healing Potion !! \n\n";
								if(chest[i]/10 == 200)
								{
									s = "Special Potion :";
									updateStatus(line + 7,"");
								}
								else if(chest[i]/10 == 100)
								{
									s = "Rare Potion : ";
									updateStatus(line + 8,"");
								}
								else if(chest[i]/10 == 50)
								{
									s = "Normal Potion : ";
									updateStatus(line + 9,"");
								}
							}
							else if(chest[i] % 10 == 1)
							{
								cout<<"\nYou Got A Attacking Potion !! \n\n";
								if(chest[i]/10 == 200)
								{
									updateStatus(line + 11,"");
								}
								else if(chest[i]/10 == 100)
								{
									updateStatus(line + 12,"");
								}
								else if(chest[i]/10 == 50)
								{
									updateStatus(line + 13,"");
								}
							}
						}
					}
					else
					{
						cout<<"\nInvalid Option !!\n";
						cout<<"\nPress Any Key To Continue!!";
						getch();
						return 0;
					}
				}
				else {
					cout<<"\t\t\t\tBetter Luck Next Time!\nChest not available\n";
					cout<<"\n\nPress Any Key To Continue!!";
					getch();
					return 0;
				}
			}
			else if(ch == 'B' || ch == 'b')
			{
				Buy(line);
			}
			else
			{
				cout<<"\nInvalid Option !! \n";
				return 0;
			}
		}
		int Buy(int line)
		{
			int option;
			string s;
			cout<<"Select from the following potions:"<<endl;
			cout<<"1-Healing Potions\n2-Attacking Potions\n";
			cout<<"Your Choice(1-2): ";
			cin>>option;
			if(option == 1)
			{
				int choice;
				cout<<"\n1-Special Potion Price : 10000\n2-Rare Potion\tPrice : 5000\n3-Normal Potion\tPrice : 1000\n";
				cout<<"\nEnter Your Choice : ";
				cin>>choice;
				if(choice == 1)
				{
					updateStatus(line + 7,"");
				}
				else if(choice == 2)
				{
					updateStatus(line + 8,"");
				}
				else if(choice = 3 )
				{
					updateStatus(line + 9,"");
				}
			}
			else if(option == 2)
			{
				int choice;
				cout<<"\n1-Special Potion Price : 10000\n2-Rare Potion\tPrice : 5000\n3-Normal Potion\tPrice : 1000\n";
				cout<<"\nEnter Your Choice : ";
				cin>>choice;
				if(choice == 1)
				{
					updateStatus(line + 11,"");
				}
				else if(choice == 2)
				{
					updateStatus(line + 12,"");
				}
				else if(choice = 3 )
				{
					updateStatus(line + 13,"");
				}
			}
			else
			{
				cout<<"\nInvalid Option !! ";
				return 0;
			}
		}
				
};