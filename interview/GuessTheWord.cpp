/*
LeetCode 843. Guess the Word
https://leetcode.com/problems/guess-the-word/

  You are given an array of unique strings words where words[i] is six letters long. One word of words was chosen as a secret word.

You are also given the helper object Master. You may call Master.guess(word) where word is a six-letter-long string, and it must be from words. Master.guess(word) returns:

-1 if word is not from words, or
an integer representing the number of exact matches (value and position) of your guess to the secret word.
There is a parameter allowedGuesses for each test case where allowedGuesses is the maximum number of times you can call Master.guess(word).

For each test case, you should call Master.guess with the secret word without exceeding the maximum number of allowed guesses. You will get:

"Either you took too many guesses, or you did not find the secret word." if you called Master.guess more than allowedGuesses times or if you did not call Master.guess with the secret word, or
"You guessed the secret word correctly." if you called Master.guess with the secret word with the number of calls to Master.guess less than or equal to allowedGuesses.
The test cases are generated such that you can guess the secret word with a reasonable strategy (other than using the bruteforce method).

 

Example 1:

Input: secret = "acckzz", words = ["acckzz","ccbazz","eiowzz","abcczz"], allowedGuesses = 10
Output: You guessed the secret word correctly.
Explanation:
master.guess("aaaaaa") returns -1, because "aaaaaa" is not in wordlist.
master.guess("acckzz") returns 6, because "acckzz" is secret and has all 6 matches.
master.guess("ccbazz") returns 3, because "ccbazz" has 3 matches.
master.guess("eiowzz") returns 2, because "eiowzz" has 2 matches.
master.guess("abcczz") returns 4, because "abcczz" has 4 matches.
We made 5 calls to master.guess, and one of them was the secret, so we pass the test case.
Example 2:

Input: secret = "hamada", words = ["hamada","khaled"], allowedGuesses = 10
Output: You guessed the secret word correctly.
Explanation: Since there are two words, you can guess both.
  */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// This is the Master's API interface.
// You should not implement it, or speculate about its implementation
class Master {
public:
    int guess(string word) {
        // This is a dummy implementation for testing purposes
        string secretWord = "acckzz";
        if (word == secretWord) {
            cout << "Congratulations! You guessed the secret word." << endl;
            return 6;
        } else {
            int matchCount = 0;
            for (int i = 0; i < word.size(); ++i) {
                if (word[i] == secretWord[i]) {
                    ++matchCount;
                }
            }
            return matchCount;
        }
    }
};

class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        for (int i = 0; i < 10; ++i) { // Given that the number of guesses is fixed at 10
            int guessIndex = rand() % wordlist.size(); // Randomly pick a word from the remaining list
            string guessWord = wordlist[guessIndex];
            int matchCount = master.guess(guessWord); // Get the number of matches with the secret word
            
            if (matchCount == 6) // If all characters match, we've found the secret word
                return;
            
            vector<string> nextWordlist; // Next wordlist based on the matches
            for (const string& word : wordlist) {
                if (match(word, guessWord) == matchCount) // Only consider words with the same number of matches
                    nextWordlist.push_back(word);
            }
            swap(wordlist, nextWordlist); // Update wordlist for the next iteration
        }
    }
    
    int match(const string& word1, const string& word2) {
        int count = 0;
        for (int i = 0; i < word1.size(); ++i) {
            if (word1[i] == word2[i])
                ++count;
        }
        return count;
    }
};

int main() {
    Solution solution;
    vector<string> wordlist = {"acckzz", "ccbazz", "eiowzz", "abcczz", "abcdef", "aaaaaa", "aaaaab", "aaaabb"};
    Master master;
    solution.findSecretWord(wordlist, master);
    return 0;
}


/*

Output:

Congratulations! You guessed the secret word.

*/
