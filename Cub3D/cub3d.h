/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:41:11 by ichejra           #+#    #+#             */
/*   Updated: 2020/11/07 13:34:06 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "mlx.h"
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>

typedef struct		s_sprite
{
	int				*x;
	int				*y;
	double			sprt_x;
	void			*img;
	double			sprt_y;
	int				*texture;
	double			*zbuff;
	int				*sprt_ord;
	double			*sprt_dist;
	double			inv_det;
	double			trans_y;
	double			trans_x;
	int				s_sprtx;
	int				sprt_h;
	int				s_drawy;
	int				e_drawy;
	int				sprt_w;
	int				e_drawx;
	int				s_drawx;
	int				strip;
	int				dist;
	int				s_bpp;
	int				s_sl;
	int				s_en;
	int				sprtw;
	int				sprth;
	char			*spr;
	int				num;
}					t_sprite;

typedef struct		s_tex
{
	char			*tex_n;
	char			*tex_s;
	char			*tex_w;
	char			*tex_e;
	int				tex_er;
	int				tex_x;
	int				tex_y;
	int				texwidth;
	int				texheight;
}					t_tex;

typedef struct		s_bmp
{
	unsigned char	*img_bmp;
	size_t			index;
	size_t			size;
}					t_bmp;

typedef struct		s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				win_width;
	int				win_height;
	int				size;
}					t_win;

typedef struct		s_err
{
	int				alloc;
	int				index;
	int				count;
	int				jindex;
	int				r_index;
	int				f_index;
	int				c_index;
	int				e_index;
	int				w_index;
	int				n_index;
	int				so_index;
	int				s_index;
}					t_err;

typedef struct		s_struct
{
	t_err			err;
	t_win			win;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			camera_x;
	double			raydir_x;
	double			raydir_y;
	int				map_x;
	int				map_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	double			perpwalldist;
	double			old_dir_x;
	double			old_plane_x;
	double			plane_x;
	double			plane_y;
	double			movespeed;
	double			rotspeed;
	double			time;
	double			oldtime;
	int				x_step;
	int				y_step;
	int				hit;
	int				side;
	int				ln_height;
	int				draw_start;
	int				draw_end;
	double			wallx;
	double			step;
	double			tex_pos;
	long long int	color;
	int				*texture;
	int				*data;
	int				bpp;
	int				sl;
	int				e;
	void			*img;
	int				x;
	int				y;
	int				j;
	int				i_wdth;
	int				i_height;
	t_tex			tex;
	t_bmp			bmp;
	long long int	f_clr;
	long long int	c_clr;
	int				k;
	t_sprite		sprite;
	char			*ln;
	int				fd;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			er;
	int				r;
	int				g;
	int				b;
	char			**map;
	int				map_wid;
	int				map_hgt;
	int				index;
	int				save;
	int				check;
	int				lng;
	int				old_lng;
	int				ret;
}					t_struct;

void				sortsprites(t_struct *param);
void				sprites_loop(t_struct *param);
void				set_tex(t_struct *param);
void				tex_loop(t_struct *param);
void				f_and_c_clr(t_struct *param);
int					get_next_line(int fd, char **line);
size_t				ft_strlen(const char *s);
void				*ft_memmove(void *dst, const void *src, size_t len);
char				*ft_fstrjoin(char *s1, char *s2);
char				*ft_fstrjoin_c(char *s1, char const *s2, int c);
char				*ft_strchr(const char *s, int c);
void				line_loop(t_struct *param);
int					ft_save(t_struct *prm, char *filename);
int					check_save(char **argv, t_struct *param);
void				draw_map(t_struct *param);
int					key_press(int key, t_struct *param);
void				init_struct(t_struct *param);
void				get_res(t_struct *prm, char **ln);
void				handle_map(t_struct *prm);
void				floor_color(t_struct *prm, char **ln);
void				ceil_color(t_struct *prm, char **ln);
void				check_map_er(t_struct *prm, int i, int j);
void				check_map_er_sec(t_struct *prm, int i, int k);
void				check_map_len_thd(t_struct *prm, int i, int k);
void				store_map(t_struct *prm, char **ln);
void				skip_dig(char **ln);
void				skip_sp(char **ln);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
int					ft_isspace(int c);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *s1);
char				*ft_strtrim(char const *s1, char const *set);
void				ft_free(t_struct *prm);
void				sprite_loop(t_struct *param);
void				wall_hit(t_struct *param);
void				player_step(t_struct *prm);
void				error_man(t_struct *param);
void				get_tex(t_struct *prm);
void				err_man_missing_key(t_struct *prm);
void				check_double_key(t_struct *prm, char *ln);
void				alloc_fail(t_struct *prm);
void				check_unknown_char(t_struct *prm);
void				check_map_chars(t_struct *prm);

#endif
