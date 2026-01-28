#include "system.h"

std::unique_ptr<Event> makeEvent(EventType type, int timeStamp)
{
	switch (type)
	{
	case EventType::TEMP_EVENT: 
		double temp = utilitys::randomDecimalValue(0, 60);
		return std::make_unique<event_Type::TemperatureReading>(timeStamp, temp);
	case EventType::BUTTON_EVENT:
		double temp = utilitys::randomValue(1, 10);
		return std::make_unique<event_Type::ButtonPress>(timeStamp, temp);
	case EventType::MOTION_EVENT : 
		double temp = utilitys::randomValue(20, 60);
		return std::make_unique<event_Type::MotionRecord>(timeStamp, temp);

	default: return nullptr;
	}
}
void system_Manager::run()
{
	event_List List;
	menu::menuStatus menustatus;
	do
	{
		menu::printWholeMenu(menu::printMenuOptions, menu_Element::main);
		menu::selectMenuItem(menustatus, List);
	} 
	while (!menustatus.EXIT_Menu);
}

void system_Actions::creat_Event(event_List& L)
{
	std::cout << "What type of event is happening" << std::endl;
	menu::printEventTypes(menu_Element::Eventtype);
	std::cout << "Enter: " << std::endl;
	auto event = static_cast<EventType>(utilitys::inputValidation());
	std::cout << "how many event do you want to make" << std::endl;
	int iterations = 0;
	std::cin >> iterations;

	for (int i = 0; i < iterations;	i++)
	{
		int timeStamp = utilitys::TimeGenerator();
		auto newEvent = makeEvent(event, timeStamp);
		newEvent->printEvent();
		L
	}


}
