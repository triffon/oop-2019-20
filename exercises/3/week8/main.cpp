#include <iostream>
#include <fstream>
#include "Student.h"
using namespace std;
void binaryFileWriteDemo(Student * arr, int arrSize){
    /// We write the data in blocks with specific size by 1:1 copies
    ofstream fout("students.bin", ios::out | ios::binary);
    fout.write((const char *)&arrSize,sizeof(int));
    for(int i=0;i<arrSize;i++){
        fout.write((const char *)&arr[i],sizeof(Student));
    }
    fout.close();
}
void binaryFileReadDemo(Student *& arr, int& arrSize){
    /// can read at a random position because the data is with fixed block size
    ifstream fin ("students.bin", ios::in | ios::binary);
    fin.read((char *)&arrSize,sizeof(int));
    arr = new Student[arrSize];
    /// reading the third student directly
    Student temp;
    fin.seekg(4+sizeof(Student)*2,ios::beg);
    fin.read((char *)&temp,sizeof(Student));
    cout << temp;

    for(int i=0;i<arrSize;i++){
        fin.read((char *)&arr[i],sizeof(Student));
    }

    fin.close();
}
void textFileWriteDemo(Student * arr, int arrSize){
    /// We try to write the data represented as a human readable text
    /// Very cool because we can edit the data without having a program
    ofstream fout("students.txt", ios::out);
    fout << arrSize << endl;
    for(int i=0;i<arrSize;i++){
        fout << arr[i];
    }
    fout.close();
}
void textFileReadDemo(Student *& arr, int& arrSize){
    /// we have to read consequently every data record (Student)
    ifstream fin ("students.txt", ios::in);
    fin >> arrSize;
    arr = new Student[arrSize];
    for(int i=0;i<arrSize;i++){
        fin >> arr[i];
    }
    fin.close();
}
void print(Student* arr, int n){
    for(int i=0;i<n;i++){
        cout << arr[i];
    }
}

void readFromConsole(Student *& arr, int& n){
    cin >> n;
    arr = new Student[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
}

int main()
{
    Student * arr;
    int n;
    /// readFromConsole(arr,n);
    /// text file
    /// textFileWriteDemo(arr,n);
    /// textFileReadDemo(arr,n);
    /// binary file
    /// binaryFileWriteDemo(arr,n);
    binaryFileReadDemo(arr,n);

    /// print(arr,n);
    return 0;
}
