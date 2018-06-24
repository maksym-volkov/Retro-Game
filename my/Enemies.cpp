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

#include "Enemies.hpp"

ObjectField::ObjectField(void) {

	obj = new SpaceObject[22];
}
void ObjectField::update() {
    // update existing objects
    srand(time(0) + clock());
    for(size_t i = 0; i < 22; i++) {
        if(obj[i].getPos().y > 22)
        {
        	vec2i p = {1, rand() % 80 + 1};
            obj[i].setPos(p);
        }
        obj[i].update();
    } 
}

SpaceObject* ObjectField::getData() const  { return obj; }

SpaceObject::SpaceObject(void) { pos.x = rand() % 80 + 1; pos.y = rand() % 21 + 1; }

void SpaceObject::update() { pos.y += 1; }

vec2i SpaceObject::getPos() const { return pos; }

void SpaceObject::setPos(vec2i np) { pos = np; }
