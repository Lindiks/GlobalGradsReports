#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
#include <string.h>
#include <time.h>


#include "defs.h"


//PURPOSE: Calculate the neccessary Calculations, and display Report 1
//INPUT: rList - List containing the data neccessary for computing the data || w - pointer to WorldDataType object containing the neccessary data
void reportOne(ReportListType* rList, WorldDataType *w){
    ReportDataType *r;
    float c2, c3, c4, c5;

    for(int i=0; i < w->numCountry; i++){

        c2 = ((float) w->countryStats[i]->cTotal2 / (float) w->wTotal2)*100;
        c3 = ((float) w->countryStats[i]->cTotal3 / (float) w->wTotal3)*100;
        c4 = ((float) w->countryStats[i]->cTotal4 / (float) w->wTotal4)*100;
        c5 = ((float) w->countryStats[i]->cTotalA / (float) w->wTotalA)*100;

        initReportEntry(w->countryStats[i]->countryCode, c2, c3, c4, c5, &r);
        addDataToList(GENERIC,rList, r);
    }

    printf("\n");


    printf("\tCOUNTRY \tBACHELOR \tMASTERS \tDOCTORATE \tALL DEGREES \t \n");
    printf("-----------------------------------------------------------------------------------\n" );
    printReportList(rList);

}

//PURPOSE: Grabs all data relevant to the needs of report 1
//INPUT: list - Main list of all data from the input file || w- double pointer to WorldDataType
void reportOneData(ListType *list, WorldDataType**w){
    int state = 1;
    int index;
    CountryDataType *c;

    NodeType *currNode = list->head;
    NodeType *prevNode = NULL;

    while (currNode != NULL) {

        for(int i=0; i<(*w)->numCountry; i++){
            if(strcmp((*w)->countryStats[i]->countryCode, currNode->data->countryCode)==0){
                state = 1;
                index = i;
                break;
            }
            state =0;
            }
            if(state ==0 || (*w)->numCountry==0){
                initCountry(currNode->data->countryCode, &c);
                addCountry(c, w);
            }
            if(strcmp(currNode->data->gender, "T")==0){
                if(strcmp(currNode->data->degree,"L6")==0){
                    updateworld(currNode->data->numGrads, 0, 0, 0, w);
                    updateCountry(currNode->data->numGrads, 0, 0, 0, &(*w)->countryStats[index]);
                }
                else if(strcmp(currNode->data->degree, "L7")==0){
                    updateworld( 0, currNode->data->numGrads, 0, 0, w);
                    updateCountry(0, currNode->data->numGrads, 0,0,  &(*w)->countryStats[index]);
                }
                else if(strcmp(currNode->data->degree, "L8")==0){
                    updateworld(0, 0, currNode->data->numGrads, 0, w);
                    updateCountry(0, 0, currNode->data->numGrads, 0, &(*w)->countryStats[index]);
                }
            }
        prevNode = currNode;
        currNode = currNode->next;
    }
}


//PURPOSE: Calculate the neccessary Calculations, and display Report 2
//INPUT: rList - List containing the data neccessary for computing the data || w - pointer to WorldDataType object containing the neccessary data
void reportTwo(ReportListType* rList, WorldDataType *w){
  ReportDataType *r;
  float c2, c3, c4, c5;
    for(int i=0; i < w->numCountry; i++){
     c2 = ((float) w->countryStats[i]->cTotal2 / (float) w->countryStats[i]->cTotalA )*100;
     c3 = -1;
     c4 = -1;
     c5 = -1;
      initReportEntry(w->countryStats[i]->countryCode, c2, c3, c4, c5, &r);
      addDataToList(WORLD_COUNTRIES, rList, r);
    }

  printf("\n");

  printf("\tCOUNTRY \t FEMALE GRADUATES \n");
  printReportListRange(rList, 5, w->numCountry-5, 1);
}


