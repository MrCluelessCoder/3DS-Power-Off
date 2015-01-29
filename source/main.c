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
		//Get AppID
		NS_APPID aptGetMenuAppID()
		
		{
		NS_APPID menu_appid;
		aptOpenSession();
		APT_GetAppletManInfo(NULL, 0xff, NULL, NULL, &menu_appid, NULL);
		aptCloseSession();
		return menu_appid;
		}
		
		//HID Input
		hidScanInput();
		input = hidKeysDown();

		//Reboot EmuNand if L is pressed
		if (input & KEY_L) break;
		//Reboot SyNand if R is pressed
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
		}
	}

	// Exit services
	gfxExit();
	hidExit();
	aptExit();
	srvExit();
	return 0;
}
