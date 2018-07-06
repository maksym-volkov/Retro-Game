// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/23 18:18:55 by sperkhun          #+#    #+#             //
//   Updated: 2018/06/23 18:18:55 by sperkhun         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAME_HPP
# define GAME_HPP
# include <ncurses.h>
# include <locale.h>
# include <string>
# include "Player.hpp"
# include "Enemies.hpp"
# include "Weapon.hpp"
# include "Boss.hpp"

class Game {

public:

	Game(void);
	Game(Game const & src);
	~Game(void);

	void	run(void);
	void	close(void);
	void	display_menu(time_t);
	// void	display_enemies(int t, Weapon weapon[], SpaceObject* s1, SpaceObject* s2);
	bool	game_over(void);
	Game &	operator=(Game const & raw);

private:

	WINDOW *	main_win;
	WINDOW *	game_win;
	Player *	player;
	Enemies *	stars;
	Enemies *	asteroids;
};

#endif