/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmatrix.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 13:11:01 by ohakola           #+#    #+#             */
/*   Updated: 2020/01/31 16:28:40 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMATRIX_H
# define LIBMATRIX_H

# define TRUE 1
# define FALSE 0

# include <math.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct		s_matrix
{
	size_t			rows;
	size_t			cols;
	double			*m;
}					t_matrix;

typedef struct		s_vector
{
	size_t			size;
	double			*v;
}					t_vector;

typedef struct		s_canvas
{
	double			width;
	double			height;
	double			near;
	double			far;
	double			angle;
}					t_canvas;

typedef struct		s_local_axes
{
	t_vector		*xaxis;
	t_vector		*yaxis;
	t_vector		*zaxis;
}					t_local_axes;

# define VALUE_AT(mat, r, c) (mat)->m[c * (mat)->rows + r]

t_matrix			*ft_matrix_new(size_t cols, size_t rows);
t_matrix			*ft_matrix_id(size_t cols, size_t rows);
int					ft_matrix_add_double(const t_matrix *m1,
					const double d, t_matrix *res);
int					ft_matrix_add(const t_matrix *m1,
					const t_matrix *m2, t_matrix *res);
int					ft_matrix_sub_double(const t_matrix *m1,
					const double d, t_matrix *res);
int					ft_matrix_sub(const t_matrix *m1, const t_matrix *m2,
					t_matrix *res);
int					ft_matrix_mul(const t_matrix *m1, const t_matrix *m2,
					t_matrix *res);
int					ft_matrix_mul_double(const t_matrix *m1,
					const double d, t_matrix *res);
t_vector			*ft_vector_new(size_t size);
t_vector			*ft_vector4_new(double x, double y, double z);
int					ft_vector_to_matrix(const t_vector *vec, t_matrix *res);
int					ft_matrix_mul_vector(const t_matrix *m1, const t_vector *v,
					t_vector *res);
int					ft_scale_matrix(size_t cols, size_t rows, t_vector *scale,
					t_matrix *res);
int					ft_matrix_scale(t_matrix *mat, t_matrix *scale,
					t_matrix *res);
int					ft_vector_scale(t_vector *vec, t_vector *scale);
int					ft_vector_set_all(t_vector *vec, double d);
int					ft_vector_set_vals(t_vector *vec, double *arr,
					size_t arr_size);
int					ft_matrix_set_vals(t_matrix *mat, double *arr,
					size_t arr_size);
int					ft_dimensions_equal(const t_matrix *m1, const t_matrix *m2);
void				ft_putint_fd(int nb, int fd);
void				ft_puterror(char *err);
void				ft_putint(int nb);
void				ft_putmatrix(t_matrix *mat);
int					ft_matrix_set_all(t_matrix *mat, double nb);
void				ft_matrix_free(t_matrix *mat);
void				ft_vector_free(t_vector *vec);
void				ft_putvector(t_vector *vec);
double				ft_vector_mag(t_vector *vec);
int					ft_vector_normalize(t_vector *vec, t_vector *res);
int					ft_vector_sub(t_vector *v1, t_vector *v2, t_vector *res);
int					ft_vector_add(t_vector *v1, t_vector *v2, t_vector *res);
double				ft_vector_dot(t_vector *v1, t_vector *v2);
int					ft_vector_cross(t_vector *v1, t_vector *v2, t_vector *res);
int					ft_perspective_matrix(t_canvas *c, t_matrix *res);
int					ft_orthographic_matrix(t_canvas *c, t_matrix *res);
int					ft_vector_forward(t_vector *position, t_vector *target,
					t_vector *res);
int					ft_fps_cam(t_vector *position, double pitch, double yaw,
					t_matrix *res);
int					ft_rotation_matrix(int angle_x, int angle_y, int angle_z,
					t_matrix *res);
int					ft_matrix_inverse_4x4(t_matrix *m1, t_matrix *res);
t_matrix			*ft_scale_matrix_xyz(double x, double y, double z);
int					ft_matrix_mul_vector_lst(t_matrix *m, t_vector **vecs,
					size_t n);
t_vector			*ft_vector_dup(t_vector *v);

#endif
