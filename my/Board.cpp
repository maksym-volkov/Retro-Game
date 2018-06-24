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

#include "Board.hpp"

// struct
// {
//     Board::vec2i;
//     char disp_char;
// }   player;

Board::Board(void)
{
	this->wnd = initscr();
    cbreak();
    noecho();
    clear();
    refresh();

    keypad(wnd, true);

    nodelay(wnd, true);

    curs_set(0);

    if(!has_colors()) {
        endwin();
        printf("ERROR: Terminal does not support color.\n");
        exit(1);
    }

    start_color();

    attron(A_BOLD);
    box(wnd, 0, 0);
    attroff(A_BOLD);

    this->init_status = 0;
}

Board::~Board(void)
{
	endwin();
}

void Board::run()
{
	struct winsize size;
	int in_char;
    Player player;
	Weapon weapon[15];
    bool exit_requested = false;
    // printf("%d rows, %d columns\n", size.ws_row, size.ws_col);

    while(1)
    {
		in_char = wgetch(wnd);

		// mvaddch(player.y, player.x, ' ');

		switch(in_char) {
            case 'q':
                exit_requested = true;
                break;
            case KEY_UP:
            case 'w':
                if (player.y > 10)
                    player.y -= 1;
                break;
            case KEY_DOWN:
            case 's':
                if (player.y < size.ws_row)
                    player.y += 1;
                break;
            case KEY_LEFT:
            case 'a':
                if (player.x > 0)
                    player.x -= 1;
                break;
            case KEY_RIGHT:
            case 'd':
                if (player.x < size.ws_col)
                    player.x += 1;
                break;
            case ' ':
            {
            	for (int cur = 0; cur < 15; cur++)
            	{
            		if (weapon[cur].exist == false)
            		{
                        // printf("%i\n", cur);
            			weapon[cur].exist = true;
            			weapon[cur].x = player.x;
            			weapon[cur].y = player.y - 1;
            			break ;
            		}
            		// break ;
            	}
            }
            default:
                break;
        }
        clear();
        // printf("%i %i\n", size.ws_row, size.ws_col);
        mvaddch(player.y, player.x, player.dispChar);
        // mvprintw(10, 10, (char*)size.ws_row);
        // clear();
        refresh();
        // mvprintw(player.y, player.x, "%C", L'2d1ffff');
        for (int cur = 0; cur < 15; cur++)
        {
            if (weapon[cur].exist == true)
            {
            	weapon[cur].y -= 1;
            	mvaddch(weapon[cur].y, weapon[cur].x, weapon[cur].dispChar);
            }
            if (weapon[cur].exist == true && weapon[cur].y < 0)
            {
            	weapon[cur].exist = false;
            }
        }
        refresh();

        if(exit_requested) break;

        usleep(10000);
        refresh();
    }
}
