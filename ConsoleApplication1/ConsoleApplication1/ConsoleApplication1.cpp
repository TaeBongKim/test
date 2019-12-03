// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

bool isWall(int x, int y)
{
	if (x < 0 || x >= 5)
		return true;

	if (y < 0 || y >= 5)
		return true;

	return false;
}

int calAbs(int a, int b)
{
	return (a - b) > 0 ? (a - b) : (b - a);
}


int main(int argc, char** argv) {
	const int size = 5;

	int arr[size][size] = {
		{9, 20, 2, 18, 11},
		{19, 1, 25, 3, 21},
		{8, 24, 10, 17, 7},
		{15, 4, 16, 5, 6},
		{12, 13, 22, 23, 14}
	};

	int directionX[] = { 0, 0, -1, 1 };
	int directionY[] = { -1, 1, 0, 0 };

	int newX, newY;
	int sum = 0;

	for (int x = 0; x < size; x++) {
		for (int y = 0; y < size; y++) {
			for (int dir = 0; dir < 4; dir++) {
				newX = x + directionX[dir];
				newY = y + directionY[dir];

				if (!isWall(newX, newY)) {
					sum += calAbs(arr[x][y], arr[newX][newY]);
				}
			}
		}
	}

	cout << "sum : " << sum << endl;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
