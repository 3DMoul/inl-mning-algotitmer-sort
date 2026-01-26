#include "eventmanager.h"

Event::Event(EventType type, std::string eventadjectiv, int timeStamp, int Id, double MinSimulation, double MaxSimulation)
    : type_(type), eventId_(Id), eventadjectiv(eventadjectiv), MinSimulation(MinSimulation), MaxSimulation(MaxSimulation) {
    // Constructor body (if needed)
}
double Event::getValue() const
{
	return 0.0;
}


event_Type::TemperatureReading::TemperatureReading(int timeStamp, int Id)
	: Event(EventType::TEMP_EVENT, "C", timeStamp, Id, 0, 60) {
};


event_Type::ButtonPress::ButtonPress(int timeStamp, int Id)
	: Event(EventType::BUTTON_EVENT, "Time pressed", timeStamp, Id, 1, 10) {
};

event_Type::MotionRecord::MotionRecord(int timeStamp, int Id)
	: Event(EventType::MOTION_EVENT, "Frames", timeStamp, Id, 20, 60) {
};