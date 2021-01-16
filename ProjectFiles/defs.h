#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
#include <string.h>
#include <time.h>




#define MAX_STR 32
#define MAX_ARR 50



typedef struct {
    char countryCode[MAX_STR];
    char countryName[MAX_STR];
    char gender[MAX_STR];
    char degree[MAX_STR];
    int year;
    int numGrads;

} CountryYearType;

typedef struct {
//  CountryYearType forYear;
  char countryCode[MAX_STR];
  int cTotalA;
  int cTotal2;
  int cTotal3;
  int cTotal4;
  int cTotal5;

} CountryDataType;

typedef struct Node{
    CountryYearType *data;
    struct Node *prev;
    struct Node *next;
} NodeType;

typedef struct{
  NodeType *head;
  NodeType *tail;
} ListType;



typedef struct {
  int wTotalA;
  int wTotal2;
  int wTotal3;
  int wTotal4;
  int wTotal5;
  int numCountry;
  CountryDataType *countryStats[MAX_ARR];

} WorldDataType;

typedef struct {
  char countryCol[MAX_STR];
  float col2;
  float col3;
  float col4;
  float col5;

} ReportDataType;


typedef struct ReportNode{
    ReportDataType *data;
    struct ReportNode *prev;
    struct ReportNode *next;
} ReportNodeType;

typedef struct{
  ReportNodeType *head;
  ReportNodeType *tail;

} ReportListType;


typedef enum {GENERIC, BY_MAIN, WORLD_COUNTRIES, REPORT1, REPORT2, REPORT3, REPORT4}  SortType;








//init.c
void initTable(CountryDataType*, int numRow, int numCol);
void initCountryRecord(char*, char*, char*, char*, int, int, CountryYearType**);
void initAllCountries(FILE*, ListType*);
void initCountry(char*, CountryDataType**);
void initReportEntry(char*, float, float, float, float, ReportDataType**);
void initWorld(WorldDataType**);



//util.c
void addCountryToList(SortType, ListType*, CountryYearType*);
void addToEndList(ListType*, CountryYearType*);
void updateCountry(int, int, int, int, CountryDataType **);
void updateworld(int, int, int, int, WorldDataType **);
void addCountry(CountryDataType*, WorldDataType**);
void addDataToList(SortType, ReportListType*, ReportDataType*);
void cleanUpReport(ReportListType*, WorldDataType*);
void cleanup(ListType*);

//print.c
void printList(ListType*);
void printCountry(CountryYearType*);
void printRow(ReportDataType*);
void printReportList(ReportListType*);
void printReportListRange(ReportListType*, int, int, int);


//reports.c
void reportOne(ReportListType*, WorldDataType*);
void reportOneData(ListType*, WorldDataType**);

void reportTwo(ReportListType*, WorldDataType*);
void reportTwoData(ListType *, WorldDataType**);

void reportThree(ReportListType*, WorldDataType*);
void reportThreeData(ListType *, WorldDataType**);

void reportFour(ReportListType*, WorldDataType*);
void reportFourData(int, ListType *, WorldDataType**);

void reportFive(ReportListType*, WorldDataType*);
void reportFiveData(ListType*, WorldDataType**);
