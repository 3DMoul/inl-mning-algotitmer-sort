#pragma once
#include <iostream>
#include "eventmanager.h"
#include "eventlist.h"


namespace sort_Manager{
	enum class SortingChoice { selectionSort = 1, quickSort = 2 };
	void selectionSort(event_List*& List);
	event_List* getTail(event_List* head);
	event_List* partition(event_List* head, event_List* tail);
	void quickSortHelper(event_List* head, event_List* tail);
	event_List* quickSort(event_List* head);
}