#include <3ds.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

NS_APPID currentAppId;

int main()
{
	// Initialize services
	srvInit();
	aptInit();
	hidInit(NULL);
	gfxInitDefault();

    u32 input;
	// Main loop
	while (aptMainLoop())
	{
		//HID Input
		hidScanInput();
		input = hidKeysDown();

		//Reboot EmuNand if L is pressed
		if (input & KEY_L) break;
		//Reboot SysNand if R is pressed
		if (input & KEY_R)
			{
			//Reboot Code
			aptOpenSession();
			APT_HardwareResetAsync(NULL);
			aptCloseSession();
			}
		else
		{
			//Power Off Code
			aptOpenSession();
			APT_ReplySleepQuery(NULL, currentAppId, 0x0);
			aptCloseSession();
			
			aptSetStatusPower(1);
			aptSetStatus(APP_SUSPENDING);
		}
	
	}

	// Exit services
	gfxExit();
	hidExit();
	aptExit();
	srvExit();
	return 0;
}
