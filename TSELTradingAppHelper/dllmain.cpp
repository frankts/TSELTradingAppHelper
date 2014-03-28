// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#import "C:\\Program Files (x86)\\TradeStation 9.1\\Program\\TSKIT.DLL" no_namespace

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

extern "C" {

int __stdcall  GetNetworkID(IEasyLanguageObject* pELObj) 
{
	ITradeStationPlatform* pTS = NULL;
	int networkID = -1;

	if(pELObj != NULL)
	{
		pELObj->get_Platform(&pTS);

		if(pTS != NULL)
		{
			pTS->get_NetworkID(&networkID);
			pTS->Release();
		}
	}
	
	return networkID;
}

}