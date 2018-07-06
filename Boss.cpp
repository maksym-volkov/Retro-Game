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

#include "Boss.hpp"

Boss::Boss(void)
{
	this->yy = false;
	this->dispChar[0] = L'¯';
	this->dispChar[1] = '\\';
	this->dispChar[2] = '_';
	this->dispChar[3] = '(';
	this->dispChar[4] = L'ツ';
	this->dispChar[5] = ')';
	this->dispChar[6] = '_';
	this->dispChar[7] = '/';
	this->dispChar[8] = L'¯';
	this->y = 0;
	this->x[0] = 0;
	this->x[1] = 1;
	this->x[2] = 2;
	this->x[3] = 3;
	this->x[4] = 4;
	this->x[5] = 5;
	this->x[6] = 6;
	this->x[7] = 7;
	this->x[8] = 8;
	return ;
}

Boss::~Boss(void)
{
	return ;
}

Boss::Boss(Boss const & src)
{
	this->y = src.y;
}

Boss & Boss::operator=(Boss const & rhs)
{
	this->y = rhs.y;
	return (*this);
}

void	Boss::clean(void)
{
	// mvaddch(this->y, this->x, ' ');
}

void	Boss::drow(void)
{
	// mvaddch(this->y, this->x, this->dispChar);
}

void	Boss::update(void)
{
    // if (this->exist == true)
    // {
    //     this->y -= 1;
    // }
    // if (this->exist == true && this->y < 2)
    // {
    //     this->exist = false;
    // }
}
