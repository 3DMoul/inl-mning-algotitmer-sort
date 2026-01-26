#pragma once
#include "iostream"
#include "string"
#include "eventmanager.h"

struct List
{
	Event* currentEvent;
	List* next;
};