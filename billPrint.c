#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>

struct Patientnew {
    int patId;
    char patName[25];
    int age;
    char gender;
    char phNumber[12];
    
};

struct Medicinenew {
    int medId;
    char medName[100];
    char dosage[100];
    int quantity;
    float price;
    int category;
};

struct Patientnew patt;
struct Medicinenew medd;

void drawLine()
{
    for(int i=27;i<105;i++)
    {
        printf("-");
    }
}

int extractPatientDetails(int patId) {
    FILE *file = fopen("patient.txt","r");
    if (file == NULL) {
        perror("Access Denied");
        return 1;
    }

    while (fscanf(file, "%d %s %d %c %s\n", &patt.patId, patt.patName, &patt.age, &patt.gender, patt.phNumber)!= EOF) {
        if (patt.patId == patId) {
            break;
            return;
            //fclose(file);
        }
    }
    fclose(file);
}

//function to print date
void billingTime() {
    time_t t;   
    time(&t);
    boldred();printf("Bill Date: ");boldwhite();printf("%s", ctime(&t));
    reset();
}

int extractMedicineDetails() {
    FILE *file = fopen("purchasedItems.txt","r");
    if (file == NULL) {
        perror("Access Denied");
        return 1;
    }
    boldgreen();
    float sgst=0, cgst=0, totalBillAmount=0, billAmount=0, discount=0;
    int i=1;
    while (fscanf(file, "%d %s %s %d %f %d", &medd.medId, medd.medName, medd.dosage, &medd.quantity, &medd.price, &medd.category) != EOF) {
        gotoxy(30,11+i);  printf("%d",medd.medId); gotoxy(43,11+i); printf("%s",medd.medName);gotoxy(64,11+i); printf("%s",medd.dosage);gotoxy(73,11+i);printf("%d",medd.quantity);gotoxy(85,11+i); printf("%0.2f",medd.price);

        //dont touch this code
        sgst += 0.09 * medd.price * medd.quantity;
        cgst += 0.09 * medd.price * medd.quantity;
        billAmount = medd.price * medd.quantity;

        //use goto whatever u want here it should be printed everytime under the price section
        gotoxy(98,11+i);printf("%0.2f", billAmount);

        totalBillAmount += billAmount;
        i++;
    }
    fclose(file);
    boldwhite();gotoxy(38,28);printf("Bill Amount: %0.2f", totalBillAmount);
    reset();
    if(totalBillAmount>=1000 && totalBillAmount <2000) {
        discount = totalBillAmount * 0.01;
    }
    if(totalBillAmount>=2000 && totalBillAmount <3000) {
        discount = totalBillAmount * 0.02;
    }
    if(totalBillAmount>3000) {
        discount = totalBillAmount * 0.04;
    }
    FILE *purchase = fopen("purchasedItems.txt","w");
    if(purchase == NULL) {
        perror("Access Denied");
        return 1;
    }
    fclose(purchase);
    gotoxy(27,27);drawLine();
    boldwhite();gotoxy(38,29);printf("Discount: %0.2f", discount);
    gotoxy(38,30);printf("SGST (9%%): %0.2f",sgst);
    gotoxy(38,31);printf("CGST (9%%): %0.2f", cgst);
    totalBillAmount += sgst + cgst - discount;
    gotoxy(38,32);printf("Total Bill Amount: %0.2f", totalBillAmount);
    reset();
}


void printBill(int patId) {
    billTemplate();
    extractPatientDetails(patId);
    boldred();gotoxy(54,2);printf("MAKSAD ");boldwhite();printf("PHARMACY");
    boldred();gotoxy(31,3);printf("E-Mail: ");boldwhite();printf("maksad911@gmail.com");gotoxy(68,3);boldred();printf("Phone: ");boldwhite();printf("+91 9112266779");
    boldred();gotoxy(30,4);printf("GST No.: ");boldwhite();printf("29AAAAA0000A1Z5");gotoxy(64,4);billingTime();
    reset();
    gotoxy(27,5);drawLine();
    boldmagneta();gotoxy(53,6);printf("Patient Details");
    
    boldCyan();gotoxy(35,7);printf("ID: %d",patt.patId);
    gotoxy(59,7);printf("Age: %d",patt.age);
    gotoxy(78,7);printf("Gender: %c",patt.gender);
    gotoxy(35,8);printf("Patient Name: %s",patt.patName);
    gotoxy(78,8);printf("Number: %s",patt.phNumber);
    reset();
    gotoxy(27,9);drawLine();

    boldyellow();gotoxy(30,10);printf("Med.ID");
    gotoxy(43,10);printf("Item");
    gotoxy(64,10);printf("Dosage");
    gotoxy(73,10);printf("Quantity");
    gotoxy(85,10);printf("Unit Price");
    gotoxy(98,10);printf("Price");
    reset();
    gotoxy(27,11);drawLine();
    extractMedicineDetails();
    gotoxy(27,33);drawLine();
    boldCyan();gotoxy(38,34);printf("Thank You For Visiting, Take Care");reset();
    gotoxy(1,37);

    getchar();
    getchar();
}

