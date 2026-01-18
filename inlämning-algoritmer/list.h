#pragma once
#include "iostream"
#include "string"
#include "eventmanager.h"

struct List
{
    int timestamp_;
    int eventId_;
    double MinSimulation, MaxSimulation;
    std::string eventadjectiv;
    int value_;
    EventType type_;
	List* rest;
};