// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemies.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/23 18:13:09 by sperkhun          #+#    #+#             //
//   Updated: 2018/06/23 18:13:10 by sperkhun         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ENEMIES_HPP
# define ENEMIES_HPP

# include <stdlib.h>
# include "SpaceObject.hpp"

class Enemies {

public:

	Enemies(void);
	Enemies(Enemies const & src);
	~Enemies(void);

	void			update(void);
	SpaceObject*	getData(void) const;
	Enemies&		operator=(Enemies const & raw);

private:

	SpaceObject*	obj;

};

#endif