/*
Programmer:	Michael Page

Assignment: 5

Date: 10/15/2018

Description: 
			This program gathers names of teacher and salary information. It uses 
			2 two-dimensional arrays to gather the name information. After all info 
			is received it will them calculate the min, max and average salarie and
			display them to the user.

Input:
	  The program will ask the user to input first name, last name, and salarie information.
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
int main(void)
{
	// DECLARE ALL VARIABLES
	
	// Declare first and last name variables 
	char charFirstNames[MAX][MAX];
	char charLastNames[MAX][MAX];
	char charFirstNameHolder[MAX];
	char charLastNameHolder[MAX];
	int intFirstColNum = 0;
	int intLastColNum = 0;
	bool boolFirstChecked = false;
	bool boolLastChecked = false;

	// Declare variable for salaries
	int intSalaries[MAX];
	int intSortedSalaries[MAX];
	int intSalaryEntry = 0;
	int intSalariesIndex = 0;
	int intMax = 0;
	int intMin = 0;
	int intAvg = 0;
	int intSum = 0;
	int intSwap = 0;
	int intSalaryMaxNum = 0;
	int intSalaryMinNum = 0;
	char charSalaryEntry[MAX] = "";
	bool boolSalaryChecked = false;

	// Bool for while loop exit
	bool boolDone = false;

	// Declare int i and j
	int i;
	int j;

	// Initialize arrays
	for (i = 0; i < MAX; ++i)
	{
		charFirstNames[i][0] = '\0';
		charLastNames[i][0] = '\0';
	}

	// Main while loop will gather information for first names, last names and salaries.
	// It will test all arrays for correctness
	while (!boolDone)
	{
		// check to see if all inputs are good to move on to next inputs
		if (boolFirstChecked && boolLastChecked && boolSalaryChecked)
		{
			boolFirstChecked    = false;
			boolLastChecked     = false;
			boolSalaryChecked   = false;
		}

		// check to make sure first names are correct otherwise make user enter again
		if (!boolFirstChecked)
		{
			if (!boolFirstChecked && boolLastChecked)
			{
				printf("Please Re-Enter first name (Press Enter if done): ");
				fgets(charFirstNameHolder, MAX, stdin);
				charFirstNameHolder[strlen(charFirstNameHolder - 1)] = '\0';
			}
			else
			{
				printf("Please Enter first name (Press Enter if done): ");
				fgets(charFirstNameHolder, MAX, stdin);
				charFirstNameHolder[strlen(charFirstNameHolder - 1)] = '\0';
			}

		}

		// if strlen() in 1 that 1 has to be null terminator, so Exit.
		if (strlen(charFirstNameHolder) == 1)
		{
			boolDone = true;
			printf("\n\n");
			continue;
		}

		// check to make sure last names are correct otherwise make user enter again
		if (!boolLastChecked)
		{
			if (!boolLastChecked && boolFirstChecked)
			{
				printf("Please Re-Enter last name: ");
				fgets(charLastNameHolder, MAX, stdin);
				charLastNameHolder[strlen(charLastNameHolder - 1)] = '\0';
			}
			else
			{
				printf("Please Enter last name: ");
				fgets(charLastNameHolder, MAX, stdin);
				charLastNameHolder[strlen(charLastNameHolder - 1)] = '\0';
			}
		}
		
		// Check if salary is ok if not make user input again
		if (!boolSalaryChecked)
		{
			if (!boolSalaryChecked && boolFirstChecked)
			{
				printf("Please enter salary for first name %s: ", charFirstNameHolder);
				fgets(charSalaryEntry, MAX, stdin);
				charSalaryEntry[strlen(charSalaryEntry - 1)] = '\0';
			}
			else if (!boolSalaryChecked && boolLastChecked)
			{
				printf("Please enter salary for last name %s: ", charLastNameHolder);
				fgets(charSalaryEntry, MAX, stdin);
				charSalaryEntry[strlen(charSalaryEntry - 1)] = '\0';
			}
			else
			{
				printf("Please enter a salary: ");
				fgets(charSalaryEntry, MAX, stdin);
				charSalaryEntry[strlen(charSalaryEntry - 1)] = '\0';
			}
			
		}


		// Check first name to verify it is made of alpha characters
		for (i = 0; (i < strlen(charFirstNameHolder - 1)) && (!boolFirstChecked); ++i)
		{
			if (isalpha(charFirstNameHolder[i]))
			{
				continue;
			}
			else if (i == (strlen(charFirstNameHolder) - 1))
			{
				boolFirstChecked = true;
			}
			else
			{
				printf("That is not a proper first name!\n");
				break;
			}


			if (boolFirstChecked)
			{
				strcpy(charFirstNames[intFirstColNum], charFirstNameHolder);
				intFirstColNum += 1;
				break;
			}
		}


		// Check Last name to verify it is made of alpha characters
		for (i = 0; (i < strlen(charLastNameHolder - 1)) && (!boolLastChecked); ++i)
		{
			if (isalpha(charLastNameHolder[i]))
			{
				continue;
			}
			else if (i == (strlen(charLastNameHolder) - 1))
			{
				boolLastChecked = true;
			}
			else
			{
				printf("That is not a proper last name!\n");
				break;
			}


			if (boolLastChecked)
			{
				strcpy(charLastNames[intLastColNum], charLastNameHolder);
				intLastColNum += 1;
				break;
			}
		}

		// Check salary information to make sure it is only integers
		for (i = 0; i < strlen(charSalaryEntry) - 1; ++i)
		{
			if (isdigit(charSalaryEntry[i]))
			{
				if (i == (strlen(charSalaryEntry) - 2))
				{
					intSalaryEntry = atoi(charSalaryEntry); // atoi takes a string and makes a integer
					intSalaries[intSalariesIndex] = intSalaryEntry;
					intSalariesIndex += 1;
					boolSalaryChecked = true;
				}
			}
			else
			{
				printf("That is not a valid salary!\n");
				break;
			}
		}
	}


	// Output teachers names and salaries
	for (i = 0; i < intFirstColNum; ++i)
	{
		printf("Teacher %d: %s %s    Salary (per year):$%d\n\n", intFirstColNum, charFirstNames[i],
																charLastNames[i], intSalaries[i]);
	}
	

	// Get Average salary. 
	for (i = 0; i < intSalariesIndex; ++i)
	{
		intSum = intSum + intSalaries[i];
	}
	intAvg = intSum / (intSalariesIndex);


	// Create new array to be sorted
	for (i = 0; i < intSalariesIndex; ++i)
	{
		intSortedSalaries[i] = intSalaries[i];
	}


	// Bubble Sort Array Ascending and get min and max
	for (i = 0; i < (intSalariesIndex - 1); ++i)
	{
		for (j = 0; j < (intSalariesIndex - i - 1); ++j)
		{
			if (intSortedSalaries[j] > intSortedSalaries[j + 1])
			{
				intSwap = intSortedSalaries[j];
				intSortedSalaries[j] = intSortedSalaries[j + 1];
				intSortedSalaries[j + 1] = intSwap;
			}
		}

	}

	// Get min and max from bubble sorted array
	intMin = intSortedSalaries[0];
	intMax = intSortedSalaries[intSalariesIndex - 1];

	for (i = 0; i < intSalariesIndex; ++i)
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
	printf("The average salary is: $%d\n", intAvg);
	printf("\n");
	printf("The top salary is %s %s at $%d\n", charFirstNames[intSalaryMaxNum], 
											charLastNames[intSalaryMaxNum], intMax);
	printf("\n");
	printf("The bottom salary is %s %s at $%d\n", charFirstNames[intSalaryMinNum],
		charLastNames[intSalaryMinNum], intMin);
	printf("\n\n\n");

	system("pause");
	return 0;
}