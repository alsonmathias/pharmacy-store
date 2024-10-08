#include<stdio.h>

void boldred () {
  printf("\033[1;31m");
}

void boldyellow(){
  printf("\033[1;33m");
}
void boldblack(){
    printf("\033[1;30m");
}
void boldgreen()
{
    printf("\033[1;32m");
}
void boldblue()
{
    printf("\033[1;34m");
}
void boldpurple()
{
    printf("\033[1;35m");
}
void boldCyan(){
    printf("\033[1;36m");
}
void boldmagneta()
{
   printf("\033[1;35m");
}
void boldwhite()
{
  printf("\033[1;37m");
}

void red () {
  printf("\033[0;31m");

}

void yellow(){
  printf("\033[0;33m");
}
void black(){
    printf("\033[0;30m");
}
void green()
{
    printf("\033[0;32m");
}
void blue()
{
    printf("\033[0;34m");
}
void purple()
{
    printf("\033[0;35m");
}
void Cyan(){
    printf("\033[0;36m");
}
void magneta()
{
   printf("\033[0;35m");
}
void reset() {
  printf("\033[0m");
}
void bkwhite()
{
  printf("\033[107m");
}
void bkcyan()
{
  printf("\033[46m");
}
// void main()
// {
//   red();
//   printf("Hello world\n");
//   yellow();
//   printf("Hello world\n");
//   black();
//   printf("Hello world\n");
//   green();
//   printf("Hello world\n");
//   blue();
//   printf("Hello world\n");
//   purple();
//   printf("Hello world\n");
//   Cyan();
//   printf("Hello world\n");
//   magneta();
//   printf("Hello world\n");


//   boldred();
//   printf("Hello world\n");
//   boldyellow();
//   printf("Hello world\n");
//   boldblack();
//   printf("Hello world\n");
//   boldgreen();
//   printf("Hello world\n");
//   boldblue();
//   printf("Hello world\n");
//   boldpurple();
//   printf("Hello world\n");
//   boldCyan();
//   printf("Hello world\n");
//   boldmagneta();
//   printf("Hello world\n");
// }