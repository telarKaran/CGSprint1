/*
Filename: getdefect.c
Description: Read all defects from input file.
*/
#include <stdio.h>
#include <pthread.h>
#define SUCCESS 1
#define ERROR 0
#define MAXDEFECT 10
struct defect{
    char *defectID;
    char *description;
    char *moduleName;
    char *functionalArea;
    char *date;
    char *status;
    char *type;

};
typedef struct defect defect;
void checkValidity(char *str){

}
void validDefect(defect *defect_arr, char *str){

}
void invalidDefect(char *str){

}
void *getDefect(void *file){
    defect * defect_arr[MAXDEFECT];

    char *file_location = (char *)file;
    printf("\n--- Got this file %s", file_location);

    

}