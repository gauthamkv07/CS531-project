#include<stdio.h>
#include<string.h>
#include "shoppingCart.h"

double total = 0,tax = 0;

void shoppingCart(struct cart *head,struct cart *tail) {
    if(head == NULL) {
        printf("Cart is Empty\n");
    } else {
        struct cart *temp = head;

        printf("                 CART                     \n");
        printf("id    name                     qty   price\n");

        while(temp!=NULL) {
            total += temp->price;
            printf("%d    %-25s  %d    %-10.2f\n", temp->itemId, temp->name,  temp->qty, temp->price);
            temp = temp -> next;
        }
        tax += total * 0.06;
        total += total * 0.06;
        printf("tax :                                %.2f\n", tax);
        printf("total :                              %.2f\n", total);
    }
}