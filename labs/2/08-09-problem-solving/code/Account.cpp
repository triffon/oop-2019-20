#include "Account.hpp"
#include <cstring>

Account::Account(std::ifstream& in)
{
    size_t len;
    in.read((char*) &len, sizeof(len));
    m_nickname = new char[len];
    in.read(m_nickname, len);
    in.read((char*) &m_money, sizeof(m_money));
    
    in.read((char*) &len, sizeof(len));
    for (size_t i = 0; i < len; i++) {
        Account::ticketPair_t pair;
        in.read((char*) &pair.second, sizeof(pair.second));
        pair.first = Ticket(in);
        m_tickets.push_back(pair);
    }
}


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
    m_tickets = other.m_tickets;
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


void Account::serialize(std::ofstream& out) const
{
    size_t len = strlen(m_nickname) + 1;
    out.write((const char*) &len, sizeof(len));
    out.write((const char*) m_nickname, len);
    out.write((const char*) &m_money, sizeof(m_money));

    len = m_tickets.size();
    out.write((const char*) &len, sizeof(len));
    for (size_t i = 0; i < len; i++) {
        out.write((const char*) &m_tickets[i].second, sizeof(m_tickets[i].second));
        m_tickets[i].first.serialize(out);
    }
}


void Account::addTicket(const Ticket& ticket, unsigned short numOfTickets)
{
    m_tickets.push_back({ticket, numOfTickets});
}


std::ostream& operator<<(std::ostream& out, const Account& obj)
{
    out << " --- " << obj.m_nickname << " --- " << std::endl
        << "  Funds: $" << obj.m_money << std::endl
        << "  Tickets:" << std::endl;

    for (size_t i = 0; i < obj.m_tickets.size(); i++)
        std::cout << "    " << obj.m_tickets[i].second << "x " << obj.m_tickets[i].first;

    return out;
}
