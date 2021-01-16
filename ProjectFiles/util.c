#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
#include <string.h>
#include <time.h>

#include "defs.h"



//PURPOSE: Updates the country's data
//INPUT: c2 - to be added to cTotal2, c3 - to be added to cTotal3, c4 - to be added to cTotal4, c5 - to be added to cTotal5, c - double pointer of CountryDataType
//*NOTE* Every parameter passed in contributes to the running total for that country
void updateCountry(int c2, int c3, int c4, int c5, CountryDataType **c){
    (*c)-> cTotalA = (*c)->cTotalA + c2+ c3+ c4 + c5;
    (*c)->cTotal2 = (*c)->cTotal2 + c2;
    (*c)-> cTotal3 = (*c)->cTotal3 + c3;
    (*c)-> cTotal4 = (*c)->cTotal4 + c4;
    (*c)-> cTotal5 = (*c)->cTotal5 + c5;
}

//PURPOSE: Updates the 'worlds' data
//INPUT: c2, c3, c4, c5 - all update their corresponding totals || c - double pointer of CountryDataType
//*NOTE* Every parameter passed in contributes to the running total
void updateworld(int c2, int c3, int c4, int c5, WorldDataType **w){
    (*w)->wTotalA = (*w)->wTotalA + c2 + c3 + c4 + c5;
    (*w)->wTotal2 = (*w)->wTotal2 + c2;
    (*w)->wTotal3 = (*w)->wTotal3 + c3;
    (*w)->wTotal4 = (*w)->wTotal4 + c4;
    (*w)->wTotal5 = (*w)->wTotal5 + c5;
}

void addCountryToList(SortType s, ListType *list, CountryYearType *c) {
    addToEndList(list, c);
}

//PURPOSE: To add an element to the array found in WorldDataType
//INPUT: c - pointer to object to be added to array || w-> double pointer to WorldDataType
void addCountry(CountryDataType *c, WorldDataType **w){
  (*w)->countryStats[(*w)->numCountry] = c;
  (*w)->numCountry++;
}

//PURPOSE: Add (and sort if neccessary) the given object to the linked List
//INPUT: s - Determines the sorting to be done || list - (pointer) Linked list to be updated || r - pointer of ReportDataType
void addDataToList(SortType s, ReportListType *list, ReportDataType *r){
    ReportNodeType *currNode;
    ReportNodeType *prevNode;
    ReportNodeType *newNode;

    currNode = list->head;
    prevNode = NULL;

    while (currNode != NULL) {
        if(s == 2 && (currNode->data->col2 < r->col2)){
            break;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }

    newNode = malloc(sizeof(NodeType));
    newNode->data = r;
    newNode->prev = NULL;
    newNode->next = NULL;

    if(prevNode == NULL){
        list->head = newNode;
    }
    else{
        prevNode->next = newNode;
    }
    newNode->next = currNode;
    newNode->prev = prevNode;

    if(currNode!=NULL){
        currNode->prev = newNode;
    }

    while(currNode!=NULL) {
        prevNode = currNode;
        currNode = currNode->next;
    }
    list->tail = prevNode;
}

//PURPOSE: Add the given object to the linked List
//INPUT: list - (pointer) Linked list to be updated || c - pointer of CountryYearType
void addToEndList(ListType *list, CountryYearType *c){
    NodeType *currNode;
    NodeType *prevNode;
    NodeType *newNode;

    currNode = list->head;
    prevNode = NULL;
    while (currNode != NULL) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    newNode = malloc(sizeof(NodeType));
    newNode->data = c;
    newNode->prev = NULL;
    newNode->next = NULL;

    if(prevNode == NULL){
        list->head = newNode;
    }
    else{
        prevNode->next = newNode;
    }

    newNode->next = currNode;
    newNode->prev = prevNode;

    if(currNode!=NULL){
        currNode->prev = newNode;
    }
    while(currNode!=NULL) {
        prevNode = currNode;
        currNode = currNode->next;
    }
    list->tail = prevNode;
}

//PURPOSE: Frees the nodes contained in the list
//INPUT: list - Linked list to be freed
void cleanup(ListType *list){
    NodeType *currNode;
    NodeType *nextNode;

    currNode = list->head;

    while (currNode != NULL) {
        nextNode = currNode->next;
        free(currNode->data);
        free(currNode);
        currNode = nextNode;
    }
}

//PURPOSE: Frees the elements contained in the list and array
//INPUT: list - Linked list to be freed, w - pointer to WorldDataType instance containing the array
void cleanUpReport(ReportListType *rList, WorldDataType *w){
    ReportNodeType *currNode;
    ReportNodeType *nextNode;

    currNode = rList->head;

    while (currNode != NULL) {
        nextNode = currNode->next;
        free(currNode->data);
        free(currNode);
        currNode = nextNode;
    }
    for(int i =0; i<w->numCountry; i++){
        free(w->countryStats[i]);
    }
}
