
#include "Profile.h"

#include <iostream>
#include <cstring>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include "Math.h"
#include <cctype> 
 #include <cstring> 
 #include <cstdlib>
 #include <ctime>


using namespace std;
void welcomeScreen ();
void generateProblem (Math &math, int menuSelect, Profile &profile);
void userName(char *&input);
void validateUserInput(char *&UserInput);
void checkData(Profile &profile, string name);
void Menu();
int menuSelection(char *UserInput);
void checkAnswer (int &answer);
void saveStats(Profile profile, string name);
int const INPUT_SIZE = 100;

int main()
{	
	Math math;
	Profile profile;
	char *name = nullptr;
	char *UserInput= nullptr;
	UserInput = new char[INPUT_SIZE];
	int selection =0;
	welcomeScreen();
	userName(name);
	string user = name;
	checkData(profile,user);
	int menuSelect =0;
	
	do
	{
		
	

		Menu();
		validateUserInput(UserInput);
		menuSelect =menuSelection(UserInput);	
		if (menuSelect ==5) {
			
			cout << name << endl;
			cout << profile;
		}
		else if(menuSelect >0 && menuSelect<5) {
		
		generateProblem(math, menuSelect, profile);
	}
	
	
	
	
	} while (toupper(*UserInput)!= 'N' );
	  saveStats(profile, user);

	cout << "BYE\n";


	delete[] name;
	delete[] UserInput;
	
	return 0;
}

void welcomeScreen (){
	


cout << "(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)" << endl;
cout << "(*)(*)(*) Nathaniel Suarez (*)(*)" << endl;
cout << "(*)(*)(*)(*)  Math Game (*)(*)(*)" << endl;
cout << "(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)" << endl;
cout << "(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)" << endl;
system("pause");
system("CLS");

	
	
}

void userName(char *&input)
{
	bool isEnter = false;
	int counter = 0;
	char streamChar;
	char *TempPtr = nullptr;
	int strLength=0;
	delete[] input;
	input = new char[1];
	int counter2=0;
	cout << "Enter a Name."  << endl;
	while (isEnter == false)
	{
		cin.get(streamChar);
		
		if (streamChar == '\n')
		{
			isEnter = true;
			input[counter] = '\0';
		}
	
		else
		{
			TempPtr = new char[counter + 1];
			strncpy(TempPtr, input, counter);
			TempPtr[counter] = streamChar;
			
			delete[] input;
			input = new char[counter + 2];
			strncpy(input, TempPtr, counter + 1);
		
			delete[] TempPtr;
		
			counter++;
		}
		
	}
		 strLength = strlen(input);
	

	while (strLength ==0 ||input[counter2]!= '\0') {

		if (!isalpha(input[counter2])) {
			cout << "invalid reenter " << endl;
			userName(input);
			counter2=0;
		}
		else {
			counter2++;
	
		}
		
		
		
		
	}

	system("CLS");

}


void validateUserInput(char *&UserInput){ //

bool validInput = false;
	int counter =0;
	cout << " enter an option" << endl;
	
cin.getline(UserInput, INPUT_SIZE);

	int strLength=strlen(UserInput);
	UserInput[strLength] = '\0';
	
	while (validInput==false || strLength ==0) {
		if ((UserInput[0] =='N' || UserInput[0] =='n' 
			|| UserInput[0] == '1' ||
				UserInput[0] == '2' || UserInput[0] == '3' ||
				UserInput[0] == '4' || UserInput[0] =='5') && UserInput[1] == '\0'
		 ) { 
			validInput =true;
				
			
		}
		
	
			
		else { 
				cout << "not a valid digit" << endl;
				
				cin.getline(UserInput, INPUT_SIZE);
			
				strLength=strlen(UserInput);
					UserInput[strLength] = '\0';
		}
		
}
		
	
	system("CLS");
	
}

void Menu() { // menu
	
	
	cout << "1. Add" << endl;
	cout << "2. Subtract" << endl;
	cout << "3. Multiply" << endl;
	cout << "4. Division" << endl;
	cout << "5.  Stats" << endl;
	cout << " N or n to quit";
	
	
	
}

void checkAnswer (int &answer) { //checks answer
	
	string input;
	getline(cin, input);
    
    int inputLength = input.length();
   
    int counter = 0;
    while (counter < inputLength  || inputLength ==0 ) {
      
      
         if (!isdigit(input[counter])  ) {
              
            cout << "Not a valid digit\n";
            getline(cin, input);
            counter = 0;
            inputLength = input.length();
              
         }
         else {counter++;}
                    
     }
 
    istringstream (input) >> answer;
   
	
}

void checkData(Profile &profile ,string name) {  // opens up data
	
	name += ".txt";

	string right;
	string wrong ;
	
	fstream dataFile;
	string x;
	int convert;
	int convert2=0;
		dataFile.open(name, ios::in | ios::app);
			
		getline(dataFile, x, ' '  );
		getline(dataFile, right, ' '  );
		getline(dataFile,wrong);  
		dataFile.close();


	 	istringstream (right) >> convert;
		istringstream (wrong) >> convert2;
		profile.importStats(convert,convert2);
	
}

int menuSelection(char *UserInput) { //converts to int for menu
			int selection=0;
		if (UserInput[0] == '1') {
			return 1;
		}
		
		else if (UserInput[0] == '2') {
			return 2;
		}
	
		else if (UserInput[0] =='3') {
			return 3;
			
		}
	
		else if (UserInput[0] == '4') {
			
			return 4;
		}
		
		else if (UserInput[0] =='5') {
			return 5;	
		
		
	}
	
	else {
		return 0;
	}

	
	
	
	
}

void generateProblem (Math &math, int menuSelect, Profile &profile) {
	bool answerCheck =0;
	int answer =0;
	srand ( time(NULL) );
    int randomNumber1=rand() % 10 + 0;
    int randomNumber2=rand() % 10 + 0;
		math.importRand(randomNumber1,randomNumber2);
		
		math.generateProblemType(menuSelect);
		checkAnswer(answer);
		
		answerCheck =math.checkAnswer(answer);
		system("CLS");	
	if (answerCheck == true) {
		profile.addRight();
		cout << "RIGHT"<< endl;
	}
	else {
		profile.addWrong();
		cout << "WRONG" << endl;
		
	}
	
}

void saveStats(Profile profile, string name) {
	
	string txt =name +".txt";
int r = profile.getRight();
int w = profile.getWrong();
double t = profile.getTotal();
fstream dataFile;
 dataFile.open(txt, ios::out); // Open for output

 dataFile << name << ' '; // save name
dataFile << r << ' '; // save #right
 dataFile << w << ' '; // save # wrong
dataFile << t << ' ';  // save total
 dataFile.close();
	
	
	
	
	
	
}