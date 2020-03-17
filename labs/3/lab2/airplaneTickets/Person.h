//
// Created by tony on 17.03.20 г..
//

#ifndef FMIOOP_PERSON_H
#define FMIOOP_PERSON_H


class Person {
    char firstName[20];
    char surname[20];
    char familyName[20];
    int egn;
    int age;

public:
    const char *getFirstName() const;

    const char *getSurname() const;

    const char *getFamilyName() const;

    int getEgn() const;

    int getAge() const;

    void setFirstName(const char *firstName);

    void setSurname(const char *surname);

    void setFamilyName(const char *familyName);

    void setEgn(int egn);

    void setAge(int age);
};


#endif //FMIOOP_PERSON_H
