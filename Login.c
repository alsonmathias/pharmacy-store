#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
// #include "colors.c"

char username[25] = "pharmacy";
char password[25] = "password";


void viewUserPass()
{
    char license[7] = "216789";
    char checkLicense[7];
    defaultTemplate();
    boldpurple();gotoxy(50,15);;printf("VIEW USERNAME & PASSWORD");
    boldCyan();gotoxy(38,20);printf("Enter Your Pharmacy License No.: ");
    for(int i=0; ; i++)
    {            
        checkLicense[i] = getch();
        if(checkLicense[i] == 13 || i == 7)
        {
            printf("       ");
            checkLicense[i] = '\0';
            break;
        }
        else if(checkLicense[i] == 8)
        {
            if(i > 0)
            {
                printf("\b");
                i -= 2;
            }
        }
        else
        {
            printf("*");
        }
    }
    reset();
    int cmp = strcmp(checkLicense,license);
    //gotoxy(38,25);printf("%d\n",cmp);

    if(cmp != 0)
    {
        boldred();gotoxy(38,24);printf("Invalid License Number, Access Denied!");
        boldyellow();gotoxy(38,26);printf("Press Enter to Continue.....");reset();
        getchar();
    }
    else
    {
        boldgreen();gotoxy(38,28);printf("Access Granted!");
        gotoxy(38,30);printf("Username: %s",username);
        gotoxy(38,31);printf("Password: %s",password);
        boldyellow();gotoxy(38,33);printf("Press Enter to Continue.....");reset();
        getchar();
    }
}

void changePassword()
{
    int oFlag, iFlag;
    char choice, conf[25], user[25];
    do
    {
        oFlag = 0;
        do
        {
            iFlag = 0;
            defaultTemplate();
            boldpurple();gotoxy(56,15);printf("CHANGE PASSWORD");
            boldCyan();gotoxy(38,20);printf("Enter the Username: ");
            gets(user);
            reset();

            if(strcmp(username,user) != 0)
            {
                boldred();gotoxy(38,22);printf("Invalid Username, Try Again!!!");
                boldblue();gotoxy(38,24);printf("Do You want to try Changing the Password, or Cancel?");
                gotoxy(38,26);printf("Press 1 to Try Again");
                gotoxy(38,27);printf("Press Any Other Key to Cancel");
                boldCyan();gotoxy(38,29);printf("Enter Your Choice: ");
                scanf("%c",&choice);
                reset();
                getchar();

                if(choice == '1')
                {
                    iFlag = 1;
                }
                else 
                {
                    iFlag = -1;
                    boldyellow();gotoxy(38,31);printf("Press Enter to Continue.....");reset();
                    getchar();
                    getchar();
                }
            }
        }while(iFlag != 0 && iFlag != -1);

        if(iFlag == 0)
        {
            boldCyan();gotoxy(38,22);printf("Create a New Password: ");
            for(int i=0; ; i++)
            {            
                password[i] = getch();
                if(password[i] == 13 || i == 24)
                {
                    printf("                         ");
                    password[i] = '\0';
                    break;
                }
                else if(password[i] == 8)
                {
                    if(i > 0)
                    {
                        printf("\b");
                        i -= 2;
                    }
                }
                else
                {
                    printf("*");
                }
            }
            
            gotoxy(38,24);printf("Confirm the New Password: ");
            for(int i=0; ; i++)
            {            
                conf[i] = getch();
                if(conf[i] == 13 || i == 24)
                {
                    printf("                         ");
                    conf[i] = '\0';
                    break;
                }
                else if(conf[i] == 8)
                {
                    if(i > 0)
                    {
                        printf("\b");
                        i -= 2;
                    }
                }
                else
                {
                    printf("*");
                }
            }
            reset();

            if(strcmp(password,conf) == 0)
            {
                oFlag = 0;
                boldgreen();gotoxy(38,26);printf("Password Change Successful!!!");
                boldyellow();gotoxy(38,30);printf("Press Enter to Continue.....");reset();
                getchar();
            }
            else
            {
                oFlag = 1;
                boldred();gotoxy(38,26);printf("Password & Confirmation Do Not Match.");
                gotoxy(38,27);printf("Try Again!!!");
                boldyellow();gotoxy(38,30);printf("Press Enter to Continue.....");
                getchar();
            }
        }
    }while(oFlag != 0);
}

void login()
{
    int flag = 0;
    char choice;
    char user[25],conf[25];

    do
    {
        defaultTemplate();
         boldpurple();gotoxy(60,15);printf("LOGIN");
        boldCyan();gotoxy(38,20);printf("Enter the Username: ");
        gets(user);
        gotoxy(38,22);printf("Enter the Password: ");
        for(int i=0; ; i++)
        {            
            conf[i] = getch();
            if(conf[i] == 13 || i == 24)
            {
                printf("                         ");
                conf[i] = '\0';
                break;
            }
            else if(conf[i] == 8)
            {
                if(i > 0)
                {
                    printf("\b");
                    i -= 2;
                }
            }
            else
            {
                printf("*");
            }
        }
        printf("\n");
        reset();

        int userVal = strcmp(username,user);
        int passVal = strcmp(password,conf);
        if(userVal == 0 && passVal == 0)
        {
            boldgreen();gotoxy(38,29);printf("Login Successful!!!\n");
            boldyellow();gotoxy(38,30);printf("Press Enter to Continue......");reset();
            getchar();
            optionMenu();
            break;
        }
        else
        {
            boldred();gotoxy(38,28);printf("Invalid Username or Password!!!\n");
            boldblue();gotoxy(38,29);printf("Do You want to try Login Again, Change the Password or Cancel?");
            gotoxy(38,31);printf("Press 1 to try Login Again");
            gotoxy(38,32);printf("Press 2 to Change Login Password");
            gotoxy(38,33);printf("Press Any Other Key to Cancel");
            boldCyan();gotoxy(38,35);printf("Enter Your Choice: ");
            scanf("%c",&choice);
            reset();
            getchar();

            if(choice == '1')
            {
                flag = 1;
                boldyellow();gotoxy(38,38);printf("Press Enter to Proceed......");reset();
                getchar();
            }
            else if(choice == '2')
            {
                boldyellow();gotoxy(38,38);printf("Press Enter to Proceed......");reset();
                getchar();
                changePassword();
                flag = -1;
            }
            else
            {
                flag = -1;
                // gotoxy(38,20);printf("Press Enter to Continue......");
                // getchar();
                break;
            }
        }
    }while(flag != 0 && flag != -1);
}

void loginMenu()
{
    int choice;
    do
    {
        defaultTemplate();
        boldblue();gotoxy(44,20);printf("1. Login");
        gotoxy(44,21);printf("2. Change Password");
        gotoxy(44,22);printf("3. View Username & Password");
        gotoxy(44,23);printf("4. Exit");
        boldCyan();gotoxy(44,25);printf("Enter your choice: ");
        scanf("%d", &choice);
        reset();
        getchar();
        switch(choice)
        {
            case 1: login();
                    break;

            case 2: changePassword();
                    break;

            case 3: viewUserPass();

            case 4: LandingPageTemplate();
                    break;

            default: boldred();gotoxy(44,28);printf("Invalid Choice, Try Again......");
                     boldyellow();gotoxy(44,29);printf("Press Enter to Continue......");reset();
                     getchar();
                     break;
        }
    }while(choice != 4);
   // boldyellow();gotoxy(44,21);printf("Press Enter to Exit......");reset();
    //getchar();
    
    //system("cls");
}