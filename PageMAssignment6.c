/*
Programmer:	Michael Page

Assignment: 6

Date: 10/22/2018

Description:
			This program gathers names of teacher and salary information. It uses
			2 two-dimensional arrays to gather the name information. After all info
			is received it will them calculate the min, max and average salaries and
			display them to the user. This program displays how functions can clean
			up main().

Input:
	  The program will ask the user to input first name, last name, and salary information.
	  This information will be gathered using holder(temp) arrays and then transered over to
	  the permanent arrays.

Output:
	   The information in the arrays will be calculated to get the min salary, max salary, and
	   average salary. The program will then output the first/last names and the salary for all
	   teachers entered. Then it will output the average salary, max salary, and the min salary.
*/

// Include necesary libraries
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

// Max can be changed at any time to adjust array sizes
#define MAX 50

// Declare and Define all functions

bool CheckNameAlphas(char charNameArray[])
{
	// Check name to verify it is made of alpha characters

	// Declare function variables
	bool boolChecked = false;

	for (int i = 0; (i < strlen(charNameArray - 1)) && (!boolChecked); ++i)
	{
		if (isalpha(charNameArray[i]))
		{
			continue;
		}
		else if (i == (strlen(charNameArray) - 1))
		{
			boolChecked = true;
			return boolChecked;
		}
		else
		{
			return boolChecked; // return false
		}
	}
}

void GetName(char charNameArray[])
{
	//This function gets a name from keyboard
	fflush(stdin);
	fgets(charNameArray, MAX, stdin);
	charNameArray[strlen(charNameArray - 1)] = '\0';
}

void GetSalary(char getSalaryArray[])
{
	// This function gets the salary 
	fflush(stdin);
	fgets(getSalaryArray, MAX, stdin);
	getSalaryArray[strlen(getSalaryArray - 1)] = '\0';
}

bool CheckSalary(char charCheckSalaryArray[])
{
	// This functions checks the user entered salaray array for errors
	// it returns true if the check is ok and false if check is not ok.
	bool boolOK = false;

	// Check salary information to make sure it is only integers
	for (int i = 0; i < strlen(charCheckSalaryArray) - 1; ++i)
	{
		if (isdigit(charCheckSalaryArray[i]))
		{
			if (i == (strlen(charCheckSalaryArray) - 2))
			{
				boolOK = true;
				return boolOK;
			}
		}
		else
		{
			return boolOK; // return false
		}
	}
}

bool GetAndCheckSalary(char charSalaryArray[])
{
	// This function gets salary and checks to make sure it is legit
	// If it is legit it returns a bool value of true.
	bool boolArrayLegit = false;

	GetSalary(charSalaryArray);
	boolArrayLegit = CheckSalary(charSalaryArray);

	// Return true or false, if false function GetAndCheckSalary will be call again.
	return boolArrayLegit;

}

void InitializeArrays(char charNamesArray[MAX][MAX])
{
	// This Function initializes 2D arrays
	
	// Declare int i and j
	int i;
	int j;

	// Initialize arrays
	for (i = 0; i < MAX; ++i)
	{
		for (j = 0; j < MAX; ++j)
		{
			charNamesArray[i][j] = '\0';
			charNamesArray[i][j] = '\0';
		}

	}
}

void RemoveNewLineChar(char charNamesArray[MAX][MAX], int intColIndex)
{
	// This function takes newline character out of  2D name arrays

	// declare i and j
	int i;
	int j;

	for (i = 0; i < intColIndex; ++i)
	{
		for (j = 0; j < strlen(charNamesArray[i]); ++j)
		{
			if (charNamesArray[i][j] == '\n')
			{
				charNamesArray[i][j] = '\0';
			}
		}
	}
}

