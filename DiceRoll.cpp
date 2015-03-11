#include "Text.h"
#include <windows.h>
#include "ListArray.h"
#include "Integer.h"
#include "ListArrayIterator.h"
#include <iostream>
#include "Random.h"
using namespace std;
using namespace CSC2110;

int rollDie(int size)
{
	int num = getRandomInt(1, size);
	//cout << size << endl;
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

int roll1()
{
	char input[4];
	int size = 0;
	int	result = 0;
	bool keepGoing;
	system("cls");
	cout << "Press 'r' to roll again, 'b' to go back, \nor any number to roll again with a new die.\n";
	do{
		cout << "Enter the size of the die: ";
		cin >> input;
		
		if (input[0] == 'b')
		{
			return 0;
		}
		else if (input[0] == 'r')
		{
			if (result == 0)
			{
				cout << "You have to roll once before you can reroll!\n\n";
			}
			else
			{
				result = rollDie(size);
				cout << "Roll: " << result << endl;
			}
		}
		else
		{
			String* str = new String(input);
			size = str->a_to_i();
			result = rollDie(size);
			cout << "Roll: " << result << endl;
		}
	}while(true);
	return -1;
}

int roll2()
{
	char input[4];
	int size;
	int	result = 0;
	int numRoll;
	bool keepGoing;
	system("cls");
	cout << "Press 'r' to roll again, 'b' to go back, \nor any number to roll again with new dice.\n";
	do{
		start:
		cout << "Enter the number of the dice to roll: ";
		cin >> input;
		
		if (input[0] == 'b')
		{
			return 0;
		}
		else if (input[0] == 'r')
		{
			if (result == 0)
			{
				cout << "You have to roll once before you can reroll!\n\n";
				goto start;
			}
			else
			{
				result = rollDice(numRoll, size, 0);
				cout << " = " << result << endl;
				goto start;
			}
		}
		else
		{
			String* str = new String(input);
			numRoll = str->a_to_i();
		}
		
		cout << "Enter the size of the dice: ";
		cin >> input;
		if (input[0] == 'b')
		{
			return 0;
		}
		else if (input[0] == 'r')
		{
			if (result == 0)
			{
				cout << "You have to roll once before you can reroll!\n\n";
			}
			else
			{
				result = rollDice(numRoll, size, 0);
				cout << " = " << result << endl;
			}
		}
		else
		{
			String* str = new String(input);
			size = str->a_to_i();
			result = rollDice(numRoll, size, 0);
			cout << " = " << result << endl;
		}
	}while(true);
}

int roll3()
{
	char input[4];
	int size;
	int	result = 0;
	int numRoll;
	int numDrop;
	bool keepGoing;
	system("cls");
	cout << "Press 'r' to roll again, 'b' to go back, \nor any number to roll again with new dice.\n";
	do{
		start:
		cout << "Enter the number of the dice to roll: ";
		cin >> input;
		
		if (input[0] == 'b')
		{
			return 0;
		}
		else if (input[0] == 'r')
		{
			if (result == 0)
			{
				cout << "You have to roll once before you can reroll!\n\n";
				goto start;
			}
			else
			{
				result = rollDice(numRoll, size, numDrop);
				cout << " = " << result << endl;
				goto start;
			}
		}
		else
		{
			String* str = new String(input);
			numRoll = str->a_to_i();
		}
		
		cout << "Enter the size of the dice: ";
		cin >> input;
		if (input[0] == 'b')
		{
			return 0;
		}
		else if (input[0] == 'r')
		{
			if (result == 0)
			{
				cout << "You have to roll once before you can reroll!\n\n";
				goto start;
			}
			else
			{
				result = rollDice(numRoll, size, numDrop);
				cout << " = " << result << endl;
				goto start;
			}
		}
		else
		{
			String* str = new String(input);
			size = str->a_to_i();
		}
		
		cout << "Enter the number of the dice to drop: ";
		cin >> input;
		if (input[0] == 'b')
		{
			return 0;
		}
		else if (input[0] == 'r')
		{
			if (result == 0)
			{
				cout << "You have to roll once before you can reroll!\n\n";
			}
			else
			{
				result = rollDice(numRoll, size, 0);
				cout << " = " << result << endl;
			}
		}
		else
		{
			String* str = new String(input);
			numDrop = str->a_to_i();
			result = rollDice(numRoll, size, numDrop);
			cout << " = " << result << endl;
		}
	}while(true);
}

int rollDiceMenu()
{
	int choice;
	system("cls");
	cout << "Dice Rollerer...er\n\n";
	cout << "1. Roll 1 die\n";
	cout << "2. Roll some dice\n";
	cout << "3. Roll some dice & drop some dice\n";
	cout << "4. Back\n";
	cin >> choice;
	
	switch (choice)
	{
		case 1: roll1();
				break;
		case 2: roll2();
				break;
		case 3: roll3();
				break;
		case 4: return 0;
		default: "You have to pick a choice, stupid.\n";
	}
	
	return -1;
}