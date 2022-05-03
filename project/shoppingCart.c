#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "shoppingCart.h"

double total = 0,tax = 0;

void printBill(struct cart *head,double total,double tax);

void printCart(struct cart * head);

void printShoppingCartMenu() {
    printf("1.Place Order\n");
    printf("2.Clear cart\n");
    printf("3.Go Back\n");
}

void shoppingCart(struct cart *head) {
    if(head == NULL || head->itemId == -1) {
        printf("Cart is Empty\n");
    } else {
        printCart(head);

        //print bill
        int choice = 0;
        char buff[100];
        while(choice != 3) {
            printShoppingCartMenu();
            printf("Enter your choice:");
            fgets(buff, 100, stdin);
            choice = atoi(buff);
            switch (choice)
            {
            case 1:
                printf("\nOrder placed successfully\n\n");
                printBill(head, total, tax);
                total = 0; tax = 0;
                head->itemId = -1;
                return;
            case 2:
                printf("\nCart cleared\n\n");
                head->itemId = -1;
                return;
            case 3:
                break;
            default:
                printf("Not a valid option \n");
                break;
            }
        }
    }
}

void printCart(struct cart * head) {
    struct cart *temp = head;

        //printing cart
        printf("\nCART                     \n\n");
        printf("ind    name                                                                                      qty   price\n");

        int index = 1;
        while(temp!=NULL) {
            total += temp->price;
            printf("%d    %-90s  %d     %-10.2f\n", index, temp->prodName,  temp->qty, temp->price);
            temp = temp -> next;
            index++;
        }
        printf("\n");
        tax += total * 0.06;
        total += total * 0.06;
        printf("tax :                                                                                                  %.2f\n", tax);
        printf("total :                                                                                                %.2f\n", total);
}