#include <iostream>
#include <string>
#include "Main.h"

void startNewGame(int countOfLetters, int countOfRounds) {
	std::cout << "started new game" << std::endl;
}
int changeCount(int count, int change) {
	std::cout << "Change count: " << std::endl;
	if (count >= 0 && (count + change) >= 0) {
		return count + change;
	}
	return 0;
}