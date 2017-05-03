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
    else if (keycode == TOUCH_M)
        moovable(env);
    else if (keycode == TOUCH_O)
    {
        restart(env);
        env->moovable = 0;
    }
    else if (keycode == TOUCH_G)
       {
           env->theme = GREEN;
           refresh(env);
       }
    else if (keycode == TOUCH_B)
    {
        env->theme = BLUE;
        refresh(env);
    }
    else if (keycode == TOUCH_Y)
    {
        env->theme = YELLOW;
        refresh(env);
    }
    else if (keycode == TOUCH_P)
    {
        env->theme = PINK;
        refresh(env);
    }
    else if (keycode == TOUCH_R)
    {
        env->theme = RED;
        refresh(env);
    }
    return (0);
}

int     mouse_funct(int button, int x, int y, t_env *env)
{
   printf("button : %d\n", button);
    ft_putstr("LILLE ");
   (void)x;
   (void)y;
    if (button == SCROLL_UP /*|| button == SCROLL_BIS || button == SCROLL_OTHER*/)
            zoom(env, x - 360, y - 100);
    else if (button == SCROLL_DOWN /*|| button == SCROLL_BIS*/)
            dezoom(env, x - 360, y - 100);
    return (0);
}

int     mouse_funct_moovable(int x, int y, t_env *env)
{
    //static int tmp_x;
    //static int tmp_y;

    if (env->moovable == 1 && (360 < x)  && (x < 1200 + 360) && (100 < y) && (y < 900 + 100))
    {
            //env->jul->re_cte = 0.285 + 0.1 * (x - 360) / 1200;
            //env->jul->im_cte = 0.01 + 0.01 * (y - 100) / 900;

             env->jul->re_cte = 0.285 + 0.1 * (x - 960) / 500;
            env->jul->im_cte = 0.01 + 0.01 * (y - 550) / 450;
        /*if (x > tmp_x)
			env->jul->re_cte += 0.05;
		else
			env->jul->re_cte -= 0.05;
		if (y > tmp_y)
			env->jul->im_cte += 0.05;
		else
			env->jul->im_cte -= 0.05;*/
        refresh(env);
    
    /*tmp_x = x;
    tmp_y = y;*/
    }

    return (0);
}



