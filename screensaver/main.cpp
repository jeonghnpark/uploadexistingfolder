#define WINVER 0x0500
#include <iostream>
#include <Windows.h>

int main()
{
	DWORD sleeptime = 300000;
	INPUT ip;
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0;
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;
	ip.ki.wVk = 0x87;
	std::cout << "prevent screen saver. Ctrl+C for stop\n";
	while (true)
	{
		ip.ki.dwFlags = 0;
		SendInput(1, &ip, sizeof(INPUT));
		ip.ki.dwFlags = KEYEVENTF_KEYUP;

		SendInput(1, &ip, sizeof(INPUT));
		Sleep(sleeptime);
	}
	return 0;
	//std::cout << "hello";
	//return 0;
}
