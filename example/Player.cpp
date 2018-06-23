// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vpalyvod <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/05 19:15:35 by vpalyvod          #+#    #+#             //
//   Updated: 2017/11/05 19:15:36 by vpalyvod         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Player.hpp"
# include <iostream>

Player::Player(  void ){
    return;
}

Player::~Player ( void ) {
    return;
}

Player::Player(Player const & src) {
    this->posx = src.posx;
    this->posy = src.posy;
    this->disp_char = src.disp_char;
    this->hp = src.hp;
    this->score = src.score;
    this->boss_health = src.boss_health;
    return;
}

Player & Player::operator=(Player const & rhs) {
	this->posx = rhs.posx;
    this->posy = rhs.posy;
    return *this;
}
