#include "Account.hpp"
#include <cstring>

Account::Account(const char* nickname, double money)
    : m_nickname(new char[strlen(nickname) + 1])
    , m_money(money)
{
    strcpy(m_nickname, nickname);
}


Account::Account(const Account& other)
{
    copy(other);
}


Account& Account::operator=(const Account& other)
{
    if (this != &other) {
        clear();
        copy(other);
    }
    return *this;
}


Account::~Account()
{
    clear();
}


void Account::copy(const Account& other)
{
    m_nickname = new char[strlen(other.m_nickname) + 1];
    strcpy(m_nickname, other.m_nickname);
    m_money = other.m_money;
    m_tickets = other.m_tickets;  // Added after the practice
}


void Account::clear()
{
    delete[] m_nickname;
    m_nickname = nullptr;
}


void Account::addMoney(double money)
{
    if (money > 0) {
        m_money += money;
    }
}


void Account::withdrawMoney(double money)
{
    if (money > 0 && m_money - money > 0) {
        m_money -= money;
    }
}
