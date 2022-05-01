#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

static char *host ="zeus.vse.gmu.edu";
static char *user = "gvaradar";
static char *pass = "jydsoars";
static char *dbname = "user";
// unsigned int port =3306;
// static char *unix_socket = NULL; 
unsigned int flag = 0;

int main(){
  MYSQL *conn; //The mysql_init() function allocates or initialises a MYSQL object suitable for mysql real_connect()
  conn = mysql_init(NULL); 

  if (!(mysql_real_connect(conn,host, user, pass,dbname,0,NULL,0))){
    fprintf(stderr, "\nError %s [%d]\n", mysql_error(conn), mysql_errno(conn));
    exit(1);
  }
  printf("\nConnection Successful\n\n");
  return EXIT_SUCCESS;
}
