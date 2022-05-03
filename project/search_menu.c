#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mysql/include/mysql.h"
#include "structures.h"
#include "admin_menu.h"

void searchResults(MYSQL *conn);

void searchMenu(MYSQL *conn) {
    
    int index = 1;
    MYSQL_RES *result = mysql_list_tables(conn, "%");
    char tables[12][25];

    if (!result) {
        connection_error(conn);
        return;
    } 
    else {
        MYSQL_ROW row = mysql_fetch_row(result);
        if(!row){
            printf("nothing to display, database is empty. \n\n");
            return;
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
        char selectQuery[50];
        strcpy(selectQuery, "SELECT distinct brandName FROM ");
        strcpy(query, strcat(selectQuery , tables[choice-1]));
        if (mysql_query(conn, query)) {
            connection_error(conn);
            return;
        } else {
            MYSQL_RES *result = mysql_store_result(conn);
            if (!result) {
                printf("Couldn't get results set: %s\n", mysql_error(conn));
            } else {
                MYSQL_ROW row = mysql_fetch_row(result);
                if(!row){
                    printf("This product is not available right now. \n\n");
                    return;
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
                if(choice < index) {
                    searchResults(conn);
                }
            } 
        }
    }
}