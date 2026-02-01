#pragma once
#include <iostream>
#include <string>
#include "utility.h"
enum class EventType { TEMP_EVENT = 1, BUTTON_EVENT = 2, MOTION_EVENT = 3 };

class Event{
public:
    Event();
    Event(EventType type, std::string eventAdjectiv, std::string timeStamp, int Id, double value_);
    virtual ~Event() = default;
    void printEvent();
    std::string get_TimeStamp_();
    int get_EventId_();
    std::string get_EventAdjectiv();
    double get_Value_();
    EventType get_Type_();
private:
    std::string timestamp_;
    int eventId_;
    std::string eventadjectiv;
    double value_;
    EventType type_;
};

namespace event_Type{
    class TemperatureReading : public Event{
    public:
        TemperatureReading(std::string timeStamp, int Id, double newValue_);
    };
    class ButtonPress : public Event{
    public:
        ButtonPress(std::string timeStamp, int Id, double newValue_);
    };
    class MotionRecord : public Event{
    public:
        MotionRecord(std::string timeStamp, int Id, double newValue_);
    };
}