#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mysql/include/mysql.h"
#include "structures.h"
#include "admin_menu.h"
#include "shoppingCart.h"

struct cart * searchResults(MYSQL *conn,char product[25], char brand[25], struct cart * head);

struct cart * searchMenu(MYSQL *conn, struct cart *head) {
    
    int index = 1;
    MYSQL_RES *result = mysql_list_tables(conn, "%");
    char tables[12][25];

    if (!result) {
        connection_error(conn);
        return head;
    } 
    else {
        MYSQL_ROW row = mysql_fetch_row(result);
        if(!row){
            printf("nothing to display, database is empty. \n\n");
            return head;
        }
        printf("\n%d.", index);
        strncpy(tables[index-1],row[0],25);
        puts(row[0]);
        index++;
        while (row = mysql_fetch_row(result)) {
            printf("%d.", index);
            strncpy(tables[index-1],row[0],25);
            puts(row[0]);
            index++;
        }
        printf("%d.Back to the main menu\n\n", index);
        mysql_free_result(result);
    }

    int choice = 0;
    char buff[100];
    char query[500];
    while(choice > index+1 || choice == 0) {
        printf("Choose option: ");
        fgets(buff, 100, stdin);
        choice = atoi(buff);
        if(choice > index + 1 || choice == 0) {
            printf("Choose an valid option.\n");
        }
    }
    
    if(choice <index){
        if(!strcmp(tables[choice-1],"laptops")) {
           char selectQuery[50];
            char table[25];
            strcpy(table, tables[choice - 1]);
            strcpy(selectQuery, "SELECT distinct brandName FROM ");
            strcpy(query, strcat(selectQuery , tables[choice-1]));
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
                    char brands[12][25];
                    index = 1;
                    printf("\nBrands: \n");
                    printf("%d.", index);
                    strncpy(tables[index-1],row[0],25);
                    puts(row[0]);
                    index++;
                    while (row = mysql_fetch_row(result)) {
                        printf("%d.", index);
                        strncpy(brands[index-1],row[0],25);
                        puts(row[0]);
                        index++;
                    }
                    printf("%d.Back to the main menu\n\n", index);

                    choice = 0;
                    while(choice > index+1 || choice == 0) {
                        printf("Choose brand: ");
                        fgets(buff, 100, stdin);
                        choice = atoi(buff);
                        if(choice > index + 1 || choice == 0) {
                            printf("Choose an valid option.\n");
                        }
                    }
                    char brand[25];
                    strcpy(brand, brands[choice - 1]);

                    if(choice < index) {
                        sprintf(query, "select distinct processorBrand from %s where brandName = \"%s\"", table, brand);
                        MYSQL_RES *brandResult = mysql_store_result(conn);
                        if (!brandResult) {
                            printf("Couldn't get results set: %s\n", mysql_error(conn));
                            return head;
                        }
                        if (mysql_query(conn, query)) {
                            connection_error(conn);
                            return head;
                        } else {
                            row = mysql_fetch_row(brandResult);
                            if(!row){
                                printf("This product is not available right now. \n\n");
                                return head;
                            }
                            index = 1;
                            printf("processorBrands: \n");
                            char processorBrands[12][25];
                            char processorBrand[25];
                            printf("%d.", index);
                            strncpy(processorBrands[index-1],row[0],25);
                            puts(row[0]);
                            index++;
                            while (row = mysql_fetch_row(result)) {
                                printf("%d.", index);
                                strncpy(processorBrands[index-1],row[0],25);
                                puts(row[0]);
                                index++;
                            }
                            printf("%d.Back to the main menu\n\n", index);

                            choice = 0;
                            while(choice > index+1 || choice == 0) {
                                printf("Choose processor brand: ");
                                fgets(buff, 100, stdin);
                                choice = atoi(buff);
                                if(choice > index + 1 || choice == 0) {
                                    printf("Choose an valid option.\n");
                                }
                            }
                            strcpy(processorBrand, processorBrands[choice - 1]);
                            return searchResults(conn, table ,brands[choice-1],head);
                        }
                    }
                } 
            } 
        }
    }
    return head;
}