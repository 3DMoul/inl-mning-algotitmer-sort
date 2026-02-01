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
    event_List* List = nullptr; // empty list — do NOT create a dummy node with currentEvent == nullptr
    menu::menuStatus menustatus;
    do{
        menu::printWholeMenu(menu::printMenuOptions, menu_Element::main);
        menu::selectMenuItem(menustatus, List);
    } 
    while (!menustatus.EXIT_Menu);
}

void system_Actions::creat_Event(event_List*& L){
	std::cout << "how many event do you want to make" << std::endl;
	int iterations = 0;
	std::cin >> iterations;
	int currentSize = list_Functions::listSize(L);
	Event* eventPtr;
	Queue* event_Queue = new Queue(iterations);
	bool MultiTemp = false;
	bool MultiButton = false;
	bool MultiMotion = false;
	int currentTempid = 0;
	int currentButtonid = 0;
	int currentMotionid = 0;
	for (int i = 0; i < iterations; i++) {
		auto event = static_cast<EventType>(utilitys::randomValue(1, 4));
		if (event == EventType::TEMP_EVENT && MultiTemp == false){
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
		eventPtr = newEvent.release(); // transfer ownership from uniq_ptr to event ptr
		event_Queue->queue_enqueue(event_Queue, eventPtr);
	}
	
	while (!event_Queue->queue_isEmpty(event_Queue)){
		Event* e = event_Queue->queue_dequeue(event_Queue);
		L = list_Functions::insertAtFront(L, e);
	}
	event_Queue->queue_destroy(event_Queue);

}
void system_Actions::sort_Event(event_List*& L) {
	std::cout << "What sorting process do you want to use" << std::endl;
	menu::printOptions(menu_Element::sortType);
	int sort_choice = utilitys::inputValidation();
	std::cout << "Do you want it to be [A]scending or [D]escending" << std::endl;
	char A_D = ' ';
	std::cin >> A_D;
	A_D = (char)toupper(A_D);
	while (!(char)toupper(A_D) == 'A' && !(char)toupper(A_D) == 'D') {
		std::cout << "Wrong input...\n" <<
			"you have to choose between.\n"
			<< "[A]scending or [D]escending" << std::endl;
		std::cin >> A_D;
	}

	sorting_choice(L, sort_choice, A_D);

}
void system_Actions::sorting_choice(event_List*& L, int sc, char a_d){
	auto sortChoice = static_cast<sort_Manager::SortingChoice>(sc);
	switch (sortChoice) {
	case sort_Manager::SortingChoice::selectionSort:
		sort_Manager::selectionSort(L, a_d);
		break;
	case sort_Manager::SortingChoice::quickSort:
		sort_Manager::quickSort(L, a_d);
		break;
	default:
		std::cout << "You enterd invalid option\n" <<
					"you can only chose " << size(menu_Element::sortType) <<
					"\nTry again" << std::endl;
	}
}
void system_Actions::search_Event(event_List* L) {

}
void system_Actions::printList(event_List* head){
	event_List* current = head;
	while (current != nullptr) {
		if (current->currentEvent) current->currentEvent->printEvent();
		current = current->next;
	}
	std::cout << std::endl;
}
