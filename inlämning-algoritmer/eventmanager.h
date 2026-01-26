#pragma once
#include <iostream>
#include <string>
#include "utility.h"
enum class EventType { TEMP_EVENT = 1, BUTTON_EVENT = 2, MOTION_EVENT = 3 };

class Event
{
public:
    Event(EventType type, std::string eventAdjectiv, std::string timeStamp, int Id, double MinSimulation, double MaxSimulation);
    virtual ~Event() = default;
    virtual double Read() const;
    double minValue() const;
    double maxValue() const;
    std::string Geteventadjectiv() const;
    EventType type() const;
private:
    std::string timestamp_;
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
        TemperatureReading(std::string timeStamp, int Id, double MinSimulation, double MaxSimulation);
    };
    class ButtonPress : public Event
    {
    public:
        ButtonPress(std::string timeStamp, int Id, double MinSimulation, double MaxSimulation);
    };
    class MotionRecord : public Event
    {
    public:
        MotionRecord(std::string timeStamp, int Id, double MinSimulation, double MaxSimulation);
    };
}