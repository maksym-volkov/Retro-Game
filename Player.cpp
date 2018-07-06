// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/23 12:44:37 by sperkhun          #+#    #+#             //
//   Updated: 2018/06/23 12:44:37 by sperkhun         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Player.hpp"

Player::Player(void): xLoc(10), yLoc(10), health(100), score(0), chr('o'), curWin(initscr()) {

	getmaxyx(curWin, yMax, xMax);
	return ;
}

Player::Player(const Player & src) {

	*this = src;
	
	return ;
}

Player::Player(WINDOW * win, int y, int x, char c){

	curWin = win;
	yLoc = y;
	xLoc = x;
	health = 100;
	score = 0;
	getmaxyx(curWin, yMax, xMax);
	chr = c;

	return ;
}

Player::~Player(void) {

	return ;
}

Player &	Player::operator=(Player const & raw) {

	if (this != &raw) {

		yLoc = raw.yLoc;
		xLoc = raw.xLoc;
		curWin = raw.curWin;
		health = raw.health;
		score = raw.score;
		chr = raw.chr;
	}

	return *this;
}

void	Player::moveUp(void) {

	yLoc--;
	if (yLoc < 0)
		yLoc = 0;
}

void	Player::moveDown(void) {

	yLoc++;
	if (yLoc > yMax - 1)
		yLoc = yMax - 1;
}

void	Player::moveLeft(void) {

	xLoc--;
	if (xLoc < 0)
		xLoc = 0;
}

void	Player::moveRight(void) {

	xLoc++;
	if (xLoc > xMax - 1)
		xLoc = xMax - 1;
}

int		Player::getMove(int move) {

	switch(move) {

		case KEY_UP:
			moveUp();
			break;
		case KEY_DOWN:
			moveDown();
			break;
		case KEY_LEFT:
			moveLeft();
			break;
		case KEY_RIGHT:
			moveRight();
			break;
		default:
			break;
	}
	return move;
}

void	Player::display(void) {

	wattron(curWin, A_BOLD);
	mvwaddch(curWin, yLoc, xLoc, chr);
	wattroff(curWin, A_BOLD);
}



