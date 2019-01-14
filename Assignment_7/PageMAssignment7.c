/*
Programmer: Michael Page

Assignment: 7

Date: 11-16-2018

Description:
			This program uses a struct to store information about
			students. It hard codes student information and prints
			it to ouput. It uses StudentRecord.h and StudentRecord.c
			files to run the program.

Input:
	  The program will use a function to input 3 students information
	  and will hardcode it into the data members of StudentRecord 
	  struct.

Output:
	   The student information will then be outputed to the screen
	   by calling the ouput function within the input function.

*/

// Include necessary libraries
#include <stdio.h>
#include "StudentRecord.h"

int main(void)
{
	// Start input for struct, output funtion called within
	// InputStudentInfo
	InputStudentInfo();

	system("pause");
	return 0;
}