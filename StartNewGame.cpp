#include <iostream>
#include <string>
#include <ctime>
#include "Main.h"
const int MAX_COUNT_OF_LETTERS = 25;
const int MIN_COUNT_OF_LETTERS = 5;
const int ALPHABETH_LEN = 26;
int generateIntBetween(int rangeStart, int rangeEnd) {
	int seed;
	seed = time(0);//we use current time(since Jan 1, 1970)
	//in seconds
	//as seed to generate random number in a range
	int modReducesCount = rangeEnd - rangeStart + 1;
	int randomNumber =
		(seed % modReducesCount)
		+ rangeStart;
	return randomNumber;
}
std::string generateLetters(int countLetters) {
	std::string myLetters = "";
	if (countLetters >= MIN_COUNT_OF_LETTERS &&
		countLetters <= MAX_COUNT_OF_LETTERS) {
		int modReducesCount = ALPHABETH_LEN;
		for (int i = 0; i < countLetters; i++) {
			long seed = (6 * i) + 5 + time(0);
			// i used the help of chatGPT and the formula
			int randomNum =
			(seed % modReducesCount) + 0;
			myLetters.push_back((char)('a' + randomNum));
		}
	}
	return myLetters;
}
void printStringWithSpaces(std::string str) {//help pf chatGPT
	for (char ch : str) {
		std::cout << ch << "   ";
	} 
	//for every character in the string print the character
	//with 3 spaces
	std::cout << std::endl;
}
int countOfLetterInAWord(char letter, char* arr, int len) {
	int result = 0;
	for (int i = 0; i < len; i++) {
		if (letter == arr[i]) {
			++result;
		}
	}
	return result;
}
bool isWordNotValid(std::string word, std::string myLetters) {
	int wordLen = word.length();
	int myLettersLen = myLetters.length();
	char * charWord = &word[0];//I googled how to make char arr
	char* charLetters = &myLetters[0];//from string
	int controlCountIfCharIsPartOfStr = 0;
	for (int i = 0; i < wordLen; i++) {
		for (int j = 0; j < myLettersLen; j++) {
			if (charWord[i] == charLetters[j]) {
				++controlCountIfCharIsPartOfStr;
				if (countOfLetterInAWord(charWord[i], charWord, wordLen)
					> countOfLetterInAWord(charWord[i], charLetters, myLettersLen)) {
					return true;
				}
			}
		}
	}
	if (controlCountIfCharIsPartOfStr == 0) {
		return true;
	}
	return false;
}
void startNewGame(int countOfLetters, int countOfRounds) {
	std::cout << "started new game" << std::endl;
	std::cin.ignore();
	int resultPoints = 0;
	for (int i = 0; i < countOfRounds; i++) {
		std::string myLetters = generateLetters(countOfLetters);
		printStringWithSpaces(myLetters);
		std::string word;
		std::getline(std::cin, word);
		if (isWordNotValid(word, myLetters)) {
			std::cout << "Wrong word!" << std::endl;
		}
		else {
			resultPoints += word.length();
		}
	}
	std::cout << "You have "
		<< resultPoints <<
		" points total." <<
		std::endl;
}
void settings() {

}
void inputNewWord() {

}
void exit() {
	
}
int changeCount(int count, int change) {
	std::cout << "Change count: " << std::endl;
	if (count >= 0 && (count + change) >= 0) {
		return count + change;
	}
	return 0;
}