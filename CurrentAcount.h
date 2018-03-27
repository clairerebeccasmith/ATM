#ifndef CurrentAccountH
#define CurrentAccountH

#include "BankAccount.h"

class CurrentAccount : public BankAccount
{
public:
	CurrentAccount(const double overdraftLimit);
	CurrentAccount(const string & acctNum, const TransactionList & transList, const Date & cd, const double balance, const double overdraftLimit);
	~CurrentAccount();
	double getOverdraftLimit() const;

private:
	double overdraftLimit_;
};






#endif // !CurrentAccountH

