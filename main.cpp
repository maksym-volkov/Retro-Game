// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/23 11:37:23 by sperkhun          #+#    #+#             //
//   Updated: 2018/06/23 11:37:24 by sperkhun         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <ncurses.h>
#include "Game.hpp"
#include <stdlib.h>

int		main() {

	Game	g;

	g.run();
	return 0;
}