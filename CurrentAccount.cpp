#include "CurrentAcount.h"

// implicitly call the bank account constructor
CurrentAccount::CurrentAccount(const double overdraftLimit) : overdraftLimit_(overdraftLimit)
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
	os << getAccountNumber() << "\n";			//put account number
	os << getCreationDate() << "\n";			//put creation date
	os << getBalance() << "\n";					//put balance
	os << overdraftLimit_ << "\n";				//put overdraft limit (accessible in this class)
	return os;
}


//istream& CurrentAccount::getAccountDataFromStream(istream& is) {
//	//get BankAccount details from stream
//	is >> getAccountNumber();					//get account number
//	is >> getCreationDate();					//get creation date
//	is >> getBalance();							//get balance
//	is >> overdraftLimit_;						//get overdraft limit
//	return is;
//}



const string CurrentAccount::prepareFormattedAccountDetails() const
{
	// get the account type based on the first character of the account number
	assert(getAccountType(getAccountNumber()[0]) != "UNKNOWN");
	ostringstream os;

	os << "\n      ACCOUNT TYPE:    " << getAccountType(getAccountNumber()[0]) << " ACCOUNT";
	os << "\n      ACCOUNT NUMBER:  " << getAccountNumber();
	os << "\n      CREATION DATE:   " << getCreationDate().toFormattedString();
	os << fixed << setprecision(2)	<< setfill(' ');
	os << "\n      BALANCE:         \234" << setw(10) << getBalance();;
	os << "\n      OVERDRAFT LIMIT:         \234" << setw(10) << overdraftLimit_;
	os << "\n      ----------------------------------------";
	return os.str();
}

const bool CurrentAccount::canTransferOut(double amount) const
{
	// checking if transfer results in balance lower than the overdraft limit
	return ((amount >= 0) && ((getBalance() - amount) >= overdraftLimit_));
}

