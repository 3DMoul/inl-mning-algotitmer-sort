#pragma once
#include <iostream>
#include <string>
#include "eventmanager.h"

struct event_List{
	Event* currentEvent;
	event_List* next;
    event_List(Event* E)
    {
        currentEvent = E;
        next = nullptr;
    }
};

namespace list_Functions{
    event_List* createEventList(Event*& E);
    
    int listSize(event_List* head);
    
    event_List* insertAtFront(event_List*& head, Event*& new_Event);
    
}
