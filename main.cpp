#include <iostream>
#include <vector>
#include <string>

std::string userGuess;
int numberOfIncorrectGuesses = 0;
std::vector<char> vector1 = {};
std::vector<char> vector2 = {};


const std::vector<std::string> hangManASCIIStorage =
{
	"\n\n\n",
	" o\n\n\n",
	" o\n/\n\n",
	" o\n/|\n\n",
	" o\n/|\\\n\n",
	" o\n/|\\\n/\n",
	" o\n/|\\\n/ \\\n"
};

int takeInGuess() {
	std::cout << "Please enter the word to guess" << std::endl;
	std::cin >> userGuess;
	return 0;
}

int displayCurrentHangman() {
	std::cout << hangManASCIIStorage[numberOfIncorrectGuesses] << std::endl;
	return 0;
}

int userGuessAttemptFunction() {
	char guess;
	int incorrectCounter = 0;
	std::cout << "Please enter a letter to guess" << std::endl;
	std::cin >> guess;
	for (int i = 0; i < vector1.size(); i++) {
		if (guess == vector1[i])
			vector2[i] = vector1[i];
		else if (guess != vector1[i])
			incorrectCounter++;
	}
	if (incorrectCounter == vector1.size())
		numberOfIncorrectGuesses++;
	return 0;
}

int displayCurrentProgress() {
	for (const auto& element : vector2) {
		std::cout << element << " ";
	}
	return 0;
}

int vectorFillFunction() {

	for (int i = 0; i < userGuess.length(); i++) {
		vector1.push_back(userGuess.at(i));
		vector2.push_back('_');
	}
	return 0;
}

int testIfGameShouldEnd() {
	if (vector1 == vector2) {
		std::cout << "Congratulations! You win!" << std::endl;
		exit(0);
	}
	else if (numberOfIncorrectGuesses >= 6) {
		std::cout << "Game Over! You lose!" << std::endl;
		std::cout << "The word was" << userGuess;
		exit(0);
	}
	return 0;
}

void clearScreen() {
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}


int main() {
	takeInGuess();
	vectorFillFunction();
	clearScreen();
	while (true) {
		displayCurrentHangman();
		displayCurrentProgress();
		testIfGameShouldEnd();
		userGuessAttemptFunction();
	}
}