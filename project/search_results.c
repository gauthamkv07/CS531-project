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
    strcpy(queryPt1, "SELECT distinct id, ");
    strcpy(queryPt1, strcat(queryPt1, product));
    strcpy(queryPt2,", price  FROM ");
    strcpy(query, strcat(queryPt1,queryPt2));
    printf("%s\n\n", query);
}