#include <iostream>
#include <string>
#include <cstring>
#include "University.hpp"

using std::string;
using std::cin;
using std::cout;
using std::endl;

const size_t University::STARTING_FAC_NUM = 10000;
const size_t MAX_CMD_LEN  = 1024;

University::University()
    : currFacNum(STARTING_FAC_NUM)
{}


void displayHelp()
{
    cout << " -------------- Commands -------------" << endl
         << "  addStudent <name> <age> [specialty]" << endl
         << "  addTeacher <name> <age> <subject>" << endl
         << "  info       <name>" << endl
         << "  teach      <teacher> <student>" << endl
         << "  quit" << endl;
}


void University::run()
{
    displayHelp();
    string cmd;

    do {

        cout << endl << "> ";
        cin >> cmd;

        if (cmd.compare("addStudent") == 0) {

            string name, spec;
            size_t age;

            cin >> name >> age;
            getline(cin, spec);

            Student st(name, age, getNextFN());
            if (spec.length() > 0)
                st.setSpecialty(spec.c_str() + 1);

            m_students.push_back(st);

            cout << "Added student: " << m_students.back().getName()
                 << ", FN: " << m_students.back().getFacultyNum() << endl;

        } else if (cmd.compare("addTeacher") == 0) {

            string name, subj;
            size_t age;

            cin >> name >> age;
            cin.ignore();
            getline(cin, subj);

            m_teachers.push_back({ name, age, subj });

            cout << "Added teacher: " << m_teachers.back().getName()
                 << " teaching " << m_teachers.back().getSubject() << endl;

        } else if (cmd.compare("info") == 0) {
            
            string name;
            cin.ignore();
            getline(cin, name);

            int id = getStudentIndex(name);
            if (id != -1) {
                m_students[id].print();
                cout << endl;
                continue;
            }

            id = getTeacherIndex(name);
            if (id != -1) {
                m_teachers[id].print();
                cout << endl;
                continue;
            }

            cout << "No person with the name " << name << " found!" << endl;

        } else if (cmd.compare("teach") == 0) {

            string teachName, stName;
            cin >> teachName >> stName;

            int tId = getTeacherIndex(teachName);
            if (tId == -1) {
                cout << "No teacher with the name " << teachName << " found" << endl;
                continue;
            }

            int sId = getStudentIndex(stName);
            if (sId == -1) {
                cout << "No student with the name " << stName << " found" << endl;
                continue;
            }

            cout << teachName << " taught " << stName << " " << m_teachers[tId].getSubject() << endl;
            m_teachers[tId].teach(m_students[sId]);

        } else if (cmd.compare("help") == 0) {

            displayHelp();

        }  else if (cmd.compare("quit") == 0) {

            cout << "Bye!" << endl;

        } else {

            cout << "Unknown command! Type help for more info." << endl;
            cin.ignore(MAX_CMD_LEN, '\n');

        }

    } while (cmd.compare("quit") != 0);
}


size_t University::getNextFN()
{
    return currFacNum++;
}


int University::getTeacherIndex(const string& name) const
{
    for (size_t i = 0; i < m_teachers.size(); i++)
        if (m_teachers[i].getName().compare(name) == 0)
            return i;
    
    return -1;
}


int University::getStudentIndex(const string& name) const
{
    for (size_t i = 0; i < m_students.size(); i++)
        if (m_students[i].getName().compare(name) == 0)
            return i;
    
    return -1;
}
