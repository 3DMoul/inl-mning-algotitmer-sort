#pragma once
#include "iostream"
#include "string"
#include "vector"
#include <functional>

namespace menuElement
{
	const std::vector<std::string> main = { " Event ", " List " , " Sort ",
											" Search "," Help ", " EXIT " };
	const std::vector<std::string> Event = {};
}

namespace menu
{
	void printWholeMenu(std::function<void(const std::vector<std::string>&)> menuPrintFunc, const std::vector<std::string>& menu);
	void printMenuOptions(const std::vector<std::string>&);
	// take menuStatus by reference so changes propagate to caller
	void selectMenuItem(struct menuStatus& exit);
	void clear_interface();
	struct menuStatus
	{
		bool EXIT_Menu = false;

		void exitStatus();
	};
}