#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "shoppingCart.h"

struct cart * addItem(int id, char* name, double price, int qty, struct cart *head){
    if(head == NULL) {
        head = (struct cart *)malloc(sizeof(struct cart));
        head->itemId = id;
        head->name[0] = *name;
        head->price = price;
        head->qty = qty;
        head->next = NULL;
        printf("whatever");
        return head;
    } else {
        struct cart *tail = head;
        while(tail->next != NULL) {
            tail = tail->next;
        }
        struct cart *temp = (struct cart *)malloc(sizeof(struct cart));
        temp->itemId = id;
        temp->name[0] = *name;
        temp->price = price;
        temp->qty = qty;
        temp->next = NULL;
        tail->next = temp;
    }
    return head;
}