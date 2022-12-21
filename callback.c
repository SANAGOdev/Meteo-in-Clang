#include "my.h"

size_t callback(void *ptr, size_t size, size_t nmemb, void *stream)
{
	size_t realsize = size * nmemb;
	char *data = (char *)malloc(realsize + 1);
	memcpy(data, ptr, realsize);
	data[realsize] = '\0';

	json_object *root = json_tokener_parse(data);

	json_object *main_obj = json_object_object_get(root, "main");
	json_object *wind_obj = json_object_object_get(root, "wind");
	json_object *wind_speed_obj = json_object_object_get(wind_obj, "speed");
	json_object *temp_obj = json_object_object_get(main_obj, "temp");
	json_object *temp_min_obj = json_object_object_get(main_obj, "temp_min");
	json_object *temp_max_obj = json_object_object_get(main_obj, "temp_max");
	json_object *humidity_obj = json_object_object_get(main_obj, "humidity");
	json_object *name_obj = json_object_object_get(root, "name");

	double temp = json_object_get_double(temp_obj);
	double temp_min = json_object_get_double(temp_min_obj);
	double temp_max = json_object_get_double(temp_max_obj);
	double humidity = json_object_get_double(humidity_obj);
	char *name = json_object_get_string(name_obj);
	double wind_speed = json_object_get_double(wind_speed_obj);

	printf("Ville : %s\n", name);
	printf("Temperature : %f'C\n", temp);
	printf("Temperature maximale : %f'C\n", temp_max);
	printf("Temperature minimale : %f'C\n", temp_min);
	printf("Humidite : %f%%\n", humidity);
	printf("Vitesse du vent : %fkm/h\n", wind_speed * 3.6);

	json_object_put(root);

	free(data);
	return realsize;
}