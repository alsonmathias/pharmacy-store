#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Medicine1 {
    int medId;
    char medName[100];
    char dosage[100];
    int quantity;
    float price;
    int category;
};

void modifyQuantityUsingBill(int medId, int purchasedQty) {
    struct Medicine1 med;
    FILE *file = fopen("tablets.txt","r");

    if(file == NULL) {
        perror("Access Denied");
        return 1;
    }
    FILE *tempFile = fopen("temp_tablets.txt", "w");
    if (tempFile == NULL) {
        perror("Access Denied\n");
        return 1;
    }

    int quantity, modified = 0;

    

    while (fscanf(file, "%d %s %s %d %f %d", &med.medId, med.medName, med.dosage, &med.quantity, &med.price, &med.category) != EOF) {
        if (med.medId == medId) {
            med.quantity -= purchasedQty;
            fprintf(tempFile, "%d %s %s %d %f %d\n", med.medId, med.medName, med.dosage, med.quantity, med.price, med.category);
            modified = 1;
        } 
        else {
            fprintf(tempFile, "%d %s %s %d %f %d\n", med.medId, med.medName, med.dosage, med.quantity, med.price, med.category);
        }
    }
    

    fclose(file);
    fclose(tempFile);
    if (!modified) {
        //printf("Medicine with ID %d not found.\n", medId);
        remove("temp_tablets.txt"); // Remove temporary file
        return 1;
    }

    // Replace original file with temporary file
    if(remove("tablets.txt")!=0) {
        perror("Error removing original file: "); 
        return 1;
    }
    if (rename("temp_tablets.txt", "tablets.txt") != 0) {
        perror("Error renaming file: ");
        return 1;
    }
    // return modified;
    //exit(0);
    return;
}
