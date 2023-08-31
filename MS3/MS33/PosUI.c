/*
 Ye Tian
 ytian62@myseneca.ca
 142003227
 9 APR 2023
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#include <stdio.h>
#include "PosUI.h"
#include "PosApp.h"
#include "utils.h"

int menu(void){
    printf("The Sene-Store\n"
           "1- Inventory\n"
           "2- Add item\n"
           "3- Remove item\n"
           "4- Stock item\n"
           "5- POS\n"
           "0- exit program\n"
           "> ");
    return getIntMM(0,5,"Selection");
}
void runPos(const char filename[]){
    int sel = 0;
    int done = 0;
    loadItems("posdata.csv");
    while (!done) {
        sel = menu();
        switch (sel) {
            case 1:
                inventory();
                break;
            case 2:
                addItem();
                break;
            case 3:
                removeItem();
                break;
            case 4:
                stockItem();
                break;
            case 5:
                POS();
                break;
            default:
                saveItems("posdata.csv");
                printf("Goodbye!\n");
                done = 1;
                break;
        }
    }
}
