#include "interface.h"



void menu::printWholeMenu(std::function<void(const std::vector<std::string>&)> menuPrintFunc, const std::vector<std::string>& menu){
	std::cout << "-------------Main Menu-------------" << std::endl;
	menuPrintFunc(menu);
	std::cout << "-----------------------------------" << std::endl;
}
void menu::printMenuOptions(const std::vector<std::string>& menuItems){
	int startFrom = 1;
	for (auto& item : menuItems){
		if (startFrom < size(menuItems))
			std::cout << "[" << startFrom++ << "]" << " " << item << std::endl;
		else
			std::cout << "[" << 0 << "]" << " " << item << std::endl;
	}

}
void menu::printOptions(const std::vector<std::string>& eventItems){
	int startFrom = 1;

	for (auto& item : eventItems){
			std::cout << "[" << startFrom++ << "]" << " " << item << std::endl;
	}
}
// take menuStatus by reference so exitStatus() affects the original
void menu::selectMenuItem(menuStatus& exit, event_List*& List){
	std::cout << list_Functions::listSize(List) << std::endl;
	auto choice = static_cast<menu::menuChoice>(utilitys::inputValidation());

	menu::clear_interface();
	switch (choice){
	case menu::menuChoice::Event:
		system_Actions::creat_Event(List);
		break;
	case menu::menuChoice::Sort:
		system_Actions::sort_Event(List);
		break;
	case menu::menuChoice::Search:
		system_Actions::search_Event(List);
		break;
	case menu::menuChoice::List:
		system_Actions::printList(List);
		break;
	case menu::menuChoice::Help:
		system_Actions::help_func();
		break;
	case menu::menuChoice::EXIT:
		exit.exitStatus();
		break;
	default:
		break;
	}
}
// clears text from before this was used
void menu::clear_interface() { std::cout << "\033c"; }
// makes exit status true making the program end
void menu::menuStatus::exitStatus(){ EXIT_Menu = true; }
void interFace::help_func() {
	std::cout << " Event [1]: " << std::endl;
	std::cout << " Lets you chosse how many event you want to make. And then creats one out of three types of events\n " <<
		"(TEMP, BUTTON, MOTION)\n" <<
		"and puts it in a linked list." << std::endl;
	std::cout << " Sort [2]" << std::endl;
	std::cout << " Lets you sort you  list with help of either\n " <<
		"SelectSort for smaller dataset sizes(->o<-)\n with timecomplexity of O(n2)" <<
		"OR QuickSort for bigger dataset sizes(<-O->) with timecomplexity of O(n*logn)\n" <<
		"where you can sort by (eventtype, id, or timestamp) in ascending or descending order." << std::endl;
	std::cout << " Search [3]:" << std::endl;
	std::cout << " Lets you search for events with id or event type." << std::endl;
	std::cout << " List [4]:" << std::endl;
	std::cout << " Lists all events from the linked list." << std::endl;
	std::cout << " EXIT [0]:" << std::endl;
	std::cout << " Exits the program." << std::endl;
}