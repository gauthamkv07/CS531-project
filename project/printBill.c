#include<stdio.h>
#include<string.h>
#include "shoppingCart.h"

void printBill(struct cart *head,double total,double tax) {
    FILE *fp;

    fp = fopen("bill.txt", "w");

    struct cart *temp = head;

        fprintf(fp,"                 BILL                     \n");
        fprintf(fp,"id    name                                                                                      qty   price\n");

        while(temp!=NULL) {
            fprintf(fp,"%d    %-90s  %d    %-10.2f\n", temp->itemId, temp->prodName,  temp->qty, temp->price);
            temp = temp -> next;
        }
        fprintf(fp, "\n");
        fprintf(fp,"tax :                                                                                                 %.2f\n", tax);
        fprintf(fp,"total :                                                                                               %.2f\n", total);

        fprintf(fp,"\n        *********THANK YOU*********");

    fclose(fp);
}