int GetAverage(int intArray[], int intNum)
{
	// This function takes an int array a returns the average
	
	// declare all variables
	int i;
	int intSum = 0;
	int intAvg = 0;

	for (i = 0; i < intNum; ++i)
	{
		intSum = intSum + intArray[i];
	}
	intAvg = intSum / intNum;

	return intAvg;
}

void BubbleSortAscending(int intArray[], int intNum)
{
	// This function will use bubble sort algorithm to sort an integer array
	// it will sort ascending

	// declare variables
	int i;
	int j;
	int intSwap = 0;

	for (i = 0; i < (intNum - 1); ++i)
	{
		for (j = 0; j < (intNum - i - 1); ++j)
		{
			if (intArray[j] > intArray[j + 1])
			{
				intSwap = intArray[j];
				intArray[j] = intArray[j + 1];
				intArray[j + 1] = intSwap;
			}
		}

	}
}


void OutputTeacherInfo(char charFirstNames[MAX][MAX], char charLastNames[MAX][MAX],
						int intSalaries[MAX], int intColumnIndex)
{
	// This Function outputs all the teachers information in an organized order

	// declare all variables
	int intSortedSalaries[MAX];

	int intMax = 0;
	int intMin = 0;
	int intAvg = 0;
	int intSum = 0;

	int intSalaryMaxNum = 0;
	int intSalaryMinNum = 0;

	// Declare int i and j
	int i;
	int j;

	// Output teachers names and salaries
	for (i = 0; i < intColumnIndex; ++i)
	{
		printf("Teacher %d: %s %s     Salary (per year):$%d\n\n", i + 1, charFirstNames[i],
			charLastNames[i], intSalaries[i]);
	}

	// Get Average salary. 
	intAvg = GetAverage(intSalaries, intColumnIndex);

	// Create new array to be sorted
	for (i = 0; i < intColumnIndex; ++i)
	{
		intSortedSalaries[i] = intSalaries[i];
	}

	// Bubble Sort Array Ascending and get min and max
	BubbleSortAscending(intSortedSalaries, intColumnIndex);

	// Get min and max from bubble sorted array
	intMin = intSortedSalaries[0];
	intMax = intSortedSalaries[intColumnIndex - 1];

	for (i = 0; i < intColumnIndex; ++i)
	{
		if (intSalaries[i] == intMin)
		{
			intSalaryMinNum = i;
		}
		if (intSalaries[i] == intMax)
		{
			intSalaryMaxNum = i;
		}
	}

	// output all calculated information
	printf("The average salary is: $%d per year.\n", intAvg);
	printf("\n");
	printf("The top salary is %s %s at $%d\n", charFirstNames[intSalaryMaxNum],
		charLastNames[intSalaryMaxNum], intMax);
	printf("\n");
	printf("The bottom salary is %s %s at $%d\n", charFirstNames[intSalaryMinNum],
		charLastNames[intSalaryMinNum], intMin);
}


