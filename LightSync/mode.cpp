#include <iostream>

#include "Headers/config.h"

//void currentMode(void)
//{
//	t_rgbMode rgbMode;
//	switch (rgbMode)
//	{
//		case STATICCOLOR:
//			staticColor();
//			break;
//		case RAINBOWWAVE:
//			rainbowWave();
//			break;
//		case BREATHING:
//			breathing();
//			break;
//		case PULSE:
//			pulse();
//			break;
//		case MORPH:
//			morph();
//			break;
//		case SPECTRUM:
//			spectrum();
//			break;
//		default:
//			staticColor();
//			break;
//	}
//}

void staticColor(void)
{
	std::cout << "Static color mode" << std::endl;
}

void rainbowWave(void)
{
	std::cout << "Rainbow wave mode" << std::endl;
}

void breathing(void)
{
	std::cout << "Breathing mode" << std::endl;
}

void pulse(void)
{
	std::cout << "Pulse mode" << std::endl;
}

void morph(void)
{
	std::cout << "Morph mode" << std::endl;
}

void spectrum(void)
{
	std::cout << "Spectrum mode" << std::endl;
}