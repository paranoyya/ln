// Win32Project1.cpp: определяет точку входа для приложения.
//

#include "stdafx.h"
/*
* Ввести целочисленный массив из N целых чисел.
* Отсортировать этот массив по возрастанию методом пузырька
*/
#include <iostream>

using namespace std;

int main()
{
	int *arr; // указатель для выделения памяти под массив
	int size; // размер массива

			  // Ввод количества элементов массива
	cout << "n = ";
	cin >> size;

	if (size <= 0) {
		// Размер масива должен быть положитлеьным
		cerr << "Invalid size" << endl;
		return 1;
	}

	arr = new int[size]; // выделение памяти под массив

						 // заполнение массива
	for (int i = 0; i < size; i++) {
		cout << "arr[" << i << "] = ";
		cin >> arr[i];
	}

	int temp; // временная переменная для обмена элементов местами

			  // Сортировка массива пузырьком
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				// меняем элементы местами
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	// Вывод отсортированного массива на экран
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}