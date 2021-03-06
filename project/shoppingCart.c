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
    printf("3.Delete cart item\n");
    printf("4.Clear cart\n");
    printf("5.Go Back\n");
}

void shoppingCart(struct cart *head) {
    if(head == NULL || head->itemId == -1) {
        printf("Cart is Empty\n");
    } else {
        int index = printCart(head);

        //print bill
        int choice = 0,updateChoice = 0 , deleteChoice = 0;
        char buff[100], buffer[100], deleteBuffer[100];
        while(choice != 5) {
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
                total = 0;tax = 0;
                index = printCart(head);
                updateChoice = 0;
                break;
            case 3:
                while(deleteChoice == 0 || deleteChoice >= index) {
                    printf("choose Item to delete: ");
                    fgets(deleteBuffer, 100 ,stdin);
                    deleteChoice = atoi(deleteBuffer);
                    if(deleteChoice == 0 || deleteChoice >= index) {
                        printf("Not an valid option\n");
                    } else {
                        if(deleteChoice == 1 && index == 2) {
                            head -> itemId = -1;
                            printf("\nCart is Empty\n");
                            return;
                        } else {
                            struct cart * temp = head;
                            int itr = 1;
                            while(itr < updateChoice-1) {
                                temp = temp->next;
                                itr++;
                            }
                            if(temp->next->next == NULL) {
                                temp -> next = NULL;
                            } else {
                                temp -> next = temp -> next -> next;
                            }
                            printf("\nDeleted Item\n\n");
                        }
                    }
                }
                total = 0;tax = 0;
                index = printCart(head);
                deleteChoice = 0;
                break;
            case 4:
                printf("\nCart cleared\n\n");
                head->itemId = -1;
                return;
            case 5:
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
        total += tax;
        printf("tax :                                                                                  6%% sales tax    %.2f\n", tax);
        printf("total :                                                                                                %.2f\n", total);
        return index;
}