#ifndef MATH_H
#define MATH_H
#include <iostream> 
#include <ctime>

#include <cstdlib>
class Math;
using namespace std;


class Math
{
	public:
		Math();
		Math(int r1, int r2, int a);
		void importRand(int r1, int r2);
		void generateProblemType(int selection);
		bool checkAnswer( int userAnswer);
	private: 
	int randomNumber1;
	int randomNumber2;
	int answer;
};

#endif
