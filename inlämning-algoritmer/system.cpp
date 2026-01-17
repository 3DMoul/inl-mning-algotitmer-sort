#include "system.h"

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