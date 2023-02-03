void	display_mandelbrot(t_data *data, t_pixel pixel)
{
	t_complex	z;
	t_complex	z0;
	double		temp;
	int			iter;

	z.x = 0;
	z.y = 0;
	z0 = convert_to_cartesian(data, pixel);
	iter = 0;
	while (z.x * z.x + z.y * z.y <= 4 && iter < ITER_MAX)
	{
		temp = z.x * z.x - z.y * z.y + z0.x;
		z.y = 2 * z.x * z.y + z0.y;
		z.x = temp;
		iter++;
	}
	monochrome_gradient(data, pixel, iter);
}

void	display_mandelbrot_approx(t_data *data, t_pixel pixel)
{
	t_complex	z;
	t_complex	z2;
	t_complex	z0;
	t_complex	z_old;
	double		precision;
	int			iter;
	int			period;

	z.x = 0;
	z.y = 0;
	z2.x = 0;
	z2.y = 0;
	z_old.x = 0;
	z_old.y = 0;
	period = 0;
	precision = 0.00000000000001;
	convert_to_cartesian(data, &pixel, &z0);
	iter = 0;
	while (z2.x + z2.y <= 4 && iter < ITER_MAX)
	{
		z.y = 2 * z.x * z.y + z0.y;
		z.x = z2.x - z2.y + z0.x;
		z2.x = z.x * z.x;
		z2.y = z.y * z.y;
		iter++;
		if (z_old.x - precision < z.x && z.x < z_old.x + precision
			&& z_old.y - precision < z.y && z.y < z_old.y + precision)
		{
			iter = ITER_MAX;
			break ;
		}
		period++;
		if (period > 20)
		{
			period = 0;
			z_old.x = z.x;
			z_old.y = z.y;
		}
	}
	color_map(data, pixel, iter);
}

void	display_mandelbrot_optimized(t_data *data, t_pixel pixel)
{
	t_complex	z;
	t_complex	z0;
	double		temp;
	int			iter;

	set_zero(&z);
	convert_to_cartesian(data, &pixel, &z0);
	iter = 0;
	while (z.x * z.x + z.y * z.y <= 4 && iter < ITER_MAX)
	{
		temp = z.x * z.x - z.y * z.y + z0.x;
		z.y = 2 * z.x * z.y + z0.y;
		z.x = temp;
		iter++;
	}
	monochrome_gradient(data, pixel, iter);
}

void	display_mandelbrot_fract_color(t_data *data, t_pixel pixel)
{
	t_complex	z;
	t_complex	z0;
	double		temp;
	int			iter;
	double		fractional_count;

	set_zero(&z);
	convert_to_cartesian(data, &pixel, &z0);
	iter = 0;
	while (z.x * z.x + z.y * z.y <= 4 && iter < ITER_MAX)
	{
		temp = z.x * z.x - z.y * z.y + z0.x;
		z.y = 2 * z.x * z.y + z0.y;
		z.x = temp;
		iter++;
	}
	fractional_count = iter + 1 - log(log(sqrt(z.x * z.x + z.y * z.y))) / log(2);
	monochrome_gradient_fract(data, pixel, fractional_count);
}

//Operations --- 0 : z1 = z1 * z1 + z2
//-------------- 1 : z1 = z1 * 2 * z2
void	calc_complex(t_complex *z1, t_complex *z2, int operation)
{
	t_complex	z_temp;


	if (operation == 0)
	{
		z_temp.x = z1->x * z1->x - z1->y * z1->y + z2->x;
		z_temp.y = 2 * z1->x * z1->y + z2->y;
		z1->x = z_temp.x;
		z1->y = z_temp.y;
	}
	else if (operation == 1)
	{
		z_temp.x = 2 * (z1->x * z2->x - z1->y * z2->y);
		z_temp.y = 2 * (z1->x * z2->y + z1->y * z2->x);
		z1->x = z_temp.x;
		z1->y = z_temp.y;
	}
}

void	compute_mandelbrot_derivative(t_data *data, t_pixel pixel)
{
	t_complex	z;
	t_complex	z0;
	t_complex	derivative;
	int			iter;
	double		treshold;

	convert_to_cartesian(data, &pixel, &z0);
	z.x = z0.x;
	z.y = z0.y;
	derivative.x = 1;
	derivative.y = 0;
	iter = 0;
	treshold = 0.00000001;
	while (iter < ITER_MAX)
	{
		if ((derivative.x * derivative.x + derivative.y * derivative.y) < (treshold * treshold))
		{
			pixel_put_in_image(&data->image, pixel.x, pixel.y, encode_rgb(255, 255, 255));
			break;
		}
		if ((z.x * z.x + z.y * z.y) > 4)
		{
			pixel_put_in_image(&data->image, pixel.x, pixel.y, encode_rgb(0, 0, 0));
			break;
		}
		calc_complex(&derivative, &z, 1);
		calc_complex(&z, &z0, 0);
		iter++;
		pixel_put_in_image(&data->image, pixel.x, pixel.y, encode_rgb(175, 175, 175));
	}
}

