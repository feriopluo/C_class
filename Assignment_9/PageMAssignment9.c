/*
Programmer: Michael Page

Assignment: 9

Date: 11/28/2018

Desciption:
			This program asks the user to search for a name in a file to retrieve
			information about that person. The file then generates a letter telling
			the person they are over due on a payment.

Input:
		Input is taken from the user, from Customers.txt, and from LetterBody.txt. 
		The program prompts the user for a first name, last name, and date. If the 
		name searched for doesn't match any of the names in Customers.txt it tells
		you the search was negative.

Output:
		The program creates a letter from its output telling the recipient that they
		are overdue and need to make a payment. That letter is called Overdue.txt.

*/

#include <stdio.h>

#define MAX 50

int GetStrLen(char *charString)
{
	// This function gets the strings length

	// Count how many times we entered the loop
	int intCount = 0;

	// look for null terminator , if it finds end loop
	while (*charString != '\0')
	{
		charString++;
		intCount++;
	}
	return intCount;
}

int find(char *charStr, char *charSubStr)
{
	// This function searchs the string for a substring occurance

	// Declare variables used
	int intArrCount = 0;
	int intSubArrCount = 0;
	int intSubArrLen = GetStrLen(charSubStr);

	// Enter loop as long as we don't see null terminator
	while (*charStr != '\0')
	{
		// Keeps track of how many times we enter loop
		++intArrCount;

		// Compare characters to see if they match
		if (*charStr == *charSubStr)
		{
			// Start counting the subarray
			charSubStr++;            // move substring memory location
			++intSubArrCount;

			// If we find a match and the subarray count matches
			// the length of the substring then we are done
			// and function returns array index number
			if (intSubArrLen == intSubArrCount)
			{
				return intArrCount - intSubArrCount; //This returns index of first occurance
			}
		}
		else
		{
			// If we find a false match these need to go back to zero.
			for (int i = 0; i < intSubArrCount; ++i)
			{
				charSubStr--;
			}
			intSubArrCount = 0;
		}
		charStr++;  // move main string memory location
	}

	// I we get to this point we have no match
	return -1;
}

void CopyArray(char charArrCopyTo[], char charArrCopyFrom[])
{

	// This function copies one array into another

	for (int i = 0; i < GetStrLen(charArrCopyFrom) + 1; ++i)
	{
		if (charArrCopyFrom[i] == '\0')
		{
			charArrCopyTo[i] = '\0';
			break;
		}
		else
		{
			charArrCopyTo[i] = charArrCopyFrom[i];
		}
	}
}

void GetName(char charFNameArr[], char charLNameArr[])
{
	// This function gets two names from user input

	fflush(stdin);
	printf("Please enter first and last name of person to be searched: ");

	if (scanf("%s %s", charFNameArr, charLNameArr) != 2)
	{
		printf("Sorry, Please enter a valid first and last name!");
	}

}

void FillWithNullTerminators(char charArray[], int intArrLen)
{
	// This function fills an array up with null terminators

	if (charArray[0] != '\0')
	{
		for (int i = 0; i < intArrLen; ++i)
		{
			charArray[i] = '\0';
		}
	}
}

