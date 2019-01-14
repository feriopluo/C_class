/*
Programmer: Michael Page

Assignment: 7

Date: 11/16/2018

Description: StudentRecord.c keeps the definition of the functions declared in
			 StudentRecord.h. These files support PageMAssignment7.c.
*/

// Libraries
#include <stdio.h>
#include "StudentRecord.h"



void InputStudentInfo(void)
{
	// create instances of student records
	StudentRecord sRecord[3] = {
		{"Chester Budington", 3.25, "08/25/2017", "Science", "Fulltime"},
		{"Benjamin Button", 2.75, "02/15/1945", "Business", "Fulltime" },
		{"Jimmy Johnson", 4.00, "04/12/2015", "Physics", "Parttime"}
	};

	// call output function to print the students records
	OutputStudentInfo(sRecord);
}


void OutputStudentInfo(StudentRecord record[])
{
	// Decare count variable
	int i = 0;

	// Start loop to loop through the all members of the struct and print
	// each students records
	for (i = 0; i < 3; ++i)
	{
		printf("Student %d's Record\n", i + 1);
		printf("Name:               %s\n",     record[i].charStudentName);
		printf("GPA:                %0.2f\n",  record[i].fltGPA);
		printf("Date of graduation: %s\n",     record[i].charDateOfGraduation);
		printf("Major:              %s\n",     record[i].charMajor);
		printf("Student status:     %s\n\n\n", record[i].charStudentStatus);
	}
}