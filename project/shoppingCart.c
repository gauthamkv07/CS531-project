#include<stdio.h>
#include<string.h>
#include "shoppingCart.h"

void shoppingCart(struct cart *head,struct cart *tail) {
    if(head == NULL) {
        printf("Cart is Empty\n");
    } else {
        struct cart *temp = head;

        while(temp!=NULL) {
            printf("%d\n", temp->itemId);
            temp = temp -> next;
        }
    }
}