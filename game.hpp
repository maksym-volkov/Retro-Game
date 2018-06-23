// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   game.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vpalyvod <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/05 19:15:56 by vpalyvod          #+#    #+#             //
//   Updated: 2017/11/05 19:15:57 by vpalyvod         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#ifndef GAME_HPP
# define GAME_HPP
#include <cstdint>
#include <string>
#include <ncurses.h>
#include <curses.h>
#include <sys/ioctl.h>
#include <iostream>
#include "Asteroid.hpp"
#include "Background.hpp"
#include "Player.hpp"
#include <unistd.h>


void	initialization(Player *player, Asteroid * ast);
int init();
void run();
void close();
void run_level2();

#endif
