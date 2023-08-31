/*
 Ye Tian
 ytian62@myseneca.ca
 142003227
 1 APR 2023
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#include <stdio.h>
#include "PosApp.h"

void start(const char* action) {
    printf(">>>> %s...\n", action);
}
int loadItems(const char filename[]) {
    start("Loading Items");
    return 1;
}
void saveItems(const char filename[]) {
    start("Saving Items");
}

void inventory(void) {
    start("Inventory");
}

void addItem(void) {
    start("Adding Item");
}
void removeItem(void) {
    start("Remove Item");
}
void stockItem(void) {
    start("Stock Items");
}
void POS(void) {
    start("Point Of Sale");
}
