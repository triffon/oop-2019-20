#include <iostream>
#include <fstream>
#include <cstring>

struct Human{
    char name[30];
    int age = 18;

    Human(){};
    Human(const char name[], const int age){
        strcpy(this->name, name);
        this->age = age;
    }
};

struct Human1{
    char* name;
    int age;

    Human1(){
        name == nullptr;
        age = 0;
    }
    Human1(const char* name, const int age){
        int len = strlen(name);
        this->name = new char[len + 1];
        strcpy(this->name, name);
        this->age = age;
    }
};

int main() {
    /*std::string temp;
    //ios::in, ios::out, ios::binary, ios::ate, ios::app, ios::trunc
    std::ofstream test("../test1.txt");
    if(test.is_open()){
        test << "First line";
        test.seekp(0);
        test << "Second line";
    }
    test.close();


    std::ifstream read("../test1.txt");
    if(read.is_open()){
        while(!read.eof()){
            read >> temp;
            std::cout << temp;
        }
    }

    read.seekg(4, std::ios::end);

    read.seekg(1);
    read.close();*/
    //Начин за четене от файл със зададена дължина
    /*std::ifstream myFile("../test1.txt");
    if(!myFile){
        return 0;
    }
    int size;
    char* temp;
    myFile >> size;
    temp = new char[size + 1];
    myFile.get();

    int i = 0;
    while (myFile.good() && !myFile.eof()){
        myFile.get(temp[i++]);
    }
    temp[size] = '\0';
    myFile.close();
    std::cout << temp;*/

    //Записване на масив от обекти (Human) в binary и прочитане след това БЕЗ динамично заделяне.
    /*int size = 3;
    Human* arr = new Human[3];

    arr[0] = Human("Ivan",20);
    arr[1] = Human("Martin",20);
    arr[2] = Human("Rado",20);

    std::ofstream ofile("human.bin", std::ios::binary);
    if (!ofile){
        return 1;
    }
    ofile.write((const char*)& size, sizeof(int));
    ofile.write((const char*)& arr, size * sizeof(Human));
    ofile.close();

    std::ifstream ifile("human.bin", std::ios::binary);
    if(!ifile){
        return 1;
    }
    int sizeForRead;
    ifile.read((char*)& sizeForRead, sizeof(int));
    Human* arr1 = new Human[sizeForRead];
    ifile.read((char*)& arr1, sizeForRead * sizeof(Human));
    ifile.close();

    for(int i = 0; i < sizeForRead; i++){
        std::cout << arr1[i].name;
    }*/

    //Записване на масив от обекти (Human) в binary и прочитане след това СЪС динамично заделяне.


    int size = 3;
    Human1* arr = new Human1[size];

    arr[0] = Human1("Ivan",20);
    arr[1] = Human1("Martin",20);
    arr[2] = Human1("Rado",20);

    std::ofstream ofile("human1.bin", std::ios::binary);

    if(!ofile){
        return 1;
    }

    ofile.write((const char*)&size, sizeof(int));
    for(int i = 0; i < size; i++){
        int len = strlen(arr[i].name);
        ofile.write((const char*)&len, sizeof(int));
        ofile.write((const char*)&arr[i].name, len);
        ofile.write((const char*)&arr[i].age, sizeof(int));
    }
    ofile.close();

    std::ifstream ifile("human1.bin", std::ios::binary);
    if (!ifile){
        return 1;
    }

    int size1;
    ifile.read((char*)&size1, sizeof(int));
    Human1* arr1 = new Human1[size1];
    int temp;
    for(int i = 0; i < size1; i++){
        ifile.read((char*)&temp, sizeof(int));
        arr1[i].name = new char[temp + 1];
        ifile.read((char*)&arr1[i].name, temp);
        arr1[i].name[temp] = '\0';
        ifile.read((char*)& arr[i].age, sizeof(int));
    }

    for(int i = 0; i < size1; i++){
        std::cout << arr1[i].name << arr[i].age;
    }













    return 0;
}
