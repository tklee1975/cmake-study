#include <stdio.h>
#include <MyLib.h>
#include <string>

std::string floatToStr(const float &value)
{
	char temp[100];
	
	sprintf(temp, "%.2f", value);
	
	return temp;
}
