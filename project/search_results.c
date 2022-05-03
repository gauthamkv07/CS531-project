#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mysql/include/mysql.h"
#include "structures.h"
#include "admin_menu.h"
#include "shoppingCart.h"

struct cart * addItem(int id, char name[25], double price, int qty, struct cart *head);

struct cart * searchResults(MYSQL *conn , char product[25], char brand[25], struct cart * head) {
    printf("product : %s , brand: %s \n");
    printf("Search results: \n");

    char query[500],queryPt1[500],queryPt2[500];
    strcpy(queryPt1, "SELECT distinct id, brandName, price FROM ");
    strcpy(queryPt1, strcat(queryPt1, product));
    strcpy(queryPt2, " WHERE brandName = \"");
    strcpy(queryPt2, strcat(queryPt2, brand));
    strcpy(queryPt2, strcat(queryPt2, "\";"));
    strcpy(query, strcat(queryPt1,queryPt2));

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
            char price[12][25];
            
            int index = 1;
            strncpy(id[index-1], row[0], 2);
            strncpy(brandName[index-1], row[1], 25);
            strncpy(price[index-1], row[2], 25);
            printf("%-5d %-25s %-10s \n", index,brandName,price);
            index++;
            while (row = mysql_fetch_row(result)) {
                strncpy(id[index-1], row[0], 2);
                strncpy(brandName[index-1], row[1], 25);
                strncpy(price[index-1], row[2], 25);
                printf("%-5s %-25s %-10s \n", index,brandName,price);
                index++;
            }
            printf("%d. Back to main menu\n\n", index);

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
                return addItem(itemId,product, itemPrice, 1, head);
            }
        }
    }
    return head;
}