#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Medicine {
    int medId;
    char medName[100];
    char dosage[100];
    int quantity;
    float price;
    int category;
};
struct Medicine med;

int modifyMedicine(int medId) {
    
    boldred();
    FILE *file = fopen("tablets.txt","r");

    if(file == NULL) {
        gotoxy(29,18); perror("Access Denied");
        return 1;
    }
    FILE *tempFile = fopen("temp_tablets.txt", "w");
    if (tempFile == NULL) {
        gotoxy(29,18); perror("Access Denied\n");
        return 1;
    }
    reset();

    int quantity, modified = 0;

    boldCyan(); gotoxy(29,25); printf("Enter the modified quantity: ");
    scanf("%d", &quantity);
    reset();

    while (fscanf(file, "%d %s %s %d %f %d", &med.medId, med.medName, med.dosage, &med.quantity, &med.price, &med.category) != EOF) {
        if (med.medId == medId) {
            med.quantity += quantity;
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
        boldCyan();
        gotoxy(29,19); printf("Medicine with ID %d not found.\n", medId);
        remove("temp_tablets.txt"); // Remove temporary file
        return 1;
        reset();
    }

    // Replace original file with temporary file
    if(remove("tablets.txt")!=0) {
        boldred();
        gotoxy(29,20); perror("Error removing original file: "); 
        return 1;
    }
    if (rename("temp_tablets.txt", "tablets.txt") != 0) {
        gotoxy(29,20); perror("Error renaming file: ");
        return 1;
    }
    reset();
    // return modified;
    optionMenu();
}



int searchMedicine(int medId) {
    struct Medicine med;
    FILE *file = fopen("tablets.txt","r");
    if (file == NULL) {
        boldred();
        gotoxy(29,17); perror("Access Denied");
        return 1;
        reset();
    }

   while (fscanf(file, "%d %s %s %d %f %d", &med.medId, med.medName, med.dosage, &med.quantity, &med.price, &med.category) != EOF) {
        if (med.medId == medId) {
            boldyellow();
            gotoxy(29,18); printf("Medicine with this ID already exists.\n");
            gotoxy(30,35); printf("Enter to Continue ....\n");
            getchar();
            getchar();
            fclose(file);
            return 1;
            //modifyMedicine(medId);
            reset();
        }
    }
    fclose(file);
    reset();
    return 0;
}


int inputMedicine() {
    defaultTemplate();
    struct Medicine med;
    // Check if the medicine ID already exists
    boldCyan();

    gotoxy(29,15); printf("Enter med information (Serial No., Medicine Name, Dosage,");
    gotoxy(51,16); printf(" Quantity, Price):");
    gotoxy(29,18); printf("Serial No.: ");
    scanf("%d", &med.medId);
    reset();

    if(searchMedicine(med.medId)){
        optionMenu();
    }
    else{
        boldCyan();
        // Prompt the user to enter med information
        gotoxy(29,19); printf("Med Name: ");
        scanf("%s", med.medName); // Changed scanf to accept strings with spaces
        getchar(); // Consume the newline character

        gotoxy(29,20); printf("Dosage: ");
        scanf("%s", med.dosage);

        gotoxy(29,21); printf("Quantity: ");
        scanf("%d", &med.quantity);

        gotoxy(29,22); printf("Price: ");
        scanf("%f", &med.price);

        gotoxy(29,23); printf("Category: ");
        scanf("%d", &med.category);
        reset();
        
        //Once again open the file after its closed for the first time
        
        FILE *file = fopen("tablets.txt","a+");
        if (file == NULL) {
            boldred(); perror("Access Denied");
            reset();
            return 1;
        }
        // Write medicine information to the file

        fprintf(file, "%d %s %s %d %f %d\n", med.medId, med.medName, med.dosage, med.quantity, med.price, med.category);
        fclose(file);
        gotoxy(30,35); printf("Enter to Continue ....\n");
                getchar();
                getchar();
                optionMenu();
    
    }
     // Indicate successful operation
}
void checkStock(int category){
    defaultTemplate();
    FILE *fptr;
    fptr=fopen("tablets.txt","r");

    boldmagneta();
    
    gotoxy(32,15); printf("ID");
    gotoxy(38,15); printf("NAME");
    gotoxy(60,15); printf("DOSAGE");
    gotoxy(67,15); printf("AVAILABLE QTY");
    gotoxy(82,15); printf("PRICE");

    reset();
    int i=0;

    while(fscanf(fptr,"%d %s %s %d %f %d",&med.medId,med.medName,med.dosage,&med.quantity,&med.price,&med.category)!=EOF)
        {
            
                if(med.category==category){
                    boldCyan();
                    gotoxy(31,16+i); printf("%d",med.medId);
                    gotoxy(38,16+i); printf("%s",med.medName);
                    gotoxy(60,16+i); printf("%s",med.dosage);
                    gotoxy(70,16+i); printf("%d",med.quantity);
                    gotoxy(80,16+i); printf("%f",med.price);
                    reset();
                    i++;
                }

        }
        fclose(fptr);
        boldyellow();gotoxy(30,35); printf("Enter to Continue ....\n");
        getchar();
        getchar();
}

