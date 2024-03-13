/*

	Helen Bradford, Grecia Tragodara, and Steven Fernandez

	project.cpp

	Menu-driven interface program Text-based role playing game

	Input: Menu options then a character and weapon of choice

	Processing: 1. Display Menu & prompt user for a option
					
					1.1). Display Game's rules
					1.2). Display menu with characters options
						
						1.2.1). Prompt user for a number that chooses a character (1 is a Human, 2 is an Ogre, and 3 is an Elf) 
						1.2.2). Prompt user for to choose a weapon (1 is a Flame Thrower, 2 is a Bow and Arrow, and 3 is a Magic Potion)
						1.2.3). Calculate points earned by the weapon of choice
						1.2.4). Display player's character and points earned
						1.2.5). Create and/or update the file highscore.txt with the highest score

					
					1.3) Quit game

	Output: A Player's highest score

*/

// Header Files
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <random>
using namespace std;

// Functions Prototypes
int mainMenu();
void GameRules();
string optionMenu(int &points);
string chooseWeapon(int &random);
void TargetPoints(string, int &points2);
void DisplayScore(string, int, int);
void getScore(string, int);

int main()
{
	// Variables
	int option, points, weaponPoints;
	string character, weapon;

	// Intro 
	cout << "\nRole Playing Game ..." << endl;

	// Menu-Driven Interface
	do
	{
		option = mainMenu();

		// Drive option
		switch (option)
		{
		case 1: // Display Game's rules
			GameRules();
			break;

		case 2: // Display menu with characters options
			character = optionMenu(points);
			weapon = chooseWeapon(points);
			TargetPoints(weapon, weaponPoints);
			DisplayScore(character, points, weaponPoints);
			break;

		case 3: // Quit
			cout << "\nThank you, have a good day ..." << endl << endl;
			break;

		default:
			cout << "\nError ... Invalid option. Please try again." << endl;
		}
	} while (option != 3);


	system("pause");
	return 0;
}

/*
	int mainMenu()

	Prompt user to choose an option from the menu

	Return value: Option chose by the user
*/
int mainMenu()
{
	int option;

	// Display Menu & prompt user for a option
	cout << "\nChoose one of the following options ..." << endl
		<< "\t1. See Rules" << endl
		<< "\t2. Play Game" << endl
		<< "\t3. Quit" << endl
		<< "Option: ";
	cin >> option;

	return option;

}
/*
	void GameRules()

	Display the game rules

	Return value: None
*/
void GameRules()
{
	// Display game's rules
	cout << "\nGame Rules" << endl
		<< "\n1. Select a Character with 1 being a Human, 2 being an Ogre, and 3 being an Elf." << endl
		<< "\n2. Select your Weapon with 1 being a Flame Thrower, 2 being a Bow and Arrow, and 3 being a Magic Potion." << endl
		<< "\n3. The game will put your Character through target practice with the Flame Thrower and Bow and Arrow, or test to see if your Magic Potion was a success or failed." << endl
		<< "\n4. The game will tally up your score and display your score!" << endl
		<< "\n5. DO NOT CHOOSE ANY NUMBERS OTHER THEN THE ONES SHOWN!!!" << endl
		<< "\n6. Above all else... HAVE FUN!" << endl;
}
/*
	string optionMenu(int &points)

	Prompt user for a character

	Return value: Character and points associate with that character
*/
string optionMenu(int &points)
{
	// Variables
	string character;
	int option;

	do
	{
		// Prompt user for a character
		cout << "\nPlease Select a Character ..." << endl
			<< "\t1. Human" << endl
			<< "\t2. Ogre" << endl
			<< "\t3. Elf" << endl
			<< "Option: ";
		cin >> option;

		// Character Options
		if (option == 1)
		{
			character = "Human";
			points = 100;
		}

		if (option == 2)
		{
			character = "Ogre";
			points = 200;
		}

		if (option == 3)
		{
			character = "Elf";
			points = 300;
		}

		// Loop for validation
	} while (option != 3 && option != 1 && option != 2);
	return character;
}

/*
	string chooseWeapon(int &points)

	Prompt user for to choose a weapon

	Return value: Weapon chose by the user
*/
string chooseWeapon(int &points)
{
	// Variables
	string weapon;
	int option, random, score;

	do
	{
		// Prompt user for to choose a weapon
		cout << "\nPlease Select a Weapon ..." << endl
			<< "\t1. Flame Thrower" << endl
			<< "\t2. Bow and Arrow" << endl
			<< "\t3. Magic Potion" << endl
			<< "Option: ";
		cin >> option;

		// Weapon Options
		if (option == 1)
		{
			weapon = "Flame Thrower";

		}
		if (option == 2)
		{
			weapon = "Bow and Arrow";

		}
		if (option == 3)
		{
			weapon = "Magic Potion";

		}

		// Loop for Validation
	} while (option != 3 && option != 1 && option != 2);

	return weapon;
}

/*
	void TargetPoints(string weapon, int &points2)

	Calculate points earned by the weapon of choice

	Return value: weapon's points earned
*/

void TargetPoints(string weapon, int &points2)
{
	// Variables
	int random;

	// Calculate points earned by the Flame Thrower or Bow and Arrow
	if (weapon == "Flame Thrower" || weapon == "Bow and Arrow")
	{
		// Random Number Generator
		srand(time(NULL));
		random = rand() % 4 + 1;
		if (random == 1)
		{
			points2 = 100;
			cout << "Congratulations you hit target A";
		}
		if (random == 2)
		{
			points2 = 200;
			cout << "Congratulations you hit target B";
		}
		if (random == 3)
		{
			points2 = 300;
			cout << "Congratulations you hit target C";
		}
		if (random == 4)
		{
			points2 = 0;
			cout << "Unfortunately you didn't hit any target";
		}
	}

	// Calculate points earned by the Magic Potion
	if (weapon == "Magic Potion")
	{
		// Random Number Generator
		srand(time(NULL));
		random = rand() % 1 + 0;
		if (random == 0)
		{
			points2 = 100;
			cout << "Unsuccessful potion";
		}
		if (random == 1)
		{
			points2 = 200;
			cout << "Successful potion";
		}
	}
}
/*
	void DisplayScore(string character, int points, int points2)

	Display player's character and points earned

	Return value: none
*/

void DisplayScore(string character, int points, int points2)
{
	// Variables
	int totalScore, highScore = 0;
	string name;
	fstream myFile;

	// Intro
	cout << "\n\nUser's Score ";

	// Find total Score 
	totalScore = points + points2;
	cout << character << " " << totalScore << endl << endl;

	// Display Scores
	getScore(character, totalScore);

}

/*
	void getScore(string character, int totalScore)

	Create and/or update the file highscore.txt with the highest score

	Return Value: None

*/
void getScore(string character, int totalScore)
{
	// Variables
	fstream myFile;
	string name;
	int highScore = 0;

	// Open file
	myFile.open("highscore.txt", ios::in);
	if (myFile.is_open())
	{
		while (myFile >> name)
		{
			myFile >> highScore;
		}
	}

	// Close file
	myFile.close();

	if (highScore < totalScore)
	{
		// Open file
		myFile.open("highscore.txt", ios::out);
		myFile << character << "\t" << totalScore << endl;
		
		// Close file
		myFile.close();
	}

	// Open file
	myFile.open("highscore.txt", ios::in);
	if (myFile.is_open())
	{
		while (myFile >> character)
		{
			myFile >> highScore;
			cout << character << "\t" << highScore << endl;
		}
	}

	// Close file
	myFile.close();
}