/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:54:49 by mchaya            #+#    #+#             */
/*   Updated: 2021/02/21 14:25:44 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define BUFFER_SIZE 100
# include <math.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_color {
	double			red;
	double			green;
	double			blue;
}					t_color;

typedef struct		s_vars {
	void			*mlx;
	void			*win;
}					t_vars;

typedef struct		s_data {
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct		s_vector {
	double			x;
	double			y;
	double			z;
}					t_vector;

typedef struct		s_resol {
	int				width;
	int				height;
}					t_resol;

typedef struct		s_matrix {
	t_vector		right;
	t_vector		up;
	t_vector		forward;
}					t_matrix;

typedef struct		s_cam {
	t_vector		view_p;
	t_vector		normal_v;
	double			fov;
	struct s_cam	*next;
}					t_cam;

typedef struct		s_sphere {
	t_color			color;
	t_vector		center;
	double			diamtr;
	struct s_sphere	*next;
}					t_sphere;

typedef struct		s_plane {
	t_vector		coord;
	t_vector		normal_v;
	t_color			color;
	struct s_plane	*next;
}					t_plane;

typedef struct		s_disk {
	t_vector		center;
	double			diamtr;
	t_vector		normal_v;
	t_color			color;
	struct s_disk	*next;
}					t_disk;

typedef struct		s_trian {
	char			id;
	t_vector		fp;
	t_vector		sp;
	t_vector		tp;
	t_color			*color;
	struct s_trian	*next;
}					t_trian;

typedef struct		s_square {
	t_vector		center;
	t_vector		normal_v;
	double			size;
	t_color			color;
	struct s_square	*next;
}					t_square;

typedef struct		s_light {
	t_color			ambient;
	t_vector		coord;
	t_color			color;
	struct s_light	*next;
}					t_light;

typedef struct		s_clndr {
	t_vector		coord;
	t_vector		normal_v;
	double			diamtr;
	double			height;
	t_color			color;
	struct s_clndr	*next;
}					t_clndr;

typedef struct		s_rt {
	double			t;
	t_color			color;
	t_vector		phit;
	t_vector		normal;
	void			*near;
}					t_rt;

typedef struct		s_obj {
	int				tr;
	int				cyl;
	int				sph;
	int				sqr;
	int				pl;
	int				ds;
	t_trian			*trian;
	t_sphere		*sphere;
	t_clndr			*clndr;
	t_square		*square;
	t_plane			*plane;
	t_disk			*disk;
}					t_obj;

typedef struct		s_scene {
	t_resol			*resol;
	t_light			*light;
	t_color			*ambient;
	t_cam			*cam;
	t_obj			obj;
}					t_scene;

typedef struct		s_ray {
	t_vector		view_p;
	double			t;
	t_vector		direct;
}					t_ray;

typedef struct		s_paint {
	int				*arr;
	t_scene			*scene;
	t_data			*img;
	t_vars			vars;
}					t_paint;

typedef struct		s_close {
	t_vars			*vars;
	t_scene			*scene;
	int				*arr;
	t_data			*img;
}					t_close;

extern t_close g_close;

typedef struct		s_stuff {
	t_paint			*cam;
	t_close			*close;
}					t_stuff;

typedef struct		s_int_tr {
	t_vector		a;
	t_vector		b;
	t_vector		pvec;
	t_vector		tvec;
	t_vector		qvec;
	double			det;
	double			u;
	double			v;
}					t_int_tr;

typedef struct		s_int_sph {
	t_vector		l;
	double			d;
	double			tca;
	double			thc;
	double			t0;
	double			t1;
}					t_int_sph;

typedef struct		s_make_col {
	t_cam			cam;
	double			len;
	double			cos;
	t_ray			pack;
	t_rt			tmp1;
	t_light			*c;
	t_color			tmp;
}					t_make_col;

typedef struct		s_int_cyl {
	t_ray			q;
	t_vector		x;
	t_vector		y;
	t_ray			pack;
	double			a;
	double			b;
	double			c;
}					t_int_cyl;

t_vector			vect_sum(t_vector a, t_vector b);
t_vector			vect_subtr(t_vector a, t_vector b);
double				vect_len(t_vector vector);
double				scalar_prod(t_vector a, t_vector b);
t_vector			normalize(t_vector vector);
t_vector			cross_prod(t_vector a, t_vector b);
t_matrix			look_at(t_cam cam);
t_vector			ray_direct(double x, double y, t_resol img, t_cam cam);
t_vector			vp_mult(t_vector v, double t);
t_color				color_sum(t_color color1, t_color color2);
t_color				pcolr_mult(double i, t_color color);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strchr(const char *s, int c);
int					inter_sph(t_ray pack, t_rt *rt, t_sphere *sph);
int					inter_plane(t_ray pack, t_rt *rt, t_plane pl);
int					inter_disk(t_ray pack, t_rt *rt, t_disk *disk);
int					inter_trian(t_ray pack, t_rt *rt, t_trian *trn);
int					inter_square(t_ray pack, t_rt *rt, t_square sq);
int					inter_self(t_ray pack, t_obj obj, t_rt *rt, void *near);
t_color				make_color(t_rt rt, t_light light, t_obj obj, t_cam cam);
int					intersection(t_ray pack, t_obj obj, t_rt *rt);
t_vector			change_basis(t_vector i, t_vector x, t_vector y,
						t_vector z);
t_vector			return_basis(t_vector i, t_vector x, t_vector y,
						t_vector z);
int					inter_cyl(t_ray ray, t_rt *rt, t_clndr *cyl);
int					ft_atod(char *str, double *d);
void				parser(int fd, t_scene *scene);
int					get_next_line(int fd, char **s);
int					pars_plane(char **line, t_scene *scene);
int					pars_sqr(char **line, t_scene *scene);
int					pars_sph(char **line, t_scene *scene);
int					pars_cyl(char **line, t_scene *scene);
int					pars_light(char **line, t_scene *scene);
void				err_exit(char *line);
void				exit_pars(void);
int					get_int(char **l, int comma);
double				get_double(char **l, int comma);
t_color				get_color(char **line);
t_vector			get_vector(char **line);
int					add_to_cycle(t_cam **c, t_cam cam);
t_vector			get_normal(char **line);
int					add_to_cycle(t_cam **c, t_cam cam);
t_vector			get_normal(char **line);
int					pars_ra(char **line, t_scene *scene);
int					pars_cam(char **line, t_scene *scene);
int					pars_trian(char **line, t_scene *scene);
double				solve_qd(double a, double b, double c);
t_vector			make_right(t_vector x);
int					search_disk(t_ray ray, t_rt *rt, t_clndr cyl);
void				write_head(int fd, t_resol r, int size);
int					save_to_bmp(int *arr, t_resol r);
void				return_free(t_scene *scene, int *arr);
void				free_light(t_light *light);
void				free_trian(t_trian *trian);
void				free_sphere(t_sphere *sphere);
void				free_square(t_square *square);
void				free_clndr(t_clndr *clndr);
int					paint(int *arr, t_scene *scene, t_data *img, t_vars *v);
int					key_stuff(int key_num, t_stuff *a);
int					cam_change(int keycode, t_stuff *p);
int					cross_but(void *ptr);
int					ft_close(int keycode);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
int					create_trgb(t_color *color);
int					correct_filename(char *str);
int					correct_arg(int argc, char **argv);
void				pure_hatred(char *c, int n, char **line);
int					is_end(char *line);
#endif
