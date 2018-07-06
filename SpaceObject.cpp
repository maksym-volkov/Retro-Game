// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SpaceObject.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/24 17:49:48 by sperkhun          #+#    #+#             //
//   Updated: 2018/06/24 17:49:48 by sperkhun         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "SpaceObject.hpp"

SpaceObject::SpaceObject(void) {

    pos.x = rand() % 78;
    pos.y = -(rand() % 17 + 1); 
}

SpaceObject::SpaceObject(const SpaceObject & src) {

	*this = src;
	
	return ;
}

SpaceObject::~SpaceObject(void) {

	return ;
}

SpaceObject & SpaceObject::operator=(SpaceObject const & raw) {

	if (this != &raw) {

		pos = raw.pos;
	}

	return *this;
}

void SpaceObject::update() {

    pos.y += 1;
}

vec SpaceObject::getPos() const {

    return pos;
}

void SpaceObject::setPos(vec np) {

	pos = np;
}
