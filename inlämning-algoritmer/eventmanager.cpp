#include "eventmanager.h"

Event::Event(EventType type, std::string eventadjectiv, int timeStamp, int Id, double newValue_)
    : type_(type), eventId_(Id), eventadjectiv(eventadjectiv), value_(newValue_) {
    // Constructor body (if needed)
}
void Event::printEvent(){
	std::cout << "# " << eventId_ << std::endl;
	std::cout << "timestamp" << timestamp_ << std::endl;
	std::cout << value_ << " " << eventadjectiv << std::endl;
}

event_Type::TemperatureReading::TemperatureReading(int timeStamp, int Id, double newValue_)
	: Event(EventType::TEMP_EVENT, "C", timeStamp, Id, newValue_) {
}
event_Type::ButtonPress::ButtonPress(int timeStamp, int Id, double newValue_)
	: Event(EventType::BUTTON_EVENT, "Time pressed", timeStamp, Id, newValue_) {
};

event_Type::MotionRecord::MotionRecord(int timeStamp, int Id, double newValue_)
	: Event(EventType::MOTION_EVENT, "Frames", timeStamp, Id, newValue_) {
};