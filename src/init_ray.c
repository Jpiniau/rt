#include "rt.h"
#include "math.h"

void	init_ray(t_ray *ray, int x, int y, t_env *e)
{
	float	ratio;
	float	px;
	float	py;
	int		fov;

	(void)e;
	fov = 40;
	ratio = (float)e->width / (float)e->height;
	px = (2 * ((x + 0.5) / e->width) - 1) * tan(fov /(float)2 * M_PI /(float)180) * ratio;
	py = (1 - 2 * (y + 0.5) / e->height) * tan(fov / 2 * M_PI / 180);
	//init_vec3(&(ray->o), e->cam_pos.x, e->cam_pos.y, e->cam_pos.z);
	init_vec3(&ray->o, 0, 0, 0);
	init_vec3(&(ray->d), px, py, -1);
	normalize(&(ray->d));
}
