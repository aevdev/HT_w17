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

void matrixShift(int** matrix, size_t rows, size_t columns, int x, int y)
{
	int** copy = new int* [rows];
	for (int i = 0; i < rows; ++i)
		copy[i] = new int[columns];

	if (x > 0 && y > 0) // вправо-вверх
	{
		{
			//for (int i = 0; i < y; ++i)
			//{
			//	for (int j = 0; j < columns; ++j)
			//	{
			//		copy[i][j] = matrix[i][j];
			//	}
			//}

			//for (int i = 0; i < rows; ++i)
			//{
			//	for (int j = columns - x; j < columns; ++j)
			//	{
			//		copy[i][j] = matrix[i][j];
			//	}
			//}
		}
		//Не рабочий вариант

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
				copy[i][j] = matrix[i][j];
		}

		for (int i = y; i < rows; ++i)
		{
			for (int j = 0; j < columns - x; ++j)
			{
				matrix[i - y][j + x] = copy[i][j];
			}
		}

		if (columns > rows)
		{
			for (int i = 0; i < rows; ++i)
			{
				for (int j = 0; j < x; ++j)
				{
					matrix[i][j] = copy[j][i];
				}
			}

			for (int i = rows - y; i < rows; ++i)
			{
				for (int j = x; j < columns; ++j)
				{
					matrix[i][j] = copy[j - (columns - rows)][i + (columns - rows)];
				}
			}
		}
		else if (rows > columns)
		{
			for (int i = 0; i < rows - (rows - columns); ++i)
			{
				for (int j = 0; j < x; ++j)
				{
					matrix[i][j] = copy[j][i];
				}
			}

			for (int i = rows - y; i < rows; ++i)
			{
				for (int j = 0; j < columns; ++j)
				{
					matrix[i][j] = copy[j + (rows - columns)][i - (rows - columns)];
				}
			}
		}
		else
		{
			for (int i = 0; i < rows; ++i)
			{
				for (int j = 0; j < x; ++j)
				{
					matrix[i][j] = copy[j][i];
				}
			}

			for (int i = rows - y; i < rows; ++i)
			{
				for (int j = x; j < columns; ++j)
				{
					matrix[i][j] = copy[j][i];
				}
			}
		}

	}
	else if (x < 0 && y < 0) //влево-вниз
	{
		x *= -1;
		y *= -1;
		{
			for (int i = rows - y; i < rows; ++i)
			{
				for (int j = 0; j < columns; ++j)
				{
					copy[i][j] = matrix[i][j];
				}
			}

			for (int i = 0; i < rows; ++i)
			{
				for (int j = 0; j < x; ++j)
				{
					copy[i][j] = matrix[i][j];
				}
			}
		}
		//Не рабочий вариант
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				copy[i][j] = matrix[i][j];
			}
				
		}

		for (int i = 0; i < rows - y; ++i)
		{
			for (int j = x; j < columns; ++j)
			{
				matrix[i + y][j - x] = copy[i][j];
			}
		}

		if (columns > rows)
		{
			for (int i = 0; i < y; ++i)
			{
				for (int j = 0; j < columns - (columns - rows); ++j)
				{
					matrix[i][j] = copy[j][i];
				}
			}

			for (int i = 0; i < rows; ++i)
			{
				for (int j = columns - x; j < columns; ++j)
				{
					matrix[i][j] = copy[j - (columns - rows)][i + (columns - rows)];
				}
			}
		}
		else if (rows > columns)
		{
			for (int i = 0; i < y; ++i)
			{
				for (int j = 0; j < rows - (rows - columns); ++j)
				{
					matrix[i][j] = copy[j][i];
				}
			}

			for (int i = y; i < rows; ++i)
			{
				for (int j = columns - x; j < columns; ++j)
				{
					matrix[i][j] = copy[j + (rows - columns)][i - (rows - columns)];
				}
			}
		}
		else
		{
			for (int i = 0; i < y; ++i)
			{
				for (int j = 0; j < columns; ++j)
				{
					matrix[i][j] = copy[j][i];
				}
			}

			for (int i = y; i < rows; ++i)
			{
				for (int j = columns - x; j < columns; ++j)
				{
					matrix[i][j] = copy[j][i];
				}
			}
		}
	}
	else if (x > 0 && y < 0) //вправо-вниз
	{
		cout << "\nU razrabotchika zabolel mozg i on ne dodelal.\nPrinosim svoi izvinenia. :c";
	}
	else if (x < 0 && y > 0) //влево-вверх
	{
		cout << "\nU razrabotchika zabolel mozg i on ne dodelal.\nPrinosim svoi izvinenia. :c";
	}
	else if (x > 0 && y == 0) //вправо
	{
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				copy[i][j] = matrix[i][j];
			}

		}

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns - x; ++j)
			{
				matrix[i][j + x] = copy[i][j];
			}
		}

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < x; ++j)
			{
				matrix[i][j] = copy[i][j + (columns - x)];
			}
		}
	}
	else if (x == 0 && y > 0) //вверх
	{
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				copy[i][j] = matrix[i][j];
			}

		}

		for (int i = y; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				matrix[i - y][j] = copy[i][j];
			}
		}

		for (int i = rows - y; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				matrix[i][j] = copy[i - (rows - y)][j];
			}
		}
	}
	else if (x < 0 && y == 0) //влево
	{
		x *= -1;

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				copy[i][j] = matrix[i][j];
			}

		}

		for (int i = 0; i < rows; ++i)
		{
			for (int j = x; j < columns; ++j)
			{
				matrix[i][j - x] = copy[i][j];
			}
		}

		for (int i = 0; i < rows; ++i)
		{
			for (int j = columns - x; j < columns; ++j)
			{
				matrix[i][j] = copy[i][j - (columns - x)];
			}
		}
	}
	else if (x == 0 && y < 0) //вниз
	{
		y *= -1;
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				copy[i][j] = matrix[i][j];
			}

		}

		for (int i = 0; i < rows - y; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				matrix[i + y][j] = copy[i][j];
			}
		}

		for (int i = 0; i < y; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				matrix[i][j] = copy[i + (rows - y)][j];
			}
		}
	}
}
int main()
{
	int choose, X, Y;
	size_t ROWS, COLUMNS, index;
	srand(time(0));

	cout << "\Please enter number of rows in array: ";
	cin >> ROWS;
	cout << "\nPlease enter number of columns in array: ";
	cin >> COLUMNS;

	int** matrix = new int* [ROWS];
	for (int i = 0; i < ROWS; ++i)
		matrix[i] = new int[COLUMNS];

	cout << "\nPlease, enter how do цyou want to fill array?\n1 - Manual input.\n2 - Randomly (from -100 to 100)\nOther - exit\nEnter: ";
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

	cout << "\nPlease enter X: ";
	cin >> X;
	cout << "\nPlease enter Y: ";
	cin >> Y;
	matrixShift(matrix, ROWS, COLUMNS, X, Y);

	cout << "\nYour array:";
	printArr(matrix, ROWS, COLUMNS);

	for (int i = 0; i < ROWS; ++i)
		delete matrix[i];
	delete[] matrix;
	return 0;
}