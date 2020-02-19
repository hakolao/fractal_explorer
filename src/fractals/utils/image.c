/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:03:11 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/19 17:19:00 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void				copy_thread_imgs_to_screenshot(t_scene *scene)
{
	int		i;
	int		j;

	i = 0;
	while (i < THREADS)
	{
		j = 0;
		while (j < scene->fractal_params[i]->size)
		{
			scene->screenshot_buf[i + j] =
				scene->fractal_params[i]->frame_buf[j];
			j++;
		}
		i++;
	}
}

static unsigned char	*create_bmp_file_header(int padding_size)
{
	int						file_size;
	static unsigned char	file_header[INFO_HEADER_SIZE];

	file_size = FILE_HEADER_SIZE + INFO_HEADER_SIZE +
		(BYTES_PER_PIXEL * WIDTH + padding_size) * HEIGHT;
	ft_memset(file_header, 0, FILE_HEADER_SIZE);
	file_header[0] = (unsigned char)('B');
	file_header[1] = (unsigned char)('M');
	file_header[2] = (unsigned char)(file_size);
	file_header[3] = (unsigned char)(file_size >> 8);
	file_header[4] = (unsigned char)(file_size >> 16);
	file_header[5] = (unsigned char)(file_size >> 24);
	file_header[10] = (unsigned char)(FILE_HEADER_SIZE + INFO_HEADER_SIZE);
	return (file_header);
}

unsigned char			*create_bmp_info_header(void)
{
	static unsigned char	info_header[INFO_HEADER_SIZE];

	ft_memset(info_header, 0, INFO_HEADER_SIZE);
	info_header[0] = (unsigned char)(INFO_HEADER_SIZE);
	info_header[4] = (unsigned char)(WIDTH);
	info_header[5] = (unsigned char)(WIDTH >> 8);
	info_header[6] = (unsigned char)(WIDTH >> 16);
	info_header[7] = (unsigned char)(WIDTH >> 24);
	info_header[8] = (unsigned char)(HEIGHT);
	info_header[9] = (unsigned char)(HEIGHT >> 8);
	info_header[10] = (unsigned char)(HEIGHT >> 16);
	info_header[11] = (unsigned char)(HEIGHT >> 24);
	info_header[12] = (unsigned char)(1);
	info_header[14] = (unsigned char)(BYTES_PER_PIXEL * 8);
	return (info_header);
}

static void				generate_bmp_image(unsigned char *image, char *filename)
{
	int				padding_size;
	unsigned char	*file_header;
	unsigned char	*info_header;
	FILE			*image_file;
	int				i;

	padding_size = (4 - (WIDTH * BYTES_PER_PIXEL) % 4) % 4;
	file_header = create_bmp_file_header(padding_size);
	info_header = create_bmp_info_header();
	image_file = fopen(filename, "wb");
	fwrite(file_header, 1, FILE_HEADER_SIZE, image_file);
	fwrite(info_header, 1, INFO_HEADER_SIZE, image_file);
	i = 0;
	while (i < HEIGHT)
	{
		fwrite(image + (i * WIDTH * BYTES_PER_PIXEL),
			BYTES_PER_PIXEL, WIDTH, image_file);
		fwrite((unsigned char[3]){0, 0, 0}, 1, padding_size, image_file);
		i++;
	}
	ft_putstr(filename);
	ft_putstr(" image generated!");
	fclose(image_file);
}

int						save_image(t_scene *scene)
{
	char	*img_name;
	char	*randstr;
	char	*tmp;

	if (!(randstr = ft_itoa(rand())) ||
		!(tmp = ft_strjoin("img/screenshot_", randstr)) ||
		!(img_name = ft_strjoin(tmp, ".bmp")))
		return (0);
	ft_strdel(&randstr);
	ft_strdel(&tmp);
	copy_thread_imgs_to_screenshot(scene);
	generate_bmp_image((unsigned char*)scene->screenshot_buf, img_name);
	ft_strdel(&img_name);
	return (0);
}
