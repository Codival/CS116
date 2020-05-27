/*
 *Purpose:
 * Contains shared functions and structs for MySQL commands
 * 
 * @author Ron Sha
 * @version 1.0 1/27/2017 
*/
#ifndef DBCONNECT_H
#define DBCONNECT_H

#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

using namespace std;
 
// just going to input the general details and not the port numbers
struct connection_details
{
    char *server;
    char *user;
    char *password;
    char *database;
};
 
MYSQL* mysql_connection_setup(struct connection_details mysql_details);
 
MYSQL_RES* mysql_perform_query(MYSQL *connection, char *sql_query);
 
#endif
