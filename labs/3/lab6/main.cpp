#include "Time.h"
#include <iostream>
#include <fstream>
#include <string.h>

struct TimeStruct
{
    unsigned hours;
    unsigned minutes;
    char* text;
};

int main()
{
    /// Writing Time class to text file:
    Time t(10, 25);
    std::ofstream out("time.txt");
    if (!out)
    {
        std::cerr << "Cannot open file!\n";
        return -1;
    }
    out << t.getHours() << " " << t.getMinutes() << std::endl;
    out.close();

    /// Reading Time class from text file:
    unsigned hours, minutes;
    std::ifstream in("time.txt");
    if (!in)
    {
        std::cerr << "Cannot open file!\n";
        return -1;
    }
    in >> hours >> minutes;
    Time t1(hours, minutes);
    std::cout << "Read Time class from text file: hours=" << t1.getHours() << ", minutes=" << t1.getMinutes() << std::endl;
    in.close();


    // Writing Time class to binary file
    // 0a00 0000 1900 0000
    // 0000 000a 0000 0019
    // To understand why in binary files numbers seem flipped read:
    //     Endians - Big endian, little endian
    std::ofstream outBinary("time.bin", std::ios::binary);
    if (!outBinary)
    {
        std::cerr << "Cannot open file!\n";
        return -1;
    }
    hours = t.getHours();
    minutes = t.getMinutes();
    outBinary.write((const char*)&hours, sizeof(hours));
    outBinary.write((const char*)&minutes, sizeof(minutes));

    outBinary.close();

    /// Read is simular - try to do it on your own



///---------------------------------------------------------------------------------------
// Using Time Struct

    /// Creating Time struct with dynamic data in it
    TimeStruct tStruct = {10, 25};
    tStruct.text = new(std::nothrow) char[strlen("10:25 h")+1];
    if (!tStruct.text)
    {
        std::cerr << "Could not allocate memory\n";
        return -1;
    }
    strcpy(tStruct.text, "10:25 h");    // Could also use strdup - try it
    //std::cout << t.getHours() << " " << t.getMinutes() << std::endl;

    /// Writing the time struct to text file
    out.open("timeStruct.txt");
    if (!out)
    {
        std::cerr << "Cannot open file!\n";
        return -1;
    }
    out << tStruct.hours << " " << tStruct.minutes << " " << tStruct.text << std::endl;
    out.close();

    /// Wriging time struct to binary file
    out.open("timeStruct.bin", std::ios::binary);
    if (!out)
    {
        std::cerr << "Cannot open file!\n";
        return -1;
    }
    out.write((const char*)&tStruct.hours, sizeof(tStruct.hours));
    out.write((const char*)&tStruct.minutes, sizeof(tStruct.minutes));
    out.write(tStruct.text, strlen(tStruct.text)+1);
    out.close();

    /// Reading a time stuct from binary file
    in.open("timeStruct.bin", std::ios::binary);
    if (!in)
    {
        std::cerr << "Cannot open file!\n";
        return -1;
    }
    TimeStruct tRead;
    in.read((char*)&tRead.hours, sizeof(tRead.hours));
    in.read((char*)&tRead.minutes, sizeof(tRead.minutes));

    char tmp[50], c;
    int i = 0;
    in.read(&c, sizeof(char));
    while(in && c != '\0')
    {
        tmp[i++] = c;
        in.read(&c, sizeof(char));

        /*if (i == 50)
        {
            append(tRead.text, tmp);
            i = 0;
        }*/
    }

    tRead.text = strdup(tmp);
    std::cout << tRead.text << std::endl;

    in.close();

    return 0;
}