void GetCustomerInfo(char charName[], char charCompany[], char charAddress[],
	char charCtySt[])
{
	// This Function reads customer information from Customers.txt file
	FILE* fileCustomer = NULL;
	char charLine[200];
	int intLines = 0;
	char charFirstName[MAX];
	char charLastName[MAX];
	int intPosition = 0;

	// Fill strings up with null terminators
	FillWithNullTerminators(charLine, 200);
	FillWithNullTerminators(charFirstName, MAX);
	FillWithNullTerminators(charLastName, MAX);
	FillWithNullTerminators(charName, MAX);
	FillWithNullTerminators(charCompany, MAX);
	FillWithNullTerminators(charAddress, MAX);
	FillWithNullTerminators(charCtySt, MAX);

	GetName(charFirstName, charLastName);

	fileCustomer = fopen("Customers.txt", "r");
	if (fileCustomer == NULL)
	{
		printf("Could not open file Customer.txt");
		return -1;
	}

	while (fgets(charLine, sizeof charLine, fileCustomer) != NULL)
	{
		fflush(stdin);

		// Does the line from the file contain the first and last name?
		// if so gather the information on the customer and place that info
		// into separate arrays
		if ((find(charLine, charFirstName) != -1) && (find(charLine, charLastName) != -1))
		{
			intLines = 4;
		}
		if (intLines != 0)
		{
			if (intLines == 4)
			{
				CopyArray(charName, charLine);
				charName[GetStrLen(charName) - 1] = '\0';
			}
			else if (intLines == 3)
			{
				CopyArray(charCompany, charLine);
				charCompany[GetStrLen(charCompany) - 1] = '\0';
			}
			else if (intLines == 2)
			{
				CopyArray(charAddress, charLine);
				charAddress[GetStrLen(charAddress) - 1] = '\0';
			}
			else if (intLines == 1)
			{
				CopyArray(charCtySt, charLine);
				charCtySt[GetStrLen(charCtySt) - 1] = '\0';
			}
			else
			{
				break;
			}

			// Decrease line number so we can get each field
			--intLines;
		}
	}

	// close file
	fclose(fileCustomer);
}

void PrintOverdueBill(char charNameArr[], char charCompanyArr[], char charAddressArr[],
	char charCityStArr[])
{
	// This function creates an overdue letter with five arrays.
	// Name, Company, Adress, City State and Zip all in same array
	// it also asks the user for date information
	char charDate[13];
	char charLine[200];

	FILE* fileOverdue = NULL;
	FILE* fileLetterBody = NULL;

	// Get Date
	printf("Please enter a date of format (MM/DD/YYYY): ");
	fseek(stdin, 0, SEEK_END);                     //fflush wasn't working so I used this
	fgets(charDate, 12, stdin);
	for (int i = 0; i < strlen(charDate); ++i)
	{
		if (charDate[i] == '\n')
		{
			charDate[i] = '\0';
		}
	}
	
	// open files
	fileOverdue = fopen("Overdue.txt", "w");
	if (fileOverdue == NULL)
	{
		printf("Could not open file Overdue.txt.\n");
		return -1;
	}

	fileLetterBody = fopen("LetterBody.txt", "r");
	if (fileLetterBody == NULL)
	{
		printf("Could not open file Customer.txt");
		return -1;
	}

	// print output letter
	fprintf(fileOverdue, "\n");
	fprintf(fileOverdue, "%s\n%s\n%s\n%s\n", charNameArr, charCompanyArr,
		charAddressArr, charCityStArr);
	fprintf(fileOverdue, "\n\n%54s %s\n\n\n", "Date: ", charDate);
	fprintf(fileOverdue, "Dear %s\n\n", charNameArr);

	// last thing we do is read the body of letter and at same time
	// write it to Overdue.txt
	while (fgets(charLine, sizeof charLine, fileLetterBody) != NULL)
	{
		fflush(stdin);
		fprintf(fileOverdue, "%s", charLine);
	}

	// close files
	fclose(fileOverdue);
	fclose(fileLetterBody);

}


int main(void)
{
	// arrays to be passed
	char charNameLine[MAX];
	char charCompanyLine[MAX];
	char charAddressLine[MAX];
	char charCityStateLine[MAX];

	// get customer info
	GetCustomerInfo(charNameLine, charCompanyLine, charAddressLine,
		charCityStateLine);

	// if name array is empty it means the search results were negative
	if (GetStrLen(charNameLine) == 0)
	{
		printf("\nSearch results negative!");
	}
	else
	{
		PrintOverdueBill(charNameLine, charCompanyLine, charAddressLine,
													charCityStateLine);
	}

	// a little space
	printf("\n\n\n");

	system("pause");

	return 0;
}