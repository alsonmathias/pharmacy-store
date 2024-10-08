#include <stdio.h>

void billStore(float totalAmount) {
    FILE *file = fopen("billAmount.txt", "a+");
    if(file == NULL) {
        perror("Access Denied: ");
        return;
    }
    fprintf(file, "%0.2f\n", totalAmount);
    fclose(file);
}

void dailyProfit() {
    FILE *file = fopen("billAmount.txt", "r");
    if(file == NULL) {
        perror("Access Denied: ");
        return;
    }
    float billAmount, totalAmount = 0;
    while(fscanf(file, "%f", &billAmount) != EOF){
        totalAmount += billAmount;
    }
    printf("Turnover: %0.2f", totalAmount);
    fclose(file);
}
void main() {
    billStore(1001);
    dailyProfit();
}