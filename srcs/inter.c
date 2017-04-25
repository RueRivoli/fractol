#include "fractol.h"

float		value_x(t_env *env, int x)
{
	return (env->x_init + ((env->x_fin - env->x_init) * x / FENE_X) + \
	env->x_translation * ((env->x_fin - env->x_init) / 20));
}

float		value_y(t_env *env, int y)
{
	return (env->y_init + ((env->y_fin - env->y_init) * y / FENE_Y) + \
	env->y_translation * ((env->y_fin - env->y_init) / 20));
}

int					get_color(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'x')
			return (ft_hextoint(&str[i + 1]));
		i++;
	}
	return (-1);
}

void	modify_coord(t_env *env)
{
	float m;
	float n;

	if (env->x_zoom > 0)
		m = value_x(env, env->x_zoom);
	else
		m = 0;
	env->x_init = ((env->x_init - m) / env->zoom) + m;
	env->x_fin = ((env->x_fin - m) / env->zoom) + m;
	if (env->y_zoom > 0)
		n = value_y(env, env->y_zoom);
	else 
		n = 0;
	env->y_init = ((env->y_init - n) / env->zoom) + n;
	env->y_fin = ((env->y_fin - n) / env->zoom) + n;
}



void	trace(t_env *env)
{
	if (ft_strcmp(env->fractal_name, "mandelbrot") == 0)
		trace_mandelbrot(env);
	if (ft_strcmp(env->fractal_name, "julia") == 0)
		trace_julia(env);
}
