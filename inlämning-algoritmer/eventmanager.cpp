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

std::string Event::Geteventadjectiv() const
{
	return std::string();
}

EventType Event::type() const
{
	return EventType();
}


eventType::TemperatureReading::TemperatureReading(int Id, double MinSimulation, double MaxSimulation)
	: Event(EventType::TEMP_EVENT, "C", Id, MinSimulation, MaxSimulation) {
};


eventType::ButtonPress::ButtonPress(int Id, double MinSimulation, double MaxSimulation)
	: Event(EventType::BUTTON_EVENT, "Time pressed", Id, MinSimulation, MaxSimulation) {
};

eventType::MotionRecord::MotionRecord(int Id, double MinSimulation, double MaxSimulation)
	: Event(EventType::MOTION_EVENT, "Activity class", Id, MinSimulation, MaxSimulation) {
};