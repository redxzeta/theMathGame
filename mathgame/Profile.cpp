#include "Profile.h"
#include <iostream> 
#include <iomanip>
#include <cstdlib>

using namespace std;

Profile::Profile()
{	
	total =0;
    right =0.;
    wrong =0;
}

Profile::Profile(int r, int w, double t)
{
    right = r; wrong =w;
    total =t;
}


int Profile :: addRight() {
	
	return right++;
	
}
int Profile :: addWrong() {
	
	return wrong++;
	
}


int Profile::getRight() const
{	
    return right;
}

int Profile ::getWrong() const
{
	
	return wrong;
	
} 
void Profile :: importStats(int r, int w , double t) {
	
	right = r;
	wrong = w;
	total = t;
	
}

double Profile ::getTotal() const
{
	
	 
	 return right*0.05-wrong*0.03;
	
	
	
}

ostream &operator <<(ostream & someStream, const Profile & someProfile)
{
    someStream <<"Total Correct: "<< someProfile.getRight() << endl 
    << "Total Wrong: " << someProfile.getWrong() << endl<< fixed << showpoint << setprecision(2)
    << "Total Amount: " << someProfile.getTotal() << endl;
    system("pause"); system("CLS");
    return someStream;
}
