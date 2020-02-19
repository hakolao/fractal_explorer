/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:03:11 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/19 22:11:47 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Copies images from thread image to scene's screenshot buffer.
** Flips the image vertically so it corresponds to the app's view.
*/

static void				copy_thread_imgs_to_screenshot(t_scene *scene)
{
	int		i;
	char	*buf;
	int		row_len;
	char	tmp_row[WIDTH * BYTES_PER_PIXEL];

	i = 0;
	row_len = WIDTH * BYTES_PER_PIXEL;
	buf = scene->screenshot_buf;
	while (i < THREADS)
	{
		ft_memcpy(buf +
				i * scene->fractal_params[i]->size * BYTES_PER_PIXEL,
			scene->fractal_params[i]->frame_buf,
			scene->fractal_params[i]->size * BYTES_PER_PIXEL);
		i++;
	}
	i = 0;
	while (i < HEIGHT / 2)
	{
		ft_memcpy(tmp_row, scene->screenshot_buf + (i * row_len), row_len);
		ft_memcpy(scene->screenshot_buf + (i * row_len),
			buf + (HEIGHT - i - 1) * row_len, row_len);
		ft_memcpy(buf + (HEIGHT - i - 1) * row_len, tmp_row, row_len);
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

/*
** https://stackoverflow.com/questions/2654480/
** writing-bmp-image-in-pure-c-c-without-other-libraries
*/

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
	ft_putstr(" image generated!\n");
	fclose(image_file);
}

int						save_image(t_scene *scene)
{
	char	*img_name;
	char	*randstr;
	char	*tmp;
	// t_scene	*tmp_scene;

	if (!(randstr = ft_itoa(rand())) ||
		!(tmp = ft_strjoin("img/render_", randstr)) ||
		!(img_name = ft_strjoin(tmp, ".bmp")))
		return (0);
	ft_strdel(&randstr);
	ft_strdel(&tmp);
	// if (!(tmp_scene = new_scene(scene->mlx, scene->artist)) &&
	// 		log_err("Failed to create scene.", strerror(5)))
	// 	return (NULL);
	// artist_draw(scene->artist)(scene);
	copy_thread_imgs_to_screenshot(scene);

	generate_bmp_image((unsigned char*)scene->screenshot_buf, img_name);
	ft_strdel(&img_name);
	return (0);
}
