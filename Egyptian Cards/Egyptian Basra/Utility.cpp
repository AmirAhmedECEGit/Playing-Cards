#include "Utility.h"


//2- Utility Functions
//2.1- Elapsed_Time_In_Seconds
double Now(){
	time_t current = clock();
	return (double)current/CLOCKS_PER_SEC;
}
//2.2- Elapsed number of processor clocks
double Clocks(){
	time_t current = clock();
	return (double)current;
}
//2.3- Code to randomize number
int Random(){
	int x = 1+rand()%13;
		while (x<0 || x>13){
			x = 1+rand()%13;
		}
	return (x);
// number range is fron 1 to 13 which suits my playing cards 1->10,J,Q,K
}
int NumberRandom(){
	int x = 1+rand()%10;
		while (x<0 || x>10){
			x = 1+rand()%10;
		}
	return (x);
// number range is fron 1 to 10 which suits my playing cards 1->10 in games such as Money and BlackJack
}
void Synchronus(){
	srand((unsigned int)time(NULL));
	//based on universal time since 1970 thingy <totally random>
	//use it in Main code bedore game starts
}
//2.4- Code to display playing cards as stylised model where 1->10 the J = 11, Q = 12, K = 13
void Card_Display(int x){
		if(x==1)
		cout<<"[* 1 ]";
		else if(x==2)
		cout<<"[* 2 ]";
		else if(x==3)
		cout<<"[* 3 ]";
		else if(x==4)
		cout<<"[* 4 ]";
		else if(x==5)
		cout<<"[* 5 ]";
		else if(x==6)
		cout<<"[* 6 ]";
		else if(x==7)
		cout<<"[* 7 ]";
		else if(x==8)
		cout<<"[* 8 ]";
		else if(x==9)
		cout<<"[* 9 ]";
		else if(x==10)
		cout<<"[* 10]";
		else if(x==11)
		cout<<"[* J ]";
		else if(x==12)
		cout<<"[* Q ]";
		else if(x==13)
		cout<<"[* K ]";
		else
		cout<<"[* ??]";
}

//2.5- Code to convert user input into numbers and reject bad input
bool Find (char str[], char sub[]){
	//2.5.1 returns true if a substring is found and false if not
	char temp[Max_C_String_Size];
	for(unsigned int i = 0; i<strlen(str); i++)
	{
		for (unsigned int j = 0; j < strlen(sub); j++)
		{
			if(str[i+j] == sub[j])
			{
				temp[j]=sub[j];
					for(unsigned int k = 0;k<=strlen(sub);k++)
					{
						if(k == strlen(sub)) return true;
						else if(temp[k] == sub[k]) continue;
						else break;
					}
			}
			else break;
		}
	 }
	return false;
}
bool IsNumber(char Temp[]) {
	//2.5.2 checks if input carriage contains a valid card number
		int Temp_Length_Counter = 0;
		int Counter = 0;
		int Sum = 0;
		for (int i = 0 ; Max_C_String_Size-1 ; i++){
			Counter++;
			if((Temp[i]>='0' && Temp[i]<='9')||(Temp[i] == ' ')||(Temp[i] == '\0')){
                    if (Temp[i]=='\0') break;
				else if(Temp[i]==' ' &&  Temp_Length_Counter == 0) continue;				//space at the start is allowed
				else if (Temp[i]==' ' &&  Counter == (strlen(Temp))) continue;				//space in end is allowed
				else if (Temp[i]==' ' &&  Temp_Length_Counter > 0) return false;			//space in middle is not allowed
				else{
					Temp_Length_Counter++;
					continue;
				}
			}
			else return false;
		}
		if (Temp_Length_Counter>2) return false;
		for (int i = 0; Temp_Length_Counter ; i++ ){
            if((Temp[i]>='0' && Temp[i]<='9')){
                    Temp_Length_Counter--;
                    if(Temp_Length_Counter) Sum = Sum + (Temp[i]-'0')*10;
                    else Sum = Sum + Temp[i] - '0';
            }
		}
		if (Sum>13) return false;
		if (Sum<1) return false;
		return true;
}
bool IsLetter(char Temp[]) {
	//2.5.3 Checks if input carriage contains a valid card litera
		int Temp_Length_Counter = 0;
		int Counter = 0;
		for (int i = 0 ; Max_C_String_Size-1 ; i++){
			Counter++;
			if((Temp[i]>='a' && Temp[i]<='z')||(Temp[i]>='A' && Temp[i]<='Z')||(Temp[i] == ' ')||(Temp[i] == '\0')){
                     if (Temp[i]=='\0') break;
				if(Temp[i]==' ' &&  Temp_Length_Counter == 0) continue;				//space at the start is allowed
				else if (Temp[i]==' ' &&  Counter == (strlen(Temp))) continue;		//single space in end is allowed
				else if (Temp[i]==' ' &&  Temp_Length_Counter > 0) return false;	//space in middle is not allowed
				else{
					Temp_Length_Counter++;
					continue;
				}
			}
			else return false;
		}
		if (Temp_Length_Counter>5) return false;
		else return true;
}
int CardInput(){
	char Temp[Max_C_String_Size] = {0};

	cin.getline(Temp,Max_C_String_Size);
	while(Temp[0]=='\0' || !(IsNumber(Temp) || IsLetter(Temp))){
		//Check For Empty Input or Symbols and bad letters
		cout<<"Bad Input \nRe-Input Number(1->10) or Letters (J,Q,K):\nCard: ";
		cin.getline(Temp,Max_C_String_Size);
	}
	if		(Find(Temp,"13")||Find(Temp,"K")||Find(Temp,"k")||Find(Temp,"king")||Find(Temp,"King")||Find(Temp,"KING"))		return 13;
	else if (Find(Temp,"12")||Find(Temp,"Q")||Find(Temp,"q")||Find(Temp,"queen")||Find(Temp,"Queen")||Find(Temp,"QUEEN"))	return 12;
	else if (Find(Temp,"11")||Find(Temp,"J")||Find(Temp,"j")||Find(Temp,"jack")||Find(Temp,"Jack")||Find(Temp,"JACK"))		return 11;
	else if (Find(Temp,"10")||Find(Temp,"TEN")||Find(Temp,"Ten")||Find(Temp,"ten"))		 return 10;
	else if (Find(Temp,"9")||Find(Temp,"NINE")||Find(Temp,"Nine")||Find(Temp,"nine"))	 return 9;
	else if (Find(Temp,"8")||Find(Temp,"EIGHT")||Find(Temp,"Eight")||Find(Temp,"eight")) return 8;
	else if (Find(Temp,"7")||Find(Temp,"SEVEN")||Find(Temp,"Seven")||Find(Temp,"seven")) return 7;
	else if (Find(Temp,"6")||Find(Temp,"SIX")||Find(Temp,"Six")||Find(Temp,"six"))		 return 6;
	else if (Find(Temp,"5")||Find(Temp,"FIVE")||Find(Temp,"Five")||Find(Temp,"five"))	 return 5;
	else if (Find(Temp,"4")||Find(Temp,"FOUR")||Find(Temp,"Four")||Find(Temp,"four"))	 return 4;
	else if (Find(Temp,"3")||Find(Temp,"THREE")||Find(Temp,"Three")||Find(Temp,"three")) return 3;
	else if (Find(Temp,"2")||Find(Temp,"TWO")||Find(Temp,"Two")||Find(Temp,"two"))		 return 2;
	else if (Find(Temp,"1")||Find(Temp,"ONE")||Find(Temp,"One")||Find(Temp,"one"))		 return 1;
	else return 0;
}

