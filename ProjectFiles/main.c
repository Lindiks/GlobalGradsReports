#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
#include <string.h>
#include <time.h>


#include "defs.h"


int main(){
    FILE *infile;
    ListType *mainList;
    ReportListType *rList;
    WorldDataType *world;

    int t = 1;
    int choice;
    int userYear;

    infile = fopen("grad.dat", "r");
    if(!infile){
        printf("Error: could not open file\n");
        exit(1);
    }

    mainList = malloc(sizeof(ListType));
    mainList->head = NULL;
    mainList->tail = NULL;

    initAllCountries(infile, mainList);

    fclose(infile);

    while (t) {

        printf("Please pick one of the following reports: \n\n");

        printf("( 1 ) Total Graduate percentage for each country by Degree \n");
        printf("( 2 ) Top 5 & Bottom 5 countries for total graduate percentage \n");
        printf("( 3 ) Total graduate percentage for each country from 2014-2017 \n");
        printf("( 4 ) Top 10 Grad years\n");
        printf("( 5 ) Top 3 years that produced the most graduates\n");
        printf("( 0 ) Exit\n\n");

        printf("Please enter your choice: ");

        if(scanf("%d",&choice) != 1){
            cleanup(mainList);
            printf("Please enter correct values next time.\n");
            break;
        }
        if(choice == 1){
            printf("TITLE: Graduate percentage for each country\n" );
            rList = malloc(sizeof(ReportListType));
            rList->head = NULL;
            rList->tail = NULL;
            initWorld(&world);
            reportOneData(mainList, &world);
            reportOne(rList, world);
            cleanUpReport(rList, world);
        }
        else if (choice == 2){
            printf("TITLE: Female Proportion of Graduates per Country\n");
            rList = malloc(sizeof(ReportListType));
            rList->head = NULL;
            rList->tail = NULL;
            initWorld(&world);
            reportTwoData(mainList, &world);
            reportTwo(rList, world);
            cleanUpReport(rList, world);
        }
        else if (choice == 3){
            printf("TITLE: Graduate percentage for each country from 2014 - 2017\n" );
            rList = malloc(sizeof(ReportListType));
            rList->head = NULL;
            rList->tail = NULL;
            initWorld(&world);
            reportThreeData(mainList, &world);
            reportThree(rList, world);
            cleanUpReport(rList, world);
        }
        else if (choice == 4){
            printf("Please enter a year between 2010 - 2017 inclusive: ");
            if(scanf("%d",&userYear) != 1){
                cleanup(mainList);
                printf("Please enter correct values next time.\n");
                break;
            }else if(userYear<2010 || userYear>2017){
                printf("Please enter a valid year next time!");
            }else{
                printf("Top 10 grad contries from year %d",userYear);
                rList = malloc(sizeof(ReportListType));
                rList->head = NULL;
                rList->tail = NULL;
                initWorld(&world);
                reportFourData(userYear,mainList, &world);
                reportFour(rList, world);
                cleanUpReport(rList, world);
              }
        }
        else if (choice == 5){
            rList = malloc(sizeof(ReportListType));
            rList->head = NULL;
            rList->tail = NULL;

            initWorld(&world);
            reportFiveData(mainList, &world);
            reportFive(rList, world);
            cleanUpReport(rList, world);
        }
        else if (choice == 0){
            printf("Bye!\n");
            cleanup(mainList);
            printf("\n");
            break;
        }
        else{
            printf("please enter a valid selection!\n");
        }
    }
    return 0;
}
