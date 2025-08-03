// MiniTaskManager.cpp : Defines the entry point for the application.
//

#include "MiniTaskManager.h"

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;

	printf("Welcome to the Mini Task Manager application!\n");

	cout << "Listing all running processes:\n";
	ListProcesses();
	return 0;
}
