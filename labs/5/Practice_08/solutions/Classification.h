#pragma once

class Classification {
    double price;
    char* barcode;
    char* category;

public:
    Classification(const char* = "", double = 0, const char* = "");
    double getPrice();
    void print();
    ~Classification();
};


