
#include "stdafx.h"
#include "SortDll.h"
#include <iostream>
#include <conio.h>
#include <ctime>

using std::cout;
using std::cin;

void FillingArray(int* array, int size)
{
	cout << "\nВыберите данные: \n";
	cout << "1 - Упорядоченные по возрастанию\n";
	cout << "2 - Упорядоченные по убыванию\n";
	cout << "3 - Случайная последовательность\n";

	int number = 0;
	cin >> number;

	switch (number)
	{
	case 1:
		for (int i = 0; i < size; i++)
		{
			array[i] = i;
		}
		break;

	case 2:
		for (int i = 0; i < size; i++)
		{
			array[i] = size - i;
		}
		break;

	case 3:
		for (int i = 0; i < size; i++)
		{
			array[i] = rand();
		}
		break;

	default:
		break;
	}

	//for (int i = 0; i < size; i++)
	//{
	//	cout << array[i] << " ";
	//}
}

int main()
{
	setlocale(LC_ALL, "rus");

	int *arr = NULL;
	int number = 0;

	int size = 32768;

	unsigned int searchTimeSort = 0;
	unsigned int startTime = 0;
	unsigned int endTime = 0;

	arr = new int[size];

	FillingArray(arr, size);

	cout << "\nВыберите метод сортировки: \n";
	cout << "1 - Сортировка пузырьком\n";
	cout << "2 - Быстрая сортировка\n";

	cin >> number;

	switch (number)
	{
	case 1:
		startTime = clock();
		BubbleSort(arr, size);
		endTime = clock();
		searchTimeSort = endTime - startTime;
		break;

	case 2:
		startTime = clock();
		QuickSort(arr, size, 0, size - 1);
		endTime = clock();
		searchTimeSort = endTime - startTime;
		break;

	default:
		break;
	}
	
	cout << "\n";
	//for (int i = 0; i < size; i++)
	//{
	//	cout << arr[i] << " ";
	//}

	cout << "\nTime of Bubble Sorting " << searchTimeSort / 1000.0;

	delete arr;
	_getch();
	return 0;
}