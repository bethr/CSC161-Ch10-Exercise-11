/* Beth Reel

January 29, 2017

C++ Programming Program Design Including Data Stru...
7th Edition
D.S. Malik

Chapter 10, Exercise 11.
*/
// Implementation file for MemberType


#include <iostream>
#include <iomanip>
#include "MemberType.h"

using namespace std;


// default constructor, just initialize members to valid values


MemberType::MemberType()
{
	memberName = "";
	memberID = "000";
	booksBought = 0;
	amountSpent = 0.0;

}
//          need to work on this later
//constructor with arguments to set all members
MemberType::MemberType(string newType, string newName, int newAge, double newAmount)
{
	setMemberName(newType);
	setMemberID(newName);
	setBooksBought(newAge);
	setAmountSpent(newAmount);
}

//destructor 
MemberType::~MemberType()
{
}


// ******** setters *******



void MemberType::setMemberName(string newName)
{
	memberName = newName;
}
void MemberType::setMemberID(string newMemberID)
{
	memberID = newMemberID;
}
void MemberType::setBooksBought(int newBooks)
{
	booksBought = newBooks; 
}
void MemberType::setAmountSpent(double newAmount)
{
	amountSpent = newAmount;
}



// ***** getters ******



string MemberType::getMemberName() const
{
	return memberName;
}
string MemberType::getMemberID() const
{
	return memberID;
}
int MemberType::getBooksBought() const
{
	return booksBought;
}
double MemberType::getAmountSpent() const
{
	return amountSpent;
}



// ********* other member functions *******

// print all of the information 
void MemberType::printMember()const
{
	cout << setfill(' ') << setw(10) << getMemberName() << setw(15) << getMemberID() << setw(15) << getBooksBought() << setw(15) << getAmountSpent() << endl;
}


//test if the string is the member's ID
bool MemberType::isMemberID(string memID) const
{
	return memberID.compare(memID) == 0;
}
