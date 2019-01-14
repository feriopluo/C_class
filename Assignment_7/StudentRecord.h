/*
Programmer: Michael Page

Assignment: 7

Date: 11-16-2018

Desciption: This is the header file that goes with PageMAssignment7.c.
			The struct StudentRecord will be declared here along
			the input and output functions.

Input: A function to input student records will be declared here.

Output: A function to output student records will be declared here.
*/

#ifndef STUDENTRECORD_H
#define STUDENTRECORD_H

// Declare Struct for student info
typedef struct StudentRecord_struct
{
	char charStudentName[20];
	float fltGPA;
	char charDateOfGraduation[20];
	char charMajor[20];
	char charStudentStatus[20];
}StudentRecord;

// Declare function for input
void InputStudentInfo(void);

// Declare function for output
void OutputStudentInfo(StudentRecord studentRecord[]);

#endif 

