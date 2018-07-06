// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemies.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/23 18:13:16 by sperkhun          #+#    #+#             //
//   Updated: 2018/06/23 18:13:16 by sperkhun         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Enemies.hpp"
#include <ctime>

Enemies::Enemies(void) {

	obj = new SpaceObject[18];
}

Enemies::Enemies(const Enemies & src) {

	*this = src;
	
	return ;
}

Enemies::~Enemies(void) {

    delete [] obj;
}

Enemies & Enemies::operator=(Enemies const & raw) {

	if (this != &raw) {

		obj = raw.obj;
	}

	return *this;
}

void Enemies::update() {

	srand(time(0) + clock());
	for(size_t i = 0; i < 18; i++) {
		if(obj[i].getPos().y > 17)
		{
			vec p = {0, rand() % 78};
			obj[i].setPos(p);
		}
		else
			obj[i].update();
	}
}

SpaceObject* Enemies::getData() const {

	return obj;
}
