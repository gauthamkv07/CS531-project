#include "mysql/include/mysql.h"
void connection_error(MYSQL *conn);
int create_table(MYSQL *conn, int option);
int insert_record(MYSQL *conn, int option);
int insert_laptop(MYSQL *conn);
int insert_camera(MYSQL *conn);
int insert_phone(MYSQL *conn);
int insert_watch(MYSQL *conn);
int insert_refrigerator(MYSQL *conn);
int drop_table(MYSQL *conn, int option);
int drop_record(MYSQL *conn, int option, int id);
void display_table(MYSQL *conn);