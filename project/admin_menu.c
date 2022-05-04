#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<mysql.h>
#include "structures.h"
#include "admin_menu.h"

void connection_error(MYSQL *conn)
{
  fprintf(stderr, "%s\n", mysql_error(conn));
}

int create_table(MYSQL *conn, int option){
    if(option<1 || option>5){
        printf("option out of range, please input 1-5");
        return -1;
    }

    switch (option){
        //1 is laptop
        case 1 :
            // query returns 0 on success and 1 on fail
            if (mysql_query(conn, "CREATE TABLE laptops(\
                id INT PRIMARY KEY AUTO_INCREMENT,\
                brandName VARCHAR(24),\
                processorBrand VARCHAR(24),\
                processorModel VARCHAR(24),\
                graphicCardBrand VARCHAR(24),\
                graphicCardModel VARCHAR(24),\
                operatingSystem VARCHAR(24),\
                RAM VARCHAR(24),\
                storage VARCHAR(24),\
                price DECIMAL);")) {
                connection_error(conn);
                return -1;
            }
            printf("table created\n");
            break;

        // 2 is camera
        case 2 :
            // query returns 0 on success and 1 on fail
            if (mysql_query(conn, "CREATE TABLE cameras(\
                id INT PRIMARY KEY AUTO_INCREMENT,\
                brandName VARCHAR(24),\
                ModelNumber VARCHAR(24),\
                cameraType VARCHAR(24),\
                color VARCHAR(24),\
                sensorType VARCHAR(24),\
                sensorSize VARCHAR(24),\
                effectivePixels VARCHAR(24),\
                storage VARCHAR(24),\
                width DECIMAL,\
                height DECIMAL,\
                depth DECIMAL,\
                price DECIMAL);")) {
                connection_error(conn);
                return -1;
            }
            printf("table created\n");
            break;

        // 3 is phone
        case 3 :
            // query returns 0 on success and 1 on fail
            if (mysql_query(conn, "CREATE TABLE phones(\
                id INT PRIMARY KEY AUTO_INCREMENT,\
                brandName VARCHAR(24),\
                ModelNumber VARCHAR(24),\
                storage VARCHAR(24),\
                color VARCHAR(24),\
                width DECIMAL,\
                height DECIMAL,\
                price DECIMAL);")) {
                connection_error(conn);
                return -1;
            }
            printf("table created\n");
            break;

        // 4 is watch
        case 4 :
            // query returns 0 on success and 1 on fail
            if (mysql_query(conn, "CREATE TABLE watches(\
                id INT PRIMARY KEY AUTO_INCREMENT,\
                brandName VARCHAR(24),\
                ModelNumber VARCHAR(24),\
                type VARCHAR(24),\
                color VARCHAR(24),\
                weight DECIMAL,\
                price DECIMAL);")) {
                connection_error(conn);
                return -1;
            }
            printf("table created\n");
            break;

        // 5 is refrigerator
        case 5 :
            // query returns 0 on success and 1 on fail
            if (mysql_query(conn, "CREATE TABLE refrigerators(\
                id INT PRIMARY KEY AUTO_INCREMENT,\
                brandName VARCHAR(24),\
                ModelNumber VARCHAR(24),\
                doorStyle VARCHAR(24),\
                color VARCHAR(24),\
                width DECIMAL,\
                height DECIMAL,\
                depth DECIMAL,\
                price DECIMAL);")) {
                connection_error(conn);
                return -1;
            }
            printf("table created\n");
            break;
    }   
    return 0;
}

