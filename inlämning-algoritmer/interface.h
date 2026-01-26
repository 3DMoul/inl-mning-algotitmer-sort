#pragma once
#include "iostream"
#include "string"
#include "vector"
#include <functional>

namespace menuElement
{
	const std::vector<std::string> main = { "Event", "List" , "Sort",
											"Search","Help", "EXIT" };
	const std::vector<std::string> Eventtype = { "TEMPERATURE", "BUTTON", "MOTION" };
}

namespace menu
{
	// uses enum choose menu items
	enum class menuChoice{ EXIT = 0, Event, List, Sort, Search, Help };
	void printWholeMenu(std::function<void(const std::vector<std::string>&)> menuPrintFunc, const std::vector<std::string>& menu);
	void printMenuOptions(const std::vector<std::string>&);
	// take menuStatus by reference so changes propagate to caller
	// took help from copilot for this one
	void selectMenuItem(struct menuStatus& exit);
	void clear_interface();
	struct menuStatus
	{
		bool EXIT_Menu = false;

		void exitStatus();
	};
}