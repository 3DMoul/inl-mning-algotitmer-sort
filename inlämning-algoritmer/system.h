#pragma once
#include "interface.h"
#include "utility.h"
#include "eventmanager.h"
#include "eventlist.h"
#include "sortmanager.h"
#include "queue.h"

namespace system_Manager{
	void run();
}

namespace system_Actions{
	void creat_Event(event_List*& L);
	void printList(event_List* head);
	void sort_Event(event_List*& L);
	void sorting_choice(int choice, event_List*& L);
	void search_Event(event_List* L);
	void help_func();
}
