#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
#include <string.h>
#include <time.h>


#include "defs.h"


//PURPOSE: Print the linked list
//INPUT: list - List to be printed
void printList(ListType *list){
    NodeType *currNode = list->head;
    NodeType *prevNode = NULL;
    while (currNode != NULL) {
        printCountry(currNode->data);
        prevNode = currNode;
        currNode = currNode->next;
    }
}

//PURPOSE: Prints all attributes of the Object
//INPUT: c - pointer to object of CountryYearType
void printCountry(CountryYearType *c){
    printf(" %s, %s, %s, %s, %d, %d\n", c->countryCode, c->countryName, c->gender, c->degree, c->year, c->numGrads);
}




//PURPOSE: Print the linked list
//INPUT: rList - List to be printed
void printReportList(ReportListType* rList){//could add range to this and just continue as normal if range == 0
    ReportNodeType *currNode = rList->head;
    ReportNodeType *prevNode = NULL;
    while (currNode != NULL) {
        printRow(currNode->data);
        prevNode = currNode;
        currNode = currNode->next;
    }
}


//PURPOSE: Print the linked list between specified range
//INPUT: list - List to be printed || range1 - range to print ||range2 - range to print
void printReportListRange(ReportListType* rList, int range1, int range2, int bT){
    ReportNodeType *currNode = rList->head;
    ReportNodeType *prevNode = NULL;
    int curPos=0;
    printf("Top %d:-----------------------------------------------------------\n", range1);
    while (currNode != NULL) {
        if(curPos<range1 || curPos>=range2){
        printRow(currNode->data);
    }

    if(curPos==range1 & bT ==1){

        printf("Bottom %d:-----------------------------------------------------------\n", range1);
    }
    //probably do an if statement for the top and an if statement for the bottom :)
    prevNode = currNode;
    currNode = currNode->next;
    curPos++;
    }







}



//PURPOSE: Prints all attributes of the Object
//INPUT: r - pointer to object of ReportDataType
void printRow(ReportDataType *r){

    char c2S[MAX_STR];
    char c3S[MAX_STR];
    char c4S[MAX_STR];
    char c5S[MAX_STR];

    if(r->col2 < 0){
      strcpy(c2S, " ");
    }else{
      sprintf(c2S, "%.2f",r->col2);
    }
    if(r->col3 < 0){
      strcpy(c3S, " ");
    }else{
        sprintf(c3S, "%.2f",r->col3);
    }
    if(r->col4 < 0){
      strcpy(c4S, " ");
    }
    else{
      sprintf(c4S, "%.2f",r->col4);
    }
    if(r->col5 < 0){
      strcpy(c5S, " ");
    }else{
      sprintf(c5S, "%.2f",r->col5);
    }
    printf("\t %3s \t\t %-6s \t %-6s \t %-4s \t\t %s\n", r->countryCol, c2S, c3S, c4S, c5S);
}
