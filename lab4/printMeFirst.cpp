/*
 *Purpose:
 * Print out programmer's information such as name, class information 
 * and date/time the program is run
 * 
 * @author Ron Sha
 * @version 1.0 1/27/2017
 * 
 * @param name - Amuldeep Dhillon
 * @param courseInfo - Lab 4: CS 116-02 Thursdays
 * @return - none 
*/


#include "lab.h"
void printMeFirst(std::string name, std::string courseInfo)

{

std::cout <<" Program written by: "<< name << std::endl; // put your name here

std::cout <<" Course info: "<< courseInfo << std::endl;

time_t now = time(0);  // current date/time based on current system

char* dt = ctime(&now); // convert now to string for

   std::cout << " Date: " << dt << std::endl;

}
