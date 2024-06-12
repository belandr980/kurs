#include "reklamabase.h"
#include "menu.h"
#include "Windows.h"
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ReklamaBase reklama_base;
	Menu menu;
	menu.Start(menu, reklama_base);
	return 0;
}

