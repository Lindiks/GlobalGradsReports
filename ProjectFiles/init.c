#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
#include <string.h>
#include <time.h>

#include "defs.h"


//PURPOSE: Initalizes each countries entry and stores it to a list
//INPUT: file - reference to the opened file || list - the list for each line/entry to be added to
void initAllCountries(FILE *file, ListType* list){
    CountryDataType *c;
    CountryYearType *cy;
    int state=1;
    char cc[MAX_STR], cName[MAX_STR], g[MAX_STR], d[MAX_STR];
    int y, numG, index;

    while(1){
        fscanf(file, "%s %s %s %s %d %d", cc, cName, g, d, &y, &numG);
        if(feof(file))
            break;
        if(numG!=0){
            initCountryRecord(cc, cName, g, d, y, numG, &cy);
            addCountryToList(BY_MAIN, list, cy);
        }
    }
}


//PURPOSE: Initalizes the WorldDataType object
//INPUT: w - double pointer of type WorldDataType
void initWorld(WorldDataType** w){
    *w = malloc(sizeof(WorldDataType));

    (*w)->wTotalA=0;
    (*w)->wTotal2=0;
    (*w)-> wTotal3=0;
    (*w)->wTotal4=0;
    (*w)->wTotal5=0;
    (*w)->numCountry=0;
}


//PURPOSE: initalizes the CountryDataType object
//INPUT: code - the countries Code || c - double pointer of type CountryDataType
void initCountry(char* code, CountryDataType **c){
    (*c) = malloc(sizeof(CountryDataType));

    strcpy((*c)-> countryCode, code);
    (*c)->cTotalA=0;
    (*c)-> cTotal2=0;
    (*c)-> cTotal3=0;
    (*c)-> cTotal4=0;
    (*c)-> cTotal5=0;
}

//PURPOSE: Initalizes the ReportDataType Object that contains the column layout of the report to be dispalyed
//INPUT: c1, c2, c3, c4, c5 - contain string of data to be stored into their corresponding variables || r - double pointer of type ReportDataType
void initReportEntry(char* c1, float c2, float c3, float c4, float c5, ReportDataType **r){
    *r = malloc(sizeof(ReportDataType));

    strcpy((*r)->countryCol, c1);
    (*r)->col2 = c2;
    (*r)->col3 = c3;
    (*r)->col4 = c4;
    (*r)->col5 = c5;

}

//PURPOSE: Initalizes the country record for a specific country based on its year, degree, and gender
//INPUT: cCode - indicates the countries code || cName - indicates the countries name ||
//       g - indicates the gender || d - indicates the degree type
//       y - indicates the year of the record || numG - indicates the number of graduates

void initCountryRecord(char* cCode, char* cName, char* g, char* d, int y, int numG, CountryYearType **c){
    *c = malloc(sizeof(CountryYearType));

    strcpy((*c)->countryCode, cCode);
    strcpy((*c)->countryName, cName);
    strcpy((*c)->gender, g);
    strcpy((*c)->degree, d);

    (*c)->year = y;
    (*c)->numGrads = numG;
}


//Probably add a parameter that takes the structure type obj to populate the table
void initTable(CountryDataType* cPtr, int numRow, int numCol){

  printf("init");
//can use ncurses or just use from https://www.youtube.com/watch?v=Q3nVIpwztMw
}
