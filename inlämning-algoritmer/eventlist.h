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
    
    int listSize(event_List* head);
    event_List* insertAtFront(event_List*& head, Event*& new_Event);
    void List_destroy(event_List* List);
    void List_append(event_List* List, Event e);
    Event* List_get(const event_List* List, int id);
    void List_set(event_List* List, int index, Event e);
}
