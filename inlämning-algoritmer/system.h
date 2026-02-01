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
	void createEvent(event_List*& L);
	void printList(event_List* head);
	void sortEvent(event_List*& L);
	void searchChoice(event_List* L);
	void searchEvent(event_List* L, int id);
}
