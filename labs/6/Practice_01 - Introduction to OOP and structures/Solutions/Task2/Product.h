//
// Created by yasen on 2/22/20.
//

#ifndef TASK2_PRODUCT_H
#define TASK2_PRODUCT_H

#define BUFF_SIZE (52)

struct Product{
    char description[BUFF_SIZE];
    unsigned serialNumber;
    double cost;
};

void printProduct(const Product&);
void init(Product&, const char*, unsigned, double);

#endif //TASK2_PRODUCT_H
