//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number: 18
//Team: Asghar Mahmood b6005405, Claire Smith b6008661, Sam Simaei b5038121, Deepak Jindal b6019531 ALL SOFTWARE ENGINEERING

#ifndef CardH
#define CardH

//---------------------------------------------------------------------------
//Card: class declaration
//---------------------------------------------------------------------------

#include "ListT.h"

#include <fstream>
#include <iomanip>
#include <iostream> 
#include <string>
#include <sstream>
using namespace std;

class Card {
public:
    //constructors & destructor
	Card();
    Card(const string& cardNum, const List<string>& accList);

	//getter (assessor) functions
    const string getCardNumber() const;
    const List<string> getAccountsList() const;

	void readInCardFromFile(const string& fileName);
	bool onCard(const string& fileName) const;

	//functions to put data into and get data from streams
	const string toFormattedString() const;
	ostream& putDataInStream(ostream& os) const;
	istream& getDataFromStream(istream& is);

private:
    string cardNumber_;
    List<string> accountsList_;
};

//---------------------------------------------------------------------------
//non-member operator functions
//---------------------------------------------------------------------------

ostream& operator<<(ostream&, const Card&);	//output operator
istream& operator>>(istream&, Card&);	//input operator

#endif
