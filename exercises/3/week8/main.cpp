#include <iostream>
#include <fstream>
#include "Student.h"
using namespace std;
void binaryFileWriteDemo(Student * arr, int arrSize){
    /// We write the data in blocks with specific size by 1:1 copies
    ofstream fout("students.bin", ios::out | ios::binary);
    fout.close();
}
void binaryFileReadDemo(){
    /// can read at a random position because the data is with fixed block size
    ifstream fin ("students.bin", ios::in | ios:binary);
    fin.close();
}
void textFileWriteDemo(Student * arr, int arrSize){
    /// We try to write the data represented as a human readable text
    /// Very cool because we can edit the data without having a program
    ofstream fout("students.txt", ios::out);
    fout.close();
}
viud textFileReadDemo(){
    /// we have to read consequently every data record (Student)
    ifstream fin ("students.txt", ios::in);
    fin.close();
}
int main()
{
    int n;
    cin >> n;
    Student * arr = new Student[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        cout << arr[i];
    }
    /// text file
    textFileWriteDemo();
    textFileReadDemo();
    /// binary file
    binaryFileWriteDemo();
    binaryFileReadDemo();
    return 0;
}