int insert_record(MYSQL *conn, int option){
    if(option<1 || option>5){
        printf("option out of range, please input 1-5");
        return -1;
    }

    switch (option){
        //1 is laptop
        case 1 :
            if(insert_laptop(conn)==-1){
                return -1;
            }
            printf("record inserted.\n");
            break;

        // 2 is camera
        case 2 :
            if(insert_camera(conn)==-1){
                return -1;
            }
            printf("record inserted.\n");
            break;

        // 3 is phone
        case 3 :
            if(insert_phone(conn)==-1){
                return -1;
            }
            printf("record inserted.\n");
            break;

        // 4 is watch
        case 4 :
            if(insert_watch(conn)==-1){
                return -1;
            }
            printf("record inserted.\n");
            break;

        // 5 is refrigerator
        case 5 :
            if(insert_refrigerator(conn)==-1){
                return -1;
            }
            printf("record inserted.\n");
            break;
    }

    return 0;
}

int insert_laptop(MYSQL *conn){
    char buffer[25];
    char processing[30];
    char query[500] = "INSERT IGNORE INTO laptops VALUES(NULL";
    float temp;

    // ask user for the struct info
    printf("please input the brandName within 24 characters long: \n");
    // try to get an user input string 
    scanf("%[^\n]%*c",buffer);
    // getchar();
    // add ' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the processorBrand within 24 characters long: \n");
    // try to get an user input string 
    scanf("%[^\n]%*c",buffer);
    // getchar();
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);


    printf("please input the processorModel within 24 characters long: \n");
    // try to get an user input string 
    scanf("%[^\n]%*c",buffer);
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the graphicCardBrand within 24 characters long: \n");
    // try to get an user input string 
    scanf("%[^\n]%*c",buffer);
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the graphicCardModel within 24 characters long: \n");
    // try to get an user input string 
    scanf("%[^\n]%*c",buffer);
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the operatingSystem within 24 characters long: \n");
    // try to get an user input string 
    scanf("%[^\n]%*c",buffer);
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the RAM like 16GB: \n");
    // try to get an user input string 
    scanf("%[^\n]%*c",buffer);
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the storage like 500GB: \n");
    // try to get an user input string 
    scanf("%[^\n]%*c",buffer);
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
  
    strcat(processing, ",");
    strcat(query,processing);

    printf("please input the price: \n");
    // try to get an user input string 
    scanf("%f",&temp);
    getchar();
    // add , and the decimal
    processing[0] = '\0';
    sprintf(processing, "%f", temp);
    strcat(query,processing);
    strcat(query, ");");

    // insert the record
    if (mysql_query(conn, query)) {
      connection_error(conn);
      return -1;
    }

    return 0;
}

int insert_camera(MYSQL *conn){
    char buffer[25];
    char processing[30];
    char query[500] = "INSERT IGNORE INTO cameras VALUES(NULL";
    float temp;

    // ask user for the struct info
    printf("please input the brandName within 24 characters long: \n");
    // try to get an user input string 
    scanf("%[^\n]%*c",buffer);
    // add ' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the ModelNumber within 24 characters long: \n");
    // try to get an user input string 
    scanf("%[^\n]%*c",buffer);
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the cameraType within 24 characters long: \n");
    // try to get an user input string 
    scanf("%[^\n]%*c",buffer);
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the color within 24 characters long: \n");
    // try to get an user input string 
    scanf("%[^\n]%*c",buffer);
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the sensorType (COMS, Live MOS) within 24 characters long: \n");
    // try to get an user input string 
    scanf("%[^\n]%*c",buffer);
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the sensorSize (Four Thirds System, APS-C) within 24 characters long: \n");
    // try to get an user input string 
    scanf("%[^\n]%*c",buffer);
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the effectivePixels (16.1 megapixels) within 24 characters long: \n");
    // try to get an user input string 
    scanf("%[^\n]%*c",buffer);
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the storage like 500GB: \n");
    // try to get an user input string 
    scanf("%[^\n]%*c",buffer);
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(processing, ",");
    strcat(query,processing);

    printf("please input the width: \n");
    // try to get an user input string 
    scanf("%f",&temp);
    getchar();
    // add , and the decimal
    processing[0] = '\0';
    sprintf(processing, "%f", temp);
    strcat(processing, ",");
    strcat(query,processing);  

    printf("please input the height: \n");
    // try to get an user input string 
    scanf("%f",&temp);
    getchar();
    // add , and the decimal
    processing[0] = '\0';
    sprintf(processing, "%f", temp);
    strcat(processing, ",");
    strcat(query,processing);

    printf("please input the depth: \n");
    // try to get an user input string 
    scanf("%f",&temp);
    getchar();
    // add , and the decimal
    processing[0] = '\0';
    sprintf(processing, "%f", temp);
    strcat(processing, ",");
    strcat(query,processing);

    printf("please input the price: \n");
    // try to get an user input string 
    scanf("%f",&temp);
    getchar();
    // add , and the decimal
    processing[0] = '\0';
    sprintf(processing, "%f", temp);
    strcat(query,processing);
    strcat(query, ");");

    // insert the record
    if (mysql_query(conn, query)) {
      connection_error(conn);
      return -1;
    }

    return 0;
}

