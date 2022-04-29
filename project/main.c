#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "shoppingCart.h"

//function to display shopping cart
void shoppingCart(struct cart *head,struct cart *tail);

//function to add Item
struct cart * addItem(int id, char* name, double price, int qty, struct cart *head);

void printMenu() {
    printf("1.Admin\n");
    printf("2.Search for Products\n");
    printf("3.My Shopping Cart\n");
    printf("4.Quit\n");
}

void main() {
    struct cart *head = NULL,*tail = NULL;

    int choice = 0;
    char buff[100];
    while(choice != 4) {
        printMenu();
        printf("Enter your choice:");
        fgets(buff, 100, stdin);
        choice = atoi(buff);
        switch(choice) {
            case 1: 
                printf("Admin\n");
                break;
            case 2: 
                printf("Search for products\n");
                break;
            case 3:
                shoppingCart(head, tail);
                break;
            case 4:
                break;
            case 5:
                head = addItem(1,"firstItem",25.0,1,head);
                head = addItem(2,"secondItem",35.0,2,head);
                head = addItem(3,"thirdItem",45.0,1,head);
                break;
            default:
                printf("Not a valid input \n");
                break;
        }
    }
}