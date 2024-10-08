#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>
// #include "templates.c"
// #include "colors.c"
// #include "gotoXY.c"
// #include "logo.c"


struct Patient {
    int patId;
    char patName[25];
    int age;
    char gender;
    char phNumber[12];
    
};
struct Patient pat;
int modifyPatient(int patId) {
    
    FILE *file = fopen("patient.txt","r");

    if(file == NULL) {
        perror("Access Denied");
        return 1;
    }
    FILE *tempFile = fopen("temp_patient.txt", "w");
    if (tempFile == NULL) {
        perror("Access Denied\n");
        return 1;
    }

    int modified = 0;
    char phNumber[12];
    printf("Enter the Phone Number: ");
    scanf("%s", phNumber);
    

    while (fscanf(file, "%d %s %d %c %s", &pat.patId, pat.patName, &pat.age, &pat.gender, pat.phNumber) != EOF) {
        if (pat.patId == patId) {
            fprintf(tempFile, "%d %s %d %c %s\n", pat.patId, pat.patName, pat.age, pat.gender, phNumber);
            modified = 1;
        } 
        else {
            fprintf(tempFile, "%d %s %d %c %s\n", pat.patId, pat.patName, pat.age, pat.gender, pat.phNumber);
        }
    }
    
    fclose(file);
    fclose(tempFile);
    if (!modified) {
        printf("paticine with ID %d not found.\n", patId);
        remove("temp_patient.txt"); // Remove temporary file
        return 1;
    }

    // Replace original file with temporary file
    if(remove("patient.txt")!=0) {
        perror("Error removing original file: "); 
        return 1;
    }
    if (rename("temp_patient.txt", "patient.txt") != 0) {
        perror("Error renaming file: ");
        return 1;
    }
    while (fscanf(file, "%d %s %d %c %s", &pat.patId, pat.patName, &pat.age, &pat.gender, pat.phNumber) != EOF) {
        printf("%s", pat.phNumber);
    }
    // return modified;
    exit(0);
}




int searchPatient(int patId) {
    // struct Patient pat;
    FILE *file = fopen("patient.txt","r");
    if (file == NULL) {
        perror("Access Denied");
        return 1;
    }
    while (fscanf(file, "%d %s %d %c %s", &pat.patId, pat.patName, &pat.age, &pat.gender, pat.phNumber)!= EOF) {
        if (pat.patId == patId) {
            boldyellow(); gotoxy(40,25);printf("Pateint already exits\n"); reset();
            fclose(file);
            //modifyPatient(patId);
            return 1;
            break;
        }
    }
    fclose(file);
    return 0;
}



//Input the patient details
 int pateintDetailsInput() {
    int patID;
    system("cls");
    defaultTemplate();
    boldwhite();gotoxy(40,20); printf("Enter the details\n");
    
    gotoxy(40,22);printf("Patient ID: ");
    scanf("%d", &patID);
    

    if(searchPatient(patID) == 1){
        boldyellow();gotoxy(30,30); printf("Enter to Continue ....\n");reset();
                getchar();
                getchar();
        return pat.patId; 
    }
    else{
        gotoxy(40,24); printf("Pateint patName: ");
        scanf("%s", pat.patName);
        
        getchar();

        gotoxy(40,26);printf("Gender(M/F): ");
        scanf(" %c", &pat.gender);

        //if the entered gender is wrong it will ask again
        while(pat.gender != 'm' && pat.gender != 'M' && pat.gender != 'f' && pat.gender != 'F') {
                gotoxy(40,25); printf("Please enter the correct Gender(M/F): ");
                getchar();
                scanf("%c", &pat.gender);
        } 
        
        if(pat.gender =='M' || pat.gender == 'm'){
            pat.gender='M';
        }
        if(pat.gender =='F' || pat.gender == 'f'){
            pat.gender='F';
        }

        gotoxy(40,27);printf("Age: ");
        scanf("%d", &pat.age);

        gotoxy(40,29);printf("Phone Number: ");
        scanf("%s", pat.phNumber);

        FILE *file = fopen("patient.txt","a+");
        if (file == NULL) {
            perror("Access Denied");
            return 1;
        }

        // Write patient information to the file
        fprintf(file, "%d %s %d %c %s\n", patID, pat.patName, pat.age, pat.gender, pat.phNumber);
         boldyellow();gotoxy(30,30); printf("Enter to Continue ....\n");reset();
                getchar();
                getchar();
        fclose(file);
    }
    
    return patID; 
 }
