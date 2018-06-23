/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:33:16 by mvolkov           #+#    #+#             */
/*   Updated: 2018/06/18 15:33:16 by mvolkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_H
# define BOARD_H
# include <iostream>
# include <cstdlib>
# include <ncurses.h>
# include <unistd.h>
# include "Weapon.hpp"
# include <cstdint>
# include <string>
# include <curses.h>
# include <sys/ioctl.h>

class Board {

public:
	typedef struct
	{
		uint x;
		uint y;
	}		vec2ui;

	typedef struct
	{
		int x;
		int y;
	}		vec2i;

	Board(void);

	~Board(void);

	void run();

	int		init_status;
private:
	std::string name,
				type;
	WINDOW*		wnd;
};

#endif