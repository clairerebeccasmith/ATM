//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number: 18
//Team: Asghar Mahmood b6005405, Claire Smith b6008661, Sam Simaei b5038121, Deepak Jindal b6019531 ALL SOFTWARE ENGINEERING

#ifndef TransactionListH
#define TransactionListH

//---------------------------------------------------------------------------
//TransactionList: class declaration
//---------------------------------------------------------------------------

//#include "ListT.h"
#include <list> // STL Container
#include "Transaction.h"

#include <cassert> 	// for assert()
#include <sstream>

class TransactionList {
public:
    void   addNewTransaction(const Transaction&);
    const Transaction newestTransaction() const;
    const  TransactionList olderTransactions() const;
    TransactionList getTransactionsUpToDate(const Date& date) const; 
	TransactionList getTransactionsUpToDate(const Date& date, TransactionList trlistToTraverse) const; // recursive version
    TransactionList getTransactionsForAmount(double amount) const;
    TransactionList getTransactionsForTitle(const string& searchString) const;
    TransactionList getTransactionsForDate(const Date& date) const;
    void   deleteFirstTransaction();
    void   deleteTransactionsUpToDate(const Date& date);
    void   deleteGivenTransaction(const Transaction&);
    int    size() const;
    TransactionList getMostRecentTransactions(int number) const;
	double getTotalTransactions() const;
	const string toFormattedString() const;		//return transactionlist as a (formatted) string
	ostream& putDataInStream(ostream& os) const;	//send TransactionList info into an output stream
	istream& getDataFromStream(istream& is);	//receive TransactionList info from an input stream

	TransactionList & operator+=(TransactionList trList);

private:
    list<Transaction> listOfTransactions_;	//list of transactions
};

//---------------------------------------------------------------------------
//non-member operator functions
//---------------------------------------------------------------------------

ostream& operator<<(ostream&, const TransactionList&);	//insertion operator
istream& operator>>(istream& is, TransactionList& trl); //extraction operator

#endif

