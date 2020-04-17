#include "System.hpp"
#include <fstream>
#include <cstring>

const char*  SAVE_FILE_NAME = "system.bin";
const size_t MAX_INPUT_LEN  = 128;

System::System()
{}


System& System::i()
{
    static System sys;
    return sys;
}


System::~System()
{
    for (size_t i = 0; i < events.size(); i++)
        delete events[i];
}


bool System::createAccount(const Account& acc)
{
    if (getAcc(acc.getNickname()) == nullptr) {
        accs.push_back(acc);
        return true;
    }
    
    return false;
}


bool System::createEvent(const Event& event)
{
    if (getEv(event.getName()) == nullptr) {
        events.push_back(new Event(event));
        return true;
    }

    return false;
}


bool System::buyTicket(const char* accName, const char* eventName, size_t count)
{
    Event* event = getEv(eventName);
    Account* acc = getAcc(accName);

    if (event == nullptr) {
        std::cout << "Event " << eventName << " not found!" << std::endl;
        return false;
    }

    if (acc == nullptr) {
        std::cout << "Account " << accName << " not found!" << std::endl;
        return false;
    }

    if (acc->getMoney() < event->getPrice() * count) {
        std::cout << "Account " << accName << " doesn't have enough funds!" << std::endl;
        return false;
    }

    acc->withdrawMoney(event->getPrice() * count);
    acc->addTicket(Ticket(event->getPrice(), event), count);

    return true;
}


bool byPriceAsc(Event* ev1, Event* ev2)
{
    return ev1->getPrice() < ev2->getPrice();
}


void System::displayEvents(Order order)
{
    switch (order) {
        case PRICE_ASC: {
            events.sort(byPriceAsc);
            break;
        }

        case PRICE_DESC: {
            events.sort( [](Event* ev1, Event* ev2) { return ev1->getPrice() > ev2->getPrice(); } );
            break;
        }
        
        default: {
        case MOST_RECENT: {
            events.sort( [](Event* ev1, Event* ev2) { return ev1->getDate() > ev2->getDate(); } );
            break;
        }}

        case LEAST_RECENT: {
            events.sort( [](Event* ev1, Event* ev2) { return ev1->getDate() < ev2->getDateww(); } );
            break;
        }
    }

    for (size_t i = 0; i < events.size(); i++)
        std::cout << *events[i];
}


void System::run()
{
    if (deserialize())
        std::cout << "Successfully loaded " << accs.size() << " account(s) and " << events.size() << " event(s)." << std::endl;
    else
        std::cout << "No previous system information." << std::endl;
    
    displayHelp();

    char command[MAX_INPUT_LEN];
    char name[MAX_INPUT_LEN];
    do {

        std::cout << "> ";
        std::cin >> command;

        if (strcmp(command, "help") == 0) {
            displayHelp();
        }

        else if (strcmp(command, "create_acc") == 0) {
            char moneyStr[MAX_INPUT_LEN];
            std::cin >> name;
            std::cin.getline(moneyStr, MAX_INPUT_LEN);
            if (createAccount({ name, atof(moneyStr) }))
                std::cout << "Account " << name << " created." << std::endl;
            else
                std::cout << "Account " << name << " already exists!" << std::endl;
        }

        else if (strcmp(command, "create_ev") == 0) {
            int day, month, year, hour, minute;
            size_t seats;
            double price;
            std::cin >> name >> day;
            std::cin.get(); // get the '/'
            std::cin >> month;
            std::cin.get(); // get the '/'
            std::cin >> year >> hour;
            std::cin.get(); // get the ':'
            std::cin >> minute >> seats >> price;

            // Using the standard c++ time struct
            tm date = {};
            date.tm_year = year - 1900;
            date.tm_mon = month - 1;
            date.tm_mday = day;
            date.tm_hour = hour - 1;
            date.tm_min = minute;

            if (createEvent({ name, mktime(&date), seats, price }))
                std::cout << "Event " << name << " created." << std::endl;
            else
                std::cout << "Event " << name << " already exists!" << std::endl;
        }

        else if (strcmp(command, "buy_ticket") == 0) {
            char evName[MAX_INPUT_LEN];
            char numStr[MAX_INPUT_LEN];
            std::cin >> name >> evName;
            std::cin.getline(numStr, MAX_INPUT_LEN);
            int count = atoi(numStr);
            if (count == 0)
                count = 1;

            if (count > 0) {
                if (buyTicket(name, evName, count))
                    std::cout << name << " successfully bought " << count << " ticket(s) for " << evName << std::endl;
            } else {
                std::cout << "Cannot buy non-positive number of tickets!" << std::endl;
            }
        }

        else if (strcmp(command, "add_money") == 0) {
            double amount;
            std::cin >> name >> amount;
            Account* acc = getAcc(name);
            if (acc) {
                acc->addMoney(amount);
                std::cout << "Successfully added $" << amount << " to " << name << std::endl;
            } else {
                std::cout << "Account " << name << " not found!" << std::endl;
            }
        }

        else if (strcmp(command, "withdraw") == 0) {
            double amount;
            std::cin >> name >> amount;
            Account* acc = getAcc(name);
            if (acc) {
                acc->withdrawMoney(amount);
                std::cout << "Successfully withdrawn $" << amount << " from " << name << std::endl;
            } else {
                std::cout << "Account " << name << " not found!" << std::endl;
            }
        }

        else if (strcmp(command, "events") == 0) {
            char option[MAX_INPUT_LEN];
            char c;
            std::cin.get(c); // get the ' '
            if (c != '\n')
                std::cin.getline(option, MAX_INPUT_LEN);

            Order order = Order::MOST_RECENT;
            if (strcmp(option, "cheapest") == 0)
                order = Order::PRICE_ASC;
            else if (strcmp(option, "most expensive") == 0)
                order = Order::PRICE_DESC;
            else if (strcmp(option, "oldest") == 0)
                order = Order::LEAST_RECENT;

            displayEvents(order);
        }

        else if (strcmp(command, "acc_info") == 0) {
            std::cin >> name;
            Account* res = getAcc(name);
            if (res)
                std::cout << *res << std::endl;
            else
                std::cout << "Account " << name << " not found!" << std::endl;
        }

        else if (strcmp(command, "exit") == 0) {
            if (serialize()) {
                std::cout << "Successfully saved the system information." << std::endl;
            } else {
                std::cout << "Couldn't save the system information! Exit anyway [y/n]? ";
                char option;
                std::cin.ignore(MAX_INPUT_LEN, '\n');
                std::cin.get(option);
                if (option == 'n' || option == 'N')
                    command[0] = '\n';
            }
        }

        else {
            std::cout << "Unknown command! Type 'help' for more information." << std::endl;
        }

    } while (strcmp(command, "exit") != 0);
}