//PURPOSE: Grabs all data relevant to the needs of report 2
//INPUT: list - Main list of all data from the input file || w- double pointer to WorldDataType
void reportTwoData(ListType *list, WorldDataType**w){
    int state = 1;
    int index;
    CountryDataType *c;
    index = 0;

    NodeType *currNode = list->head;
    NodeType *prevNode = NULL;

    while (currNode != NULL) {
        for(int i=0; i<(*w)->numCountry; i++){
            if(strcmp((*w)->countryStats[i]->countryCode, currNode->data->countryCode)==0){
                state = 1;
                index = i;
                break;
            }
            state = 0;
            }
            if(state == 0 || (*w)->numCountry == 0){
                initCountry(currNode->data->countryCode, &c);
                addCountry(c, w);
            }
            if(strcmp(currNode->data->countryCode, (*w)->countryStats[index]->countryCode)!=0){
                index = index+1;
            }
            if((strcmp(currNode->data->gender, "F") == 0) && (strcmp(currNode->data->countryCode, (*w)->countryStats[index]->countryCode)==0)){
                if(strcmp(currNode->data->degree,"L6")==0){
                    updateCountry(currNode->data->numGrads, 0, 0, 0, &(*w)->countryStats[index]);
                }
                else if(strcmp(currNode->data->degree, "L7")==0){
                    updateCountry(currNode->data->numGrads, 0, 0, 0, &(*w)->countryStats[index]);
                }
                else if(strcmp(currNode->data->degree, "L8")==0){
                    updateCountry(currNode->data->numGrads, 0, 0, 0, &(*w)->countryStats[index]);
                }
            }
            else if((strcmp(currNode->data->gender, "M")==0) && (strcmp(currNode->data->countryCode, (*w)->countryStats[index]->countryCode)==0)){
                if(strcmp(currNode->data->degree,"L6")==0){
                    updateCountry(0, currNode->data->numGrads, 0,0,  &(*w)->countryStats[index]);
                }
                else if(strcmp(currNode->data->degree, "L7")==0){
                    updateCountry(0, currNode->data->numGrads, 0,0,  &(*w)->countryStats[index]);
                }
                else if(strcmp(currNode->data->degree, "L8")==0){
                    updateCountry(0, currNode->data->numGrads, 0,0,  &(*w)->countryStats[index]);
                }
            }
        prevNode = currNode;
        currNode = currNode->next;
    }
}




//PURPOSE: Calculate the neccessary Calculations, and display Report 3
//INPUT: rList - List containing the data neccessary for computing the data || w - pointer to WorldDataType object containing the neccessary data
void reportThree(ReportListType* rList, WorldDataType *w){
    ReportDataType *r;
    float c2, c3, c4, c5;
    for(int i=0; i < w->numCountry; i++){
        c2 = ((float) w->countryStats[i]->cTotal2 / (float) w->wTotal2)*100;

        c3 = ((float) w->countryStats[i]->cTotal3 / (float) w->wTotal3)*100;

        c4 = ((float) w->countryStats[i]->cTotal4/ (float) w->wTotal4)*100;

        c5 = ((float) w->countryStats[i]->cTotal5 / (float) w->wTotal5)*100;

        initReportEntry(w->countryStats[i]->countryCode, c2, c3, c4, c5, &r);
        addDataToList(GENERIC, rList, r);
    }
    printf("\n");
    printf("TITLE: Graduate percentage for each country\n" );

    printf("\tCOUNTRY \t 2014 \t\t 2015 \t\t 2016 \t\t 2017 \t \n");
    printf("-----------------------------------------------------------------------------------\n" );
    printReportList(rList);
}

//PURPOSE: Grabs all data relevant to the needs of report 3
//INPUT: list - Main list of all data from the input file || w- double pointer to WorldDataType
void reportThreeData(ListType *list, WorldDataType**w){
    int state = 1;
    int index;
    CountryDataType *c;

    NodeType *currNode = list->head;
    NodeType *prevNode = NULL;

    while (currNode != NULL) {

        for(int i=0; i<(*w)->numCountry; i++){
            if(strcmp((*w)->countryStats[i]->countryCode, currNode->data->countryCode)==0){
                state = 1;
                index = i;
                break;
            }
            state =0;
            }
            if(state ==0 || (*w)->numCountry==0){
                initCountry(currNode->data->countryCode, &c);
                addCountry(c, w);
            }
            if(strcmp(currNode->data->gender, "T")==0)
            {
                if(currNode->data->year == 2014){
                    updateworld(currNode->data->numGrads, 0, 0, 0, w);
                    updateCountry(currNode->data->numGrads, 0, 0, 0, &(*w)->countryStats[index]);
                }
                else if(currNode->data->year == 2015){
                    updateworld( 0, currNode->data->numGrads, 0, 0, w);
                    updateCountry(0, currNode->data->numGrads, 0,0, &(*w)->countryStats[index]);

                }
                else if(currNode->data->year == 2016){
                    updateworld(0, 0, currNode->data->numGrads, 0, w);
                    updateCountry(0, 0, currNode->data->numGrads, 0, &(*w)->countryStats[index]);
                }
                else if(currNode->data->year == 2017){
                    updateworld(0, 0, 0, currNode->data->numGrads,w);
                    updateCountry(0, 0, 0,currNode->data->numGrads, &(*w)->countryStats[index]); //should probably replace this with the node data
                }
            }
        prevNode = currNode;
        currNode = currNode->next;
        }
}



