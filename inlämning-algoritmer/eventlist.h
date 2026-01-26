#pragma once
#include "iostream"
#include "string"
#include "eventmanager.h"

struct event_List
{
	Event* currentEvent;
	event_List* next;
};

namespace list_Functions
{
    static event_List* createEventList(Event* E) 
    {
        event_List* newEvent = (event_List*)std::malloc(sizeof(event_List));
        if (!newEvent) 
            return nullptr;
        newEvent->currentEvent = E;
        newEvent->next = nullptr;
        return newEvent;
    }
}
