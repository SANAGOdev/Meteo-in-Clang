#ifndef MY_
#define MY_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <json-c/json.h>

#define MAX_SIZE 4096
#define KEY "&lang=fr&units=metric&appid=fbefbc21cd9c68493fd2a190bff949ea"

char *make_api_url(char *ville);
size_t callback(void *ptr, size_t size, size_t nmemb, void *stream);

#endif MY_
