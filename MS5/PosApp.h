/*
 Ye Tian
 ytian62@myseneca.ca
 142003227
 15 APR 2023
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
void inventory(void);   //MS2
void addItem(void); //MS5
void removeItem(void);  //MS5
void stockItem(void);   //MS4
int selectItems(void);  //MS4
void POS(void);     //MS35
int loadItems(const char filename[]);   //MS2
void saveItems(const char filename[]);  //MS31
double cost(const struct Item* item);   //MS2
void listItems(void);   //MS2
double billDisplay(const struct Item* item);    //MS32
void display(const struct Item* item);  //MS33
int search(void);   //MS34
#endif // !SDDS_POSAPP_H

