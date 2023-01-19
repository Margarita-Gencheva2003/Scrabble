#include <iostream>
#include <string>
#include "Main.h"
const std::string MENU_COMMANDS[] = { "1", "2a", "2.a",
							"a", "2b", "2.b" ,"b", "3", "4"};
const int COUNT_OF_MENU_POS_COMDS = 9;
void printMainMenu() {
	std::cout << 
	"1. Start new game\n"<<
	"2. Settings\n"<<
		" a. Change count of letters\n" << 
		" b. Change count of rounds\n" << 
	"3. Include new word in dictionary\n" <<
	"4. Exit" << std::endl;

}
bool isStrCommandNotValid(std::string str) {
	int controlCounter = 0;
	for (int i = 0; i < COUNT_OF_MENU_POS_COMDS; i++) {
		if (str == MENU_COMMANDS[i]) {
			++controlCounter;
		}
	}
	if (controlCounter == 0) {
		return true;
	}
	return false;
}
void navigator(std::string str, int countLetters, int countRounds) {
	std::string strIfFalse = "";
	int controlMaxWrongInput = 0;
	if (isStrCommandNotValid(str)) {
		std::cout << "Please enter a valid command" <<
			" to access the menu" << std::endl;
		std::getline(std::cin, strIfFalse);
		++controlMaxWrongInput;
		if (controlMaxWrongInput > 10) {
			return;
		}
		navigator(strIfFalse, countLetters, countRounds);
	}
	else {
		if (str == MENU_COMMANDS[0]) {
			startNewGame(countLetters, countRounds);
		} 
		if (str == MENU_COMMANDS[1]||
			str == MENU_COMMANDS[2] ||
			str == MENU_COMMANDS[3]) {
			int changeLetters = 0;
			countLetters = changeCount(countLetters, changeLetters);
		}
		if (str == MENU_COMMANDS[4] ||
			str == MENU_COMMANDS[5] ||
			str == MENU_COMMANDS[6]) {
			int changeRounds = 0;
			countLetters = changeCount(countRounds, changeRounds);
		}
		if (str == MENU_COMMANDS[7]) {
			std::cout << "Include new word in dictionary"
				<< std::endl;
		}
		if (str == MENU_COMMANDS[8]) {
			std::cout << "Exit" << std::endl;
		}
		printMainMenu();
	}
}
int main() {
	int countOfLetters = 10;
	int countOfRounds = 10;
	printMainMenu();
	std::string myCommandAccessMenu = "";
	std::getline(std::cin, myCommandAccessMenu);
	navigator(myCommandAccessMenu, countOfLetters, countOfRounds);
}