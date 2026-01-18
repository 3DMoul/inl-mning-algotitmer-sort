#include "eventmanager.h"

Event::Event(EventType type, std::string UnitOfMeasurment, std::string SensorName, double MinSimulation, double MaxSimulation)
{
}

double Event::Read() const
{
	return 0.0;
}

double Event::minValue() const
{
	return 0.0;
}

double Event::maxValue() const
{
	return 0.0;
}

std::string Event::GetUnitOfMeasurement() const
{
	return std::string();
}

EventType Event::type() const
{
	return EventType();
}



eventType::TemperatureReading::TemperatureReading(std::string NewName, double MinSimulation, double MaxSimulation)
	: Event(EventType::TemperatureReading, "C", NewName, MinSimulation, MaxSimulation) {
};

double eventType::TemperatureReading::Read() const
{
	return 0.0;
}

eventType::ButtonPress::ButtonPress(std::string NewName, double MinSimulation, double MaxSimulation)
	: Event(EventType::ButtonPress, "Time pressed", NewName, MinSimulation, MaxSimulation) {
}
double eventType::ButtonPress::Read() const
{
	return 0.0;
}
;

eventType::MotionRecord::MotionRecord(std::string NewName, double MinSimulation, double MaxSimulation)
	: Event(EventType::MotionRecord, "Activity class", NewName, MinSimulation, MaxSimulation) {
}
double eventType::MotionRecord::Read() const
{
	return 0.0;
}
;