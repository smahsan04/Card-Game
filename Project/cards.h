class Card{
	public:
		Card ()	{ }
		virtual void set_card() = 0;
		virtual int getcard(int i,int j) = 0;
		virtual void remove() = 0;
};

class Legendary : public Card{
	private:
		vector <int> card[2];
	public:
		Legendary(){ }
		
		void set_card()
		{
			srand(time(NULL));
			for(int i = 0 ; i < 2 ; i++)	//Legendary Cards
			{				
				card[i].push_back(rand() % 200+800);		// Xp Between 800 - 999
				card[i].push_back(500);
			}
		}
		int getcard(int i,int j) { return card[i][j]; }
		
		void remove(){ 
			for(int i = 0 ; i < 2; i++)
			{
				card[i].clear();
			}
		}
};

class Epic : public Card{
	private:
		vector <int> card[3];
	public:
		Epic(){	}
		
		void set_card()
		{
			srand(time(NULL));
			for(int i = 0 ; i < 3 ; i++)		//Epic Cards 
			{				
				card[i].push_back(rand() % 200+600);		// Xp Between 600 - 799
				card[i].push_back(400);
			}
		}
		int getcard(int i,int j) { return card[i][j]; }
		
		void remove(){ 
			for(int i = 0 ; i < 3; i++)
			{
				card[i].clear();
			}
		}
};

class Rare : public Card{
	private:
		vector <int> card[5];
	public:
		Rare(){	}
		
		void set_card()
		{
			srand(time(NULL));
			for(int i = 0 ;i < 5 ; i++)		//Rare Cards 
			{
				card[i].push_back(rand() % 200+400);		// Xp Between 400 - 599
				card[i].push_back(300);
			}
		}
		int getcard(int i,int j) { return card[i][j]; }
		
		void remove(){ 
			for(int i = 0 ; i < 5; i++)
			{
				card[i].clear();
			}
		}
};

class Normal : public Card{
	private:
		vector <int> card[10];
	public:
		Normal(){ }
		
		void set_card()
		{
			srand(time(NULL));
			for(int i = 0 ;i < 10 ; i++)	//Normal Cards
			{
				card[i].push_back(rand() % 200+200);		// Xp Between 200 - 399
				card[i].push_back(200);
			}
		}
		
		int getcard(int i,int j) { return card[i][j]; }
		
		void remove(){ 
			for(int i = 0 ; i < 10; i++)
			{
				card[i].clear();
			}
		}
};

class Deck
{
	private:
		Legendary L;
		Epic E;
		Rare R;
		Normal N;
		vector <vector<int>> player1_deck;
		vector <vector<int>> player2_deck;
		vector <int> deck[20];
		int point1 = 0,point2 = 0 ;
		int index1,index2;
	public:	
		Deck() { }
		
		void fill_deck();
		void shuffle();
		void deal();
		friend int Play_game(Deck &obj,string user1,string user2,int line1,int line2);
};

void Deck :: fill_deck()
{
	L.set_card();
	R.set_card();
	E.set_card();
	N.set_card();
	
	int index = 0;
	
	for(int i = 0 ; i < 2 ;i++)
	{
		for(int j = 0 ; j < 2; j++)
		{
			deck[i].push_back(L.getcard(index,j));
		}
		index++;
	}
	
	index = 0;
	for(int i = 2 ; i < 5 ;i++)
	{
		for(int j = 0 ; j < 2; j++)
		{
			deck[i].push_back(E.getcard(index,j));
		}
		index++;
	}
	
	index = 0;
	for(int i = 5 ; i < 10 ;i++)
	{
		for(int j = 0 ; j < 2; j++)
		{
			deck[i].push_back(R.getcard(index,j));
		}
		index++;
	}
	
	index = 0;
	for(int i = 10 ; i < 20 ;i++)
	{
		for(int j = 0 ; j < 2; j++)
		{
			deck[i].push_back(N.getcard(index,j));
		}
		index++;
	}
	
}

void Deck :: shuffle()
{
	srand(time(NULL));
	int x,y;
	int temp;
	int freq[20][2] = {0};
	for(int i = 0 ; i < 20 ; i++)
	{
		x = rand() % 20 + 1;
		for(int j = 0; j < 2 ; j++)
		{
			if( freq[i][j] > 0 || freq[x][j] > 0 )
			{
				continue;
			}
			temp = deck[i][j];
			deck[i][j] = deck[x][j];
			deck[x][j] = temp;
			freq[i][j]++;
			freq[x][j]++;
		}
	}

}

void Deck :: deal()
{
	for(int i = 0 ; i < 10 ; i+=2)
	{
		player1_deck.push_back(deck[i]);
		player2_deck.push_back(deck[i+1]);
	}
	
	L.remove();
	E.remove();
	R.remove();
	N.remove();
	for(int i = 0 ; i < 20 ; i++)
	{
		deck[i].clear();
	}
}