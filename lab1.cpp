#include "stdafx.h"
#include <utility> // для std::swap. В C++11 используйте заголовок <utility>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	int* array;
	int length;
	cin >> length;
	array = new int[length];
	for (int i = 0; i < length; i++) {
		cin >> array[i];
	}

	// Перебираем каждый элемент массива
	// (кроме последнего, он уже будет отсортирован к тому времени, когда мы до него доберемся)
	for (int startIndex = 0; startIndex < length - 1; ++startIndex)
	{
		// В переменной smallestIndex хранится индекс наименьшего значения, которое мы нашли в этой итерации
		// Начинаем с того, что наименьший элемент в этой итерации - это первый элемент (индекс 0)
		int smallestIndex = startIndex;

		// Затем ищем элемент поменьше в остальной части массива
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			// Если мы нашли элемент, который меньше нашего наименьшего элемента
			if (array[currentIndex] < array[smallestIndex])
				// запоминаем его
				smallestIndex = currentIndex;
		}

		// smallestIndex теперь наименьший элемент 
		// меняем местами наше начальное наименьшее число с тем, которое мы обнаружили
		swap(array[startIndex], array[smallestIndex]);
	}
	delete[] array;

	for (int index = 0; index < length; ++index)
		cout << array[index] << ' ';

	return 0;
}
