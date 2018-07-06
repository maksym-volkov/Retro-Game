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

#ifndef BOSS_H
# define BOSS_H
# include "Game.hpp"
# include "Player.hpp"

class Boss
{
	public:
		Boss();
		Boss(Boss const & src);
		~Boss();
		Boss & operator=(Boss const & rhs);
		void	clean(void);
		void	drow(void);
		void	update(void);
		int		x[9];
		int		y;
		wchar_t	dispChar[9];
		bool	yy;
};

#endif
