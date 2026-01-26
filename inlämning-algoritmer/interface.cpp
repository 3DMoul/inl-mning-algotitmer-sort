#include "interface.h"
#include "utility.h"



void menu::printWholeMenu(std::function<void(const std::vector<std::string>&)> menuPrintFunc, const std::vector<std::string>& menu)
{
	menu::clear_interface();
	std::cout << "-------------Main Menu-------------" << std::endl;
	menuPrintFunc(menu);
	std::cout << "-----------------------------------" << std::endl;

}
void menu::printMenuOptions(const std::vector<std::string>& menuItems)
{
	int startFrom = 1;
	if (size(menuItems) >= 4)
	{
		for (auto& item : menuItems)
		{
			if (startFrom < size(menuItems))
				std::cout << "[" << startFrom++ << "]" << " " << item << std::endl;
			else
				std::cout << "[" << 0 << "]" << " " << item << std::endl;
		}
	}
	else
	{
		for (auto& item : menuItems)
		{
				std::cout << "[" << startFrom++ << "]" << " " << item << std::endl;
		}
	}

}
// take menuStatus by reference so exitStatus() affects the original
void menu::selectMenuItem(menuStatus& exit)
{
	auto choice = static_cast<menu::menuChoice>(utilitys::inputValidation());
	switch (choice)
	{
	case menu::menuChoice::Event:

		break;
	case menu::menuChoice::Sort:

		break;
	case menu::menuChoice::Search:

		break;
	case menu::menuChoice::List:

		break;
	case menu::menuChoice::Help:

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
