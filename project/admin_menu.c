#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>
#include "structures.h"
#include "admin_menu.h"

void connection_error(MYSQL *conn)
{
  fprintf(stderr, "%s\n", mysql_error(conn));
  mysql_close(con);
}

int create_table(MYSQL *conn, int option){
    if(option<1 || option>5){
        print("option out of range, please input 1-5");
        return -1;
    }
    
    switch (option){
        //1 is laptop
        case 1 :
            // query returns 0 on success and 1 on fail
            if (mysql_query(conn, "CREATE TABLE laptops(
                id INT PRIMARY KEY AUTO_INCREMENT,
                brandName VARCHAR(24), 
                processorBrand VARCHAR(24), 
                processorModel VARCHAR(24), 
                graphicCardBrand VARCHAR(24), 
                graphicCardModel VARCHAR(24), 
                operatingSystem VARCHAR(24), 
                RAM VARCHAR(24), 
                storage VARCHAR(24), 
                price DECIMAL)")) {
                connection_error(conn);
                return -1;
            }
            break;

        // 2 is camera
        case 2 :
            // query returns 0 on success and 1 on fail
            if (mysql_query(conn, "CREATE TABLE cameras(
                id INT PRIMARY KEY AUTO_INCREMENT,
                brandName VARCHAR(24), 
                ModelNumber VARCHAR(24), 
                cameraType VARCHAR(24), 
                color VARCHAR(24), 
                sensorType VARCHAR(24), 
                sensorSize VARCHAR(24), 
                effectivePixels VARCHAR(24), 
                storage VARCHAR(24), 
                width DECIMAL,
                height DECIMAL,
                depth DECIMAL,
                price DECIMAL)")) {
                connection_error(conn);
                return -1;
            }
            break;

        // 3 is phone
        case 3 :
            // query returns 0 on success and 1 on fail
            if (mysql_query(conn, "CREATE TABLE phones(
                id INT PRIMARY KEY AUTO_INCREMENT,
                brandName VARCHAR(24), 
                ModelNumber VARCHAR(24), 
                storage VARCHAR(24), 
                color VARCHAR(24),
                width DECIMAL,
                height DECIMAL,
                price DECIMAL)")) {
                connection_error(conn);
                return -1;
            }
            break;

        // 4 is watch
        case 4 :
            // query returns 0 on success and 1 on fail
            if (mysql_query(conn, "CREATE TABLE watches(
                id INT PRIMARY KEY AUTO_INCREMENT,
                brandName VARCHAR(24), 
                ModelNumber VARCHAR(24), 
                type VARCHAR(24), 
                color VARCHAR(24),
                weight DECIMAL,
                price DECIMAL)")) {
                connection_error(conn);
                return -1;
            }
            break;

        // 5 is refrigerator
        case 5 :
            // query returns 0 on success and 1 on fail
            if (mysql_query(conn, "CREATE TABLE refrigerators(
                id INT PRIMARY KEY AUTO_INCREMENT,
                brandName VARCHAR(24), 
                ModelNumber VARCHAR(24), 
                doorStyle VARCHAR(24), 
                color VARCHAR(24),
                width DECIMAL,
                height DECIMAL,
                depth DECIMAL,
                price DECIMAL)")) {
                connection_error(conn);
                return -1;
            }
            break;
    }   
    return 0;
}

int insert_record(MYSQL *conn, int option){
    if(option<1 || option>5){
        print("option out of range, please input 1-5");
        return -1;
    }

    switch (option){
        //1 is laptop
        case 1 :
            if(insert_laptop(conn)==-1){
                printf("insert failed")
                return -1;
            }
            break;

        // 2 is camera
        case 2 :
            if(insert_camera(conn)==-1){
                printf("insert failed")
                return -1;
            }
            break;

        // 3 is phone
        case 3 :
            if(insert_phone(conn)==-1){
                printf("insert failed")
                return -1;
            }
            break;

        // 4 is watch
        case 4 :
            if(insert_watch(conn)==-1){
                printf("insert failed")
                return -1;
            }
            break;

        // 5 is refrigerator
        case 5 :
            if(insert_refrigerator(conn)==-1){
                printf("insert failed")
                return -1;
            }
            break;
    }

    return 0;
}

