//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number: 18
//Team: Asghar Mahmood b6005405, Claire Smith b6008661, Sam Simaei b5038121, Deepak Jindal b6019531 ALL SOFTWARE ENGINEERING


#include "CurrentAcount.h"

// implicitly call the bank account constructor
CurrentAccount::CurrentAccount() : BankAccount(), overdraftLimit_(0.0)
{}

//explicitly call the bank account constructor
CurrentAccount::CurrentAccount(const string& acctNum, 
		const TransactionList& transList, 
		const Date& cd, const double balance, const double overdraftLimit) 
		: BankAccount(acctNum, transList, cd, balance), overdraftLimit_(overdraftLimit)
{}


CurrentAccount::~CurrentAccount()  
{}

double CurrentAccount::getOverdraftLimit() const
{
	return overdraftLimit_;
}

ostream& CurrentAccount::putAccountDetailsInStream(ostream& os) const {
	//put (unformatted) BankAccount details in stream
	BankAccount::putAccountDetailsInStream(os);
	os << overdraftLimit_ << "\n";				//put overdraft limit (accessible in this class)
	return os;
}


istream& CurrentAccount::getAccountDataFromStream(istream& is) {
	//get BankAccount details from stream by calling its version
	BankAccount::getAccountDataFromStream(is);
	// store overdraft limit from the stream
	is >> overdraftLimit_;
	return is;
}

double CurrentAccount::maxBorrowable() const
{
	// returns what is available to borrow
	return getBalance() + overdraftLimit_;
}

bool CurrentAccount::canWithdraw(double amount) const
{
	return amount <= maxBorrowable();
}

const string CurrentAccount::prepareFormattedAccountDetails() const
{
	// get the account type based on the first character of the account number
	assert(getAccountType(getAccountNumber()[0]) != "UNKNOWN");
	ostringstream os;

	os << BankAccount::prepareFormattedAccountDetails();
	os << "\n      OVERDRAFT LIMIT:         \234" << setw(10) << overdraftLimit_;
	os << "\n      ----------------------------------------";
	return os.str();
}

const bool CurrentAccount::canTransferOut(double amount) const
{
	// checking if transfer results in balance lower than the overdraft limit
	return ((amount >= 0.0) && ((getBalance() - amount) >= -overdraftLimit_));
}

