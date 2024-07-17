#include "../include/cub3D.h"

static t_data init_argumet()	// init the data structure
{
	t_data dt; // init the data structure

	dt.map2d = calloc(10, sizeof(char *)); // init the map
	dt.map2d[0] = strdup("1111111111111111111111111"); //fill the map
	dt.map2d[1] = strdup("1000000000000000000100001");
	dt.map2d[2] = strdup("1001000000000000000000001");
	dt.map2d[3] = strdup("10010000000000E0001000001");
	dt.map2d[4] = strdup("1001000000000000001000001");
	dt.map2d[5] = strdup("1001000000100000001000001");
	dt.map2d[6] = strdup("1001000000000000001000001");
	dt.map2d[7] = strdup("1001000000001000001000001");
	dt.map2d[8] = strdup("1111111111111111111111111");
	dt.map2d[9] = NULL;
	dt.p_y = 3; // player y position in the map
	dt.p_x = 14; // player x position in the map
	dt.w_map = 25; // map width
	dt.h_map = 9; // map height
	return (dt); // return the data structure
}

int	main(void)
{
	t_data	data;

	data = init_argumet();
	power_on(&data);
	return (0);
}
