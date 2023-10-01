#include <iostream>
#include <Windows.h>
#include "Headers/LFX2.h"
#include <ctime>
#include <iomanip>
#include <tchar.h>

int main()
{
	LFX2INITIALIZE initFunction;
	LFX2RELEASE releaseFunction;

	LFX2GETNUMDEVICES getNumDevicesFunction;
	LFX2GETDEVDESC getDeviceDescriptionFunction;
	LFX2GETNUMLIGHTS getNumLightsFunction;
	LFX2GETLIGHTDESC getLightDescriptionFunction;

	LFX2RESET resetFunction;
	LFX2UPDATE updateFunction;
	LFX2LIGHT lightFunction;
	LFX2GETVERSION versionFunction;

	HINSTANCE hLibrary = LoadLibrary(_T(LFX_DLL_NAME));
	if (hLibrary)
	{
		initFunction = (LFX2INITIALIZE)GetProcAddress(hLibrary, LFX_DLL_INITIALIZE);
		releaseFunction = (LFX2RELEASE)GetProcAddress(hLibrary, LFX_DLL_RELEASE);

		getNumDevicesFunction = (LFX2GETNUMDEVICES)GetProcAddress(hLibrary, LFX_DLL_GETNUMDEVICES);
		getDeviceDescriptionFunction = (LFX2GETDEVDESC)GetProcAddress(hLibrary, LFX_DLL_GETDEVDESC);
		getNumLightsFunction = (LFX2GETNUMLIGHTS)GetProcAddress(hLibrary, LFX_DLL_GETNUMLIGHTS);
		getLightDescriptionFunction = (LFX2GETLIGHTDESC)GetProcAddress(hLibrary, LFX_DLL_GETLIGHTDESC);

		resetFunction = (LFX2RESET)GetProcAddress(hLibrary, LFX_DLL_RESET);
		updateFunction = (LFX2UPDATE)GetProcAddress(hLibrary, LFX_DLL_UPDATE);
		lightFunction = (LFX2LIGHT)GetProcAddress(hLibrary, LFX_DLL_LIGHT);
		versionFunction = (LFX2GETVERSION)GetProcAddress(hLibrary, LFX_DLL_GETVERSION);

		LFX_RESULT result = initFunction();
		if (result == LFX_SUCCESS)
		{
			if (versionFunction == NULL)
				std::cout << "SDK version not found ..." << std::endl;
			else
			{
				unsigned int versionSize = 255;
				char* version = new char[versionSize];
				result = versionFunction(version, versionSize);
				std::cout << "SDK version: " << version << std::endl;
				delete[]version;
			}

			unsigned int numDevices = 0;
			result = getNumDevicesFunction(&numDevices);
			std::cout << "Devices: " << numDevices << std::endl;

			for (unsigned int devIndex = 0; devIndex < numDevices; devIndex++)
			{
				unsigned int numLights = 0;
				unsigned char devType = 0;
				unsigned char* devTypePtr = &devType;

				unsigned int descSize = 255;
				char* description = new char[descSize];
				result = getDeviceDescriptionFunction(devIndex, description, descSize, &devType);
				std::cout << "Description: " << description << std::endl;
				delete[]description;

				description = new char[descSize];
				result = getNumLightsFunction(devIndex, &numLights);
				for (unsigned int lightIndex = 0; lightIndex < numLights; lightIndex++)
				{
					result = getLightDescriptionFunction(devIndex, lightIndex, description, descSize);
					if (result != LFX_SUCCESS)
						continue;

					std::cout << "\tLight: " << lightIndex << "\tDescription: " << description << std::endl;
				}

				delete[]description;
			}

			resetFunction();

			int color = 0x00ff00; // color
			lightFunction(LFX_ALL, color | LFX_FULL_BRIGHTNESS);
			updateFunction();
			system("cls");
			std::cout << "Color: " << std::hex << std::setw(6) << std::setfill('0') << color << std::endl;
			Sleep(100);

			std::cout << "Done.\r\n\r\nPress any key to finish ..." << std::endl;
			_gettch();
			result = releaseFunction();
		}
		else
		{
			switch (result)
			{
			case LFX_ERROR_NODEVS:
				std::cout << "There is not AlienFX device available." << std::endl;
				break;
			default:
				std::cout << "There was an error initializing the AlienFX device." << std::endl;
				break;
			}
		}

		FreeLibrary(hLibrary);
	}
	else
		std::cout << "Failed to load LightFX.dll." << std::endl;

	return 0;
}
