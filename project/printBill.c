#include<stdio.h>
#include<string.h>
#include "shoppingCart.h"

void printBill(struct cart *head,double total,double tax) {
    FILE *fp;

    fp = fopen("bill.txt", "w");

    struct cart *temp = head;

        fprintf(fp,"BILL\n\n");
        fprintf(fp,"ind    name                                                                                      qty   price\n");

        int index = 1;
        while(temp!=NULL) {
            fprintf(fp,"%d    %-90s  %d     %-10.2f\n", index, temp->prodName,  temp->qty, temp->price);
            temp = temp -> next;
            index++;
        }
        fprintf(fp, "\n");
        fprintf(fp,"tax :                                                                                  6%% sales tax    %.2f\n", tax);
        fprintf(fp,"total :                                                                                                %.2f\n", total);

        fprintf(fp,"\n        *********THANK YOU*********");

    fclose(fp);
}