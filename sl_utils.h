/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:48:53 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/07/01 19:10:47 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_UTILS_H
# define SL_UTILS_H

# define KEY_LEFT 	123
# define KEY_RIGHT	124
# define KEY_DOWN 	125
# define KEY_UP 	126
# define KEY_ESC	53
# define SPEED		3
# define MOVESPEED	4

# define WINDOW_NAME	"./so_long"
# define SPRITE_SIZE	32

# define KEY_PRESS		2
# define KEY_RELEASE	3
# define ON_DESTROY		17
# define VISIBILITY		15
# define EXPOSE			12
# define NOEXPOSE		14
# define FOCUSIN		9
# define FOCUSOUT		10

# define KEY_PRESS_MASK		1
# define KEY_RELEASE_MASK	2
# define NO_EVENT_MASK		0
# define EXPOSURE_MASK		15
# define FOCUS_MASK			21
# define VISIBILITY_MASK	16

enum e_direction
{
	down,
	left,
	right,
	up,
};

enum
{
	event_ending = -1,
	game_over = -1,
	error = 2,
	file_error = 3,
	map_char_error = 4,
};

typedef struct s_img
{
	void	*ptr;
	int		*pixels;
	int		mem;
	int		x;
	int		y;
	int		movements;
}	t_img;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map
{
	char	c;
	int		open;
	int		flag;
	t_point	pos;
}	t_map;

typedef struct s_counter
{
	int		empty;
	int		collectible;
	int		exit;
	int		start;
	int		movements;
	int		time;
}	t_counter;

typedef struct s_draw
{
	char	**map;
	int		height;
	int		length;
	int		size;
	char	*line;
	char	*temp;
}	t_draw;

typedef struct s_frames
{
	void	*frame0;
	void	*frame1;
	void	*frame2;
	void	*frame3;
	void	*frame4;
	void	*frame5;
}	t_frames;

typedef struct s_emydata
{
	int			direction;
	int			collectible;
	int			exit;
	int			start;
	int			movements;
	char		type;
	t_frames	enemy_a;
}	t_emydata;

typedef struct s_game
{
	void		*mlx_pointer;
	void		*window_pointer;
	t_counter	i;
	t_draw		plot;
	t_img		character;
	t_img		character_l;
	t_img		character_r;
	t_img		character_u;
	t_img		floor;
	t_img		wall;
	t_img		collect;
	t_img		goal;
	t_frames	goal_a;
	t_frames	down_a;
	t_frames	left_a;
	t_frames	right_a;
	t_frames	up_a;
	t_frames	collect_a;
	t_emydata	enemy;
	int			moving;
	int			exposed;
}	t_game;

#endif