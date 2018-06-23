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

#ifndef WEAPON_H
# define WEAPON_H
# include "Board.hpp"

class Weapon
{
	public:
		Weapon();
		Weapon(Weapon const & src);
		~Weapon();
		Weapon & operator=(Weapon const & rhs);
		int		x;
		int		y;
		char	dispChar;
		bool	exist;
};

#endif
