#include "system.h"

static std::unique_ptr<Event> makeEvent(EventType type, int listSize, std::string timeStamp){
	double temp = 0.0;
	int id = listSize;
	switch (type){
	case EventType::TEMP_EVENT: 
		temp = utilitys::randomDecimalValue(0, 60);
		return std::make_unique<event_Type::TemperatureReading>(timeStamp, id, temp);
	case EventType::BUTTON_EVENT:
		temp = utilitys::randomValue(1, 10);
		return std::make_unique<event_Type::ButtonPress>(timeStamp, id, temp);
	case EventType::MOTION_EVENT : 
		temp = utilitys::randomValue(20, 60);
		return std::make_unique<event_Type::MotionRecord>(timeStamp, id, temp);

	default: return nullptr;
	}
}
void system_Manager::run(){
    event_List* List = nullptr; // empty list
    menu::menuStatus menustatus; // exit status declared
    do{
        menu::printWholeMenu(menu::printMenuOptions, menu_Element::main);// print menu
        menu::selectMenuItem(menustatus, List);
    } 
    while (!menustatus.EXIT_Menu);
}

void system_Actions::createEvent(event_List*& L){
	std::cout << "how many event do you want to make" << std::endl;
	int iterations = 0;
	std::cin >> iterations;
	int currentSize = list_Functions::listSize(L);
	Event* eventPtr;
	Queue* event_Queue = new Queue(iterations);
	// i use these bools to check if an id has been used so i can use the same id
	// for a different events so it looks like it comes from the same sensor
	bool MultiTemp = false;
	bool MultiButton = false;
	bool MultiMotion = false;
	int currentTempid = 0;
	int currentButtonid = 0;
	int currentMotionid = 0;
	for (int i = 0; i < iterations; i++) {
		auto event = static_cast<EventType>(utilitys::randomValue(1, 4));
		if (event == EventType::TEMP_EVENT && MultiTemp == false){ // here it checks and when its true for one it locks that id
			MultiTemp = true;
			currentTempid = currentSize + 1;
			currentSize++;
		}
		else if (event == EventType::BUTTON_EVENT && MultiButton == false){
			MultiButton = true;
			currentButtonid = currentSize + 1;
			currentSize++;
		}
		else if (event == EventType::MOTION_EVENT && MultiMotion == false){
			MultiMotion = true;
			currentMotionid = currentSize + 1;
			currentSize++;
		}
		std::string timeStamp = utilitys::TimeGenerator();
		std::unique_ptr<Event> newEvent;
		if (event == EventType::TEMP_EVENT && MultiTemp == true) {
			newEvent = makeEvent(event, currentTempid, timeStamp);
		}
		else if (event == EventType::BUTTON_EVENT && MultiButton == true) {
			newEvent = makeEvent(event, currentButtonid, timeStamp);
		}
		else if (event == EventType::MOTION_EVENT && MultiMotion == true) {
			newEvent = makeEvent(event, currentMotionid, timeStamp);
		}
		
		newEvent->printEvent();
		eventPtr = newEvent.release(); // transfer ownership from uniq_ptr to normal ptr
		event_Queue->enqueue(eventPtr); // puts in queue
	}
	
	while (!event_Queue->isEmpty()){
		Event* e = event_Queue->dequeue(); // puts in linked list
		L = list_Functions::insertAtFront(L, e);
	}
	event_Queue->destroy(); // deletes queue

}
void system_Actions::sortEvent(event_List*& L) {
	std::cout << "What sorting process do you want to use" << std::endl;
	menu::printOptions(menu_Element::sortType);
	int sortChoice = utilitys::inputValidation(); // here is for choice of selections or quicksort
	std::cout << "Do you want it to be [A]scending or [D]escending" << std::endl;
	char ad = ' ';
	std::cin >> ad; // here is for choice of decencing or ascending sorting
	ad = (char)toupper(ad);
	while (!(char)toupper(ad) == 'A' && !(char)toupper(ad) == 'D') {
		std::cout << "Wrong input...\n" <<
			"you have to choose between.\n"
			<< "[A]scending or [D]escending" << std::endl;
		std::cin >> ad;
	}

	menu::sortingChoice(L, sortChoice, ad);

}
void system_Actions::searchChoice(event_List* L) {
	std::cout << "What what event Id do you want" << std::endl;
	std::cout << "Input:";
	int id = 0;
	id = utilitys::inputValidation();
	searchEvent(L, id);
}
void system_Actions::searchEvent(event_List* L, int id) {
	event_List* current = L;
	while (current != nullptr) { // goes throu list until current is nullptr
		if (current->currentEvent->get_EventId_() == id) {
			current->currentEvent->printEvent();
		}
		current = current->next;
	}
}

void system_Actions::printList(event_List* head){
	event_List* current = head;
	while (current != nullptr) { // goes throu list until current is nullptr
		current->currentEvent->printEvent();
		current = current->next;
	}
	std::cout << std::endl;
}
