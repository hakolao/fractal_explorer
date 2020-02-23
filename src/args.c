/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 23:39:18 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/23 16:12:49 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				is_valid_arg(char *arg)
{
	return (ft_strequ(arg, "mandelbrot") ||
			ft_strequ(arg, "julia") ||
			ft_strequ(arg, "burning_ship") ||
			ft_strequ(arg, "bird_of_prey") ||
			ft_strequ(arg, "julia_n") ||
			ft_strequ(arg, "julia_mod") ||
			ft_strequ(arg, "phoenix_mod") ||
			ft_strequ(arg, "burning_julia") ||
			ft_strequ(arg, "mandelbrot_n"));
}

int				check_args(char *arg, int *size, int *fractal)
{
	int		res;

	if ((res = is_valid_arg(arg)))
		(*size)++;
	if (ft_strequ(arg, "mandelbrot"))
		*fractal = mandelbrot;
	else if (ft_strequ(arg, "julia"))
		*fractal = julia;
	else if (ft_strequ(arg, "burning_ship"))
		*fractal = burning_ship;
	else if (ft_strequ(arg, "mandelbrot_n"))
		*fractal = mandelbrot_n;
	else if (ft_strequ(arg, "julia_n"))
		*fractal = julia_n;
	else if (ft_strequ(arg, "bird_of_prey"))
		*fractal = bird_of_prey;
	else if (ft_strequ(arg, "julia_mod"))
		*fractal = julia_mod;
	else if (ft_strequ(arg, "phoenix_mod"))
		*fractal = phoenix_mod;
	else if (ft_strequ(arg, "burning_julia"))
		*fractal = burning_julia;
	return (res);
}

static int		parse_rgb(char *colorstr, int *r, int *g, int *b)
{
	int		i;

	i = 0;
	while (*colorstr)
	{
		if (!ft_isdigit(*colorstr) && *colorstr != ',')
			return (FALSE);
		if (ft_isdigit(*colorstr))
		{
			if (i == 0)
				*r = ft_atoi(colorstr);
			if (i == 1)
				*g = ft_atoi(colorstr);
			if (i == 2)
				*b = ft_atoi(colorstr);
			i++;
		}
		while (*colorstr && (ft_isdigit(*colorstr)))
			colorstr++;
		if (*colorstr == ',')
			colorstr++;
	}
	if (i != 3)
		log_err("Wrong number of RGB ints", strerror(5));
	return (i == 3);
}

static t_rgb	*parse_rgb_str(char *colorstr)
{
	int		r;
	int		g;
	int		b;
	int		i;
	t_rgb	*rgb;

	i = 0;
	if (!(rgb = malloc(sizeof(*rgb))))
		return (NULL);
	if (!parse_rgb(colorstr, &r, &g, &b))
		return (NULL);
	if (!(r <= 255 && r >= 0 &&
		g <= 255 && g >= 0 &&
		b <= 255 && b >= 0))
	{
		log_err("RGB values must be between or equal to 0 & 255",
			strerror(5));
		return (NULL);
	}
	rgb->r = r;
	rgb->g = g;
	rgb->b = b;
	return (rgb);
}

/*
** Parse colors from format:
** -colors=244\,20\,33\|22\,30\,150
** arg + 8 to skip to first digit.
** The parser is quite lenient on commas,
** -colors=244\,20\,33\|22\,30\,150,,, will work too
** or -colors=244\,,,,20\,,,33\|22\,,,,30\,150
*/

t_colors		*parse_colors(char *arg)
{
	char		**color_strs;
	t_rgb		**colors;
	t_colors	*color_data;
	int			i;
	int			size;

	if ((!(color_data = malloc(sizeof(*color_data))) ||
		!(color_strs = ft_strsplit(arg + 8, '|'))) &&
		log_err("Failed to parse colors", strerror(5)))
		return (NULL);
	i = 0;
	while (color_strs[i])
		i++;
	size = i;
	if (!(colors = malloc(sizeof(*colors) * size)) &&
		log_err("Failed to malloc colors", strerror(5)))
		return (NULL);
	i = -1;
	while (++i < size)
		if (!(colors[i] = parse_rgb_str(color_strs[i])) &&
			log_err("Failed to parse rgb values", strerror(5)))
			return (NULL);
	color_data->colors = colors;
	color_data->size = size;
	return (color_data);
}
