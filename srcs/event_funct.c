#include "fractol.h"

int			key_funct(int keycode, t_env *env)
{
    (void)env;
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
    else if (keycode == TOUCH_O)
        restart(env);
    return (0);
}

int     mouse_funct(int button, int x, int y, t_env *env)
{
   printf("button : %d\n", button);
   (void)x;
   (void)y;
    if (button == SCROLL_UP /*|| button == SCROLL_BIS || button == SCROLL_OTHER*/)
            zoom(env, x - 360, y - 100);
    else if (button == SCROLL_DOWN)
            dezoom(env, x - 360, y - 100);
    return (0);
}
