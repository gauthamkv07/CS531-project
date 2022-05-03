#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "shoppingCart.h"

double total = 0,tax = 0;

void printBill(struct cart *head,double total,double tax);

void printShoppingCartMenu() {
    printf("1.Place Order\n");
    printf("2.Go Back\n");
}

void shoppingCart(struct cart *head) {
    if(head == NULL || head->itemId == -1) {
        printf("Cart is Empty\n");
    } else {
        struct cart *temp = head;

        //printing cart
        printf("                 CART                     \n");
        printf("id    name                                              qty   price\n");

        while(temp!=NULL) {
            total += temp->price;
            printf("%d    %-50s  %d    %-10.2f\n", temp->itemId, temp->prodName,  temp->qty, temp->price);
            temp = temp -> next;
        }
        tax += total * 0.06;
        total += total * 0.06;
        printf("tax :                                             %.2f\n", tax);
        printf("total :                              %.2f\n", total);

        //print bill
        int choice = 0;
        char buff[100];
        while(choice != 2) {
            printShoppingCartMenu();
            printf("Enter your choice:");
            fgets(buff, 100, stdin);
            choice = atoi(buff);
            switch (choice)
            {
            case 1:
                printBill(head, total, tax);
                total = 0; tax = 0;
                head->itemId = -1;
                return;
            case 2:
                break;
            default:
                printf("Not a valid option \n");
                break;
            }
        }
    }
}