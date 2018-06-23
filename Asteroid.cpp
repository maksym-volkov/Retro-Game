// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Asteroid.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vpalyvod <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/05 19:14:36 by vpalyvod          #+#    #+#             //
//   Updated: 2017/11/05 19:14:37 by vpalyvod         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Asteroid.hpp"
# include <iostream>
Asteroid::Asteroid(  void ){
    return;
}
Asteroid::~Asteroid ( void ) {
    return;
}
Asteroid::Asteroid(Asteroid const & src) {
    this->posx = src.posx;
    this->posy = src.posy;
    this->val = src.val;
    return;
}

Asteroid & Asteroid::operator=(Asteroid const & rhs) {
	this->posx = rhs.posx;
    this->posy = rhs.posy;
    return *this;
}
Blaster::Blaster(  void ){
    return;
}
Blaster::~Blaster ( void ) {
    return;
}
Blaster::Blaster(Blaster const & src) {
    this->posx = src.posx;
    this->posy = src.posy;
    this->val = src.val;
    this->fire = src.fire;
    return;
}
Blaster & Blaster::operator=(Blaster const & rhs) {
	this->posx = rhs.posx;
    this->posy = rhs.posy;
    return *this;
}
Boss::Boss(  void ){
    return;
}
Boss::~Boss ( void ) {
    return;
}
Boss::Boss(Boss const & src) {
    this->posx = src.posx;
    this->posy = src.posy;
    this->val = src.val;
    this->score = src.score;
    return;
}
Boss & Boss::operator=(Boss const & rhs) {
	this->posx = rhs.posx;
    this->posy = rhs.posy;
    return *this;
}


