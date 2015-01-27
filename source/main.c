#include <3ds.h>
#include <stdlib.h>
#include <string.h>
#include <3ds/types.h>
#include <3ds/svc.h>
#include <3ds/srv.h>
#include <3ds/services/apt.h>
#include <3ds/services/gsp.h>

NS_APPID currentAppId;

int main()
{
	// Initialize services
	srvInit();
	aptInit();
	hidInit(NULL);
	gfxInitDefault();
	
	
	// NS_APPID 
	NS_APPID aptGetMenuAppID()
	
	{
		NS_APPID menu_appid;
		aptOpenSession();
		APT_GetAppletManInfo(NULL, 0xff, NULL, NULL, &menu_appid, NULL);
		aptCloseSession();
		
		return menu_appid;
	}
	
	//Main loop
	while (aptMainLoop())
		
	{
		aptOpenSession();
		APT_ReplySleepQuery(NULL, currentAppId, 0x0);
		aptCloseSession();	
		
		aptSetStatusPower(1);
		aptSetStatus(APP_SUSPENDING);
	}
	
	// Exit services
	gfxExit();
	hidExit();
	aptExit();
	srvExit();
	return 0;
}
