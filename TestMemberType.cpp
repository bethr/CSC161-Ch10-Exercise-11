/* Beth Reel

January 29, 2017

C++ Programming Program Design Including Data Stru...
7th Edition
D.S. Malik

Chapter 10, Exercise 11. 

In this exercise, you will design a class memberType.

a. Each object of memberType can hold the name of a person, member ID, number of books 
   bought, and amount spent.
b. Include the member functions to perform the various operations on the objects of 
   memberType—for example, modify, set, and show a person’s name. Similarly, update, 
   modify, and show the number of books bought and the amount spent.
c. Add the appropriate constructors.
d. Write the definitions of the member functions of memberType.
e. Write a program to test various operations of your class memberType.

*/
// Test file for MemberType
#include <iomanip>
#include <string>
#include <fstream>
#include <iostream>

#include "MemberType.h"

using namespace std;

// size of our array - how many MEMBERS, max
const int MAX_MEMBERS = 5; 

void getAllMembers(MemberType members[], int& numMembers);

// function to print all of the members
void printAllMembers(MemberType members[], const int numMembers);

// function to print single member
void printOneMember(MemberType members[], const int i, const int numMembers);

// function to find member by ID
int findMemberID(const string memberID, MemberType members[], const int numMembers);



int main()
{

	// local storage
	
	MemberType memberType[MAX_MEMBERS]; // the array of members
	string inputString = "";   // placeholder for input
	int inputInt = 0; 
	double inputDouble = 0; 
	int numMembers = 0; 
	int j = 0; 

	//  read member list from input file

	getAllMembers(memberType, numMembers);

	// print to screen the list of all members

	printAllMembers(memberType, numMembers);


	// ask the user for one of the MEMBER ID'S and print
	cout << "Enter an ID for a member to modify: " << endl;
	cin >> inputString;
	cout << endl;

	int foundMember = findMemberID(inputString, memberType, numMembers);

	if (foundMember != 0) {
		j = foundMember; 
		printOneMember(memberType, j, numMembers); 
	
		cout << "Enter new member name: " << endl;
		cin >> inputString;
		if (inputString != "")
		{
			memberType[j-1].setMemberName(inputString);
		}
		cout << "Enter new Member ID: " << endl;
		cin >> inputString;
		if (inputString != "")
		{
			memberType[j - 1].setMemberID(inputString);
		}
		cout << "Enter new # books bought: " << endl;
		cin >> inputInt;
		if (inputInt != 0)
		{
			memberType[j - 1].setBooksBought(inputInt);
		}
		cout << "Enter new amount spent: " << endl;
		cin >> inputDouble;
		if (inputDouble != 0)
		{
			memberType[j - 1].setAmountSpent(inputDouble);
		}
		// printOneMember(memberType, j, numMembers);
		printAllMembers(memberType, numMembers);
	}
	else {
		cout << "No member found by that member ID" << endl;
	}

	return 0;
}


// get sample members from the text file
void getAllMembers(MemberType members[], int& count)
{
	string memberName, memberID;
	int books;
	double amount;
	count = 0;
	ifstream inFile; // input file stream variable
	inFile.open("MemberFile.txt");
	                                                     
	while (inFile && count < MAX_MEMBERS) {

		// read in the member info
		inFile >> memberName >> memberID >> books >> amount;
		
		// create a new member object and store it in the array
		members[count] = MemberType(memberName, memberID, books, amount);

		if (inFile) count++;
	}
  
	inFile.close();
	return;
}

// print out all of the members 
void printAllMembers(MemberType members[], const int count)
{
	// print a header 
	cout << "All Members:" << endl;
	cout << setw(10) << "Name" << setw(15) << "Member ID" << setw(15) << "Books Bought" << setw(15) << "Amount Spent" << endl;
	cout << setw(55) << setfill('=') << "=" << endl;

	// print a row for each member
	for (int i = 0; i < count; i++) {
		members[i].printMember();
	}
}


void printOneMember(MemberType members[], const int j, const int count)
{
	cout << setw(10) << "Name" << setw(15) << "Member ID" << setw(15) << "Books Bought" << setw(15) << "Amount Spent" << endl;
	cout << setw(35) << setfill('=') << "=" << endl;
	members[j-1].printMember();
}
 

// find member given its ID
int findMemberID(const string memberID, MemberType members[], const int count)
{

	// look through each member  name; if found, print the corresponding type
	for (int i = 0; i < count; i++) {
		
		if (members[i].isMemberID(memberID)) {

			return i+1; 
		}
	}
	return 0;
}

