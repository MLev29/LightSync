#pragma once

#include <iostream>


typedef struct s_color
{
	int red;
	int green;
	int blue;
	std::string hexString;
} t_color;

t_color initColor(void);
void colorToHex(int, int, int);
int digitCount(int color);
std::string perColor(int);
