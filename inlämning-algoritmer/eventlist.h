#pragma once
#include "iostream"
#include "string"
#include "eventmanager.h"

struct event_List
{
	Event* currentEvent;
	event_List* next;
};

