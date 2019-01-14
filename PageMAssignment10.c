/*
Programmer: Michael Page

Assignment: 10

Date: 12/02/2018

Desciption:
			This program uses recursion to figure out if a string contains a 
			palindrome.

Input:
		Main will call a recursive palindrome function several times with different
		strings.The function will determine whether or not it is a palindrome.

Output:
		The palindrom function will printf to the screen "passed" and then printf 
		whether or not it is a palindrome.

*/

#include <stdio.h>

// This function came from assignment 8
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


void IsPalindrome(char charString[], int intArrLenDivideByTwo, const int intArrLength)
{
	// This function recursively calls itself until it determines
	// whether the passed string is a palindrome
	// the second parameter is used to solve the odd/even delema, it truncates
	// the odd lengthed arrays and ignores the middle character.
	// The two indexes start in the middle and work their way away from each other
	// comparing characters until the left index is == 0.

	int intGoLeftIndex = intArrLenDivideByTwo;                      // this index travels left
	int intGoRightIndex = (intArrLength - 1) - intGoLeftIndex;      // this index travels right

	if (charString[intGoLeftIndex] != charString[intGoRightIndex])  //compares characters
	{
		printf("Passed: Not Palindrome\n");							//prints result
	}
	else if (intGoLeftIndex == 0)                                   //if left index reached 0, its a palindrome
	{
		printf("Passed: Palindrome\n");                             // print result
	}
	else                                                            // another recursion
	{
		--intGoLeftIndex;                                           // minus 1 from left index
		IsPalindrome(charString, intGoLeftIndex, intArrLength);
	}

}

int main(void)
{
	// Lets put them into a pointer array
	char *charTestArrays[] = { "kayak","ghost","CiviC","car","mom","redder","noon","guitar" };

	// Sends them through the palindrome function and prints the results
	// In for loop I use sizeof to find the length of my pointer array
	for (int i = 0; i < ((sizeof charTestArrays) / (sizeof charTestArrays[0])); ++i)
	{
		// Test palindromes and print the results
		IsPalindrome(charTestArrays[i], GetStrLen(charTestArrays[i]) / 2, GetStrLen(charTestArrays[i]));
	}

	// tidy the screen a little
	printf("\n\n");

	system("pause");
	return 0;
}