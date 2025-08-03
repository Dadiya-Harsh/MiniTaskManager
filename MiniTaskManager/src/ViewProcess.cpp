#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <iostream>
#include "../MiniTaskManager.h"

void ListProcesses() {
    HANDLE hProcessSnap;
    PROCESSENTRY32 pe32;

    // Take a snapshot of all processes in the system
    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcessSnap == INVALID_HANDLE_VALUE) {
        std::cerr << "CreateToolhelp32Snapshot failed.\n";
        return;
    }

    pe32.dwSize = sizeof(PROCESSENTRY32);

    // Get the first process
    if (!Process32First(hProcessSnap, &pe32)) {
        std::cerr << "Process32First failed.\n";
        CloseHandle(hProcessSnap); // clean up
        return;
    }

    std::cout << "PID\tProcess Name\n";
    std::cout << "===========================\n";

    // Walk the snapshot of processes
    do {
#ifdef UNICODE
        std::wcout << pe32.th32ProcessID << "\t" << pe32.szExeFile << std::endl;
#else
        std::cout << pe32.th32ProcessID << "\t" << pe32.szExeFile << std::endl;
#endif
    } while (Process32Next(hProcessSnap, &pe32));

    CloseHandle(hProcessSnap);
}

//int main() {
//    ListProcesses();
//    return 0;
//}