#include<stdio.h>
#include<stdlib.h>

struct medicine {
    int medId;
    char medName[100];
    char dosage[100];
    int quantity;
    float price;
    int purchasedQty;
    int category;
};
struct medicine item;



//Menu for Selecting Medicines
void createBill(int category, int patId) {
    int id, purchasedQty, purchaseFlag = 0;
    char choice;
    FILE *items, *purchase;

    system("cls");
    defaultTemplate();
    boldred(); 
    gotoxy(30, 15); printf("MedID"); 
    gotoxy(30 + 8, 15); printf("Medicine Name");
    gotoxy(30 + 35, 15); printf("Dosage");
    gotoxy(30 + 50, 15); printf("Price");

    items = fopen("tablets.txt", "r");
    if (items == NULL) {
        perror("Error opening file");
        return;
    }

    int j = 0;
    while (fscanf(items, "%d %s %s %d %f %d", &item.medId, item.medName, item.dosage, &item.quantity, &item.price, &item.category) != EOF) {
        if (item.category == category) {
            boldwhite(); 
            gotoxy(30, 17 + j); printf("%d", item.medId); 
            gotoxy(30 + 8, 17 + j); printf("%s", item.medName);
            gotoxy(30 + 35, 17 + j); printf("%s", item.dosage);
            gotoxy(30 + 50, 17 + j); printf("%0.2f", item.price); 
            reset();
            j++;
        }
    }
    fclose(items);

    boldwhite();
    gotoxy(35, 27); printf("SELECT THE MEDICINE BY ENTERING THE ID:  ");
    scanf("%d", &id);
    gotoxy(35, 28); printf("ENTER THE QUANTITY:  ");
    scanf("%d", &purchasedQty);
    reset();

    items = fopen("tablets.txt", "r");
    if (items == NULL) {
        perror("Error opening file");
        return;
    }

    purchase = fopen("purchasedItems.txt", "a+");
    if (purchase == NULL) {
        perror("Access Denied");
        return;
    }

    while (fscanf(items, "%d %s %s %d %f %d", &item.medId, item.medName, item.dosage, &item.quantity, &item.price, &item.category) != EOF) {
        if (item.medId == id && item.category == category) {
            if (item.quantity - purchasedQty < 0) {
                boldyellow(); 
                gotoxy(40, 31); printf("THE ITEM IS NOT AVAILABLE CURRENTLY\n"); 
                reset();
                purchaseFlag = 1;
                break;
            }
            // To Deduct the Qty in the File
            fclose(items);
            modifyQuantityUsingBill(id, purchasedQty);

            fprintf(purchase, "%d %s %s %d %f %d\n", item.medId, item.medName, item.dosage, purchasedQty, item.price, item.category);
            purchaseFlag = 1;
        }
    }
    fclose(items);
    fclose(purchase);

    if (purchaseFlag != 1) {
        boldyellow(); 
        gotoxy(30, 31); printf("The Entered Id is Invalid. Please Enter Valid ID..."); 
        reset();
        getchar();
        getchar();
    }

    boldyellow(); 
    gotoxy(38, 33); printf("IF YOU WANT TO ADD MORE ENTER \"Y\" ELSE \"N\"");
    gotoxy(38, 34); scanf(" %c", &choice); 
    reset();

    if (choice == 'N' || choice == 'n') {
        printBill(patId);
    } else {
        createBill(selectCategory(), patId);
    }
}


//Menu to Select category
int selectCategory(){
    int category;
    system("cls");
    defaultTemplate();
    gotoxy(35,15); boldred(); printf("[1].TABLETS");      gotoxy(40+25,15); boldblue(); printf("[2].SYRUPS");
    gotoxy(35,20); boldyellow(); printf("[3].WOUND CARE & DRESSINGS");      gotoxy(40+25,20); boldgreen(); printf("[4].OTHER ITEMS");
    gotoxy(35,25); boldwhite(); printf("SELECT THE CATEGORY ");
    gotoxy(35,27); scanf("%d",&category);reset();

    switch(category){
        case 1:
        case 2:
        case 3:
        case 4:return category;
            break;
        default:boldred();gotoxy(30,29); printf("Invalid Category!!! Please Enter Valid category Number\n");
                boldyellow();gotoxy(30,30); printf("Enter to Continue ....\n");
                getchar();
                getchar();
                reset();
                selectCategory();
            break;
    }
}

