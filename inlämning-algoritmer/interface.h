#pragma once
#include "utility.h"
#include "eventlist.h"
#include "system.h"
#include <iostream>
#include <string>
#include <vector>
#include <functional>

namespace menu_Element{
	const std::vector<std::string> main = { "Event", "List" , "Sort",
											"Search","Help", "EXIT" };

	const std::vector<std::string> EventType = { "TEMPERATURE", "BUTTON", "MOTION" };

	const std::vector<std::string> sortType = { "SelectSort", "QuickSort" };
}

namespace menu{
	// uses enum choose menu items
	enum class menuChoice{ EXIT = 0, Event, List, Sort, Search, Help };
	void printWholeMenu(std::function<void(const std::vector<std::string>&)> menuPrintFunc, const std::vector<std::string>& menu);
	void printMenuOptions(const std::vector<std::string>&);
	void printOptions(const std::vector<std::string>& eventItems);
	// take menuStatus by reference so changes propagate to caller
	// took help from copilot for this one
	void selectMenuItem(struct menuStatus& exit, event_List*& List);
	void clear_interface();
	// have this to hold the exit status if the user tries to exit
	struct menuStatus{
		bool EXIT_Menu = false;

		void exitStatus();
	};
}
namespace interFace
{
	void help_func();

}