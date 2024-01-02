// https://www.geeksforgeeks.org/efficiently-find-first-repeated-character-string-without-using-additional-data-structure-one-traversal/

// Efficiently check First repeated character
// in C++ program 
#include<bits/stdc++.h>
using namespace std;

// Returns -1 if all characters of str are
// unique.
// Assumptions : (1) str contains only characters
//				 from 'a' to 'z'
//			 (2) integers are stored using 32
//				 bits
int FirstRepeated(string str)
{
	// An integer to store presence/absence
	// of 26 characters using its 32 bits.
	int checker = 0;
	int i = 0;

	for (auto ch : str)
	{
		int val = (ch - 'a');

		// If bit corresponding to current
		// character is already set
		if ((checker & (1 << val)) > 0)
			return i;

		// set bit in checker
		checker |= (1 << val);
		i++;
		
	}

	return -1;
}

// Driver code
int main()
{
	string s = "abcfdeacf";
	int i=FirstRepeated(s);
	if (i!=-1)
		cout <<"Char = "<< s[i] << " and Index = "<<i;
	else
		cout << "No repeated Char";
	return 0;
}

/* Output : 

Char = a and Index = 6

*/
