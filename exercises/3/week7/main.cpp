#include <iostream> /// input output stream
#include <istream> /// input stream
#include <ostream> /// output stream
#include <fstream> /// file stream which has both input and output, includes all of the above, so they are redundant. I added them just for the demo.

using namespace std;

void binaryVsTextFileDemo(){
    int data; /// another buffer for storing data read from the file
    fstream file("BinVsText");
    /// Binary - copies the bytes to the specified location without any conversions
    file.read((char*) &data, sizeof(int));

    cout << hex << data << endl;

    file.seekg(0,ios::beg);
    /// Text - looks at the argument of >> operator and converts the bytes
    file >> data;
    cout << dec << data << endl;
}

void ifstreamDemo()
{
    char buff[5]; /// buffer for storing data read from the file

    /// opens file only for reading
    ifstream fin("input.txt");
    /// ifstream fin("input.txt", ios::in); //same as above
    /// Read function
    /// reads data into a buffer up to size n
    /// good for reading binary data
    fin.read(buff,4);

    cout << "read: " << buff << endl;

    /// reads data into a buffer up to size n-1  or until delimeter is found('\n' by default).
    /// Delimeter is not extracted from the input buffer and appends terminating char '0'
    /// good for reading unformatted plain text data
    fin.get(buff,5);
    cout << "get: " << buff << endl;

    /// reads data into a buffer up to size n-1  or until delimeter is found('\n' by default). Delimeter is extracted from the input buffer and discarded and appends terminating char '0'
    /// Makes an error if delimeter is not found
    /// good for reading unformatted plain text data up to a specific delimeter
    fin.getline(buff,5);
    cout << "getline: " << buff << endl;
    ///tellg/seekg
    ///every input character stream consists of a internal buffer(array) and a current index to get from
    /// tellg - returns the get index
    cout << "tellg(): " << fin.tellg() << endl;
    /// seekg (offest, whence) - changes the get index
    fin.seekg(0,ios::beg); /// possible flags for whence are ios::end, ios::curr and ios::beg, these are public static const data member(you will understand that in the future)
    /// for formatted input we can still use >>
    /// perfect for text input
    fin >> buff;
    cout << buff << endl;
    /// writes contents to buffer if the file has updated since opening it
    fin.sync();

    /// close function, only for file streams
    /// we usually don't need to call it because the destructor automatically calls it
    /// makes the ifstream object free to open another file
    fin.close();
}
void ofstreamDemo(){
    char buff[64]; /// buffer for storing data to be written to the file
    ofstream fout("output.txt");

    cin >> buff;
    /// write just copies the bytes without doing any conversions
    fout.write(buff,4);

    fout.flush(); /// immediately writes contents of the buffer to the file

    cin >> buff;
    fout << buff; /// formatted output just like cout

    cout << "tellp(): " << fout.tellp() << endl; /// prints the put position
    fout.seekp(0,ios::beg); /// positions put index to the beginning

    fout.put('X'); /// puts a single character in the file

    /// flushes buffer contents to the file and makes the stream available to open another file
    fout.close();
}
int main(){
    //ifstreamDemo();
    //ofstreamDemo();
    //binaryVsTextFileDemo();
    return 0;
}
