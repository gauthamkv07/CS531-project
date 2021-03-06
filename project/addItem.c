#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "shoppingCart.h"

void printAdded();

struct cart * addItem(int id, double price, char name[25], char prodName[200], int qty, struct cart *head){
    if(head == NULL || head->itemId == -1) {
        head = (struct cart *)malloc(sizeof(struct cart));
        head->itemId = id;
        strcpy(head->name,name);
        strcpy(head->prodName, prodName);
        head->price = price;
        head->qty = qty;
        head->next = NULL;
        printAdded();
        return head;
    } else {
        struct cart *tail = head;
        if(tail->itemId == id && strcmp(tail->name, name) == 0) {
            tail->price += price;
            tail->qty += qty;
            printAdded();
            return head;
        }
        while(tail->next != NULL) {
            tail = tail->next;
            if(tail != NULL) {
                if(tail->itemId == id && strcmp(tail->name, name) == 0) {
                    tail->price += price;
                    tail->qty += qty;
                    printAdded();
                    return head;
                }
            }
        }
        struct cart *temp = (struct cart *)malloc(sizeof(struct cart));
        temp->itemId = id;
        strcpy(temp->name,name);
        strcpy(temp->prodName, prodName);
        temp->price = price;
        temp->qty = qty;
        temp->next = NULL;
        tail->next = temp;
    }
    printAdded();
    return head;
}

void printAdded() {
    printf("Item added to cart\n");
}