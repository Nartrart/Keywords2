
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>
using namespace std;


int main()
{
	//title of the page!
	system("title C.B.P.P");

	//colors the background 
	system("color 3F");

	// Display Title of program to user
	cout << "Welcome... To the Official CIA Code Breaking Practice Program 2...\n\n";

	// asks for a name
	cout << "-----Please Input Your Name-----\nName: ";

	// the var to hold the users name
	string userName;

	cin >> userName;
	cout << "Welcome to the simulation, " << userName << ".\n\n";

	// the intro
	cout << "This simulation is a simple exercize to help develop your code breaking skills.\n";

	// directions on what to do
	cout << "Guess the letters to break the code. Unfortunately, if you do not guess correctly you have failed the program.\n\n";

	// our 10 secret mousekatools
	/*
										_____
								   .d88888888bo.
								 .d8888888888888b.
								 8888888888888888b
								 888888888888888888
								 888888888888888888
								  Y8888888888888888
							,od888888888888888888P
						 .'`Y8P'```'Y8888888888P'
					   .'_   `  _     'Y88888888b
					  /  _`      `      Y88888888b   ____
				   _  | /  \            8888888888.d888888b.
				  d8b | | /|            8888888888d8888888888b
				 8888_\ \_|/  \__/      d888888888888888888888b
				 .Y8P  `'-.            d88888888888888888888888
				/          `          `      `Y8888888888888888
				|                        __    888888888888888P
				 \                       / `   dPY8888888888P'
				  '._                  .'     .'  `Y888888P`
					 `"'-.,__    ___.-'    .-'
					     `-._````  __..--'`
							 ''''''
	*/
	vector<string> wordBank = 
	{
		{"secret"},
		{"computer"},
		{"agent"},
		{"hack"},
		{"law",},
		{"whisper",},
		{"defrag"},
		{"perish"},
		{"bomb"},
		{"coordinates"},
	};

	// counts the number of simulations being run by starting at 1
	int simulationNumber = 1;
	char runAgain = 'y';

	while (runAgain == 'y') {
		// displays simulation number to recruit
		cout << "Simulation #" << simulationNumber << " initializing..\n\n";

		// random word generator
		srand(static_cast<unsigned int>(time(0)));

		vector<string> chosenWords;
		for (int i = 0; i < 3; i++) {
			chosenWords.push_back(wordBank[(rand() % wordBank.size())]);
		}
		int guessesLeft;

		//beginning of 3 word loop
		for (int dx = 0; dx < 3; dx++) {

			bool wordFound = false;
			char currentGuess;
			int lettersCorrect = 0;
			int wordIndex = 0; //unused
			string currentWord = "temp";
			string lettersGuessed = "";
			guessesLeft = 20;
			currentWord = chosenWords[dx];

			// reveals letters
			vector<string> hiddenWord(currentWord.length(), "-");

			// guess counter
			while ((guessesLeft != 0) && (!(lettersCorrect == currentWord.length()))) {
				// guess counter p. 2
				cout << "\nYou have " << guessesLeft << " incorrect guesses remaining.\n\n";

				// Show recruit the letters they've guessed
				if (lettersGuessed.empty()) {
					cout << "You have not guessed yet.";
				}
				else {
					cout << "You guessed: ";
					// prints each element in the lettersGuessed
					for (unsigned int j = 0; j < lettersGuessed.length(); j++) {
						cout << lettersGuessed[j] << " ";
					}
					// reveals the letters guess ;)
					lettersCorrect = 0;
					// checking if increment is true
					for (unsigned int j = 0; j < currentWord.length(); j++) {
						for (unsigned int k = 0; k < lettersGuessed.length(); k++) {
							if (currentWord[j] == lettersGuessed[k]) {
								lettersCorrect++;
							}
						}
					}
					cout << "\nYou guessed " << lettersCorrect << " out of ";
					cout << currentWord.length() << " letters correctly.";
				}
				// prints secret word
				cout << "\nYour word is: ";
				for (unsigned int j = 0; j < hiddenWord.size(); j++) {
					cout << hiddenWord[j] << " ";
				}
				// checking for a solution
				if (lettersCorrect == currentWord.length()) {
					cout << "\n\n---You have guessed correctly!!---";
					cout << "\n------------------------\n";
					break;
				}
				bool characterAlreadyGuessed = false;
				do {
					// time for the next guess
					cout << "\n\nEnter a letter: ";
					cin >> currentGuess;

					// if the recruit has entered a letter already entered
					for (unsigned int j = 0; j < lettersGuessed.length(); j++) {
						if (currentGuess == lettersGuessed[j]) {
							// Get recruit ’s guess
							cout << "You've guessed that already, silly!!!";
							characterAlreadyGuessed = true;
							break;
						}
						else {
							characterAlreadyGuessed = false;
						}
					}
				} while (characterAlreadyGuessed);

				// adds guess to letters
				if (!lettersGuessed.empty()) {

					for (unsigned int j = 1; j - 1 < lettersGuessed.length(); j++) {
						if (currentGuess < lettersGuessed[j - 1]) {
							lettersGuessed.insert(j - 1, 1, currentGuess);
							break;
						}
						else if (currentGuess > lettersGuessed[j - 1]) {
							if (j != lettersGuessed.length()) {
								continue;
							}
							else {
								lettersGuessed.insert(j, 1, currentGuess);
							}
						}
					}
				}
				else {
					lettersGuessed = lettersGuessed + currentGuess;
				}
				// If the guess is correct
				bool letterInWord = false;
				for (unsigned int j = 0; j < currentWord.length(); j++) {
					if (currentGuess == currentWord[j]) {
						letterInWord = true;
						// Update the word guessed so far with the new letter
						hiddenWord[j] = currentGuess;
					}
				}
				if (letterInWord) {
					// congrats!
					cout << "Correct!!.\n";
				}
				// Otherwise
				else {
					// wrong >:(
					cout << "Character not found in word.";
					// incrementing wrong guessses
					guessesLeft--;
				}
			}
		}
		// if the recruit is a failure
		if (guessesLeft == 0) {
			// bro... you fail :pensive:
			cout << "You have failed the simulation. Sowwy.";
		}
		// Otherwise
		else {
			// Hallelujah you won son!
			cout << "Simulation Complete! Congrats!";
		}
		// ask if they wanna play again
		cout << "\n\nWould you like to play again?(y/n): ";
		cin >> runAgain;
		// if oui oui
		if (runAgain == 'y') {
			// simulations counter
			simulationNumber++;
			// bro we gotta keep going
			continue;
		}
		// Otherwise 
		else break;
	}
	// the end *flourishes dramatically*
	cout << "----END OF SIMULATION----\n\n";

	system("pause");
	return 0;
}
