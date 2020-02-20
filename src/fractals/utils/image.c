/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:03:11 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/20 21:23:58 by ohakola          ###   ########.fr       */
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
	char	tmp_row[IMG_WIDTH * BYTES_PER_PIXEL];

	i = 0;
	row_len = IMG_WIDTH * BYTES_PER_PIXEL;
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
	while (i < IMG_HEIGHT / 2)
	{
		ft_memcpy(tmp_row, scene->screenshot_buf + (i * row_len), row_len);
		ft_memcpy(scene->screenshot_buf + (i * row_len),
			buf + (IMG_HEIGHT - i - 1) * row_len, row_len);
		ft_memcpy(buf + (IMG_HEIGHT - i - 1) * row_len, tmp_row, row_len);
		i++;
	}
}

static unsigned char	*create_bmp_file_header(int padding_size)
{
	int						file_size;
	static unsigned char	file_header[INFO_HEADER_SIZE];

	file_size = FILE_HEADER_SIZE + INFO_HEADER_SIZE +
		(BYTES_PER_PIXEL * IMG_WIDTH + padding_size) * IMG_HEIGHT;
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
	info_header[4] = (unsigned char)(IMG_WIDTH);
	info_header[5] = (unsigned char)(IMG_WIDTH >> 8);
	info_header[6] = (unsigned char)(IMG_WIDTH >> 16);
	info_header[7] = (unsigned char)(IMG_WIDTH >> 24);
	info_header[8] = (unsigned char)(IMG_HEIGHT);
	info_header[9] = (unsigned char)(IMG_HEIGHT >> 8);
	info_header[10] = (unsigned char)(IMG_HEIGHT >> 16);
	info_header[11] = (unsigned char)(IMG_HEIGHT >> 24);
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

	padding_size = (4 - (IMG_WIDTH * BYTES_PER_PIXEL) % 4) % 4;
	file_header = create_bmp_file_header(padding_size);
	info_header = create_bmp_info_header();
	image_file = fopen(filename, "wb");
	fwrite(file_header, 1, FILE_HEADER_SIZE, image_file);
	fwrite(info_header, 1, INFO_HEADER_SIZE, image_file);
	i = 0;
	while (i < IMG_HEIGHT)
	{
		fwrite(image + (i * IMG_WIDTH * BYTES_PER_PIXEL),
			BYTES_PER_PIXEL, IMG_WIDTH, image_file);
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
	t_scene	*tmp_scene;

	ft_putstr("Rendering image...\n");
	if (!(randstr = ft_itoa(rand())) ||
		!(tmp = ft_strjoin("img/render_", randstr)) ||
		!(img_name = ft_strjoin(tmp, ".bmp")))
		return (0);
	ft_strdel(&randstr);
	ft_strdel(&tmp);
	if (!(tmp_scene = image_render_scene(scene)))
		return (0);
	artist_draw(tmp_scene->artist)(tmp_scene);
	copy_thread_imgs_to_screenshot(tmp_scene);
	generate_bmp_image((unsigned char*)tmp_scene->screenshot_buf,
		img_name);
	delete_scene(tmp_scene);
	ft_strdel(&img_name);
	return (0);
}
