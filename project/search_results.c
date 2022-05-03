#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mysql/include/mysql.h"
#include "structures.h"
#include "admin_menu.h"

void searchResults(MYSQL *conn , char product[25], char brand[25]) {
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
            puts(row[2]);
            while (row = mysql_fetch_row(result)) {
                    // printf("%d.", index);
                    // strncpy(brands[index-1],row[0],25);
                puts(row[2]);
            }
        }
    }
}