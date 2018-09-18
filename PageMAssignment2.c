/*

Programmer: Michael Page

Lab Assignment 2

Date: 09/14/2018

Description: The purpose of this program is to calculate the average grade of
			 two students. It will ask for the name and four grades for each 
			 student, calculate and output the averages for each student.

Input:
			 The program will ask for input of each students first and last 
			 name and four grades in real time.

Output:
			 The program will print to the screen the students first and last
			 names and the average grade of those two students.

*/

#include <stdio.h> // standard input output library

int main(void)
{  // starts function main

	
		// Declare four float variables for student 1, one for each grade.
		float fltFirstStudentGrade1;
		float fltFirstStudentGrade2;
		float fltFirstStudentGrade3;
		float fltFirstStudentGrade4;

	
		// Declare four float variables for student 2, one for each grade.
		float fltSecondStudentGrade1;
		float fltSecondStudentGrade2;
		float fltSecondStudentGrade3;
		float fltSecondStudentGrade4;

	
		// This variable will hold the computed grade average
		float fltGradeAverage;

	
		// This variable is used to calculate the average
		const float FLTFOURGRADES = 4.0;


		// Variable to hold student names
		char charStudent1FirstName[21];
		char charStudent1LastName[21];
		char charStudent2FirstName[21];
		char charStudent2LastName[21];

	
		// Get user input for all student 1 grades and names
		printf("Please enter Student 1's First name: ");
		scanf("%s", charStudent1FirstName);

		printf("Please enter Student 1's Last name: ");
		scanf("%s", charStudent1LastName);

		printf("Please enter student 1's first grade: ");
		scanf("%f", &fltFirstStudentGrade1);

		printf("Please enter student 1's second grade: ");
		scanf("%f", &fltFirstStudentGrade2);

		printf("Please enter student 1's third grade: ");
		scanf("%f", &fltFirstStudentGrade3);

		printf("Please enter student 1's fourth grade: ");
		scanf("%f", &fltFirstStudentGrade4);

	
		// Get user input for all student 2 grades
		printf("\nPlease enter Student 2's First name: ");
		scanf("%s", charStudent2FirstName);

		printf("Please enter Student 2's Last name: ");
		scanf("%s", charStudent2LastName);

		printf("Please enter student 2's first grade: ");
		scanf("%f", &fltSecondStudentGrade1);

		printf("Please enter student 2's second grade: ");
		scanf("%f", &fltSecondStudentGrade2);

		printf("Please enter student 2's third grade: ");
		scanf("%f", &fltSecondStudentGrade3);

		printf("Please enter student 2's fourth grade: ");
		scanf("%f", &fltSecondStudentGrade4);

	
		// Calculate grade average for student 1
		fltGradeAverage = fltFirstStudentGrade1 + fltFirstStudentGrade2 +
					  fltFirstStudentGrade3 + fltFirstStudentGrade4;

		fltGradeAverage = fltGradeAverage / FLTFOURGRADES;

	
		// Output grade average for first student
		printf("\n%s %s's grades: ", charStudent1FirstName, 
									 charStudent1LastName);

		printf("%d, %d, ", (int)fltFirstStudentGrade1, 
						   (int)fltFirstStudentGrade2);

		printf("%d, %d.", (int)fltFirstStudentGrade3, 
						  (int)fltFirstStudentGrade4);

		printf(" Their average is %d.\n", (int)fltGradeAverage);

	
		// Calculate grade average for student 2
		fltGradeAverage = fltSecondStudentGrade1 + fltSecondStudentGrade2 +
		fltSecondStudentGrade3 + fltSecondStudentGrade4;

		fltGradeAverage = fltGradeAverage / FLTFOURGRADES;

	
		// Output grade average for first student
		printf("%s %s's grades: ", charStudent2FirstName, 
								   charStudent2LastName);

		printf("%d, %d, ", (int)fltSecondStudentGrade1, 
						   (int)fltSecondStudentGrade2);

		printf("%d, %d.", (int)fltSecondStudentGrade3, 
						  (int)fltSecondStudentGrade4);

		printf(" Their average is %d.", (int)fltGradeAverage);
		printf("\n\n\n");

	
		// Pause program so output doesn't disappear
		system("pause");

	
		// Tell us the program suceeded
		return 0;


}  // end function main