int insert_laptop(MYSQL *conn){
    char buffer[25];
    char processing[30];
    char querry[500] = "INSERT IGNORE INTO laptops VALUES(NULL"
    float temp;

    // ask user for the struct info
    printf("please input the brandName within 24 characters long: \n");
    // try to get an user input string 
    scanf("%24s",buffer);
    getchar();
    // add ' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(querry,processing);

    printf("please input the processorBrand within 24 characters long: \n");
    // try to get an user input string 
    scanf("%24s",buffer);
    getchar();
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(querry,processing);


    printf("please input the processorModel within 24 characters long: \n");
    // try to get an user input string 
    scanf("%24s",buffer);
    getchar();
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(querry,processing);

    printf("please input the graphicCardBrand within 24 characters long: \n");
    // try to get an user input string 
    scanf("%24s",buffer);
    getchar();
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(querry,processing);

    printf("please input the graphicCardModel within 24 characters long: \n");
    // try to get an user input string 
    scanf("%24s",buffer);
    getchar();
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(querry,processing);

    printf("please input the operatingSystem within 24 characters long: \n");
    // try to get an user input string 
    scanf("%24s",buffer);
    getchar();
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(querry,processing);

    printf("please input the RAM like 16GB: \n");
    // try to get an user input string 
    scanf("%24s",buffer);
    getchar();
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(querry,processing);

    printf("please input the storage like 500GB: \n");
    // try to get an user input string 
    scanf("%24s",buffer);
    getchar();
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
  
    strcat(processing, ",");
    strcat(querry,processing);

    printf("please input the price: \n");
    // try to get an user input string 
    scanf("%f",&temp);
    getchar();
    // add , and the decimal
    processing[0] = '\0';
    sprintf(processing, "%f", temp);
    strcat(querry,processing);
    strcat(querry, ")");

    printf("query:%s\n", query);

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
    scanf("%24s",buffer);
    getchar();
    // add ' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the ModelNumber within 24 characters long: \n");
    // try to get an user input string 
    scanf("%24s",buffer);
    getchar();
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the cameraType within 24 characters long: \n");
    // try to get an user input string 
    scanf("%24s",buffer);
    getchar();
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the sensorType (COMS, Live MOS) within 24 characters long: \n");
    // try to get an user input string 
    scanf("%24s",buffer);
    getchar();
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the sensorSize (Four Thirds System, APS-C) within 24 characters long: \n");
    // try to get an user input string 
    scanf("%24s",buffer);
    getchar();
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the effectivePixels (16.1 megapixels) within 24 characters long: \n");
    // try to get an user input string 
    scanf("%24s",buffer);
    getchar();
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the storage like 500GB: \n");
    // try to get an user input string 
    scanf("%24s",buffer);
    getchar();
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
    strcat(query, ")");

    printf("query:%s\n", query);

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
    scanf("%24s",buffer);
    getchar();
    // add ' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the ModelNumber within 24 characters long: \n");
    // try to get an user input string 
    scanf("%24s",buffer);
    getchar();
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the storage (500gb) within 24 characters long: \n");
    // try to get an user input string 
    scanf("%24s",buffer);
    getchar();
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the color: \n");
    // try to get an user input string 
    scanf("%24s",buffer);
    getchar();
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
    strcat(query, ")");

    printf("query:%s\n", query);

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
    scanf("%24s",buffer);
    getchar();
    // add ' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the ModelNumber within 24 characters long: \n");
    // try to get an user input string 
    scanf("%24s",buffer);
    getchar();
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the type (mechanical, quartz, automatical) within 24 characters long: \n");
    // try to get an user input string 
    scanf("%24s",buffer);
    getchar();
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the color: \n");
    // try to get an user input string 
    scanf("%24s",buffer);
    getchar();
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
    strcat(query, ")");

    printf("query:%s\n", query);

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
    scanf("%24s",buffer);
    getchar();
    // add ' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the ModelNumber within 24 characters long: \n");
    // try to get an user input string 
    scanf("%24s",buffer);
    getchar();
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the doorStyle (frech-door, side-by-side) within 24 characters long: \n");
    // try to get an user input string 
    scanf("%24s",buffer);
    getchar();
    // add ,' ' to the string
    processing[0] = '\0';
    strcat(processing, ",");
    strcat(processing, "'");
	strcat(processing, buffer);
	strcat(processing, "'");
    strcat(query,processing);

    printf("please input the color: \n");
    // try to get an user input string 
    scanf("%24s",buffer);
    getchar();
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
    strcat(query, ")");

    printf("query:%s\n", query);

    // insert the record
    if (mysql_query(conn, query)) {
      connection_error(conn);
      return -1;
    }

    return 0;
}

int drop_table(MYSQL *conn, int option){
    if(option<1 || option>5){
        print("option out of range, please input 1-5");
        return -1;
    }

    switch (option){
        //1 is laptop
        case 1 :
            // query returns 0 on success and 1 on fail
            if (mysql_query(conn, "DROP TABLE IF EXISTS laptops")) {
                connection_error(conn);
                return -1;
            }
            break;

        // 2 is camera
        case 2 :
            // query returns 0 on success and 1 on fail
            if (mysql_query(conn, "DROP TABLE IF EXISTS cameras")) {
                connection_error(conn);
                return -1;
            }
            break;

        // 3 is phone
        case 3 :
            // query returns 0 on success and 1 on fail
            if (mysql_query(conn, "DROP TABLE IF EXISTS phones")) {
                connection_error(conn);
                return -1;
            }
            break;

        // 4 is watch
        case 4 :
            // query returns 0 on success and 1 on fail
            if (mysql_query(conn, "DROP TABLE IF EXISTS watches")) {
                connection_error(conn);
                return -1;
            }
            break;

        // 5 is refrigerator
        case 5 :
            // query returns 0 on success and 1 on fail
            if (mysql_query(conn, "DROP TABLE IF EXISTS refrigerators")) {
                connection_error(conn);
                return -1;
            }
            break;
    }   
    return 0;
}