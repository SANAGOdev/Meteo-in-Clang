#define _CRT_SECURE_NO_WARNINGS
#include "my.h"

int main(void)
{
	char ville[MAX_SIZE];
	printf("Entrez un nom de ville : ");
	scanf("%s", &ville);

	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, make_api_url(ville));

		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);

		curl_easy_perform(curl);

		curl_easy_cleanup(curl);
	}

	return 0;
}