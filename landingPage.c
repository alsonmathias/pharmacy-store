
void landingPage(){
    LandingPageTemplate();
    redLogo();
    pharmName();
    boldred(); gotoxy(12,28); printf("Email:"); boldwhite(); printf(" Maksad911@gmail.com"); 
    boldred(); gotoxy(90,28); printf("Phone: ");boldwhite(); printf("+91 9112266779 ");reset();
    gotoxy(0,40);
    getchar();
    getchar();
    loginMenu();
    return; 
}
