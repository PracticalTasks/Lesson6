#include<iostream>
#include"BlackJack.h"

using namespace std;

void endll()
{
	cout << "\n\n";
	cout.flush();
}

int main()
{
	//Task 1
	{
		cout << "Task 1\n";
		cout << "Please enter an integer: ";
		const int SZ{ 100 };
		char arr[SZ]{};
		int i{};
		while (cin.get(arr[i]))
		{
			if (arr[i] < '0' || arr[i] > '9')
			{
				cin.ignore(256, '\n');
				i = 0;
				cout << "Enter error!\n";
				cout << "Please enter an integer: ";
				continue;
			}
			i++;
			if (cin.peek() == 10)
			{
				arr[i] = '\0';
				break;
			}
				
		}
		i = 0;
		while (arr[i] != '\0')
		{
			cout << arr[i];
			++i;
		}
		cout << '\n';
	}

	//Task 2
	{
		cout << "\n\nTask 2\n";
		cout << "Any text";
		endll();
		cout << "Any text";
	}

}
