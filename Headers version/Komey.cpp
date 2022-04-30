#include "Komey.h"


//4- Game Classes
//4-1 DeckHashTable
//Type: HashTable (array of size 13)
//functionality: Stores number of cards
//Draws card from it according to certain Hashing index
//initially is full
int N = 4;									//defines the number of cards in one hand in games like Basra (4 or 8) recommended
int Deck_Size = 13*N;							//defines number of total cards (52, 104, etc)
char dummyvariable[Max_C_String_Size];
void parameter_change(){
		cout<<"Enter Number of cards in hand (Complexity Test): ";
		N = PA_Opt_in(100000);
		if(N<4)
		{
			cout<<"minimum cards chosen... N = 4\n";
			N = 4;
		}
		else
		cout<<"cards in hand chosen... N = "<<N<<"\n";
		cout<<"Total Cards in deck: "<<N*13<<" cards \n";
}

	int Deck::Hash_Index(int Card_Number)
	{
		//function that determines hashing index
		return ((Card_Number-1)%13);
	}
	Deck::Deck()
	{
		//Default Constructor
		for (int i = 0; i < 13; i++)
		{
			DeckCards[i] = N;
		}
		RemainingCards = 13*N;
	}
	void Deck::Reset_Deck()
	{
		//Resets to default after game round ends
		for (int i = 0; i < 13; i++)
		{
			DeckCards[i] = N;
		}
			RemainingCards = 13*N;
	}
	bool Deck::IsEmpty()
	{
		//checks if deck is empty, returns 1 if empty and returns 0 if not empty
		if (RemainingCards>0) return false;
		else return true;
	}
	bool Deck::CardExist(int Card){
		if (DeckCards[Hash_Index(Card)]>0) return true;
		else return false;
	}
	int Deck::DrawCard()
	{
		int Card = Random();
			while (!CardExist(Card))
			{Card = Random();}
			RemainingCards--;
			DeckCards[Card-1]--;
			return Card;
	}
	int Deck::NumberDrawCard()
	{
		int Card = NumberRandom();
			while (!CardExist(Card))
			{Card = NumberRandom();}
			RemainingCards--;
			DeckCards[Card-1]--;
			return Card;
	}
	void Deck::DisplayDeck()
	{
		for (int i = 0; i < 13; i++)
		{
			Card_Display(i+1);
			cout<<"x "<<DeckCards[i];
			cout<<"\n";
		}

	}


	Basra::Basra()
	{//Default Constructor
	Player = Playing_Hand();
	AI = Playing_Hand();
	Kotshena = Deck();
	Field = Floor();
	Player_Score = 0;
	AI_Score = 0;
	}
	void 	Basra::Reset()
	{//Reset Function for play again option
		Player_Score = 0;
		AI_Score = 0;
		Player.ResetHand();
		AI.ResetHand();
		Kotshena.Reset_Deck();
		Field.Reset_Floor();
	}
	void 	Basra::PlayerDraw()
	{
		for (int i = 0; i < N; i++)
		{
			Player.DrawCard(Kotshena.DrawCard());
		}
	}
	void 	Basra::AIDraw()
	{
		for (int i = 0; i < N; i++)
		{
			AI.DrawCard(Kotshena.DrawCard());
		}
	}
	void 	Basra::FieldDraw()
	{
		for (int i = 0; i < N; i++)
		{
			Field.PlaceCard(Kotshena.DrawCard());
		}
	}
	void 	Basra::Oppening()
	{
		PlayerDraw();
		AIDraw();
		FieldDraw();
	}
	void 	Basra::EndTurn()
	{
		cout<<"\n\nEmpty Hands, Drawing "<<N<<" Cards from Deck...\n";
		PlayerDraw();
		AIDraw();
	}
	void 	Basra::Text()
	{	cout<<"-------------------------------------------------\n\t\t     KOMEY!\n";
		cout<<"-------------------------------------------------\n";
		cout<<"Your Score: "<<Player_Score<<"		AI Score:	"<<AI_Score;
		cout<<"\nCurrent AI Cards: \n(only visible during testing)\n";
		//add comment before the AI Display to hide it from player
		if(AI.Count<=100)AI.DisplayHand();
		else cout<<"supressed, more than 100 cards";
		cout<<"\nCurrent Floor Cards:\n";
		if(Field.FloorCardCount<=100)Field.FloorDisplay();
		else cout<<"supressed, more than 100 cards";
		cout<<endl;
		cout<<"\nCurrent Player Cards:\n";
		if(Player.Count<=100)Player.DisplayHand();
		else cout<<"supressed, more than 100 cards";
		cout<<"-------------------------------------------------\n";
		cout<<"Remaining Cards in Deck:	"<<Kotshena.RemainingCards<<"\n";
	}

	void 	Basra::Play()
	{
		int x = 0;		//player card
		int y = 0;		//AI card
		int z[13] = {0};//Priority Matrix upon which AI decides
		double timestart = 0;
		double clockstart = 0;
		double Time_Elapse_In_Seconds = 0;
		double Clocks_Elapsed_In_Processor_Speed = 0;
		double total_time = 0;
		double total_clocks = 0;
		Oppening();
		while (!(Kotshena.IsEmpty()) || !(Player.IsEmpty()) || !(AI.IsEmpty()))
		{
			while (!(Player.IsEmpty()) || !(AI.IsEmpty()))
			{
				Text();
				cout<<"Your Turn, Pick a Card From 1 to 10 or letter (J,K,Q)\nCard:	";
				x = (Player.PlayCard(CardInput()));
				timestart = Now();
				clockstart = Clocks();
				if (x==11)
				{
					Player_Score++;
					Player_Score += Field.EatsAllCards();
					Text();
				}
				else if (Field.CardRank(x)>0)
				{
					Player_Score++;
					Player_Score += Field.CardBank(x);
					Player_Score += Field.MultiFours(x);
					Player_Score += Field.MultiThrees(x);
					Player_Score += Field.MultiTwos(x);
					Text();
				}
				else
				{
					Field.PlaceCard(x);
					Text();
				}
				Time_Elapse_In_Seconds+=Now()-timestart;
				Clocks_Elapsed_In_Processor_Speed+=Clocks()-clockstart;
				cout<<"Press Enter to Continue Playing Game....";
				cin.getline(dummyvariable,Max_C_String_Size);
				timestart = Now();
				clockstart = Clocks();
				cout<<"AI Turn.... Comparing Card Ranks and possible win\nCard:	";
				for (int i = 0; i < 13; i++)
				{
					if(!(AI.IsFound(i+1))) z[i] = -1;
					else z[i] = Field.CardRank(i+1);
				}
				y = MaxOf(z);
				Card_Display(y);
				AI.PlayCard(y);
				cout<<"\n";
				if (y==11)
				{
					AI_Score++;
					AI_Score += Field.EatsAllCards();
				}
				else if (Field.CardRank(y)>0 && y != 11)
				{
					AI_Score++;
					AI_Score += Field.CardBank(y);
					AI_Score += Field.MultiFours(y);
					AI_Score += Field.MultiThrees(y);
					AI_Score += Field.MultiTwos(y);
				}
				else
				{
					Field.PlaceCard(y);
				}
				Time_Elapse_In_Seconds = Now() - timestart;
				Clocks_Elapsed_In_Processor_Speed = Clocks() - clockstart;
				cout<<"\nTime Elpased in this round: "<<Time_Elapse_In_Seconds<<" seconds";
				cout<<"\nProcessor Clocks Elpased in this round: "<<Clocks_Elapsed_In_Processor_Speed<<" clocks\n";
				total_time+=Time_Elapse_In_Seconds;
				total_clocks+=Clocks_Elapsed_In_Processor_Speed;
				Time_Elapse_In_Seconds = 0 ;
				Clocks_Elapsed_In_Processor_Speed = 0;
			}
			if(!Kotshena.IsEmpty())EndTurn();
		}
		cout<<"\nGame Ended, Remaining cards go to player: ";
		Player_Score+=Field.FloorCardCount;
		cout<<"\nAI Score: "<<AI_Score;
		cout<<"\nPlayer Score: "<<Player_Score;
		if(Player_Score > AI_Score) cout<<"\nCongrats!!! You Win\n";
		else if(Player_Score == AI_Score) cout<<"\nDraw! You got same result as AI\n";
		else cout<<"\nHard luck!:( You Lose\n";
		cout<<"\nTime Elpased in total game computations: "<<total_time<<" seconds";
		cout<<"\nProcessor Clocks Elpased in total game computations: "<<total_clocks<<" clocks\n";
	}
