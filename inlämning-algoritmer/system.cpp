#include "system.h"
std::unique_ptr<Event> makeEvent(EventType type, int timeStamp)
{
	switch (type)
	{
	case EventType::TEMP_EVENT: return std::make_unique<event_Type::TemperatureReading>(timeStamp, 0.0, 60.0);
	case EventType::BUTTON_EVENT: return std::make_unique<event_Type::ButtonPress>(timeStamp, 0, 5);
	case EventType::MOTION_EVENT : return std::make_unique<event_Type::MotionRecord>(timeStamp, 20, 60);

	default: return nullptr;
	}
}
void system_Manager::run()
{
	menu::menuStatus menustatus;
	do
	{
		menu::printWholeMenu(menu::printMenuOptions, menu_Element::main);
		menu::selectMenuItem(menustatus);
	} 
	while (!menustatus.EXIT_Menu);
}

void system_Actions::creat_Event()
{
	std::cout << "What type of event is happening" << std::endl;
	menu::printEventTypes(menu_Element::Eventtype);
	std::cout << "Enter: " << std::endl;
	auto event = static_cast<EventType>(utilitys::inputValidation());
	int timeStamp = utilitys::TimeGenerator();
	auto newEvent = makeEvent(event, timeStamp);
	
}
