#include "sortmanager.h"

void sort_Manager::selectionSort(int array[]) {
	for (int i = 0; i < sizeof(array); i++) {
		int min = i;
		for (int j = i + 1; j < sizeof(array) + 1; j++) {
			if (array[min] > array[j]) {
				min = j;
			}
		}
		int temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
}
void sort_Manager::quickSort(int array[], int start, int end) {
	if (end <= start) { return; }
	int pivot = partition(array, start, end);
	quickSort(array, start, pivot - 1);
	quickSort(array, pivot + 1, end);
}
int sort_Manager::partition(int array[], int start, int end) {
	int pivot = array[end];
	int i = start - 1;
	for (int j = start; j <= end - 1; j++) {
		if (array[j] < pivot) {
			i++;
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	i++;
	int temp = array[i];
	array[i] = array[end];
	array[end] = temp;
	return i;
}