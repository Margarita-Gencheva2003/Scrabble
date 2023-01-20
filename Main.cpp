#include <iostream>
#include <string>
#include "Main.h"
const std::string MENU_COMMANDS[] = { "1", "2a", "2.a",
							"a", "2b", "2.b" ,"b", "3", "4"};
const int COUNT_OF_MENU_POS_COMDS = 9;
void printMainMenu() {
	std::cout << 
	"\n1. Start new game\n"<<
	"2. Settings\n"<<
		" a. Change count of letters\n" << 
		" b. Change count of rounds\n" << 
	"3. Include new word in dictionary\n" <<
	"4. Exit" << std::endl;

}
bool isCommandValid(int command) {
	if (command < 1 ||
		command > 4) {
		return false;
	}
	return true;
}
void navigator(int numAccessMenu, int countLetters, int countRounds) {
	if (isCommandValid(numAccessMenu)) {
		switch (numAccessMenu) {
		case 1:
			startNewGame(countLetters, countRounds);
			break;
		case 2:
			settings(countLetters, countRounds);
			break;
		case 3:
			inputNewWord();
			break;
		case 4:
			exit();
			break;
		}
	}
	else {
		int controlWrongInputs = 0;
		int newTry = 0;
		while (!isCommandValid(newTry)) {
			std::cout << "Enter a number between 1 and 4: "
				<< std::endl;
			std::cin >> newTry;
			++controlWrongInputs;
			if (controlWrongInputs > 5) {
				return;
			}
		} 
		navigator(newTry, countLetters, countRounds);
	}
}
int main() {
	int countOfLetters = 10;
	int countOfRounds = 10;
	int commandNum = 0;
	printMainMenu();
	std::cout << "Enter a num between 1 and 4: ";
	std::cin >> commandNum;
	navigator(commandNum, countOfLetters, countOfRounds);
}