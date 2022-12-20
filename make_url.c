#define _CRT_SECURE_NO_WARNINGS
#include "my.h"

char *make_api_url(char *ville)
{
	char api_url[MAX_SIZE] = "https://api.openweathermap.org/data/2.5/weather?q=";
	strcat(api_url, ville);
	strcat(api_url, KEY);
	return api_url;
}
