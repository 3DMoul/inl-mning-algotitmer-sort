#pragma once
#include "iostream"
#include "string"
#include "eventmanager.h"

struct List
{
    std::string timestamp_;
    int eventId_;
    int value_;
    double MinSimulation, MaxSimulation;
    std::string eventadjectiv;
    EventType type_;
	List* rest;
};