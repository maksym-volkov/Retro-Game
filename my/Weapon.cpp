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

#include "Weapon.hpp"

Weapon::Weapon(void)
{
	this->exist = false;
	this->dispChar = '|';
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}

Weapon::Weapon(Weapon const & src)
{
	this->x = src.x;
	this->y = src.y;
	this->dispChar = src.dispChar;
}

Weapon & Weapon::operator=(Weapon const & rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;
	this->dispChar = rhs.dispChar;
	return (*this);
}
