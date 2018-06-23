// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Background.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vpalyvod <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/05 19:14:59 by vpalyvod          #+#    #+#             //
//   Updated: 2017/11/05 19:15:00 by vpalyvod         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#ifndef BACKGROUND_H
# define BACKGROUND_H

#include "game.hpp"
# include <iostream>
#include <cmath>

class Background {

public:
	Background(void);
    Background(Background const & src);
    ~Background(void);
    Background &  operator=( Background const & rhs );
	int posx;
	int posy;
	char val;

};

#endif
