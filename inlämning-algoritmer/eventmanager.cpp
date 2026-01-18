#include "eventmanager.h"

Event::Event(EventType type, std::string eventadjectiv, int Id, double MinSimulation, double MaxSimulation)
    : type_(type), eventId_(Id), eventadjectiv(eventadjectiv), MinSimulation(MinSimulation), MaxSimulation(MaxSimulation) {
    // Constructor body (if needed)
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

std::string Event::GetUnitOfeventadjectiv() const
{
	return std::string();
}

EventType Event::type() const
{
	return EventType();
}



eventType::TemperatureReading::TemperatureReading(int Id, double MinSimulation, double MaxSimulation)
	: Event(EventType::TemperatureReading, "C", Id, MinSimulation, MaxSimulation) {
};

double eventType::TemperatureReading::Read() const
{
	return 0.0;
}

eventType::ButtonPress::ButtonPress(int Id, double MinSimulation, double MaxSimulation)
	: Event(EventType::ButtonPress, "Time pressed", Id, MinSimulation, MaxSimulation) {
}
double eventType::ButtonPress::Read() const
{
	return 0.0;
}
;

eventType::MotionRecord::MotionRecord(int Id, double MinSimulation, double MaxSimulation)
	: Event(EventType::MotionRecord, "Activity class", Id, MinSimulation, MaxSimulation) {
}
double eventType::MotionRecord::Read() const
{
	return 0.0;
}
;