#pragma once
#include <iostream>


namespace sort_Manager{
	enum class SortingChoice { selectionSort = 1, quickSort = 2 };
	void selectionSort(int array[]);
	void quickSort(int array[], int start, int end);
	int partition(int array[], int start, int end);
}