// skribbl io bot.cpp : Defines the entry point for the console application.
//

// skribblio bot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include <stdlib.h>

using namespace std;


int main(int argc, char* argv[])
{
	if (argv[1] == NULL)
	{
		cout << "please provide file name" << endl;
		system("PAUSE");
		return 0;
	}
	ifstream file(argv[1]); // pass file name as argument
	string linebuffer;

	int wordleng = 0;
	cout << "wordlength plz" << endl;
	cin >> wordleng;
	int notimeout = 0;
	//HWND chromehandle = FindWindowEx(NULL, NULL, NULL, TEXT("skribbl.io - Google Chrome"));
	//SetActiveWindow(chromehandle);
	Sleep(2000);
	while (file && getline(file, linebuffer)) {
		if (linebuffer.length() == 0)continue;
		int leng = linebuffer.length();
		int i = 0;
		// do something
		if (linebuffer.length() == wordleng)
		{
			char* charray = new char[linebuffer.length() + 1];
			strcpy(charray, linebuffer.c_str());


			for (int i = 0; i <= leng; i++)
			{
				HKL n = GetKeyboardLayout(0);
				BYTE letter = VkKeyScanEx(charray[i], n);
				keybd_event(letter, 0x45, NULL, NULL);
				keybd_event(letter, 0x45, KEYEVENTF_KEYUP | NULL, NULL);
			}
			keybd_event(VK_RETURN, 0x45, NULL, NULL);
			keybd_event(VK_RETURN, 0x45, KEYEVENTF_KEYUP | NULL, NULL);

			notimeout++;
			int notime = notimeout % 4;
			if (notime == NULL)
			{
				Sleep(3500);
			}
		}


	}
	system("PAUSE");
	return 0;
}