bool System::serialize() const
{
    std::ofstream out(SAVE_FILE_NAME, std::ios::binary);

    if (!out) {
        std::cout << "Cannot open " << SAVE_FILE_NAME << " file for writing!" << std::endl;
        return false;
    }

    size_t len = events.size();
    out.write((const char*) &len, sizeof(len));
    for (size_t i = 0; i < len; i++)
        events[i]->serialize(out);

    len = accs.size();
    out.write((const char*) &len, sizeof(len));
    for (size_t i = 0; i < len; i++)
        accs[i].serialize(out);

    out.close();
    return true;
}


bool System::deserialize()
{
    std::ifstream in(SAVE_FILE_NAME, std::ios::binary);
    if (!in)
        return false;

    size_t len;
    in.read((char*) &len, sizeof(len));
    for (size_t i = 0; i < len; i++)
        events.push_back(new Event(in));

    in.read((char*) &len, sizeof(len));
    for (size_t i = 0; i < len; i++)
        accs.push_back(Account(in));

    in.close();
    return true;
}


Account* System::getAcc(const char* nickname)
{
    for (size_t i = 0; i < accs.size(); i++)
        if (strcmp(nickname, accs[i].getNickname()) == 0)
            return &accs[i];

    return nullptr;
}


Event* System::getEv(const char* name) const
{
    for (size_t i = 0; i < events.size(); i++)
        if (strcmp(name, events[i]->getName()) == 0)
            return events[i];

    return nullptr;
}


void System::displayHelp() const
{
    std::cout 
        << " ------------------ Commands ------------------- - -------------------- Info --------------------" << std::endl
        << "  help       \t\t\t\t\t - displays this message" << std::endl
        << "  create_acc <name> [money]\t\t\t - create an account" << std::endl
        << "  create_ev  <name> <dd/mm/yy hh:mm> <#seats> <price>\t - create an event" << std::endl
        << "  buy_ticket <acc_name> <event_name> [#tickets]\t - buy one or more tickets" << std::endl
        << "  add_money  <acc_name> <amount>\t\t - add money to an account" << std::endl
        << "  withdraw   <acc_name> <amount>\t\t - withdraw money from an account" << std::endl
        << "  events     [order]\t\t\t\t - display events in order { cheapest, most expensive, oldest, newest }" << std::endl
        << "  acc_info   <acc_name>\t\t\t\t - displays info about the account" << std::endl
        << "  exit       \t\t\t\t\t - saves the system and exits the program." << std::endl;
}
