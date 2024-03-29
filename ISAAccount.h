//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number: 18
//Team: Asghar Mahmood b6005405, Claire Smith b6008661, Sam Simaei b5038121, Deepak Jindal b6019531 ALL SOFTWARE ENGINEERING


#ifndef ISAAccountH
#define ISAAccountH

#include "SavingsAccount.h"

class ISAAccount : public SavingsAccount
{
public:

	ISAAccount();
	// constructors and destructors
	ISAAccount(const string & acctNum, const TransactionList & transList,
		const Date & cd, const double balance, const double minimumBalance,
		const double maxYearlyDeposit, const double currentYearlyDeposit,
		const Date& endDepositPeriod);
	~ISAAccount();

	// accessors
	double getMaximumYearlyDeposit() const;
	double getCurrentYearlyDeposit() const;
	Date getEndDepositPeriod() const;

	// mutators
	void updateCurrentYearlyDeposit(const double yearlyDeposit);

	// virtual functions
	virtual ostream& putAccountDetailsInStream(ostream& os) const;
	virtual istream& getAccountDataFromStream(istream& is);
	virtual const string prepareFormattedAccountDetails() const;
	virtual bool canTransferIn(double amount) const;
	virtual void recordTransferIn(double amount, const string & activeAccountNum); // to update yearly deposit
	virtual void recordDeposit(double amount);
	virtual bool canWithdraw(double amount) const;
	virtual double maxBorrowable() const;

private:
	double maximumYearlyDeposit_, currentYearlyDeposit_;
	Date endDepositPeriod_;
};







#endif // !ISAAccountH
