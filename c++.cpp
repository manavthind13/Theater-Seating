#include <iostream>
using namespace std;
void printMenu() 
{ 
	cout << "\nChoose Option: ";
	cout << "\na: Choose Seat Number:\n";
	cout << "b: See Available Seats for their price:\n";
	cout << "c: Book Seat\n\n";
}
void printSeats(int arr[10][10]) 
{ 
	cout << "Here are all the available seats and price\n\n";
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}
void chooseSeat(int arr[10][10]) 
{ 
	int row; 
	int col; 
	while (true) 
	{ 
		cout << "Type Row Number (Bottom: 1st Row):";
		cin >> row;
		if (row < 1 || row > 10) 
		{ 
			cout << "Wrong Input, Try Again\n";
		}
		else {
			break;
		}
	}
	while (true) 
	{ 
		cout << "Type Column Number (Left: 1st Column):";
		cin >> col;
		if (col < 1 || col > 10)
		{ 
			cout << "Wrong Input. Try Again\n";
		}
		else 
		{
			break;
		}
	}
	if (arr[9 - row + 1][col - 1] == 0) 
	{
		cout << "Seat Already Booked, Try Again\n";
		chooseSeat(arr);
	}
	else { 
		cout << "Congratulations, your seat is booked. \n";
		arr[9 - row + 1][col - 1] = 0;
	}
}
void seeAvaialbleSeats(int arr[10][10]) 
{
	int price; 
	cout << "Enter Price For Searching:";
	cin >> price;
	cout << "Available Seats for Price :" << price << "\n";
	for (int i = 9; i >= 0; i--) 
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr[i][j] == price) 
			{ 
				cout << "Row: " << (9 - i + 1) << " Column: " << (j + 1) << "\n";
			}
		}
	}
	cout << "\n";
}
int main() 
{
	int arr[10][10] =
	{
	{10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
	{10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
	{10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
	{10, 10, 20, 20, 20, 20, 20, 20, 10, 10},
	{10, 10, 20, 20, 20, 20, 20, 20, 10, 10},
	{10, 10, 20, 20, 20, 20, 20, 20, 10, 10},
	{20, 20, 30, 30, 40, 40, 30, 30, 20, 20},
	{20, 30, 30, 40, 50, 50, 40, 30, 20, 20},
	{30, 40, 50, 50, 50, 50, 50, 50, 40, 30},
	{30, 40, 50, 50, 50, 50, 50, 50, 40, 30}
	};

	bool loop = true; 
	while (loop) {
		printSeats(arr); 
		printMenu(); 
		char c; 
		cin >> c;
		switch (c) 
		{ 
		case 'c': 
			chooseSeat(arr);
			break;
		case 'a': 
			seeAvaialbleSeats(arr);
			break;
		case 'q': 
			loop = false;
			cout << "Quitting Program";
			break;
		default: 
			cout << "Wrong Entry. Please Try Again!\n\n";
		}
	}
	return 0;
}