// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Asteroid.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vpalyvod <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/05 19:14:43 by vpalyvod          #+#    #+#             //
//   Updated: 2017/11/05 19:14:44 by vpalyvod         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ASTEROID_H
# define ASTEROID_H
# include <iostream>
#include <cmath>

class Asteroid {
public:
    Asteroid(void);
    Asteroid(Asteroid const & src);
    ~Asteroid(void);
    Asteroid &  operator=( Asteroid const & rhs );
    int posx;
    int posy;
    char val;
};
class Blaster {
public:
    Blaster(void);
    Blaster(Blaster const & src);
    ~Blaster(void);
    Blaster &   operator=( Blaster const & rhs );
    int posx;
    int posy;
    char val;
    int fire;
};
class Boss {
public:
    Boss(void);
    Boss(Boss const & src);
    ~Boss(void);
    Boss &  operator=( Boss const & rhs );
    int posx;
    int posy;
    char val;
    int score;
};
#endif
