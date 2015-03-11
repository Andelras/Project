#include <iostream>
#include "Random.h"
#include <windows.h>
#include "DiceRoll.h"
using namespace std;

int mainMenu()
{
	int value;
	int choice;
	system("cls");
	cout << "D&D Tool Kit\n\n";
	cout << "1. Roll some dice\n";
	cout << "2. Create some NPCs\n";
	cout << "3. Roll some PCs\n";
	cout << "4. Create some monsters\n";
	cout << "5. Quit\n";
	cin >> choice;
	
	switch (choice)
	{
		case 1: do{
				value = rollDiceMenu();
				}while(value != 0);
				break;
		case 2: cout << "\nComing in a future version\n\n";
				break;
				//npcMenu();
		case 3: cout << "\nComing in a future version\n\n";
				break;
				//pcMenu();
		case 4: cout << "\nComing in a future version\n\n";
				break;
				//monsterMenu();
		case 5: return 0;
		default: "You have to pick a choice, stupid.\n\n";
	}
	return -1;
}

int main()
{
	int value;
	randomInit();
	//rollDice(4, 6, 0);
	do{
		value = mainMenu();
	}while(value != 0);
	return 0;
}