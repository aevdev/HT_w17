#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void printArr(int** matrix, size_t rows, size_t columns)
{
	for (int i = 0; i < rows; ++i)
	{
		cout << '\n';
		for (int j = 0; j < columns; ++j)
		{
			cout << matrix[i][j] << '\t';
		}
	}
}

void insertColumn(int*** matrix, size_t rows, size_t columns, size_t index, int choose)
{
	int** copy = new int* [rows];
	for (int i = 0; i < rows; ++i)
		copy[i] = new int[columns + 1];

	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < index; ++j)
			copy[i][j] = (*matrix)[i][j];

	if (choose == 1)
	{
		for (int i = 0; i < rows; ++i)
		{
			cout << "\nPlease enter [" << i << "][" << index << "] element: ";
			cin >> copy[i][index];
		}
	}
	else
	{
		for (int i = 0; i < rows; ++i)
			copy[i][index] = rand() % (100 + 100) - 100;
	}
	
	for (int i = 0; i < rows; ++i)
		for (int j = index + 1; j < columns + 1; ++j)
			copy[i][j] = (*matrix)[i][j - 1];

	for (int i = 0; i < rows; ++i)
		delete (*matrix)[i];
	delete[](*matrix);

	(*matrix) = copy;
	for (int i = 0; i < rows; ++i)
		(*matrix)[i] = copy[i];
}

void deleteColumn(int*** matrix, size_t rows, size_t columns, size_t index)
{
	int** copy = new int* [rows];
	for (int i = 0; i < rows; ++i)
		copy[i] = new int[columns - 1];

	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < index; ++j)
			copy[i][j] = (*matrix)[i][j];

	for (int i = 0; i < rows; ++i)
		for (int j = index; j < columns - 1; ++j)
			copy[i][j] = (*matrix)[i][j + 1];

	for (int i = 0; i < rows; ++i)
		delete (*matrix)[i];
	delete[](*matrix);

	(*matrix) = copy;
	for (int i = 0; i < rows; ++i)
		(*matrix)[i] = copy[i];
}

int main()
{
	int choose;
	size_t ROWS, COLUMNS, index;
	srand(time(0));

	cout << "\Please enter number of rows in array: ";
	cin >> ROWS;
	cout << "\nPlease enter number of columns in array: ";
	cin >> COLUMNS;

	int** matrix = new int* [ROWS];
	for (int i = 0; i < ROWS; ++i)
		matrix[i] = new int[COLUMNS];

	cout << "\nPlease, enter how do öyou want to fill array?\n1 - Manual input.\n2 - Randomly (from -100 to 100)\nOther - exit\nEnter: ";
	cin >> choose;
	if (choose == 1)
	{
		for (int i = 0; i < ROWS; ++i)
			for (int j = 0; j < COLUMNS; ++j)
			{
				cout << "\nPlease enter [" << i << "][" << j << "] element: ";
				cin >> matrix[i][j];
			}

	}
	else if (choose == 2)
	{
		for (int i = 0; i < ROWS; ++i)
			for (int j = 0; j < COLUMNS; ++j)
				matrix[i][j] = rand() % (100 + 100) - 100;
	}
	else
	{
		for (int i = 0; i < ROWS; ++i)
			delete matrix[i];
		delete[] matrix;

		return 0;
	}
	cout << "\nYour array:";
	printArr(matrix, ROWS, COLUMNS);

	cout << "\nPlease enter the index in which you want to insert your column\n(from 0 to "<< COLUMNS << ")\nEnter:";
	cin >> index;
	if (index > COLUMNS)
	{
		cerr << "\nInvalid insertion index!";
		for (int i = 0; i < ROWS; ++i)
			delete matrix[i];
		delete[] matrix;
		return 0;
	}

	cout << "\nHow do you want to fill column? (1 - Manual input. Other - randomly (from -100 to 100))\nEnter: ";
	cin >> choose;

	insertColumn(&matrix, ROWS, COLUMNS, index, choose);

	cout << "\nYour new array (INSERTED):";
	printArr(matrix, ROWS, COLUMNS + 1);

	cout << "\nPlease enter the index of column which you want to delete\n(from 0 to " << COLUMNS + 1 << ")\nEnter:";
	cin >> index;

	deleteColumn(&matrix, ROWS, COLUMNS + 1, index);
	cout << "\nYour new array (DELETED):";
	printArr(matrix, ROWS, COLUMNS);

	for (int i = 0; i < ROWS; ++i)
		delete matrix[i];
	delete[] matrix;
	return 0;
}