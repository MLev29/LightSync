#include <iostream>

#include "../Headers/logic/color.h"

/// <summary>
/// Initialize color value to 0
/// </summary>
/// <returns>Return color as RBG</returns>
t_color initColor(void)
{
	t_color color;
	color.red   = 0;
	color.green = 0;
	color.blue  = 0;

	return color;
}

/// <summary>
/// Converts color integer to hexadecimal 
/// </summary>
/// <param name="red">get red integer value</param>
/// <param name="green">get green integer value</param>
/// <param name="blue">get blue integer value</param>
void colorToHex(int red, int green, int blue)
{
	std::string hexRed;
	std::string hexGreen;
	std::string hexBlue;
	std::string hexString;
	
	t_color color;

	hexRed = perColor(red);
	hexGreen = perColor(green);
	hexBlue  = perColor(blue);

	// Combine 3 hex values for RGB

	
	color.hexString = hexRed + hexGreen + hexBlue;

	std::cout << "hex String: " << color.hexString << std::endl; // debug remove
}

/// <summary>
/// Converts integer to hex string 
/// </summary>
/// <param name="color">Take 1 of 3 colors (RBG)</param>
/// <returns>Returns hex color string</returns>
std::string perColor(int color)
{
	const int max = 2;
	char hex[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
	std::string	hexString[2];
	
	int resultInt = color;
	int hexArray[max]; 

	// convert base 10 to base 16 as int
	for (int i = max - 1; i >= 0; i--)
	{
		float result = color / 16.0F;
		resultInt = result;

		hexArray[i] = (result - resultInt) * 16;
		
		color = resultInt;
	}

	*hexString = { hex[hexArray[0]], hex[hexArray[1]] };

	return *hexString;
}