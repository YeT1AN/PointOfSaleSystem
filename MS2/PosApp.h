/*
 Ye Tian
 ytian62@myseneca.ca
 142003227
 6 APR 2023
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef SDDS_POSAPP_H
#define SDDS_POSAPP_H
#include "POS.h"
struct Item {
    char SKU[MAX_SKU_LEN];
    char name[61];
    double price;
    int taxed;
    int quantity;
};

void start(const char* action);
void inventory(void);
void addItem(void);
void removeItem(void);
void stockItem(void);
void POS(void);

int loadItems(const char filename[]);
void saveItems(const char filename[]);
double cost(const struct Item* item);
void listItems(void);
int isEmpty(FILE* file);
#endif // !SDDS_POSAPP_H

