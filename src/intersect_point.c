#include "rt.h"
#include <math.h>

float	intersect_point(float a, float b, float delta)
{
	float	t[2];

	if (delta == 0)
		return (-b / a * 2);
	else
	{
		t[0] = (-b - sqrt(delta)) / (2 * a);
		t[1] = (-b + sqrt(delta)) / (2 * a);
		if (t[0] < t[1])
		{
			if (t[0] > 0)
				return (t[0]);
			else
				return (t[1]);
		}
		else
		{
			if (t[1] > 0)
				return (t[1]);
			else
				return (t[0]);
		}
	}
}
