const int Max_Level = 20;

class User_Details{
	private:
		string username,password;
		int level,num_wins,id;
		long int price;
		vector <int> Healing[3];
		vector <int> Attacking[3];
		static int count;
		string s[3];
	public:
		User_Details()
		{
			username = "";
			password = "";
			level = 1;
			price = 0;
			num_wins = 0;
			for(int i = 0 ; i < 3 ; i++)
			{
				Healing[i].push_back(0);
			}
			for(int i = 0 ; i < 3 ; i++)
			{
				Attacking[i].push_back(0);
			}
		}
		
		void setdata(string un,string ps)
		{
			int num;
			srand(time(NULL));
			username = un;
			password = ps;
			id = rand() % 1000 + 1;
			
			fstream Players;
			fstream file;
			file.open("Account.txt", ios :: app);
			Players.open("Count.txt", ios :: out);
			
			if(!file.is_open())
			{
				cout<<"\nFile Not Opened Successfully !! ";
			}
			
			file<<username<<"\n";
			file<<password<<"\n";
			file<<id<<"\n";
			file<<level<<"\n";
			file<<price<<"\n";
			file<<num_wins<<"\n";
			file<<"\n";
			for(int i = 0 ; i < 3 ; i++)
			{
				file<<Healing[i][0]<<"\n";
			}
			file<<"\n";
			for(int i = 0 ; i < 3 ; i++)
			{
				file<<Attacking[i][0]<<"\n";
			}
			
			cout<<"\nYour Username : "<<username;
			cout<<"\nYour User id : "<<id;
			count++;
			Players<<count;
			
			file.close();
			Players.close();
		}
		
		void reward(int line)
		{
			updateStatus(line + 5,"1000");
		}
		void setwins(int line)
		{
			updateStatus(line + 6,"");
			num_wins++;
			if(num_wins == 15)
			{
				if(level != Max_Level)
				{
					level++;
					
				}
				else
					cout<<"\nYou Have Reached Maximum Level !! \n";
					
				num_wins = 0;
			}
	    }
		
};

int User_Details :: count = 0;