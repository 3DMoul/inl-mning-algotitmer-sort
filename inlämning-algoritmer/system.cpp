#include "system.h"
std::unique_ptr<Event> MakeEvent(EventType type, const std::string& newname)
{
	switch (type)
	{
	case EventType::TEMP_EVENT: return std::make_unique<eventType::TemperatureReading>(newname, 0.0, 60.0);
	case EventType::BUTTON_EVENT: return std::make_unique<eventType::ButtonPress>(newname, 0, 5);
	case EventType::MOTION_EVENT : return std::make_unique<eventType::MotionRecord>(newname, 20, 60);

	default: return nullptr;
	}
}
void systemManager::run()
{
	menu::menuStatus menustatus;
	do
	{
		menu::printWholeMenu(menu::printMenuOptions, menuElement::main);
		menu::selectMenuItem(menustatus);
	} 
	while (!menustatus.EXIT_Menu);
}

void creat_Event()
{
	std::cout << "What type of event is happening" << std::endl;
	menu::printMenuOptions(menuElement::Eventtype);



}
