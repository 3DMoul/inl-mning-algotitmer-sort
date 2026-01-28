#include "system.h"

static std::unique_ptr<Event> makeEvent(EventType type, event_List* L, int timeStamp){
	double temp = 0.0;
	int id = list_Functions::listSize(L);
	std::cout << id << std::endl;
	switch (type){
	case EventType::TEMP_EVENT: 
		temp = utilitys::randomDecimalValue(0, 60);
		return std::make_unique<event_Type::TemperatureReading>(timeStamp, id + 1, temp);
	case EventType::BUTTON_EVENT:
		temp = utilitys::randomValue(1, 10);
		return std::make_unique<event_Type::ButtonPress>(timeStamp, id + 1, temp);
	case EventType::MOTION_EVENT : 
		temp = utilitys::randomValue(20, 60);
		return std::make_unique<event_Type::MotionRecord>(timeStamp, id + 1, temp);

	default: return nullptr;
	}
}
void system_Manager::run(){
	event_List* List = new event_List(nullptr);
	menu::menuStatus menustatus;
	do{
		menu::printWholeMenu(menu::printMenuOptions, menu_Element::main);
		menu::selectMenuItem(menustatus, List);
	} 
	while (!menustatus.EXIT_Menu);
}

void system_Actions::creat_Event(event_List* L){
	std::cout << "What type of event is happening" << std::endl;
	menu::printEventTypes(menu_Element::Eventtype);
	std::cout << "Enter: " << std::endl;
	auto event = static_cast<EventType>(utilitys::inputValidation());
	std::cout << "how many event do you want to make" << std::endl;
	int iterations = 0;
	std::cin >> iterations;

	for (int i = 0; i < iterations;	i++){
		int timeStamp = utilitys::TimeGenerator();
		auto newEvent = makeEvent(event, L , timeStamp);
		newEvent->printEvent();
		L = list_Functions::insertAtFront(L, newEvent.get());
		//list_Functions::createEventList(newEvent.get());
	}


}
void system_Actions::printList(event_List* head){
	event_List* current = head;
	while (current->currentEvent != nullptr) {
		current->currentEvent->printEvent();
		current = current->next;
	}
	std::cout << std::endl;
}
