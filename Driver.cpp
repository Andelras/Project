#include <iostream>
#include "Random.h"
#include "ListArray.h"
#include "Integer.h"
#include "ListArrayIterator.h"
using namespace std;
using CSC2110::ListArray;
using CSC2110::Integer;
using CSC2110::ListArrayIterator;

int rollDie(int size)
{
	int num = getRandomInt(1, size);
	//cout << num->getValue() << endl;
	return num;
}

int rollDice(int numRoll, int size, int numDrop)
{
	int total = 0;
	int min = 1000000;
	int mindex;
	int counter = 0;
	ListArray<Integer>* roll = new ListArray<Integer>();
	
	if (numDrop >= numRoll)
	{
		cout << "Hey, ya screwed up.\n";
		cout << "You can't drop more than you roll!\n";
		return -1;
	}
	
	Integer* temp;
	for (int i = 0; i < numRoll; i++)
	{
		temp = new Integer(rollDie(size));
		roll->add(temp);
	}
	
	ListArrayIterator<Integer>* iter;
	for (int j = 0; j < numDrop; j++)
	{
		min = 1000000;
		counter = 0;
		iter = roll->iterator();
		while(iter->hasNext())
		{
			int temp2 = iter->next()->getValue();

			if (temp2 < min)
			{
				min = temp2;
				mindex = counter + 1;
			}
			counter++;
		}
		
		roll->remove(mindex);
		cout << min << " + ";
	}
	
	counter = 0;
	ListArrayIterator<Integer>* iter2 = roll->iterator();
	while (iter2->hasNext())
	{
		int temp3 = iter2->next()->getValue();
		if (counter == 0)
		{
			cout << "( " << temp3;
		}
		else
		{
			cout << " + " << temp3;
		}
		total += temp3;	
		counter++;
	}
	
	cout << " )";
	return total;
}

int rollDiceMenu()
{
	int choice;
	int size,
		numRoll,
		numDrop,
		result;
	cout << "\nDice Rollerer...er\n\n";
	cout << "1. Roll 1 die\n";
	cout << "2. Roll some dice\n";
	cout << "3. Roll some dice and drop some dice\n";
	cout << "4. Back\n";
	cin >> choice;
	
	switch (choice)
	{
		case 1: cout << "\nEnter the size of the die: ";
				cin >> size;
				result = rollDie(size);
				cout << "Roll: " << result << endl;
				break;
		case 2: cout << "Enter the number of the dice to roll: ";
				cin >> numRoll;
				cout << "Enter the size of the die: ";
				cin >> size;
				result = rollDice(numRoll, size, 0);
				cout << " = " << result << endl;
				break;
		case 3: cout << "Enter the number of the dice to roll: ";
				cin >> numRoll;
				cout << "Enter the size of the die: ";
				cin >> size;
				cout << "Enter the number of the dice to drop: ";
				cin >> numDrop;
				result = rollDice(numRoll, size, numDrop);
				cout << " = " << result << endl;
				break;
		case 4: return 0;
		default: "You have to pick a choice, stupid.\n";
	}
	
	return -1;
}

int mainMenu()
{
	int value;
	int choice;
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
	do
	{
		value = mainMenu();
	}while(value != 0);
	return 0;
}