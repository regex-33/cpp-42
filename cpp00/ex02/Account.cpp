#include "Account.hpp"



Account::Account(): _accountIndex(0), _amount(0), _nbDeposits(0), _nbWithdrawals(0) {}
Account::~Account(){}
Account::Account(int initial_deposit) : _accountIndex(0), _amount(0), _nbDeposits(initial_deposit), _nbWithdrawals(0) {}

int Account::getTotalAmount()
{
    return _totalAmount;
}

int Account::getNbAccounts()
{
    return _totalNbDeposits;
}

int Account::getNbDeposits()
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
    return _totalNbWithdrawals;
}






static std::string _getFormattedTimestamp()
{
    // Get the current time
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    // Convert the current time to a string representation
    std::stringstream ss;
    ss << std::put_time(std::localtime(&currentTime), "%Y%m%d_%H%M%S");
    return ss.str();
}

static void _displayLineOutput(int index, int amount)
{
    std::string timestamp = _getFormattedTimestamp();
    std::cout << "[" << timestamp << "] index:" << index << ";amount:" << amount << ";created" << std::endl;
}


void Account::_displayTimestamp()
{
     std::string timestamp = _getFormattedTimestamp();
     std::cout << "[" << timestamp << "]"; 
}



// void Account::displayStatus(void)const
// {
//     _displayLineOutput()
// }