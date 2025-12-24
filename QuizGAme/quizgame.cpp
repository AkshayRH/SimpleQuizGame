
#include <iostream>
#include <limits>
#include <fstream>
using namespace std;

void quizgame();	 // Main Quiz GAme Function
void aboutSection(); // About App
void clrscr();		 // For Clearing The Screen

// A Simple Quiz Game With scoring system, Using 1 Dimensional Arrays (S)

int main()

{

	int choice;									   // Creating a variable 'choice'
	cout << "\nWelcome To Quiz Game v1.1" << endl; // welcome Text to user

	while (true)
	{
		// For Displaying Menu
		cout << "\n1.Start The Game" << endl;
		cout << "2.About/UPdates" << endl;
		cout << "3.Exit" << endl;
		cout << "\nEnter Your Choice 1/2/3: ";
		if (!(cin >> choice))
		{
			// If input is not an integer
			cin.clear();										 // Clear error flags
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard input buffer
			clrscr();											 // Fucntion For Clearing The Screen
			cout << "Invalid input. Please enter a valid choice." << endl;
			continue;
		}
		switch (choice)
		{
		case 1:
			clrscr();
			quizgame();
			break;

		case 2:
			clrscr();
			aboutSection();
			break;

		case 3:
			clrscr();
			cout << "Thank You" << endl;
			return 1;
			break;

		default:
			clrscr();
			cout << "Invalid Choice, Select Correct Option" << endl;
			break;
		}
	}
	return 0;
}

void quizgame()
{
	int score = 0; // Creating Variable score for scoring system in game which is set to default value '0'
	// Displaying Isntructions
	cout << "Welcome to the Quiz Game Difficulty: Easy Level: 1" << endl;
	cout << "\nInstructions:" << endl;
	cout << "1. There are Five OBjective Type Questions" << endl;
	cout << "2. For Each Correct Answer Your score Gain +1, -1 for Wrong" << endl;
	cout << "3. Type correct Option in lowercase letter a,b,c" << endl;
	cout << "4. Press E/e to Exit in middle of game" << endl;
	cout << "\nAll The Best ^_^" << endl;
	system("pause");
	clrscr();

	string answers[5] = {"c", "b", "c", "a", "b"}; // Correct Answer Options
	string userAnswers[5];						   // Max Answers 5

	string questions[5] = {// Questions To Respond
						   "Q1: Which planet is in Habitable Zone?\nA. Mars\nB. Jupiter\nC. Earth",
						   "Q2: Which is the dwarf Planet of our solar System?\nA. Mars\nB. Pluto\nC. Jupiter",
						   "Q3: How Many Planets are there in Solar system?\nA. 2\nB. 12\nC. 8",
						   "Q4: In Which Galaxy We Live?\nA. Milkyway\nB. Andromeda\nC. Pinwheel",
						   "Q5: Which is the Largest Planet in our Solar System?\nA. Mercury\nB. Jupiter\nC. Earth"};
	// More Questions Can be added

	string correctAnswers[5] = {
		// Correct Answers
		"C. Earth",
		"B. Pluto",
		"C. 8",
		"A. Milkyway",
		"B. Jupiter",
	};

	for (int i = 0; i < 5; i++)
	{

		cout << "\n";
		cout << questions[i] << endl; // Displaying Questions
		cin >> userAnswers[i];		  // Taking Input From user

		if (userAnswers[i] == answers[i]) // Checking User Answer
		{
			clrscr();
			cout << "Correct! " << endl;
			score++;								   // Score +1
			cout << "Your Score is " << score << endl; // Displaying Score
		}
		else if (userAnswers[i] == "E" || userAnswers[i] == "e") // If user Wants to exit
		{
			clrscr();
			return; // Returns to Main Menu
		}
		else
		{
			clrscr();
			cout << "Wrong! Correct Answer is " << correctAnswers[i] << endl; // If Wrong Answer Displays Wrong Message Aswell AS  the correct Answer
			score--;														  // Score -1
			cout << "Your Score is " << score << endl;
		}
	}

	// Displaying Final Score After end of Game
	cout << "\nYour score is " << score << " out of 5" << endl;
	// Code for Ranking System depend on score
	if (score >= 4)
	{
		cout << "\nExcellent \nCheers ^_^" << endl;
	}
	else if (score >= 2 && score <= 4)
	{
		cout << "\nVery Good \nWell Done :)" << endl;
	}
	else
	{

		cout << "\nVery Bad \nBetter Luck Next Time!!" << endl;
	}

	cout << "\nThank YOu!!" << endl; // Displaying Thank you Message after the end of game
	system("pause");
	clrscr();

	string path = "\\UserHistory\\Game\\userhistory.txt\\";
	ofstream file(path, ios::app);
	if (file.is_open())
	{
		for (int i = 0; i < 5; i++)
		{
			file << questions[i] << " " << correctAnswers[i] << " " << correctAnswers[i] << endl;
			file << endl;
				}
		file.close();
	}
}

void aboutSection()
{

	cout << "About: \nA Mini QuizGame Project Made By Akshay RH, Class 11 Student" << endl;
	cout << "\nUpdates: \n1. Added In game exiting Feature" << endl;
	cout << "2. Fixed Bugs and Made more Smoother" << endl;
	cout << "3. Fixed Clearscreen Buffer" << endl;
	system("pause");
	clrscr();
	return;
}

void clrscr() // Function to clear the screen
{

	system("cls");
}

// key answers
//  Q1 (C)
//  Q2 (B)
//  Q3 (C)
//  Q4 (A)
//  Q5 (B)

// By Akshay RH :)
