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

#ifndef ENEMIES_H
# define ENEMIES_H
# include "Board.hpp"
# include "Player.hpp"

typedef	struct {

	int	y;
	int	x;
} vec2ui;

typedef	struct {

	int	y;
	int	x;
} vec2i;

class SpaceObject {

public:

	SpaceObject(void);
	// SpaceObject(SpaceObject const & src);
	// ~SpaceObject(void);

	void	update(void);
	vec2i	getPos(void) const;
	void	setPos(vec2i);

private:

	vec2i	pos;

};

class ObjectField {

public:

	ObjectField(void);
	// SpaceObject(SpaceObject const & src);
	// ~SpaceObject(void);

	void			update(void);
	SpaceObject*	getData(void) const;

private:

	SpaceObject*	obj;

};

#endif
