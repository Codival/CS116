/*
 *Purpose:
 * Print out programmer's information such as name, class information 
 * and date/time the program is run
 * 
 * @author Ron Sha
 * @version 1.0 5/1/2017
 * 
 * @param name - Amuldeep Dhillon
 * @param courseInfo - Lab 1: CS 116-02 Thursdays
 * @return - none 
*/
#include "dbconnect.h"

MYSQL* mysql_connection_setup(struct connection_details mysql_details)
{
     // first of all create a mysql instance and initialize the variables within
    MYSQL *connection = mysql_init(NULL);
 
    // connect to the database with the details attached.
    if (!mysql_real_connect(connection,mysql_details.server, 
	mysql_details.user, mysql_details.password, 
	mysql_details.database, 0, NULL, 0)) {
      printf("Conection error : %s\n", mysql_error(connection));
      exit(1);
    }
    return connection;
}
 
MYSQL_RES* mysql_perform_query(MYSQL *connection, char *sql_query)
{
   // send the query to the database
   if (mysql_query(connection, sql_query))
   {
      printf("MySQL query error : %s\n", mysql_error(connection));
      exit(1);
   }
 
   return mysql_use_result(connection);
}
 