//PURPOSE: Calculate the neccessary Calculations, and display Report 4
//INPUT: rList - List containing the data neccessary for computing the data || w - pointer to WorldDataType object containing the neccessary data
void reportFour(ReportListType* rList, WorldDataType *w){
    ReportDataType *r;
    float c2, c3, c4, c5;
    for(int i=0; i < w->numCountry; i++){
        c2 = ((float) w->countryStats[i]->cTotal2 / (float) w->wTotal2)*100;
        c3 =-1;
        c4 = -1;
        c5 = -1;
        initReportEntry(w->countryStats[i]->countryCode, c2, c3, c4, c5, &r);
        addDataToList(WORLD_COUNTRIES, rList, r);
    }

    printf("\n");
    printf("TITLE: TOP 10 grad countries \n" );

    printf("\tCOUNTRY \t year  \n");

    printReportListRange(rList, 10, w->numCountry+1, 0);

}

//PURPOSE: Grabs all data relevant to the needs of report 4
//INPUT: sYear- year to currate data for || list - Main list of all data from the input file || w- double pointer to WorldDataType
void reportFourData(int sYear, ListType *list, WorldDataType**w){
    int state = 1;
    int index;
    CountryDataType *c;

    NodeType *currNode = list->head;
    NodeType *prevNode = NULL;

    while (currNode != NULL) {

        for(int i=0; i<(*w)->numCountry; i++){
            if(strcmp((*w)->countryStats[i]->countryCode, currNode->data->countryCode)==0){
                state = 1;
                index = i;
                break;
            }
            state =0;
            }
            if(state ==0 || (*w)->numCountry==0){
                initCountry(currNode->data->countryCode, &c);
                addCountry(c, w);
            }
            if(strcmp(currNode->data->gender, "T")==0)
            {
                if(currNode->data->year == sYear){
                    updateworld(currNode->data->numGrads, 0, 0, 0, w);
                    updateCountry(currNode->data->numGrads, 0, 0, 0, &(*w)->countryStats[index]);
            }
        }
    prevNode = currNode;
    currNode = currNode->next;
    }
}








//PURPOSE: Calculate the neccessary Calculations, and display Report 2
//INPUT: rList - List containing the data neccessary for computing the data || w - pointer to WorldDataType object containing the neccessary data
void reportFive(ReportListType* rList, WorldDataType *w){
    ReportDataType *r;
    float c2, c3, c4, c5;
    for(int i=0; i < w->numCountry; i++){
        c2 =  (float) w->countryStats[i]->cTotal2 / w->wTotalA;
        c3 = -1;
        c4 = -1;
        c5 = -1;
        initReportEntry(w->countryStats[i]->countryCode, c2, c3, c4, c5, &r);
        addDataToList(WORLD_COUNTRIES, rList, r);
    }
    printf("\n");
    printf("TITLE: TOP year for graduates \n" );

    printf("\tYEAR \tpercent of all DEGREES  \n");
    printReportListRange(rList, 3, w->numCountry+1, 0);
}

//PURPOSE: Grabs all data relevant to the needs of report 5
//INPUT: list - Main list of all data from the input file || w- double pointer to WorldDataType
void reportFiveData(ListType *list, WorldDataType**w){
    int state = 1;
    int index;
    CountryDataType *c;
    int curYear1, curYear2, curYear3;
    char str[MAX_STR];

    NodeType *currNode = list->head;
    NodeType *prevNode = NULL;

    while (currNode != NULL) {
        int x = currNode->data->year;
        sprintf(str, "%d",x);
        for(int i=0; i<(*w)->numCountry; i++){
            if(strcmp((*w)->countryStats[i]->countryCode, str)==0){
                state = 1;
                index = i;
                break;
            }
            state =0;
            }
            if(state ==0 || (*w)->numCountry==0){
                initCountry(str, &c);
                addCountry(c, w);
            }
            if(strcmp(currNode->data->gender, "T")==0)
            {
                updateworld(currNode->data->numGrads, 0, 0, 0, w);
                updateCountry(currNode->data->numGrads, 0, 0, 0, &(*w)->countryStats[index]);
            }
        prevNode = currNode;
        currNode = currNode->next;
    }
}
