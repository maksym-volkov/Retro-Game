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

#include "Player.hpp"

Player::Player(void)
{
	this->dispChar = '0';
	this->x = 10;
	this->y = 18;
	return ;
}

Player::~Player(void)
{
	return ;
}

Player::Player(Player const & src)
{
	this->x = src.x;
	this->y = src.y;
	this->dispChar = src.dispChar;
}

Player & Player::operator=(Player const & rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;
	this->dispChar = rhs.dispChar;
	return (*this);
}

void	Player::display(void)
{
	mvaddch(this->y, this->x, this->dispChar);
}