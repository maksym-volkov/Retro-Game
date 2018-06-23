// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vpalyvod <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/05 19:15:44 by vpalyvod          #+#    #+#             //
//   Updated: 2017/11/05 19:15:45 by vpalyvod         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#ifndef PLAYER_HPP
# define PLAYER_HPP

class Player {

public:
	Player(void);
	Player(Player const & src);
	~Player(void);
	Player &	operator=( Player const & rhs );
	int posx;
	int posy;
	char disp_char;
	int hp;
	int score;
	int boss_health;

};

#endif
