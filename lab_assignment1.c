/*

Programmer: Michael Page

Lab Assignment 1

Date: 09/03/2018

Description: The purpose of this program is to calculate the average grade of
			 two students.It will ask for grade inputs, calculate the and
			 output the averages.

Input:
The program will ask for input of four grades from each of the two students
in real time.

Output:
The program will print to the screen the average grade of those two students.

*/

#include <stdio.h> // standard input output library

int main(void) 
{  // starts function main
		
		// Declare four integer variables for student 1, one for each grade.
		int intFirstStudentGrade1; 
		int intFirstStudentGrade2;
		int intFirstStudentGrade3;
		int intFirstStudentGrade4;

		// Declare four integer variables for student 2, one for each grade.
		int intSecondStudentGrade1; 
		int intSecondStudentGrade2;
		int intSecondStudentGrade3;
		int intSecondStudentGrade4;

		// This variable will hold the computed grade average
		int intGradeAverage;  

		// Get user input for all student 1 grades
		printf("Please enter student 1 first grade: ");
		scanf("%d", &intFirstStudentGrade1); 

		printf("Please enter student 1 second grade: ");
		scanf("%d", &intFirstStudentGrade2);

		printf("Please enter student 1 third grade: ");
		scanf("%d", &intFirstStudentGrade3);

		printf("Please enter student 1 fourth grade: ");
		scanf("%d", &intFirstStudentGrade4);

		// Get user input for all student 2 grades
		printf("\nPlease enter student 2 first grade: ");
		scanf("%d", &intSecondStudentGrade1);

		printf("Please enter student 2 second grade: ");
		scanf("%d", &intSecondStudentGrade2);

		printf("Please enter student 2 third grade: ");
		scanf("%d", &intSecondStudentGrade3);

		printf("Please enter student 2 fourth grade: ");
		scanf("%d", &intSecondStudentGrade4);

		// Calculate grade average for student 1
		intGradeAverage = intFirstStudentGrade1 + intFirstStudentGrade2 + 
						  intFirstStudentGrade3 + intFirstStudentGrade4;
		
		intGradeAverage = intGradeAverage / 4;

		// Output grade average for first student
		printf("\nStudent 1 grades: ");
		printf("%d, %d, ", intFirstStudentGrade1, intFirstStudentGrade2);
		printf("%d, %d.", intFirstStudentGrade3, intFirstStudentGrade4);
		printf(" Average is %d.\n", intGradeAverage);

		// Calculate grade average for student 2
		intGradeAverage = intSecondStudentGrade1 + intSecondStudentGrade2 +
						  intSecondStudentGrade3 + intSecondStudentGrade4;
		
		intGradeAverage = intGradeAverage / 4;

		// Output grade average for first student
		printf("Student 2 grades: ");
		printf("%d, %d, ", intSecondStudentGrade1, intSecondStudentGrade2);
		printf("%d, %d.", intSecondStudentGrade3, intSecondStudentGrade4);
		printf(" Average is %d.", intGradeAverage);
		printf("\n\n\n");

		// Pause program so output doesn't disappear
		system("pause");

		// Tell us the program suceeded
		return 0;

}  // end function main