//2.6- A utility function to get Maximum of two integers
int Max(int a, int b)
{
	if (a > b) return a;
	else return b;
}

//2.7- Option checking, number input function
int  PA_Opt_in (int n)		//Positive Option input fucntion
	{
		int x;
    	std::cin >> x;
		while((std::cin.fail()) || (x<1||x>n)) //gives 1 if cin fails or x is not among option
    		{
        		std::cin.clear();
        		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        		std::cout << "Bad entry. chooose a valid option: ";
        		std::cin >> x;
    		}
		return x;
	}
//2.8- Find Biggest element in 3 elements
int Biggest(int x,int y,int z)
{
	int temp = x;
	if(y>temp) temp = y;
	if(z>temp) temp = z;
	return temp;
}

//2.9- Find Biggest element in an array
int MaxOf(int arr[13]){
int temp = arr[0];
int index = 0;
for (int i = 1; i < 13; i++)
{
	if(temp < arr[i])
	{
		temp=arr[i];
		index = i;
	}
}
return (index+1);
}

//2.10- Intro Text Display
void Intro()
{
cout<<"Hall of Glory:\n";
cout<<"1- Amir Ahmed Hassan Mohamed\n";
cout<<"2- Ahmed Sayed Bakry\n";
cout<<"3- Omnia Ehab\n";
cout<<"\n";
cout<<"Game:\n";
cout<<"Kotshena\n";
cout<<"we had the idea to create Kotshena then add the Egyptian spice and\n";
cout<<"involve not only foreign game modes but also Egyptian games\n";
cout<<"-------------------------------------------------\n";
}
void Basra_Intro()
{
cout<<"Rules:\n";
cout<<"Egyptian Basra:\n";
cout<<"1.1- Cards are Numbers (1->10) and Literals (J,Q,K)\n";
cout<<"1.2- in the starting round, each player draws 4 random cards and field has 4 random cards too.\n";
cout<<"1.3- in your turn you play a card to field, you take all field cards that have\n";
cout<<"same card number as yours or those who sums up to it and bank them as a score.\n";
cout<<"example: 10 = 4+3+2+1 = 5+4+1 = 5+3+2 = 6+3+1 = 7+2+1 = 8+2 =....\n";
cout<<"1.4- the \"J\" card is called \"Jack\" -El Wallad- has the ability to take\n";
cout<<"all cards on field as score, in case field is not empty.\n";
cout<<"1.5- When deck and hand cards end, player with most score wins\n";
cout<<"Press Enter to Continue Playing Game....";
}