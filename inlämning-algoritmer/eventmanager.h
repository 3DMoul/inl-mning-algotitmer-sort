#pragma once
#include "iostream"
#include "string"

enum class EventType { TemperatureReading = 1, ButtonPress = 2, MotionRecord = 3 };

class Event
{
public:
    Event(EventType type, std::string UnitOfMeasurement, std::string SensorName, double MinSimulation, double MaxSimulation);
    virtual ~Event() = default;
    virtual double Read() const;
    std::string name() const;
    double minValue() const;
    double maxValue() const;
    std::string GetUnitOfMeasurement() const;
    EventType type() const;
private:
    int timestamp_;
    int sensorId_;
    int value_;
    EventType type_;
};

namespace eventType
{
    class TemperatureReading : public Event
    {
    public:
        TemperatureReading(std::string NewName, double MinSimulation, double MaxSimulation);
        double Read() const override;
    };
    class ButtonPress : public Event
    {
    public:
        ButtonPress(std::string NewName, double MinSimulation, double MaxSimulation);
        double Read() const override;
    };
    class MotionRecord : public Event
    {
    public:
        MotionRecord(std::string NewName, double MinSimulation, double MaxSimulation);
        double Read() const override;
    };
}