/*
 Ye Tian
 ytian62@myseneca.ca
 142003227
 9 APR 2023
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "PosApp.h"
#include <stdio.h>
#include "PosApp.h"
int main() {
    int i;
    int foundIndex;
    loadItems("posdata.csv");
    for(i = 0; (foundIndex = search()) != -2;i++){
        if(foundIndex >= 0) {
            printf("SKU found at index %d\n", foundIndex);
        }
        else {
            printf("SKU not found!\n");
        }
    }
    printf("Search was executed %d times...", i);
    return 0;
}
