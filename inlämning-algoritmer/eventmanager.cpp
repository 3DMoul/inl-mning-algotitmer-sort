#include "eventmanager.h"
Event::Event()
    : type_(EventType::TEMP_EVENT),
    timestamp_(0),
    eventId_(0),
    eventadjectiv(""),
    value_(0.0)
{
}

Event::Event(EventType type, std::string eventadjectiv, int timeStamp, int Id, double newValue_)
    : type_(type), eventId_(Id), eventadjectiv(eventadjectiv), value_(newValue_), timestamp_(timeStamp) {
    // Constructor body (if needed)
}
void Event::printEvent(){
    std::cout << "---------------------------------------" << std::endl;
	std::cout << "#" << eventId_ << std::endl;
	std::cout << "Timestamp: " << timestamp_ << std::endl;
	std::cout << value_ << " " << eventadjectiv << std::endl;
    std::cout << "---------------------------------------" << std::endl;

}

int Event::get_TimeStamp_()
{
	return timestamp_;
}

int Event::get_EventId_()
{
	return eventId_;
}

std::string Event::get_EventAdjectiv()
{
	return eventadjectiv;
}

double Event::get_Value_()
{
	return value_;
}

EventType Event::get_Type_()
{
	return type_;
}

event_Type::TemperatureReading::TemperatureReading(int timeStamp, int Id, double newValue_)
    : Event(EventType::TEMP_EVENT, "C", timeStamp, Id, newValue_) {
}

event_Type::ButtonPress::ButtonPress(int timeStamp, int Id, double newValue_)
    : Event(EventType::BUTTON_EVENT, "Time pressed", timeStamp, Id, newValue_) {
}

event_Type::MotionRecord::MotionRecord(int timeStamp, int Id, double newValue_)
    : Event(EventType::MOTION_EVENT, "Frames", timeStamp, Id, newValue_) {
}