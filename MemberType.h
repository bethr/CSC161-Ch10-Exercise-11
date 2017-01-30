/* Beth Reel

January 29, 2017

C++ Programming Program Design Including Data Stru...
7th Edition
D.S. Malik

Chapter 10, Exercise 11.
*/
// Header file for MemberType

#include <string>

using namespace std;

class MemberType {

public:
	// constructors & destructors 
	MemberType();
	MemberType(string memberName, string memberID, int booksBought, double amountSpent);
	~MemberType();

	//setters
	void setMemberName(string);
	void setMemberID(string);
	void setBooksBought(int);
	void setAmountSpent(double);

	//getters
	string getMemberName() const; 
	string getMemberID() const;
	int getBooksBought() const;
    double getAmountSpent() const;

	//other member functions
	//print out the entire get information in a nice format 
	void printMember() const;

	// test if the memberID given matches this member
	bool isMemberID(string memberID) const;

private:
	string memberName;
	string memberID;
	int booksBought;
	double amountSpent;

};

