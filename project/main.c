#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mysql/include/mysql.h"
#include "structures.h"
#include "admin_menu.h"

//temp
void printMenu() {
    printf("------------------------------------\n");
    printf("1.Admin\n");
    printf("2.Search for Products\n");
    printf("3.My Shopping Cart\n");
    printf("4.Quit\n");
    printf("Enter your choice:");
}

void print_admin_menu() {
    // display admin menu
    printf("------------------------------------\n");
    printf("1.Insert Product Info\n");
    printf("2.Delete Product Info\n");
    printf("3.Display the list of products\n");
    printf("4.Back to main menu\n");
    printf("Enter your choice:");
}

void print_insert_menu() {
    // display insert menu
    printf("------------------------------------\n");
    printf("1.Insert Product Table\n");
    printf("2.Insert Product Item\n");
    printf("Enter your choice:");
}

void print_delete_menu() {
    printf("------------------------------------\n");
    printf("1.Delete Product Table\n");
    printf("2.Delete Product Item\n");
    printf("Enter your choice:");
}

void print_display_menu() {
    printf("------------------------------------\n");
    printf("1.Display All Product Tables\n");
    printf("2.Display All Product Items\n");
    printf("Enter your choice:");
}

void print_product_menu(){
    printf("------------------------------------\n");
    printf("1.Laptops\n");
    printf("2.Cameras\n");
    printf("3.Phones\n");
    printf("4.Watches\n");
    printf("5.Refrigerators\n");
    printf("Enter your choice:");
}

// variables for db connections
static char *host ="helios.vse.gmu.edu";
static char *user ="wyuan5";
static char *pass = "pazyglum";
static char *dbname = "wyuan5";
// unsigned int port =3306;
// static char *unix_socket = NULL; 
unsigned int flag = 0;

// begin of the main
void main() {
    
    // open sql connection
    MYSQL *conn; //The mysql_init() function allocates or initialises a MYSQL object suitable for mysql real_connect()
    conn = mysql_init(NULL); 

    if (!(mysql_real_connect(conn, host, user, pass,dbname,0,NULL,0))){
        fprintf(stderr, "\nError %s [%d]\n", mysql_error(conn), mysql_errno(conn));
        mysql_close(conn);
    }

    int choice = 0;
    int admin_choice = 0;
    int insert_delete_choice = 0;
    int product_choice = 0;
    int product_id = 0;
    char buff[100];
    while(choice != 4) {
        printMenu();
        fgets(buff, 100, stdin);
        choice = atoi(buff);
        switch(choice) {
            case 1: 
                while(admin_choice != 4) {
                    print_admin_menu();
                    fgets(buff, 100, stdin);
                    admin_choice = atoi(buff);
                    switch(admin_choice){
                        case 1:
                            print_insert_menu();
                            fgets(buff, 100, stdin);
                            insert_delete_choice = atoi(buff);
                            if(insert_delete_choice != 1 && insert_delete_choice != 2){
                                printf("option out of range, please input 1 or 2\n");
                                admin_choice = 0;
                            }
                            else if(insert_delete_choice == 1){
                                print_product_menu();
                                fgets(buff, 100, stdin);
                                product_choice = atoi(buff);
                                printf("\nchoice:%d\n",product_choice );
                                create_table(conn, product_choice);
                            }
                            else if(insert_delete_choice == 2){
                                print_product_menu();
                                fgets(buff, 100, stdin);
                                product_choice = atoi(buff);
                                printf("\nchoice:%d\n",product_choice );
                                insert_record(conn, product_choice);
                            }
                            break;

                        case 2:
                            print_delete_menu();
                            fgets(buff, 100, stdin);
                            insert_delete_choice = atoi(buff);
                            if(insert_delete_choice != 1 && insert_delete_choice != 2){
                                printf("option out of range, please input 1 or 2\n");
                                admin_choice = 0;
                            }
                            else if(insert_delete_choice == 1){
                                print_product_menu();
                                fgets(buff, 100, stdin);
                                product_choice = atoi(buff);
                                drop_table(conn, product_choice);
                            }
                            else if(insert_delete_choice == 2){
                                print_product_menu();
                                fgets(buff, 100, stdin);
                                product_choice = atoi(buff);
                                printf("Please input the id of the item you want to delete: \n");
                                fgets(buff, 100, stdin);
                                product_id = atoi(buff);
                                drop_record(conn, product_choice, product_id);
                            }
                            break;

                        case 3:
                            print_display_menu();
                            fgets(buff, 100, stdin);
                            insert_delete_choice = atoi(buff);
                            if(insert_delete_choice != 1 && insert_delete_choice != 2){
                                printf("option out of range, please input 1 or 2\n");
                                admin_choice = 0;
                            }
                            else if(insert_delete_choice == 1){
                                display_table(conn);
                            }
                            else if(insert_delete_choice == 2){
                                print_product_menu();
                                fgets(buff, 100, stdin);
                                product_choice = atoi(buff);
                                display_record(conn, product_choice);
                            }
                            break;

                        case 4:
                            
                            break;

                        default:
                            printf("option out of range, please input 1-4\n");
                            break;
                    }
                }
                // need to reset both of the choices here
                choice = 0;
                admin_choice = 0;
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

    // close connection and exit
    mysql_close(conn);
    exit(0);
}
