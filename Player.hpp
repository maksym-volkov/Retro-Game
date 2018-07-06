// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/23 12:44:32 by sperkhun          #+#    #+#             //
//   Updated: 2018/06/23 12:44:32 by sperkhun         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <ncurses.h>

class Player {

public:

	int		xLoc;
	int		yLoc;
	int		health;
	int		score;

	Player(void);
	Player(WINDOW * win, int y, int x, char c);
	Player(Player const & src);
	~Player(void);

	void	moveUp(void);
	void	moveDown(void);
	void	moveLeft(void);
	void	moveRight(void);
	int		getMove(int move);
	void	display(void);
	Player&	operator=(Player const & raw);

private:

	int		xMax;
	int		yMax;
	char	chr;
	WINDOW	* curWin;

};

#endif