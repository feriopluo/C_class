/*

Programmer: Michael Page

Lab Assignment 3

Date: 09/19/2018

Description: The purpose of this program is to calculate the average grade of
			 two students. It will ask for the name, four grades, and how many 
			 absences. It will output a short sentence or a couple of short
			 sentences about each student.

Input:
			 The program will ask for input of each students first and last 
			 name, four grades and how many absences the student
			 has in real time.

Output:
			 The program will print to the screen the students first and last
			 names, all the grades, the average grade and the alphabet grade
			 received of those two students. If the absences are more than
			 three, the student will be dropped from the class and output 
			 will reflect the same. If the program sees that the student has
			 an 'A' and less than 3 absences it will output a special sentence
			 about how great the student is.

*/

#include <stdio.h> // standard input output library
#include <string.h> // string library

int main(void)
{  // starts function main


		// Declare four float variables for student 1, one for each grade.
		int intFirstStudentGrade1 = 0;
		int intFirstStudentGrade2 = 0;
		int intFirstStudentGrade3 = 0;
		int intFirstStudentGrade4 = 0;


		// Declare four float variables for student 2, one for each grade.
		int intSecondStudentGrade1 = 0;
		int intSecondStudentGrade2 = 0;
		int intSecondStudentGrade3 = 0;
		int intSecondStudentGrade4 = 0;


		// This variable will hold the computed grade average
		int intGradeAverage = 0;


		// This is for the absences variables
		int intStudent1Absences = 0;
		int intStudent2Absences = 0;


		// This variable is used to calculate the average
		const int INTFOURGRADES = 4;


		// Variable to hold student names
		char charStudent1FirstName[51];
		char charStudent1LastName[51];
		char charStudent2FirstName[51];
		char charStudent2LastName[51];
		char charStudent1FullName[102] = "";
		char charStudent2FullName[102] = "";

		// Variables to hold student alphabet grades
		char charStudent1ClassGrade[2] = "";
		char charStudent2ClassGrade[2] = "";


		// Get user input for all student 1 grades, 
		// names and absences.
		printf("Please enter Student 1's First name: ");
		scanf("%s", charStudent1FirstName);

		printf("Please enter Student 1's Last name: ");
		scanf("%s", charStudent1LastName);

		printf("Please enter student 1's first grade: ");
		scanf("%d", &intFirstStudentGrade1);

		printf("Please enter student 1's second grade: ");
		scanf("%d", &intFirstStudentGrade2);

		printf("Please enter student 1's third grade: ");
		scanf("%d", &intFirstStudentGrade3);

		printf("Please enter student 1's fourth grade: ");
		scanf("%d", &intFirstStudentGrade4);

		printf("Please enter Student 1's absences: ");
		scanf("%d", &intStudent1Absences);


		// Get user input for all student 2 grades,
		// names and absences.
		printf("\nPlease enter Student 2's First name: ");
		scanf("%s", charStudent2FirstName);

		printf("Please enter Student 2's Last name: ");
		scanf("%s", charStudent2LastName);

		printf("Please enter student 2's first grade: ");
		scanf("%d", &intSecondStudentGrade1);

		printf("Please enter student 2's second grade: ");
		scanf("%d", &intSecondStudentGrade2);

		printf("Please enter student 2's third grade: ");
		scanf("%d", &intSecondStudentGrade3);

		printf("Please enter student 2's fourth grade: ");
		scanf("%d", &intSecondStudentGrade4);

		printf("Please enter Student 2's absences: ");
		scanf("%d", &intStudent2Absences);

		// Concatenate student names
		strcat(charStudent1FullName, charStudent1FirstName);
		strcat(charStudent1FullName, " ");
		strcat(charStudent1FullName, charStudent1LastName);

		strcat(charStudent2FullName, charStudent2FirstName);
		strcat(charStudent2FullName, " ");
		strcat(charStudent2FullName, charStudent2LastName);


		// Calculate grade average for student 1
		intGradeAverage = intFirstStudentGrade1 + intFirstStudentGrade2 +
						  intFirstStudentGrade3 + intFirstStudentGrade4;

		intGradeAverage = intGradeAverage / INTFOURGRADES;


		// Find student1's alphabet grade
		if ((intGradeAverage >= 90) && (intGradeAverage <= 100))
		{
			charStudent1ClassGrade[0] = 'A';
		}
		else if ((intGradeAverage >= 80) && (intGradeAverage <= 89))
		{
			charStudent1ClassGrade[0] = 'B';
		}
		else if ((intGradeAverage >= 70) && (intGradeAverage <= 79))
		{
			charStudent1ClassGrade[0] = 'C';
		}
		else if ((intGradeAverage >= 60) && (intGradeAverage <= 69))
		{
			charStudent1ClassGrade[0] = 'D';
		}
		else
		{
			charStudent1ClassGrade[0] = 'F';
		}


		// Output Student 1's information
		if (intStudent1Absences > 2)
		{
			printf("\n\n%s was dropped from CIS161 due to %d absences.\n",
				   charStudent1FullName, intStudent1Absences);
		}
		// I put this in here because it sounds funny if you say
		// that the student got "a A". This makes it say "an A" or "an F".
		else if ((charStudent1ClassGrade[0] == 'A') || (charStudent1ClassGrade[0] == 'F'))
		{
			printf("\n\n%s's grades: ", charStudent1FullName);
			printf("%d, %d, ", intFirstStudentGrade1, intFirstStudentGrade2);
			printf("%d, %d.", intFirstStudentGrade3, intFirstStudentGrade4);
			printf(" Average is %d.\n", intGradeAverage);
			printf("%s's final grade for CIS161 is an %s.\n",
				   charStudent1FullName, charStudent1ClassGrade);
		}
		// This makes it say "a B", "a C" or "a D".
		else
		{
			printf("\n\n%s's grades: ", charStudent1FullName);
			printf("%d, %d, ", intFirstStudentGrade1, intFirstStudentGrade2);
			printf("%d, %d.", intFirstStudentGrade3, intFirstStudentGrade4);
			printf(" Average is %d.\n", intGradeAverage);
			printf("%s's final grade for CIS161 is a %s.\n\n",
				   charStudent1FullName, charStudent1ClassGrade);
		}

		// If student gets an A and has less than 3 absences
		if ((charStudent1ClassGrade[0] == 'A') && (intStudent1Absences < 3))
		{
			printf("\n%s has an A and less than 3 absences and should"
				   " be recomended for\nValedictorian of the Century.\n\n",
				   charStudent1FullName);
		}
		

	
		// Calculate grade average for student 2
		intGradeAverage = intSecondStudentGrade1 + intSecondStudentGrade2 +
						  intSecondStudentGrade3 + intSecondStudentGrade4;

		intGradeAverage = intGradeAverage / INTFOURGRADES;

		// Find student 2's alphabet grade
		if ((intGradeAverage >= 90) && (intGradeAverage <= 100))
		{
			charStudent2ClassGrade[0] = 'A';
		}
		else if ((intGradeAverage >= 80) && (intGradeAverage <= 89))
		{
			charStudent2ClassGrade[0] = 'B';
		}
		else if ((intGradeAverage >= 70) && (intGradeAverage <= 79))
		{
			charStudent2ClassGrade[0] = 'C';
		}
		else if ((intGradeAverage >= 60) && (intGradeAverage <= 69))
		{
			charStudent2ClassGrade[0] = 'D';
		}
		else
		{
			charStudent2ClassGrade[0] = 'F';
		}
	
		// Output Student 2's information
		if (intStudent2Absences > 2)
		{
			printf("\n%s was dropped from CIS161 due to %d absences.\n",
				   charStudent2FullName, intStudent2Absences);
		}
		// I put this in here because it sounds funny if you say
		// that the student got "a A". This makes it say "an A" or "an F".
		else if ((charStudent2ClassGrade[0] == 'A') || (charStudent2ClassGrade[0] == 'F'))
		{
			printf("\n%s's grades: ", charStudent2FullName);
			printf("%d, %d, ", intSecondStudentGrade1, intSecondStudentGrade2);
			printf("%d, %d.", intSecondStudentGrade3, intSecondStudentGrade4);
			printf(" Average is %d.\n", intGradeAverage);
			printf("%s's final grade for CIS161 is an %s.\n",
				   charStudent2FullName, charStudent2ClassGrade);
		}
		// This makes it say "a B", "a C" or "a D".
		else
		{
			printf("\n%s's grades: ", charStudent2FullName);
			printf("%d, %d, ", intSecondStudentGrade1, intSecondStudentGrade2);
			printf("%d, %d.", intSecondStudentGrade3, intSecondStudentGrade4);
			printf(" Average is %d.\n", intGradeAverage);
			printf("%s's final grade for CIS161 is a %s.\n",
				   charStudent2FullName, charStudent2ClassGrade);
		}

		// If student gets an A and has less than 3 absences
		if ((charStudent2ClassGrade[0] == 'A') && (intStudent2Absences < 3))
		{
			printf("\n%s has an A and less than 3 absences and should"
				   " be recomended for\nValedictorian of the Century.\n",
				   charStudent2FullName);
		}

		printf("\n\n\n");

	
		// Pause program so output doesn't disappear
		system("pause");

	
		// Tell us the program suceeded
		return 0;


}  // end function main