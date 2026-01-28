#pragma once
#include <iostream>

namespace sort_Manager{
	void selectionSort(int array[]);
	void quickSort(int array[], int start, int end);
	int partition(int array[], int start, int end);
}