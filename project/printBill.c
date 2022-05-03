#include<stdio.h>
#include<string.h>
#include "shoppingCart.h"

void printBill(struct cart *head,double total,double tax) {
    FILE *fp;

    fp = fopen("bill.txt", "w");

    struct cart *temp = head;

        fprintf(fp,"                 BILL                     \n");
        printf("id    name                                              qty   price\n");

        while(temp!=NULL) {
            printf("%d    %-50s  %d    %-10.2f\n", temp->itemId, temp->prodName,  temp->qty, temp->price);
            temp = temp -> next;
        }
        printf("tax :                                                         %.2f\n", tax);
        printf("total :                                                       %.2f\n", total);

        fprintf(fp,"\n        *********THANK YOU*********");

    fclose(fp);
}