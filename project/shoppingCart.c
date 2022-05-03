#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "shoppingCart.h"

double total = 0,tax = 0;

void printBill(struct cart *head,double total,double tax);

int printCart(struct cart * head);

void printShoppingCartMenu() {
    printf("\nCart menu:\n");
    printf("1.Place Order\n");
    printf("2.update cart item\n");
    printf("3.Clear cart\n");
    printf("4.Go Back\n");
}

void shoppingCart(struct cart *head) {
    if(head == NULL || head->itemId == -1) {
        printf("Cart is Empty\n");
    } else {
        int index = printCart(head);

        //print bill
        int choice = 0;
        char buff[100];
        int updateChoice = 0;
        char buffer[100];
        while(choice != 4) {
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
                while(updateChoice == 0 || updateChoice >= index) {
                    printf("Choose iitem to edit: ");
                    fgets(buffer, 100, stdin);
                    updateChoice = atoi(buffer);
                    if(updateChoice == 0 || updateChoice >= index) {
                        printf("Not an valid option\n");
                    } else {
                        int qty = 0;
                        char qtyBuffer[100];
                        while(qty <= 0 || qty > 5) {
                            printf("Enter qty: ");
                            fgets(qtyBuffer, 100, stdin);
                            qty = atoi(qtyBuffer);
                            if(qty <= 0) {
                                printf("Not an valid qty\n");
                            } else {
                                struct cart * temp = head;
                                int itr = 1;
                                while(itr < updateChoice) {
                                    temp = temp->next;
                                    itr++;
                                }
                                temp -> price = (temp->price/temp->qty) *qty;
                                temp -> qty = qty;
                            }
                        }
                    }
                }
                index = printCart(head);
                updateChoice = 0;
                break;
            case 3:
                printf("\nCart cleared\n\n");
                head->itemId = -1;
                return;
            case 4:
                break;
            default:
                printf("Not a valid option \n");
                break;
            }
        }
    }
}

int printCart(struct cart * head) {
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
        return index;
}