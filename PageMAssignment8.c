/*
Programmer: Michael Page

Assignment: 8

Date: 11/26/2018

Description:
			This program passes two pointer arrays through function find().
			The first array is whole sentence about some topic. The second
			array is a substring of the first array. Example: first array
			"I love thanksgiving", second array is "thanks". If find() finds
			a match within the main array it will return the index number of
			the first occurance the match (which would be 7, which is "t" in
			"thanks"). The program will print out formatted examples of how find works.

Input:
	  There are two functions that do work for input. One is GetStringLen().
	  This function returns the length of a string. The second is find(), and will be
	  the workhorse that processes all the input. GetStringLen() will be called
	  within find(). find() outputs either an index number or -1.

Output:
	   The output will show the user only examples of either an index location
	   within an array (indicating a match and showing us the first index
	   occurance) or -1 ( indicating that there was no match found at all).
*/

// This is the only library
#include <stdio.h>

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


int main(void)
{
	// Create char arrays

	// Main strings to be searched
	char *charPtrArray[] = { "I love watching Magnum PI!" ,
							 "When I was a little boy I dreamed about climbing Mt Everest!",
							 "I think instructor McCary loves sausage pizza!" };

	// Substrings
	char *charPtrSubArray[] = { "ching","climbing","sausage","PI","ing","boy","ink" };

	// Declare counter variables
	int i;
	int j;

	// Loop through arrays and print a formatted output
	// find() will be called here
	for (i = 0; i < 3; ++i)
	{
		printf("Array:%s\n", charPtrArray[i]);
		for (j = 0; j < 7; ++j)
		{
			printf("Testing sub-array:%-15s", charPtrSubArray[j]);
			printf("Result: %d\n", find(charPtrArray[i], charPtrSubArray[j]));
		}
		printf("\n");
	}

	// A little space
	printf("\n\n");


	system("pause");
	return 0;
}

