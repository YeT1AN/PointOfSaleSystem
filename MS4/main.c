/*
 Ye Tian
 ytian62@myseneca.ca
 142003227
 15 APR 2023
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "PosUI.h"
void fileDump(const char* filename);
void ressetData();
int main() {
   ressetData();
   fileDump("posdata.csv");
   runPos("posdata.csv");
   fileDump("posdata.csv");
   return 0;
}

void ressetData() {
   FILE* f_origin = fopen("posdataOrigin.csv", "r");
   FILE* f_data = fopen("posdata.csv", "w");
   char ch;
   while(fscanf(f_origin, "%c", &ch) == 1) {
      fprintf(f_data, "%c", ch);
   }
   fclose(f_origin);
   fclose(f_data);
}
void fileDump(const char* filename) {
   FILE* fptr = fopen(filename, "r");
   if(fptr) {
      char ch = 0;
      printf("Contents of file >>%s<<:\n", filename);
      while(fscanf(fptr, "%c", &ch) == 1) {
         putchar(ch);
      }
      fclose(fptr);
      printf("End of data in >>%s<<\n", filename);
   } else {
      printf("file: >>%s<< not found!\n", filename);
   }
}
