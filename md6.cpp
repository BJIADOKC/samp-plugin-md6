#pragma once



#include "md6.h"





logprintf_t logprintf;


extern void *pAMXFunctions;





PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
    return (SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES);
}



PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData)
{
    pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
    logprintf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];

    logprintf("  MD6 v%s by BJIADOKC loaded", PLUGIN_VERSION);

    return 1;
}



PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
	logprintf("  MD6 v%s by BJIADOKC unloaded", PLUGIN_VERSION);
}



PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX *amx)
{
    return amx_Register(amx, amxNatives::md6Natives, -1);
}



PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX *amx)
{
    return AMX_ERR_NONE;
}



void binary_hex_represintation(unsigned char *binary, char *digest, int length)
{
	static const char hexits[17] = "0123456789abcdef";

	if((length % 2))
		length--;

	for(int i = 0; i < length; i++) 
	{
		digest[i * 2] = hexits[binary[i] >> 4];
		digest[(i * 2) + 1] = hexits[binary[i] & 0x0F];
	}
}