int insert_phone(MYSQL *conn){
    char buffer[25];
    char processing[30];
    char query[500] = "INSERT IGNORE INTO phones VALUES(NULL";
    float temp;

    // ask user for the struct info
    printf("please input the brandName within 24 characters long: \n");
    // try to get an user input string 
    scanf("%[^\n]%*c",buffer);
    // add ' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the ModelNumber within 24 characters long: \n");
    // try to get an user input string 
    scanf("%[^\n]%*c",buffer);
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the storage (500gb) within 24 characters long: \n");
    // try to get an user input string 
    scanf("%[^\n]%*c",buffer);
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the color: \n");
    // try to get an user input string 
    scanf("%[^\n]%*c",buffer);
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(processing, ",");
    strcat(query,processing);

    printf("please input the width: \n");
    // try to get an user input string 
    scanf("%f",&temp);
    getchar();
    // add , and the decimal
    processing[0] = '\0';
    sprintf(processing, "%f", temp);
    strcat(processing, ",");
    strcat(query,processing);  

    printf("please input the height: \n");
    // try to get an user input string 
    scanf("%f",&temp);
    getchar();
    // add , and the decimal
    processing[0] = '\0';
    sprintf(processing, "%f", temp);
    strcat(processing, ",");
    strcat(query,processing);

    printf("please input the price: \n");
    // try to get an user input string 
    scanf("%f",&temp);
    getchar();
    // add , and the decimal
    processing[0] = '\0';
    sprintf(processing, "%f", temp);
    strcat(query,processing);
    strcat(query, ");");

    // insert the record
    if (mysql_query(conn, query)) {
      connection_error(conn);
      return -1;
    }

    return 0;
}

int insert_watch(MYSQL *conn){
    char buffer[25];
    char processing[30];
    char query[500] = "INSERT IGNORE INTO watches VALUES(NULL";
    float temp;

    // ask user for the struct info
    printf("please input the brandName within 24 characters long: \n");
    // try to get an user input string 
    scanf("%[^\n]%*c",buffer);
    // add ' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the ModelNumber within 24 characters long: \n");
    // try to get an user input string 
    scanf("%[^\n]%*c",buffer);
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the type (mechanical, quartz, automatical) within 24 characters long: \n");
    // try to get an user input string 
    scanf("%[^\n]%*c",buffer);
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the color: \n");
    // try to get an user input string 
    scanf("%[^\n]%*c",buffer);
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(processing, ",");
    strcat(query,processing);

    printf("please input the weight: \n");
    // try to get an user input string 
    scanf("%f",&temp);
    getchar();
    // add , and the decimal
    processing[0] = '\0';
    sprintf(processing, "%f", temp);
    strcat(processing, ",");
    strcat(query,processing);  

    printf("please input the price: \n");
    // try to get an user input string 
    scanf("%f",&temp);
    getchar();
    // add , and the decimal
    processing[0] = '\0';
    sprintf(processing, "%f", temp);
    strcat(query,processing);
    strcat(query, ");");

    // insert the record
    if (mysql_query(conn, query)) {
      connection_error(conn);
      return -1;
    }

    return 0;
}

