#include "fractol.h"



/*void		change_coef_zoom(t_env *env, int x, int y)
{
	float r;
	float t;
	float s;
	float g;

	r = env->alphax * x + env->betax;
	printf("%f\n", r);
	t = env->betax;
	env->betax = t + (r - t) / 2;
	env->alphax = (r - env->betax) / x;
	printf("%f\n", env->alphax * x + env->betax);

	
	s = env->alphay * y + env->betay;
	printf("%f\n", s);
	g = env->betay;
	env->betay = g + (s - g) / 2;
	env->alphay = (s - env->betay) / y;
	printf("%f\n", env->alphay * y + env->betay);	
	check_extremes(env);
}*/

/*void		change_coef_zoom(t_env *env, int x, int y)
{
	float r;
	float t;
	float s;
	float g;

	r = env->alphax * x + env->betax;
	printf("%f\n", r);
	t = env->betax;
	env->betax = t + (r - t) / 2;
	env->alphax = (r - env->betax) / x;
	printf("%f\n", env->alphax * x + env->betax);

	
	s = env->alphay * y + env->betay;
	printf("%f\n", s);
	g = env->betay;
	env->betay = g + (s - g) / 2;
	env->alphay = (s - env->betay) / y;
	printf("%f\n", env->alphay * y + env->betay);
}

/*void		change_coef_dezoom(t_env *env, int x, int y)
{
	float r;
	float t;
	float s;
	float g;

	r = env->alphax * x + env->betax;
	printf("%f\n", r);
	t = env->betax;
	env->betax = t - (r - t) / 2;
	if (env->betax < -2.1)
	{
		env->betax = -2.1;
	}
	env->alphax = (r - env->betax) / x;

	s = env->alphay * y + env->betay;
	

	g = env->betay;
	env->betay = g - (s - g) / 2;
	if (env->betay < -1.2)
		env->betay = -1.2;
	env->alphay = (s - env->betay) / y;
	printf("%f\n", env->alphay * y + env->betay);
}*/