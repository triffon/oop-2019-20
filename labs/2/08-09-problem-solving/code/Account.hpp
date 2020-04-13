#pragma once
#include "Vector.hpp"
#include "Pair.hpp"
#include "Ticket.hpp"
#include "Account.hpp"

class Account
{
public:
    Account(const char* nickname = "unnamed", double startingMoney = 0);
    Account(const Account& other);
    Account& operator=(const Account& other);
    ~Account();

    void addMoney(double money);
    void withdrawMoney(double money);
    inline double getMoney() const { return m_money; }
    inline const char* getNickname() const { return m_nickname; }

private:
    void copy(const Account& other);
    void clear();

    using ticketPair_t = Pair<Ticket, unsigned short>;

    char* m_nickname;
    double m_money;
    Vector<ticketPair_t> m_tickets;
};
