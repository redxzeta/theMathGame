#ifndef PROFILE_H
#define PROFILE_H

#include <iostream> 
#include <cstdlib>
class Profile;
using namespace std;
 ostream &operator <<(ostream & someStream, const Profile & someProfile);
class Profile
{
	public:
			Profile();	
		Profile(int r, int w, double t);
		

	int addRight();
	int addWrong();
	
	void importStats(int r, int w, double t);	

	int getRight() const;
	int getWrong() const;
	double getTotal() const;
		
		
	friend ostream &operator <<(ostream &, const Profile &);
	
	private:
	int right;
		int wrong;
		double total;
			
	
};


#endif
