#pragma once
#include "iostream"
#include "string"

enum class EventType { TemperatureReading = 1, ButtonPress = 2, MotionRecord = 3 };

class Event
{
public:
    Event(EventType type, std::string eventadjectiv, int Id, double MinSimulation, double MaxSimulation);
    virtual ~Event() = default;
    virtual double Read() const;
    std::string name() const;
    double minValue() const;
    double maxValue() const;
    std::string Geteventadjectiv() const;
    EventType type() const;
private:
    int timestamp_;
    int eventId_;
    double MinSimulation, MaxSimulation;
    std::string eventadjectiv;
    int value_;
    EventType type_;
};

namespace eventType
{
    class TemperatureReading : public Event
    {
    public:
        TemperatureReading(int Id, double MinSimulation, double MaxSimulation);
        double Read() const override;
    };
    class ButtonPress : public Event
    {
    public:
        ButtonPress(int Id, double MinSimulation, double MaxSimulation);
        double Read() const override;
    };
    class MotionRecord : public Event
    {
    public:
        MotionRecord(int Id, double MinSimulation, double MaxSimulation);
        double Read() const override;
    };
}