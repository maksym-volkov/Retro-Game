// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SpaceObject.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/24 17:49:42 by sperkhun          #+#    #+#             //
//   Updated: 2018/06/24 17:49:43 by sperkhun         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SPACEOBJECT_HPP
# define SPACEOBJECT_HPP

# include <stdlib.h>

typedef	struct {

	int	y;
	int	x;
} vec;

class SpaceObject {

public:

	SpaceObject(void);
	SpaceObject(SpaceObject const & src);
	~SpaceObject(void);

	void			update(void);
	vec				getPos(void) const;
	void			setPos(vec);
	SpaceObject&	operator=(SpaceObject const & raw);

private:

	vec	pos;

};

#endif