#pragma once
#include <iostream>
#include <string>
#include "eventmanager.h"

struct event_List
{
	Event* currentEvent;
	event_List* next;
};

namespace list_Functions
{
    event_List* createEventList(Event* E);
    
    int listSize(event_List* head);
    
}
