/*
 Ye Tian
 ytian62@myseneca.ca
 142003227
 15 APR 2023
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "utils.h"


void toPause (void) {
    printf("Press <ENTER> to continue....");
    flushKey();
}
int getIntMM(int min, int max, const char valueName[]) {
    int value = getInt();
    while(value < min || value > max) {
        printf("[%d<=%s<=%d], retry: ", min, valueName, max);
        value = getInt();
    }
    return value;
}
double getDbl(void) {
    double value;
    int done = 0;
    char newline = 'x';
    while(!done) {
        if(scanf("%lf%c", &value, &newline) == 2) {
            if(newline == '\n') {
                done = 1;
            } else {
                printf("Please enter only an integer: ");
                flushKey();
            }
        } else { // user enterd non integer
            flushKey();
            printf("Invalid Integer, try again: ");
        }
    }
    return value;
}
double getDblMM(double min, double max, const char valueName[]) {
    double value = getDbl();
    while(value < min || value > max) {
        printf("[%02.lf<=%s<=%.2lf], retry: ", min, valueName, max);
        value = getDbl();
    }
    return value;
}
int getInt(void) {
    int value;
    int done = 0;
    char newline = 'x';
    while(!done) {
        if(scanf("%d%c", &value, &newline) == 2) {
            if(newline == '\n') {
                done = 1;
            }
            else {
                printf("Please enter only an integer: ");
                flushKey();
            }
        }
        else { // user enterd non integer
            flushKey();
            printf("Invalid Integer, try again: ");
        }
    }
    return value;
}

void flushKey(void) {
    char ch = 'x';
    while(ch != '\n') {
        ch = getchar();
    }
}

int yes(void) {
    char resp;
    char newline;
    printf("(Y)es/(N)o: ");
    do {
        scanf("%c%c", &resp, &newline);
        if(newline != '\n') {
            flushKey();
            resp = 'x';
        }
    } while(resp != 'Y' && resp != 'y' && resp != 'n' && resp != 'N' && printf("Only (y) for Yes and (n) for No are acceptable values; retry\n> "));
    return (resp == 'Y' || resp == 'y');
}
void fflushKey(FILE* file) {
    char ch = 'x';
    while (ch != '\n') {
        ch = fgetc(file);
    }
}
int isEmpty(FILE* file) {
    int ret = 0;
    if (file == NULL) {
        ret = 1;
    }
    return ret;
}
