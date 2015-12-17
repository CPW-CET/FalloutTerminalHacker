// FalloutHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "time.h"
using namespace std;

int main()
{
	srand(time(NULL));
	int RandWord = 0;

	const int MaxNumOfWords = 10;
	int difficulty = 0;
	int NumOfWords = 0;
	int NumOfLetters = 0;
	int index = 0;
	int chosenword_num = 0;
	int Num_Correct = 0;
	int Num_of_Guesses = 4;

	bool EndGame = false;

	ifstream myfile;

	string file_Name;
	string line;
	string words[MaxNumOfWords];
	string Password;
	string ChosenWord;
	string User_In_Word;

	cout << "Difficulty? (1-5): ";
	cin >> difficulty;

	switch (difficulty) {
	case 1:
		file_Name = "VeryEasy.txt";
		NumOfLetters = 4;
		NumOfWords = 5;
		RandWord = rand() % 5;
		break;
	case 2:
		file_Name = "Easy.txt";
		NumOfLetters = 5;
		NumOfWords = 7;
		RandWord = rand() % 7;
		break;
	case 3:
		file_Name = "Normal.txt";
		NumOfLetters = 6;
		NumOfWords = 8;
		RandWord = rand() % 8;
		break;
	case 4:
		file_Name = "Hard.txt";
		NumOfLetters = 7;
		NumOfWords = 9;
		RandWord = rand() % 9;
		break;
	case 5:
		file_Name = "VeryHard.txt";
		NumOfLetters = 8;
		NumOfWords = 10;
		RandWord = rand() % 10;
		break;
	default:
		break;
	}

	myfile.open(file_Name);


	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			words[index] = line;
			index++;
		}
		myfile.close();	
		
		Password = words[RandWord];

		//cout << "Choose a word (1 - " << NumOfWords << ")" << endl;

		for (int i = 0; i < NumOfWords; i++)
		{
			cout << words[i] << endl;
		}

		while (EndGame != true)
		{
			if (Num_of_Guesses == 0)
			{
				EndGame = true;
				cout << "INIT LOCKOUT" << endl;
			}
			else
			{
				cout << "Guess? ( "<< Num_of_Guesses << " left)";
				cin >> User_In_Word;

				//cin >> chosenword_num;
				//ChosenWord = words[chosenword_num-1];

				for (int i = 0; i < User_In_Word.length(); i++)
				{
					User_In_Word[i] = char(toupper(User_In_Word[i]));
				}

				//if (ChosenWord != Password)
				if (User_In_Word != Password)
				{
					//for (int i = 0; i < ChosenWord.length(); i++)
					for (int i = 0; i < User_In_Word.length(); i++)
					{
						//if (ChosenWord[i] == Password[i])
						if (User_In_Word[i] == Password[i])
						{
							Num_Correct++;
						}
					}
					Num_of_Guesses--;
					cout << Num_Correct << "/" << NumOfLetters << " Correct" << endl;
				}
				else
				{
					cout << "You chose the right word!" << endl;
					EndGame = true;
					break;
				}
			}

		}
	}
	else
	{
		cout << "Unable to open file";
	}

	system("pause");
    return 0;
}
