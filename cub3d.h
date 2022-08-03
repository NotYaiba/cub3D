/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 06:01:37 by melkarmi          #+#    #+#             */
/*   Updated: 2020/03/10 23:44:11 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# define N 10
# define SPEED 20.0
# define COLSIZE 64
# define ROTSPEED 3.0
# define EM "Error\n in map"
# define ER "Error\n in R"
# define EW "Error\n in W"
# define EN "Error\n in N"
# define ES "Error\n in S"
# define EE "Error\n in E"
# define EF "Error\n"
# define EC "Error\n"
# define ESP "Error\n in Sp"
# define E "Error\n"
# define O "out\n"
# define WHF data->wallhorsfound
# define WVF data->wallvertfound
# define HHX data->horzwallhitx
# define HHY data->horzwallhity
# define VHX  data->vertwallhitx
# define VHY data->vertwallhity
# define HD data->horzdistance
# define VD  data->vertdistance
# define PRA data->player.rotangle
# define D  data->distance
# define RX  data->file.l3erd
# define RY  data->file.tol
# define FOV data->player.view
# define CR data->file.cieling_r
# define CG data->file.cieling_g
# define CB data->file.cieling_b
# define FR data->file.floor_r
# define FG data->file.floor_g
# define FB data->file.floor_b
# define SHF data->sprites[sp].hors_found
# define SVF data->sprites[sp].vert_found
# define SHX data->sprites[sp].xhor
# define SHY data->sprites[sp].yhor
# define HU data->sprites[sp].helperu
# define H data->sprites[sp].helper
# define SVX data->sprites[sp].xvert
# define SVY data->sprites[sp].yvert
# define SD data->sprites[sp].dist
# define PX data->posx
# define PY data->posy
# define TOPX data->sprites[sp].tx
# define TOPY data->sprites[sp].ty
# define CX data->sprites[sp].cenx
# define CY data->sprites[sp].ceny
# define HX data->sprites[sp].hitx
# define HY data->sprites[sp].hity
# define BUFFER_SIZE 100

char				**g_map;
int					g_dataa[7];
int					g_line;
int					g_col;
char				**g_file;
int					g_screen;
int					g_i;
int					g_j;
int					g_c;
int					g_h;
int					g_v;
char				*g_files;
char				*g_nopath;
char				*g_sopath;
char				*g_wepath;
char				*g_eapath;
char				*g_spath;
int					g_conter;
int					g_nb_sprites;
char				**g_mp;
int					g_max;
int					g_p;
int					g_m;
int					g_f;
int					g_no;
int					g_so;
int					g_e;
int					g_w;
int					g_s;
int					g_y;
int					g_x;
int					g_cnt;
int					g_t;
char				**g_lihbity;
char				**g_li;
char				**g_lo;

typedef struct		s_player
{
	double			x;
	double			y;
	double			rotangle;
	double			view;
	double			up;
	double			down;
	double			right;
	double			left;
}					t_player;

typedef struct		s_rgb
{
	double			r;
	double			g;
	double			b;
}					t_rgb;

typedef struct		s_sprites
{
	double			x;
	double			y;
	double			dist;
	double			angle;
	double			xvert;
	double			yvert;
	double			xhor;
	double			yhor;
	double			h;
	int				helper;
	int				helperu;
	double			hitx;
	double			hity;
	double			horsdist;
	double			vertdist;
	double			vert_found;
	double			hors_found;
	int				tx;
	int				ty;
	double			cenx;
	double			ceny;
	int				is_there;
	int				texture_x;
	int				texture_y;
	double			distcenter;
}					t_sprites;

typedef struct		s_file
{
	int				tol;
	int				l3erd;
	int				floor_r;
	int				floor_g;
	int				floor_b;
	int				cieling_r;
	int				cieling_g;
	int				cieling_b;
	int				r;
	int				no;
	int				so;
	int				we;
	int				ea;
	int				s;
	int				c;
	int				f;
	int				cnt;
}					t_file;

typedef struct		s_data
{
	void			*texture;
	void			*texturen;
	void			*textures;
	void			*texturew;
	void			*texturee;
	void			*texturesp;
	void			*image;
	int				*img_data;
	int				*tex_datan;
	int				*tex_datas;
	int				*tex_dataw;
	int				*tex_datae;
	int				*tex_datasp;
	int				x;
	int				y;
	void			*str;
	void			*ptr;
	double			posx;
	double			posy;
	double			ray;
	int				j;
	double			wallhitx;
	double			wallhity;
	double			distance;
	double			itrx;
	double			itry;
	double			stepx;
	double			stepy;
	double			rayangle;
	double			nexthorx;
	double			nexthory;
	int				wallhorsfound;
	int				wallvertfound;
	double			nextverx;
	double			nextvery;
	double			vertwallhitx;
	double			vertwallhity;
	double			horzwallhitx;
	double			horzwallhity;
	double			horzdistance;
	double			vertdistance;
	int				numr;
	double			wall_thicc;
	double			window_width;
	double			window_height;
	double			cor_distance;
	double			dis_progection;
	double			wallheight;
	double			toppixle;
	double			botpixle;
	int				hit_side;
	int				bpp;
	int				size_l;
	int				endian;
	int				firstcol;
	int				hit_side2;
	t_player		player;
	t_file			file;
	t_sprites		*sprites;
	t_rgb			rgb;
	int				height;
	int				width;
	int				width_in_bytes;
	uint16_t		bitcount;
	uint32_t		imagesize;
	uint32_t		bisize;
	uint32_t		bfffsits;
	uint32_t		filesize;
	uint16_t		biplanes;
	unsigned char	header[54];
	unsigned char	*buf;
}					t_data;

size_t				ft_strlcpy(char *dst, char *src, size_t s);
void				file_free(void);
char				**ft_split2(char *s, char c);
t_rgb				colorconverter(t_data *data, int hexvalue);
void				get_screen(t_data *data, unsigned char *buf);
void				sprite(t_data *data);
void				hadik(t_data *data, double x, double y);
void				ft_freee(char ***tab);
int					count(int fd);
void				map(int n, t_data *data);
int					ft_strlen(char *s);
int					ft_putstr(char *s);
void				error(int l);
void				khikhi(t_data *data);
void				sprites_textures(t_data *data, int sp);
int					is_wall2(int x, int y);
void				init(t_data *data);
void				init2(t_data *data);
void				player(int x, int y, t_data *data);
char				**ft_split(char *str, char c);
int					get_next_line(int fd, char **line);
char				*ft_strchr(char *str, int c);
char				*ft_strjoin(char *s1, char *s2);
void				*ft_calloc(size_t c, size_t size);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strdup(char *ssrc);
void				squar(t_data *data);
void				drawcircle(int radius, t_data *data);
void				play(void);
int					deal_key(int key, t_data *data);
void				ft_putchar(char c);
int					is_wall(int x, int y);
void				draw_line(t_data *data, int color);
void				draw_rays(t_data *data);
void				drawline(t_data *data);
double				new_angle(double angle);
void				hrays(t_data *data, double angle, int col);
void				set_angle_direc(t_data *data, double angle);
double				distance(t_data *data, double x1, double y1);
void				sethorz(t_data *data, double angle);
void				setvert(t_data *data, double angle);
void				filecontrole(char **str, t_data *data);
int					count_table(char **str);
int					check_walls(char *str);
char				*ft_strtrim(char *s1, char const *set);
char				*ft_substr(const char *s, unsigned int start, size_t len);
int					check_walls2(char *str);
void				get_info(t_data *data, char *line);
void				get_file(int fd);
int					check_errors(t_data *data);
int					check_maps(t_data *data, int n);
void				get_map(int l, int fd);
int					file(t_data *data);
void				rendering(t_data *data, int col);
void				raycasting_math(t_data *data);
void				get_vert_hit(t_data *data);
void				get_hors_hit(t_data *data);
void				handle_r(char **str, t_data *data);
void				handle_no(char **str, t_data *data);
void				handle_so(char **str, t_data *data);
void				handle_ea(char **str, t_data *data);
void				handle_we(char **str, t_data *data);
void				handle_c(char **str, t_data *data);
void				handle_s(char **str, t_data *data);
void				handle_f(char **str, t_data *data);
int					ft_isdigit(char *cc);
void				get_image_text(t_data *data);
int					renderin_walls(t_data *data, int i, int col);
void				sprites_math(t_data *data, int col, int c);
double				distance2(double x, double y, double x1, double y1);
int					save(t_data *data);
int					is_sprite(int x, int y);
void				locate_player(t_data *data, double angle);
void				rendering_sprites(t_data *data, int col, int c);
unsigned int		rgb3(unsigned int r, unsigned int g, unsigned int b);
void				mem(t_data *data);
void				initsprites(t_data *data, double *s, int d);
void				mem(t_data *data);
int					cama(char *s, char c);
int					ft_error(t_data *data, char *c);
void				get_cieling(char **r, t_data *data);
void				sortdist(t_data *data);
void				get_floor(char **s, t_data *data);
void				get_tex(t_data *data);
int					creat_screen(t_data *data, unsigned char *buf);
int					key_destroy(int key, t_data *data);
int					ft_atoi(const char *s);
void				screenshot(t_data *data);
int					ft_strcmp(const char *s_1, const char *s_2);
#endif