//class Basra AI vs AI

	Basra_AI_vs_AI::Basra_AI_vs_AI()
	{//Default Constructor
	AI1 = Playing_Hand();
	AI2 = Playing_Hand();
	Kotshena = Deck();
	Field = Floor();
	AI1_Score = 0;
	AI2_Score = 0;
	}
	void Basra_AI_vs_AI::Reset()
	{//Reset Function for play again option
		AI1_Score = 0;
		AI2_Score = 0;
		AI1.ResetHand();
		AI2.ResetHand();
		Kotshena.Reset_Deck();
		Field.Reset_Floor();
	}
	void Basra_AI_vs_AI::AI1Draw()
	{
		for (int i = 0; i < N; i++)
		{
			AI1.DrawCard(Kotshena.DrawCard());
		}
	}
	void Basra_AI_vs_AI::AI2Draw()
	{
		for (int i = 0; i < N; i++)
		{
			AI2.DrawCard(Kotshena.DrawCard());
		}
	}
	void Basra_AI_vs_AI::FieldDraw()
	{
		for (int i = 0; i < N; i++)
		{
			Field.PlaceCard(Kotshena.DrawCard());
		}
	}
	void Basra_AI_vs_AI::Oppening()
	{
		AI1Draw();
		AI2Draw();
		FieldDraw();
	}
	void Basra_AI_vs_AI::EndTurn()
	{
		cout<<"\n\nEmpty Hands, Drawing "<<N<<" Cards from Deck...\n";
		AI1Draw();
		AI2Draw();
	}
	void Basra_AI_vs_AI::Text()
	{	cout<<"-------------------------------------------------\n\t\t     KOMEY!\n";
		cout<<"-------------------------------------------------\n";
		cout<<"AI1 Score: "<<AI1_Score<<"		AI2 Score:	"<<AI2_Score;
		cout<<"\nCurrent AI1 Cards: \n";
		//add comment before the AI Display to hide it from player
		if(AI1.Count<=100)AI1.DisplayHand();
		else cout<<"supressed, more than 100 cards";
		cout<<"\nCurrent Floor Cards:\n";
		if(Field.FloorCardCount<=100)Field.FloorDisplay();
		else cout<<"supressed, more than 100 cards";
		cout<<endl;
		cout<<"\nCurrent AI2 Cards:\n";
		if(AI2.Count<=100)AI2.DisplayHand();
		else cout<<"supressed, more than 100 cards";
		cout<<"-------------------------------------------------\n";
		cout<<"Remaining Cards in Deck:	"<<Kotshena.RemainingCards<<"\n";
	}

	void Basra_AI_vs_AI::Play()
	{
		int x = 0;		//player card
		int y = 0;		//AI card
		int z[13] = {0};//Priority Matrix upon which AI decides
		double timestart = 0;
		double clockstart = 0;
		double Time_Elapse_In_Seconds = 0;
		double Clocks_Elapsed_In_Processor_Speed = 0;
		double total_time = 0;
		double total_clocks = 0;
		Oppening();
		while (!(Kotshena.IsEmpty()) || !(AI1.IsEmpty()) || !(AI2.IsEmpty()))
		{
			while (!(AI1.IsEmpty()) || !(AI2.IsEmpty()))
			{
				Text();
				timestart = Now();
				clockstart = Clocks();
				cout<<"AI1 Turn.... Comparing Card Ranks and possible win\nCard:	";
				for (int i = 0; i < 13; i++)
				{
					if(!(AI1.IsFound(i+1))) z[i] = -1;
					else z[i] = Field.CardRank(i+1);
				}
				y = MaxOf(z);
				Card_Display(y);
				AI1.PlayCard(y);
				cout<<"\n";
				if (y==11)
				{
					AI1_Score++;
					AI1_Score += Field.EatsAllCards();
				}
				else if (Field.CardRank(y)>0 && y != 11)
				{
					AI1_Score++;
					AI1_Score += Field.CardBank(y);
					AI1_Score += Field.MultiFours(y);
					AI1_Score += Field.MultiThrees(y);
					AI1_Score += Field.MultiTwos(y);
				}
				else
				{
					Field.PlaceCard(y);
				}
				cout<<"AI2 Turn.... Comparing Card Ranks and possible win\nCard:	";
				for (int i = 0; i < 13; i++)
				{
					if(!(AI2.IsFound(i+1))) z[i] = -1;
					else z[i] = Field.CardRank(i+1);
				}
				y = MaxOf(z);
				Card_Display(y);
				AI2.PlayCard(y);
				cout<<"\n";
				if (y==11)
				{
					AI2_Score++;
					AI2_Score += Field.EatsAllCards();
				}
				else if (Field.CardRank(y)>0 && y != 11)
				{
					AI2_Score++;
					AI2_Score += Field.CardBank(y);
					AI2_Score += Field.MultiFours(y);
					AI2_Score += Field.MultiThrees(y);
					AI2_Score += Field.MultiTwos(y);
				}
				else
				{
					Field.PlaceCard(y);
				}
				Time_Elapse_In_Seconds = Now() - timestart;
				Clocks_Elapsed_In_Processor_Speed = Clocks() - clockstart;
				cout<<"\nTime Elpased in this round: "<<Time_Elapse_In_Seconds<<" seconds";
				cout<<"\nProcessor Clocks Elpased in this round: "<<Clocks_Elapsed_In_Processor_Speed<<" clocks\n";
				total_time+=Time_Elapse_In_Seconds;
				total_clocks+=Clocks_Elapsed_In_Processor_Speed;
				Time_Elapse_In_Seconds = 0 ;
				Clocks_Elapsed_In_Processor_Speed = 0;
			}
			if(!Kotshena.IsEmpty())EndTurn();
		}
		cout<<"\nGame Ended, Remaining cards go to AI1: ";
		AI1_Score+=Field.FloorCardCount;
		cout<<"\nAI1 Score: "<<AI1_Score;
		cout<<"\nAI2 Score: "<<AI2_Score;
		if(AI1_Score > AI2_Score) cout<<"\nAI1 wins\n";
		else if(AI1_Score == AI2_Score) cout<<"\nDraw! AI1 same result as AI2\n";
		else cout<<"\nAI2 wins\n";
		cout<<"Cards in hand chosen... N = "<<N<<"\n";
		cout<<"Total Cards in deck: "<<N*13<<" cards \n";
		cout<<"\nTime Elpased in total game computations: "<<total_time<<" seconds";
		cout<<"\nProcessor Clocks Elpased in total game computations: "<<total_clocks<<" clocks\n";
	}

