#include "interface.h"
#include "utility.h"



void menu::printWholeMenu(std::function<void(const std::vector<std::string>&)> menuPrintFunc, const std::vector<std::string>& menu)
{
	menu::clear_interface();
	std::cout << "-------------Main Menu-------------" << std::endl;
	menuPrintFunc(menu);
	std::cout << "-----------------------------------" << std::endl;

}

// Ensure this implementation is in the menu namespace
void menu::printMenuOptions(const std::vector<std::string>& menuItems)
{
	int startFrom = 1; // match switch cases (1..N)
	for (auto& item : menuItems)
	{
		std::cout << "[" << startFrom++ << "]" << item << std::endl;
	}
}

// take menuStatus by reference so exitStatus() affects the original
void menu::selectMenuItem(menuStatus& exit)
{
	int choice = 0;
	choice = utilitys::inputValidation();
	switch (choice)
	{
	case 1:

		break;
	case 2:

		break;
	case 3:

		break;
	case 4:

		break;
	case 5:

		break;
	case 6:
		exit.exitStatus();
		break;
	default:
		break;
	}
}

void menu::clear_interface() { std::cout << "\033c"; }

void menu::menuStatus::exitStatus()
{
	EXIT_Menu = true;
}