int GetAllArrays(char charFirstNames[MAX][MAX], char charLastNames[MAX][MAX], int intSalaries[MAX])
{
	// Process all name inputs, put all correct arrays in the 2D arrays
	// returns an index to use in other functions
	char charFirstNameHolder[MAX];
	char charLastNameHolder[MAX];
	int intFirstColNum = 0;
	int intLastColNum = 0;
	bool boolFirstChecked = false;
	bool boolLastChecked = false;
	int intSalaryEntry = 0;
	int intSalariesIndex = 0;
	char charSalaryEntry[MAX] = "";
	bool boolSalaryChecked = false;
	int i;
	int j;
	
	// Bool for while loop exit
	bool boolDone = false;


	// Main while loop will gather information for first names, last names and salaries.
	// It will test all arrays for correctness
	while (!boolDone)
	{
		// check to see if all inputs are good to move on to next inputs
		if (boolFirstChecked && boolLastChecked && boolSalaryChecked)
		{
			boolFirstChecked = false;
			boolLastChecked = false;
			boolSalaryChecked = false;
		}

		// Get first name or have user re-enter first name
		if (!boolFirstChecked)
		{
			if (!boolFirstChecked && boolLastChecked)
			{
				printf("Please Re-Enter first name (Press Enter if done): ");
				GetName(charFirstNameHolder);
			}
			else
			{
				printf("Please Enter first name (Press Enter if done): ");
				GetName(charFirstNameHolder);
			}

		}

		// if strlen() is 1, that 1 has to be null terminator, so Exit.
		if (strlen(charFirstNameHolder) == 1)
		{
			boolDone = true;
			printf("\n\n");
			continue;
		}

		// Get last name or have user re-enter last name
		if (!boolLastChecked)
		{
			if (!boolLastChecked && boolFirstChecked)
			{
				printf("Please Re-Enter last name: ");
				GetName(charLastNameHolder);
			}
			else
			{
				printf("Please Enter last name: ");
				GetName(charLastNameHolder);
			}
		}

		// Check if salary is ok if not make user input again
		if (!boolSalaryChecked)
		{
			if ((!boolSalaryChecked) && ((boolFirstChecked) || (boolLastChecked)))
			{
				printf("Please Re-enter salary: ");
				boolSalaryChecked = GetAndCheckSalary(charSalaryEntry);
				if (boolSalaryChecked)
				{
					intSalaryEntry = atoi(charSalaryEntry); // atoi takes a string and makes a integer
					intSalaries[intSalariesIndex] = intSalaryEntry;
					intSalariesIndex += 1;
				}
				else
				{
					printf("That is not a valid salary. Salary must be entered as numbers!\n");
				}
			}
			else
			{
				printf("Please enter salary: ");
				boolSalaryChecked = GetAndCheckSalary(charSalaryEntry);
				if (boolSalaryChecked)
				{
					intSalaryEntry = atoi(charSalaryEntry); // atoi takes a string and makes an integer
					intSalaries[intSalariesIndex] = intSalaryEntry;
					intSalariesIndex += 1;

				}
				else
				{
					printf("That is not a valid salary. Salary must be entered as numbers!\n");
				}
			}

		}


		// Check if first name is legit
		if (!boolFirstChecked)
		{
			boolFirstChecked = CheckNameAlphas(charFirstNameHolder);
			if (boolFirstChecked)
			{
				strcpy(charFirstNames[intFirstColNum], charFirstNameHolder);
				intFirstColNum += 1;
			}
			else
			{
				printf("That is not a proper first name!\n");
			}
		}


		// Check if last name is legit
		if (!boolLastChecked)
		{
			boolLastChecked = CheckNameAlphas(charLastNameHolder);
			if (boolLastChecked)
			{
				strcpy(charLastNames[intLastColNum], charLastNameHolder);
				intLastColNum += 1;
			}
			else
			{
				printf("That is not a proper last name!\n");
			}
		}
	}
	return intFirstColNum;
}

void TeacherSalaries(void)
{
	// This function declares main variables, calls other functions 
	// to initialize arrays, get arrays, cleanup and output finished arrays

	// Declare four main variable 
	char charFirstNames[MAX][MAX];
	char charLastNames[MAX][MAX];
	int intColumnIndex = 0;
	int intSalaries[MAX];

	// Initialize arrays
	InitializeArrays(charFirstNames);
	InitializeArrays(charLastNames);

	// Get all arrays
	intColumnIndex = GetAllArrays(charFirstNames, charLastNames, intSalaries);

	// take newline character out of  2D first name arrays
	RemoveNewLineChar(charFirstNames, intColumnIndex);
	RemoveNewLineChar(charLastNames, intColumnIndex);

	// Output teachers names and salaries
	OutputTeacherInfo(charFirstNames, charLastNames, intSalaries, intColumnIndex);
}

int main(void)
{
	// Call function to start process
	TeacherSalaries();

	// A little space before program exit
	printf("\n\n\n");

	system("pause");
	return 0;
}