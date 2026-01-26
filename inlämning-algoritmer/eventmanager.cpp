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


event_Type::TemperatureReading::TemperatureReading(std::string timeStamp, int Id)
	: Event(EventType::TEMP_EVENT, "C", timeStamp, Id, 0, 60) {
};


event_Type::ButtonPress::ButtonPress(std::string timeStamp, int Id)
	: Event(EventType::BUTTON_EVENT, "Time pressed", timeStamp, Id, 1, 10) {
};

event_Type::MotionRecord::MotionRecord(std::string timeStamp, int Id)
	: Event(EventType::MOTION_EVENT, "Frames", timeStamp, Id, 20, 60) {
};