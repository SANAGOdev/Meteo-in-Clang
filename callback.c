#include "my.h"

size_t callback(void *ptr, size_t size, size_t nmemb, void *stream)
{
	size_t realsize = size * nmemb;
	char *data = (char *)malloc(realsize + 1);
	memcpy(data, ptr, realsize);
	data[realsize] = '\0';

	json_object *root = json_tokener_parse(data);

	json_object *main_obj = json_object_object_get(root, "main");
	json_object *temp_obj = json_object_object_get(main_obj, "temp");
	double temp = json_object_get_double(temp_obj);

	printf("Temperature : %f\n", temp);

	json_object_put(root);

	free(data);
	return realsize;
}