/**
*
* Solution to course project # 08
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Margarita Gencheva
* @idnumber 6MI0600148
* @compiler GCC
*
* <file with functions with the main logic of the game>
*
*/

#include <iostream>
#include <string>
#include <fstream>
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
bool isWordNotInDictionary(std::string word) {
	std::ifstream readFile;
	int controlIfWordIsInFile = 0;
	std::string lineOfFile;
	readFile.open("Dictionary");
	if (!readFile) {
		return false;
	}
	while (std::getline(readFile, lineOfFile)) {
		if (lineOfFile == word) {
			++controlIfWordIsInFile;
		}
	}
	if (controlIfWordIsInFile == 0) {
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
		if (isWordNotValid(word, myLetters) ||
			isWordNotInDictionary(word)) {
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
void printMessageForChangedCount(int change, std::string str) {
	std::cout << "Now on every round you will have: ";
	std::cout << change
		<< " "
		<< str
		<< "."
		<< std::endl;
}
void backToTheMenu(int countLetters, int countRounds) {
	printMainMenu();
	std::cout << "Enter a num between 1 and 4: ";
	int nextMenuCommand = 0;
	std::cin >> nextMenuCommand;
	navigator(nextMenuCommand, countLetters, countRounds);
}
void settings(int countLetters, int countRounds) {
	std::cout << "You have chosen Settings. Tap a OR b to continue";
	std::cout << "\na is for changing count of letters"
		<< "\nb is for changing count of rounds"
		<< std::endl;
	std::cin.ignore();
	std::string option = "";
	std::getline(std::cin, option);
	int nextMenuCommand = 0;
	if (option == "a") {
		int change = 5;
		int newCountOfLetters = changeCount(countLetters, change);
		std::string strMessage = "letters";
		printMessageForChangedCount(newCountOfLetters, strMessage);
		backToTheMenu(newCountOfLetters, countRounds);
	}
	if (option == "b") {
		int change = 5;
		int newCountOfRounds = changeCount(countRounds, change);
		std::string strMessage = "rounds";
		printMessageForChangedCount(newCountOfRounds, strMessage);
		backToTheMenu(countLetters, newCountOfRounds);
	}
}
void inputNewWord(const int countLetters,const int countRounds) {
	std::cin.ignore();
	std::ofstream writeInFile;
	writeInFile.open("Dictionary.txt", std::ios::app);
	if (!writeInFile) {
		std::cerr << "Error: file could not be opened"
			<< std::endl;
	}
	std::string newWord = "";
	std::getline(std::cin, newWord);
	writeInFile << newWord << std::endl;
	writeInFile.close();
	backToTheMenu(countLetters, countRounds);
}
void exit() {
	return;
}
int changeCount(int count, int change) {
	if (count >= 0 && (count + change) >= 0) {
		return count + change;
	}
	return 0;
}