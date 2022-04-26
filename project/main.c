#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"

void printMenu() {
    printf("1.Admin\n");
    printf("2.Search for Products\n");
    printf("3.My Shopping Cart\n");
    printf("4.Quit\n");
}

void main() {
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
                printf("My Shopping Cart\n");
                break;
            case 4:
                break;
            default:
                printf("Not a valid input \n");
                break;
        }
    }
}