// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Background.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vpalyvod <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/05 19:14:54 by vpalyvod          #+#    #+#             //
//   Updated: 2017/11/05 19:14:55 by vpalyvod         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Background.hpp"
# include <iostream>

Background::Background(  void ){
    return;
}

Background::~Background ( void ) {
    return;
}
Background::Background(Background const & src) {
    this->posx = src.posx;
    this->posy = src.posy;
    this->val = src.val;
    return;
}

Background & Background::operator=(Background const & rhs) {
	this->posx = rhs.posx;
    this->posy = rhs.posy;
    return *this;
}
