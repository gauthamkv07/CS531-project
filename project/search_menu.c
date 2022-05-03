#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mysql/include/mysql.h"
#include "structures.h"
#include "admin_menu.h"

void searchMenu(MYSQL *conn) {
    MYSQL_RES *result = mysql_list_tables(conn, "%");

    if (!result) {
        
        connection_error(conn);
    } 
    else {
        MYSQL_ROW row = mysql_fetch_row(result);
        if(!row){
            printf("nothing to display, database is empty. \n\n");
            return;
        }
        puts(row[0]);
        int index = 0;
        while (row = mysql_fetch_row(result)) {
            printf("%d.", index);
            puts(row[0]);
            index++;
        }
        mysql_free_result(result);
    }
    return;
}