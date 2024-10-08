
void optionMenu(){
    defaultTemplate();
    int option, id,patId,category;
    boldred(); gotoxy(49,20); printf("[1] CREATE BILL");
    boldwhite(); gotoxy(49,22); printf("[2] ADD STOCK");
    boldred(); gotoxy(49,24); printf("[3] MODIFY STOCK");
    boldwhite(); gotoxy(49,26); printf("[4] CHECK STOCK");
    boldred(); gotoxy(49,28); printf("[5] LOGOUT");
    boldwhite(); gotoxy(49,30); printf("[6] EXIT");
    boldwhite(); gotoxy(49,32); printf("Enter the Option: ");
    scanf("%d",&option);reset();
    switch(option){
        case 1: patId = pateintDetailsInput();  
                createBill(selectCategory(),patId);
            break;
        case 2: inputMedicine();
            break;
        case 3: defaultTemplate();
                gotoxy(29,23); boldCyan(); printf("Enter MedId :");
                scanf("%d",&id);reset();
                modifyMedicine(id);
            break;
        case 4: category = selectCategory();
                checkStock(category);
            break;
        case 5:landingPage();
                break;
        case 6:gotoxy(0,50);exit(0);
        default:gotoxy(30,33); printf("Invalid Category!!! Please Enter Valid category Number");
                gotoxy(30,35); printf("Enter to Continue ....\n");
                getchar();
                getchar();
                break;
    }
    optionMenu();

}