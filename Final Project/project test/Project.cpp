/*

	Helen Bradford, Grecia Tragodara, and Steven Fernandez

	Project.cpp

	Game based on menu-driven interface to play a Text-based role playing game

	Input: User's menu option, name, character, and weapon

	Processing: 1. Prompt user for a choice in the menu
				    - if 1 display game's rules
					- if 2 prompt user for name, character, weapon
					- if 3 exit the program
				2. Prompt user for name 
				3. Prompt user for character
				    - Generate character image 
				    - Calculate points earn by the character of choice 
				4. Prompt user for a weapon
				    - Calculate points earn by the weapon of choice 
				5. Create file if file doesn't exist 
				    - Test if file is present or no
				6. Open file and compare user's score with the score store inside the file
				    - If new score is higher replace it if is not keep the old one
				7. Show user's score
				8. Show highest score ever achieved with the name of the user 

	Output: User's score and highest score ever achieved on the game

*/

// Header Files
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

// Functions Prototypes
int mainMenu();
void GameRules();
string optionMenu(int &points);
string chooseWeapon(int &random);
void TargetPoints(string, int &points2);
void DisplayScore(string, int, int);
void getScore(string, int);
string getName();
void drawGraphics(string);

int main()
{
	// Variables Declaration
	int option, points, weaponPoints;
	string character, weapon, name;

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
			name = getName();
			character = optionMenu(points);
			weapon = chooseWeapon(points);
			TargetPoints(weapon, weaponPoints);
			DisplayScore(name, points, weaponPoints);
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
	// Variables Declaration
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
	// Variables Declaration
	string character;
	int option;

	do
	{
		cout << "\nPlease Select a Character ..." << endl
			<< "\t1. Human" << endl
			<< "\t2. Ogre" << endl
			<< "\t3. Elf" << endl
			<< "Option: ";
		cin >> option;

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

		drawGraphics(character);

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
	// Variables Declaration
	string weapon;
	int option;

	do
	{
		cout << "\nPlease Select a Weapon ..." << endl
			<< "\t1. Flame Thrower" << endl
			<< "\t2. Bow and Arrow" << endl
			<< "\t3. Magic Potion" << endl
			<< "Option: ";
		cin >> option;

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
	// Variables Declaration
	int random;

	if (weapon == "Flame Thrower" || weapon == "Bow and Arrow")
	{
		srand(time(NULL));
		random = rand() % 4 + 1;
		if (random == 1)
		{
			points2 = 100;
			cout << "Congratulations you hit target A" << endl;
		}
		if (random == 2)
		{
			points2 = 200;
			cout << "Congratulations you hit target B" << endl;
		}
		if (random == 3)
		{
			points2 = 300;
			cout << "Congratulations you hit target C" << endl;
		}
		if (random == 4)
		{
			points2 = 0;
			cout << "Unfortunately you didn't hit any target" << endl;
		}
	}

	if (weapon == "Magic Potion")
	{
		srand(time(NULL));
		random = rand() % 1 + 0;
		if (random == 0)
		{
			points2 = -100;
			cout << "Unsuccessful potion" << endl;
		}
		if (random == 1)
		{
			points2 = 200;
			cout << "Successful potion" << endl;
		}
	}
}
/*
	void DisplayScore(string name, int points, int points2)

	Display player's name and points earned

	Return value: None
*/

void DisplayScore(string name, int points, int points2)
{
	// Variables Declaration
	int totalScore, highScore = 0;
	fstream myFile;

	// Intro
	cout << "\nUser's Score ";

	// Find total Score 
	totalScore = points + points2;
	cout << name << " " << totalScore << endl << endl;

	// Display Scores
	getScore(name, totalScore);

}

/*
	void getScore(string name, int totalScore)

	Create and/or update the file highscore.txt with the highest score

	Return Value: None

*/
void getScore(string name, int totalScore)
{
	// Variables Declaration
	fstream myFile;
	string name2;
	int highScore = 0;

	// Open File
	myFile.open("highscore.txt", ios::in);
	if (myFile.is_open())
	{
		while (myFile >> name2)
		{
			myFile >> highScore;
		}
	}
	// Close file
	myFile.close();

	cout << "Highest Score Ever " << endl << endl;

	// Update file if higher score is achieved 
	if (highScore < totalScore)
	{
		myFile.open("highscore.txt", ios::out);
		myFile << name << "\t" << totalScore << endl;
		myFile.close();
	}

	myFile.open("highscore.txt", ios::in);
	if (myFile.is_open()) // Open File
	{
		while (myFile >> name)
		{
			myFile >> highScore;
			cout << name << "\t" << highScore << endl;
		}
	}
	// Close File
	myFile.close();
}
/*
	string getName(string name)

	Prompt user for name

	Return value: User's name 
*/

string getName()
{
	string name;

	cout << "\nPlease enter your name: ";
	cin.ignore(); // Clear buffer
	getline(cin, name);

	return name;
}
/*
	void drawGraphics(string entity)

	Generate image of the character that the user chose to play and display it

	Return Value: None
*/

void drawGraphics(string entity)
{
	if (entity == "Human")
	{
		cout << "\t,#####," << endl;
		cout << "\t#_   _#" << endl;
		cout << "\t|a` `a|" << endl;
		cout << "\t|  u  |" << endl;
		cout << "\t\\  =  /" << endl;
		cout << "\t|\\___/|" << endl;
	}
	else if (entity == "Ogre")
	{

		cout << "    \t__, / ='`````' = // __" << endl;
		cout << "	  '//  (o) \(o) \\\\ `' " << endl;
		cout << "	 //|     ,_)   ( \\\\""" << endl;
		cout << "\t,-~~~\  `'==='  //-, " << endl;
	}
	else if (entity == "Elf")
	{
		cout << "            .-." << endl;
		cout << "           .;;\\ |" << endl;
		cout << "          /::::\\ |\\\\" << endl;
		cout << "         /::::'();" << endl;
		cout << "        |::::'   |" << endl;
		cout << "       |\\/`\:_/`\\/|" << endl;
		cout << "   ,__ |0_..().._0| __," << endl;
		cout << "    \\,`////\"\"\"\"\\\\\\\\`,/" << endl;
		cout << "    | )//_ o  o _\\\\( |" << endl;
		cout << "     \\/|(_) () (_)|\\/" << endl;
		cout << "       \\   '--'   /" << endl;
		cout << "       _:.______.; _" << endl;

	}
	
}