int insert_refrigerator(MYSQL *conn){
    char buffer[25];
    char processing[30];
    char query[500] = "INSERT IGNORE INTO refrigerators VALUES(NULL";
    float temp;

    // ask user for the struct info
    printf("please input the brandName within 24 characters long: \n");
    // try to get an user input string 
    scanf("%[^\n]%*c",buffer);
    // add ' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the ModelNumber within 24 characters long: \n");
    // try to get an user input string 
    scanf("%[^\n]%*c",buffer);
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the doorStyle (frech-door, side-by-side) within 24 characters long: \n");
    // try to get an user input string 
    scanf("%[^\n]%*c",buffer);
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the color: \n");
    // try to get an user input string 
    scanf("%[^\n]%*c",buffer);
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(processing, ",");
    strcat(query,processing);

    printf("please input the width: \n");
    // try to get an user input string 
    scanf("%f",&temp);
    getchar();
    // add , and the decimal
    processing[0] = '\0';
    sprintf(processing, "%f", temp);
    strcat(processing, ",");
    strcat(query,processing);  

    printf("please input the height: \n");
    // try to get an user input string 
    scanf("%f",&temp);
    getchar();
    // add , and the decimal
    processing[0] = '\0';
    sprintf(processing, "%f", temp);
    strcat(processing, ",");
    strcat(query,processing);

    printf("please input the depth: \n");
    // try to get an user input string 
    scanf("%f",&temp);
    getchar();
    // add , and the decimal
    processing[0] = '\0';
    sprintf(processing, "%f", temp);
    strcat(processing, ",");
    strcat(query,processing);

    printf("please input the price: \n");
    // try to get an user input string 
    scanf("%f",&temp);
    getchar();
    // add , and the decimal
    processing[0] = '\0';
    sprintf(processing, "%f", temp);
    strcat(query,processing);
    strcat(query, ");");

    // insert the record
    if (mysql_query(conn, query)) {
      connection_error(conn);
      return -1;
    }

    return 0;
}

int drop_table(MYSQL *conn, int option){
    if(option<1 || option>5){
        printf("option out of range, please input 1-5");
        return -1;
    }

    switch (option){
        //1 is laptop
        case 1 :
            // query returns 0 on success and 1 on fail
            if (mysql_query(conn, "DROP TABLE IF EXISTS laptops;")) {
                connection_error(conn);
                return -1;
            }
            printf("table dropped.\n");
            break;

        // 2 is camera
        case 2 :
            // query returns 0 on success and 1 on fail
            if (mysql_query(conn, "DROP TABLE IF EXISTS cameras;")) {
                connection_error(conn);
                return -1;
            }
            printf("table dropped.\n");
            break;

        // 3 is phone
        case 3 :
            // query returns 0 on success and 1 on fail
            if (mysql_query(conn, "DROP TABLE IF EXISTS phones;")) {
                connection_error(conn);
                return -1;
            }
            printf("table dropped.\n");
            break;

        // 4 is watch
        case 4 :
            // query returns 0 on success and 1 on fail
            if (mysql_query(conn, "DROP TABLE IF EXISTS watches;")) {
                connection_error(conn);
                return -1;
            }
            printf("table dropped.\n");
            break;

        // 5 is refrigerator
        case 5 :
            // query returns 0 on success and 1 on fail
            if (mysql_query(conn, "DROP TABLE IF EXISTS refrigerators;")) {
                connection_error(conn);
                return -1;
            }
            printf("table dropped.\n");
            break;
    }   
    return 0;
}

