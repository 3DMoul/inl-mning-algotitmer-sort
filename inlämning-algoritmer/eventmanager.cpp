#include "eventmanager.h"

Event::Event(EventType type, std::string eventadjectiv, std::string timeStamp, int Id, double MinSimulation, double MaxSimulation)
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


event_Type::TemperatureReading::TemperatureReading(std::string timeStamp, int Id, double MinSimulation, double MaxSimulation)
	: Event(EventType::TEMP_EVENT, "C", timeStamp, Id, MinSimulation, MaxSimulation) {
};


event_Type::ButtonPress::ButtonPress(std::string timeStamp, int Id, double MinSimulation, double MaxSimulation)
	: Event(EventType::BUTTON_EVENT, "Time pressed", timeStamp, Id, MinSimulation, MaxSimulation) {
};

event_Type::MotionRecord::MotionRecord(std::string timeStamp, int Id, double MinSimulation, double MaxSimulation)
	: Event(EventType::MOTION_EVENT, "Activity class", timeStamp, Id, MinSimulation, MaxSimulation) {
};