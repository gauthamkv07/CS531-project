#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "shoppingCart.h"

struct cart * addItem(int id, char name[25], double price, int qty, struct cart *head){
    printf("in addItem");
    if(head == NULL) {
        printf("in addItem head null");
        head = (struct cart *)malloc(sizeof(struct cart));
        head->itemId = id;
        strcpy(head->name,name);
        head->price = price*qty;
        head->qty = qty;
        head->next = NULL;
        return head;
    } else if(head->itemId == -1){
        printf("in addItem head -1");
        head->itemId = id;
        strcpy(head->name,name);
        head->price = price*qty;
        head->qty = qty;
        head->next = NULL;
        return head;
    }else {
        printf("in addItem tail");
        struct cart *tail = head;
        if(tail->itemId == id) {
            tail->price += qty*price;
            tail->qty += qty;
            return head;
        }
        while(tail->next != NULL) {
            tail = tail->next;
            if(tail != NULL) {
                if(tail->itemId == id) {
                    tail->price += qty*price;
                    tail->qty += qty;
                    return head;
                }
            }
        }
        struct cart *temp = (struct cart *)malloc(sizeof(struct cart));
        temp->itemId = id;
        strcpy(temp->name,name);
        temp->price = price*qty;
        temp->qty = qty;
        temp->next = NULL;
        tail->next = temp;
    }
    return head;
}