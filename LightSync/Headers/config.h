#pragma once

#define ledColor 0x0000ff

typedef enum s_rgbMode
{
	STATICCOLOR,
	RAINBOWWAVE,
	BREATHING,
	PULSE,
	MORPH,
	SPECTRUM
} t_rgbMode;

void currentMode(void);
void staticColor(void);
void rainbowWave(void);
void breathing(void);
void pulse(void);
void morph(void);
void spectrum(void);