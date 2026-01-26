#pragma once
#include <iostream>
#include <string>
#include "utility.h"
enum class EventType { TEMP_EVENT = 1, BUTTON_EVENT = 2, MOTION_EVENT = 3 };

class Event
{
public:
    Event(EventType type, std::string eventAdjectiv, int timeStamp, int Id, double MinSimulation, double MaxSimulation);
    virtual ~Event() = default;
    virtual double getValue() const;
private:
    int timestamp_;
    int eventId_;
    double MinSimulation, MaxSimulation;
    std::string eventadjectiv;
    int value_;
    EventType type_;
};

namespace event_Type
{
    class TemperatureReading : public Event
    {
    public:
        TemperatureReading(int timeStamp, int Id);
    };
    class ButtonPress : public Event
    {
    public:
        ButtonPress(int timeStamp, int Id);
    };
    class MotionRecord : public Event
    {
    public:
        MotionRecord(int timeStamp, int Id);
    };
}