#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<mysql.h>
#include "structures.h"
#include "admin_menu.h"
#include "shoppingCart.h"

struct cart * addItem(int id, double price, char name[25], char prodName[25], int qty, struct cart *head);

struct cart * searchPhonesResults(MYSQL *conn , char product[25], char brand[25], int sortChoice,struct cart * head) {
    char sort[100];
    if(sortChoice == 1) {
        strcpy(sort,"asc");
    } else {
        strcpy(sort,"desc");
    }

    printf("product : %s , brand: %s \n");
    printf("Search results: \n");

    char query[500];
    sprintf(query, "SELECT * FROM %s WHERE brandName = \"%s\" order by price %s", product, brand, sort);

    if (mysql_query(conn, query)) {
        connection_error(conn);
        return head;
    } else {
        MYSQL_RES *result = mysql_store_result(conn);
        if (!result) {
            printf("Couldn't get results set: %s\n", mysql_error(conn));
        } else {
            MYSQL_ROW row = mysql_fetch_row(result);
            if(!row){
                printf("This product is not available right now. \n\n");
                return head;
            }
            char id[12][2];
            char brandName[12][25];
            char ModelNumber[12][25];
            char storage[12][25];  // frech door, side-by-side
            char color[12][25];
            char width[12][25];
            char height[12][25];
            char price[12][25];
            
            printf("Index  brandName  ModelNumber Storage  color       price\n");
            int index = 1;
            strncpy(id[index-1], row[0], 2);
            strncpy(brandName[index-1], row[1], 25);
            strncpy(ModelNumber[index-1], row[2], 25);
            strncpy(storage[index-1], row[3], 25);
            strncpy(color[index-1], row[4], 25);
            strncpy(width[index-1], row[5], 25);
            strncpy(height[index-1], row[6], 25);
            strncpy(price[index-1], row[7], 25);
            printf(" %-5d %-10s %-11s %-8s %-11s %-16s \n", index,brandName[index-1], ModelNumber[index-1],storage[index-1],color[index-1],price[index -1]);
            index++;
            while (row = mysql_fetch_row(result)) {
                strncpy(id[index-1], row[0], 2);
                strncpy(brandName[index-1], row[1], 25);
                strncpy(ModelNumber[index-1], row[2], 25);
                strncpy(storage[index-1], row[3], 25);
                strncpy(color[index-1], row[4], 25);
                strncpy(width[index-1], row[5], 25);
                strncpy(height[index-1], row[6], 25);
                strncpy(price[index-1], row[7], 25);
                printf(" %-5d %-10s %-11s %-8s %-11s %-16s \n", index,brandName[index-1], ModelNumber[index-1],storage[index-1],color[index-1],price[index -1]);
                index++;
            }
            printf(" %d. Back to main menu\n\n", index);

            int choice = 0;
            char buff[100];
            while(choice > index+1 || choice == 0) {
                printf("Choose item to add to cart or enter %d to go back: ", index);
                fgets(buff, 100, stdin);
                choice = atoi(buff);
                if(choice > index + 1 || choice == 0) {
                    printf("Choose an valid option.\n");
                }
            }
            if(choice < index) {
                int itemId = atoi(id[choice-1]);
                float itemPrice = atof(price[choice-1]);
                char prodName[200];
                strcpy(prodName, strcat(product,"("));
                strcpy(prodName, strcat(prodName,"brand: "));
                strcpy(prodName, strcat(prodName,brandName[choice-1]));
                strcpy(prodName, strcat(prodName,","));
                strcpy(prodName, strcat(prodName,"ModelNumber: "));
                strcpy(prodName, strcat(prodName,ModelNumber[choice-1]));
                strcpy(prodName, strcat(prodName,","));
                strcpy(prodName, strcat(prodName,"color: "));
                strcpy(prodName, strcat(prodName,color[choice-1]));
                strcpy(prodName, strcat(prodName,","));
                strcpy(prodName, strcat(prodName,"storage: "));
                strcpy(prodName, strcat(prodName,storage[choice-1]));
                strcpy(prodName, strcat(prodName,")"));
                return addItem(itemId,itemPrice,  product, prodName ,1, head);
            }
        }
    }
    return head;
}