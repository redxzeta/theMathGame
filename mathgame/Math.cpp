#include "Math.h"
#include <cstdlib> 
#include <ctime>
#include "Profile.h"

using namespace std;


Math::Math()
{
	answer =0;
    randomNumber1= 0;
    randomNumber2=0;
}

Math::Math(int r1, int r2, int a)
{
	answer =a;
   randomNumber1=r1;
	randomNumber2=r2;
}


void Math :: importRand(int r1, int r2)
{
	randomNumber1=r1;
	randomNumber2=r2;
	
	
	
}

bool Math :: checkAnswer(int userAnswer) {
	bool answerCheck = true;
	if (answer == userAnswer) {
		return answerCheck = true;
		
	}
	else {
	
		return answerCheck = false;
	}
	
	
	
}

void Math :: generateProblemType(int selection)
{

	string type;
	if ( selection ==1) {
		answer = randomNumber1 +randomNumber2;
		type = "+";
		cout << "Addition";
	}
	else if (selection ==2 ) {
		while(randomNumber2>randomNumber1) {
			randomNumber2--;
		}
		answer = randomNumber1 -randomNumber2;
		type ="-";
		cout << "Subtractioni";
	}
	
	else if (selection ==3) {
		answer = randomNumber1 * randomNumber2;
		type = "*";
		cout << "Multiplication";
	}
	
	else  {
		cout << "Division";
		randomNumber1=(randomNumber1 * randomNumber2);
		answer = (randomNumber1 * randomNumber2) / randomNumber2;
		type ="/";
	}
	cout << endl << randomNumber1 << " " << type << " " << randomNumber2 << " = " << endl;

	

}


