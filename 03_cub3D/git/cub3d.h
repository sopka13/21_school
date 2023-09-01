/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 18:07:17 by eyohn             #+#    #+#             */
/*   Updated: 2021/02/13 18:07:20 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define MAXLNAME 256
# define VI_GRAD 66
# define ZOOM 20
# define STEP_VECT 0.125
# define M_PI 3.14159265358979323846
# define WALL '1'
# define SPASE '0'
# define SPRITE '2'
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include <errno.h>
# include <string.h>
# include <math.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct	s_leit
{
	double		x_fict;
	double		y_fict;
	int			i1;
	int			i2;
	double		x_b;
	double		y_b;
	double		x_c;
	double		y_c;
}				t_leit;

typedef struct	s_vect
{
	double		i;
	int			e;
	int			x1;
	double		cs2;
	double		sn2;
	double		dy;
	double		dx;
	double		dxstart1;
	double		dystart1;
	double		lentp;
	double		s;
	double		s1;
	double		s2;
	double		alfa_x1;
	double		alfa_x2;
	double		alfa_y1;
	double		alfa_y2;
	double		nul;
	double		coord_1;
	double		coord_2[100];
	double		k;
	double		k_s[100];
	double		s_lent[100];
	double		wall_heig;
}				t_vect;

typedef struct	s_move
{
	int			forward;
	int			back;
	int			left;
	int			right;
	int			cam_l;
	int			cam_r;
}				t_move;

typedef struct	s_cam
{
	int			x_max;
	int			y_max;
	int			x_min;
	int			y_min;
	double		x_start;
	double		y_start;
	int			alfa;
}				t_cam;

typedef struct	s_data
{
	int			save;
	char		*map_name;
	int			map_fd;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	int			cel;
	int			flor;
	int			rx;
	int			ry;
	char		**map;
	int			szmap;
	char		plor;
	int			fict;
	int			i1;
	t_cam		cam;
}				t_data;

typedef struct	s_texture
{
	void		*img;
	void		*addr;
	int			bpp;
	int			ll;
	int			endian;
	int			width;
	int			height;
}				t_texture;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			bpp;
	int			ll;
	int			endian;
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
	t_texture	sprite;
	t_move		move;
	t_data		*sflag;
}				t_mlx;

typedef struct	s_dt
{
	double		coord;
	double		wall;
}				t_dt;

int				ft_isdigit(int c);
char			*ft_strtrim(char *s1, const char *set);
char			*ft_substr(char *s, unsigned int start, size_t len);
int				get_next_line(int fd, char **line);
int				ft_free_gnl(char *a);
void			*ft_calloc(size_t n, size_t size);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
int				ft_exit(t_mlx *mlx);
int				ft_free_2(char **line, int i);
char			*ft_strputend(char *a, char b);
size_t			ft_strlen(const char *s);
int				print_error(char *str);
char			*ft_strdup(const char *src);
void			init_mlx(t_mlx *mlx, t_data *sflag);
int				ft_get_texture(t_texture *a, t_mlx *mlx, char *line);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
void			init_sflag(t_data *sflag);
int				ft_save_flag(char *a, t_data *sflag);
int				ft_name_map(int argc, char **argv, t_data *sflag);
int				ft_fileheight(int fd);
int				ft_no_flag(char *line, t_data *sflag, t_mlx *mlx);
int				ft_so_flag(char *line, t_data *sflag, t_mlx *mlx);
int				ft_s_flag(char *line, t_data *sflag, t_mlx *mlx);
int				ft_we_flag(char *line, t_data *sflag, t_mlx *mlx);
int				ft_ea_flag(char *line, t_data *sflag, t_mlx *mlx);
int				ft_atoi_n(char *str, int *rgb, int n);
int				ft_create_trgb(int t, int r, int g, int b);
int				ft_c_flag(char *line, t_data *sflag);
int				ft_f_flag(char *line, t_data *sflag);
int				ft_r_flag(char *line, t_data *sflag);
int				ft_map_flag(char *line, t_data *sflag);
int				ft_plor_emul(char a);
void			ft_fict_1(t_data *sflag, int i, int k);
int				ft_fict_2(t_data *sflag, int i, int k);
void			ft_fict_3(t_data *sflag, int i, int k);
int				ft_prc_map_3(t_data *sflag);
int				ft_first_flags(t_mlx *mlx, t_data *sflag, char *a, int chr);
char			*ft_strdup_2(char *src, int k);
int				ft_prc_map_4(t_data *sflag);
int				ft_prc_map_2(int heig, char **line, t_data *sflag, t_mlx *mlx);
int				ft_prc_map(t_data *sflag, t_mlx *mlx);
int				ft_valid_map(t_data *sflag, t_mlx *mlx);
int				ft_ac_launch(int argc, char **argv, t_data *sflag, t_mlx *mlx);
void			ft_get_settings(t_data *sflag, t_mlx *mlx);
int				ft_key_press(int keycode, t_mlx *mlx);
int				ft_key_release(int keycode, t_mlx *mlx);
void			my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
void			ft_move_forward(t_mlx *mlx);
void			ft_move_back(t_mlx *mlx);
void			ft_move_left(t_mlx *mlx);
void			ft_move_right(t_mlx *mlx);
void			ft_move_cam_r(t_mlx *mlx);
void			ft_move_cam_l(t_mlx *mlx);
int				ft_move(t_mlx *mlx);
double			ft_grad(t_mlx *mlx, double i);
double			ft_alfa(t_mlx *mlx, int d);
int				ft_colour(t_mlx *mlx, int i, int e, t_dt data);
int				ft_round_x_s1(double x, int alfa, int e);
int				ft_round_x_s2(double x, int alfa, int e);
int				ft_round_y_s1(double y, int alfa, int e);
int				ft_round_y_s2(double y, int alfa, int e);
double			ft_cross(t_mlx *mlx, t_leit *leit);
int				ft_pr_vec1(t_mlx *mlx, double s1, double i, int e);
int				ft_pr_vec2(t_mlx *mlx, double s2, double i, int e);
void			ft_destr_img(t_mlx *mlx);
void			ft_init_vect(t_vect *vect);
void			ft_dxystart(t_mlx *mlx, t_vect *vect);
void			ft_dxy(t_mlx *mlx, t_vect *vect);
void			ft_vect_start(t_mlx *mlx, t_vect *vect);
void			ft_vect_start_1(t_mlx *mlx, t_vect *vect);
int				ft_leit_1(t_mlx *mlx, t_vect *vect);
void			ft_xym(t_mlx *mlx, t_vect *vect, double *x_m, double *y_m);
void			ft_xyfict(t_mlx *mlx, t_vect *vect, t_leit *leit, double om);
int				ft_leit_2(t_mlx *mlx, t_vect *vect, int i1, int i2);
void			ft_leit_vect(t_mlx *mlx, t_vect *vect);
int				ft_condition_1(t_mlx *mlx, t_vect *vect, int i);
int				ft_condition_2(t_mlx *mlx, t_vect *vect, int i);
void			ft_a(t_mlx *mlx, t_vect *vect);
void			ft_b(t_mlx *mlx, t_vect *vect);
void			ft_print_line(t_mlx *mlx, t_vect *vect);
void			ft_char(unsigned char *start, int value);
int				ft_header(int fd, int filesize, t_mlx *mlx);
int				ft_pixel(t_mlx *mlx, int x, int y);
int				ft_write_bmp(int fd, t_mlx *mlx);
int				ft_save(t_mlx *mlx);
int				ft_print_vectors(t_mlx *mlx);
int				ft_render(t_mlx *mlx);
int				main(int argc, char **argv);
void			ft_free_map_flag(char **map, int szmap);
int				ft_return_colour(t_mlx *mlx, t_dt data);
void			ft_vect_s1(t_vect *vect, double *i1);
void			ft_alfa_bc(t_leit *leit, double x_m, double y_m, double alf_b);
void			ft_print_init(t_mlx *mlx, t_vect *vect);
void			ft_save_1(t_mlx *mlx);
int				ft_if(char **argv, t_data *sflag, int i);
int				ft_free_3(char **line, int str, int heig);

#endif
