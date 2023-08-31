/*
 Ye Tian
 ytian62@myseneca.ca
 142003227
 7 APR 2023
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#include <stdio.h>
#include "PosApp.h"
#include "utils.h"
#include <string.h>
struct Item items[MAX_NO_ITEMS];
int noOfItems = 0;

void start(const char* action) {
    printf(">>>> %s...\n", action);
}
int loadItems(const char filename[]) {
    start("Loading Items");
    FILE* file = fopen("posdata.csv", "r");
    if (!isEmpty(file)){
        while (fscanf(file, "%[^,],%[^,],%lf,%d,%d\n", items[noOfItems].SKU, items[noOfItems].name, &items[noOfItems].price, &items[noOfItems].taxed, &items[noOfItems].quantity) == 5) {
            noOfItems++;
        }
    }
    fclose(file);
    start("Done!");
    return noOfItems;
}
void saveItems(const char filename[]) {
    int i;
    start("Saving Items");
    FILE* file = fopen(filename, "w");
    if (!isEmpty(file)){
        for (i = 0; i < noOfItems; i++) {
            fprintf(file, "%s,%s,%.2lf,%d,%d\n", items[i].SKU, items[i].name, items[i].price, items[i].taxed, items[i].quantity);
        }
    }
    else {
        printf("Could not open >>%s<<\n", filename);
    }
    fclose(file);
    start("Done!");
}

void inventory(void) {
    double tav = 0;
    int i;
    start("List Items");
    listItems();
    for (i = 0; i < noOfItems; i++) {
        tav += cost(&items[i]) * items[i].quantity;
    }
    printf("                               Total Asset: $  |%14.2lf |\n"
           "-----------------------------------------------^---------------^\n", tav);
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
double cost(const struct Item* item){
    double the_cost = item->price * (1 + item->taxed * TAX);
    return the_cost;
}
int isEmpty(FILE* file) {
    int ret = 0;
    if (file == NULL) {
        ret = 1;
    }
    return ret;
}
void listItems(void){
    int i;
    char iName[19];
    printf(" Row | SKU    | Item Name          | Price |TX | Qty |   Total |\n"
           "-----|--------|--------------------|-------|---|-----|---------|\n");
    for (i = 0; i < noOfItems; i++) {
        strncpy(iName, items[i].name, 19);
        printf("%4d"
               " | "
               "%6s"
               " | "
               "%-18s"
               " |"
               "%6.2lf"
               " | "
               "%c"
               " | "
               "%3d"
               " |"
               "%8.2lf"
               " |\n", i + 1, items[i].SKU, iName, items[i].price, items[i].taxed ? 'T' : ' ', items[i].quantity, cost(&items[i]) * items[i].quantity);
    }
    printf("-----^--------^--------------------^-------^---^-----^---------^\n");
}
