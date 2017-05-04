#include "fractol.h"

int			key_funct(int keycode, t_env *env)
{
	ft_putstr("keycode :\n");
	ft_putnbr(keycode);
    if (keycode == TOUCH_ESC)
		exit(1);
    else if (keycode == ARROW_LEFT)
        translation(env, 0);
    else if (keycode == ARROW_DOWN)
        translation(env, 1);
    else if (keycode == ARROW_RIGHT)
        translation(env, 2);
    else if (keycode == ARROW_UP)
        translation(env, 3);
    else if (keycode == TOUCH_M)
        moovable(env);
    else if (keycode == TOUCH_O)
    {
        restart(env);
        env->moovable = 0;
    }
    else if (keycode == TOUCH_PLUS)
        change_iteration(env, 1);
    else if (keycode == TOUCH_LESS)
        change_iteration(env, 0);
    else if (keycode == TOUCH_G)
        change_color(env, GREEN);
    else if (keycode == TOUCH_B)
        change_color(env, BLUE);
    else if (keycode == TOUCH_Y)
        change_color(env, YELLOW);
    else if (keycode == TOUCH_P)
        change_color(env, PINK);
    else if (keycode == TOUCH_R)
        change_color(env, RED);
    return (0);
}

int     mouse_funct(int button, int x, int y, t_env *env)
{
    if (button == SCROLL_UP /*|| button == SCROLL_BIS || button == SCROLL_OTHER*/)
            zoom(env, x - 360, y - 100);
    else if (button == SCROLL_DOWN /*|| button == SCROLL_BIS*/)
            dezoom(env, x - 360, y - 100);
    return (0);
}

int     mouse_funct_moovable(int x, int y, t_env *env)
{
    if (env->moovable == 1 && (360 < x)  && (x < 1200 + 360) && (100 < y) && (y < 900 + 100))
    {
             env->jul->re_cte = 0.285 + 0.1 * (x - 960) / 500;
            env->jul->im_cte = 0.01 + 0.01 * (y - 550) / 450;
            refresh(env);
    }
    return (0);
}
