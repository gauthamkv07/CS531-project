#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "shoppingCart.h"

struct cart * addItem(int id, char name[25], float price, int qty, struct cart *head){
    if(head == NULL || head->itemId == -1) {
        head = (struct cart *)malloc(sizeof(struct cart));
        head->itemId = id;
        strcpy(head->name,name);
        head->price = price;
        head->qty = qty;
        head->next = NULL;
        return head;
    } else {
        struct cart *tail = head;
        if(tail->itemId == id) {
            tail->price += price;
            tail->qty += qty;
            return head;
        }
        while(tail->next != NULL) {
            tail = tail->next;
            if(tail != NULL) {
                if(tail->itemId == id && !strcmp(tail->name, name)) {
                    tail->price += price;
                    tail->qty += qty;
                    return head;
                }
            }
        }
        struct cart *temp = (struct cart *)malloc(sizeof(struct cart));
        temp->itemId = id;
        strcpy(temp->name,name);
        temp->price = price;
        temp->qty = qty;
        temp->next = NULL;
        tail->next = temp;
    }
    return head;
}