int drop_record(MYSQL *conn, int option, int id){

    //used for query
    char query[500];

    if(option<1 || option>5){
        printf("option out of range, please input 1-5");
        return -1;
    }

    switch (option){
        //1 is laptop
        case 1 :
            // build up query based on selected option
            sprintf(query,"DELETE FROM laptops where id = (%d);",id);
            if(mysql_query(conn,query)){
                connection_error(conn);
                return -1;
            }
            printf("record deleted.\n");
            break;

        // 2 is camera
        case 2 :
            // build up query based on selected option
            sprintf(query,"DELETE FROM cameras where id = (%d);",id);
            if(mysql_query(conn,query)){
                connection_error(conn);
                return -1;
            }
            printf("record deleted.\n");
            break;

        // 3 is phone
        case 3 :
            // build up query based on selected option
            sprintf(query,"DELETE FROM phones where id = (%d);",id);
            if(mysql_query(conn,query)){
                connection_error(conn);
                return -1;
            }
            printf("record deleted.\n");
            break;

        // 4 is watch
        case 4 :
            // build up query based on selected option
            sprintf(query,"DELETE FROM watches where id = (%d);",id);
            if(mysql_query(conn,query)){
                connection_error(conn);
                return -1;
            }
            printf("record deleted.\n");
            break;

        // 5 is refrigerator
        case 5 :
            // build up query based on selected option
            sprintf(query,"DELETE FROM refrigerators where id = (%d);",id);
            if(mysql_query(conn,query)){
                connection_error(conn);
                return -1;
            }
            printf("record deleted.\n");
            break;
    }

    return 0;
}

void display_table(MYSQL *conn){
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
        while (row = mysql_fetch_row(result)) {
            puts(row[0]);
        }
        mysql_free_result(result);
    }
    return;
}

void display_record(MYSQL *conn, int option){
    if(option<1 || option>5){
        printf("option out of range, please input 1-5");
        return;
    }
    char query[500];
    switch (option){
        //1 is laptop
        case 1 :
            strcpy(query, "SELECT * FROM laptops");
            display_helper(conn, query);
            break;

        // 2 is camera
        case 2 :
            strcpy(query, "SELECT * FROM cameras");
            display_helper(conn, query);
            break;

        // 3 is phone
        case 3 :
            strcpy(query, "SELECT * FROM phones");
            display_helper(conn, query);
            break;

        // 4 is watch
        case 4 :
            strcpy(query, "SELECT * FROM watches");
            display_helper(conn, query);
            break;

        // 5 is refrigerator
        case 5 :
            strcpy(query, "SELECT * FROM refrigerators");
            display_helper(conn, query);
            break;
    }

    return;
}

void display_helper(MYSQL *conn, char * query){
    if (mysql_query(conn, query)) {
        connection_error(conn);
    } 
    else {
        MYSQL_RES *result = mysql_store_result(conn);
        if (!result) {
            printf("Couldn't get results set: %s\n", mysql_error(conn));
        } 
        else {

            // display field names
            int num_fields = mysql_num_fields(result);
            MYSQL_FIELD *field;
            int i = 0;
            while ((field = mysql_fetch_field(result)) != NULL ) {
                printf("  %24s  |", field->name);
            }
            printf("\n");

            //display records one by one
            MYSQL_ROW row;
            
            // using a while loop for pagination of 5
            int page_counter = 0;
            char user_choice = 0;
            while (1){
                // read the records row by row and display
                if((row = mysql_fetch_row(result)) != NULL){
                    for(int i = 0; i < num_fields; i++){
                        printf("  %24s  |", row[i] ? row[i] : "NULL");
                    }
                    printf("\n");
                    page_counter += 1;
                }
                else{
                    printf("All records displayed.\n");
                    break;
                }

                // if page counter = 5, we need to ask user if they want to continue, if so, we reset the counter, else break
                if(page_counter == 5){
                    printf("Do you want to display the next 5 records? N for no, anything for yes.\n");
                    scanf("%c", &user_choice);
                    getchar();
                    if(user_choice == 'N'){
                        page_counter = 0;
                        break;
                    }
                    else{
                        page_counter = 0;
                        continue;
                    }
                }
            }
        }
    }

    return;
}