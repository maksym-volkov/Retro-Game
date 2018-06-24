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
	this->main_win = initscr();
    cbreak();
    noecho();
    clear();
    refresh();

    game_win = newwin(18, 78, 1, 1);
    main_win = newwin(24, 80, 0, 0);

    keypad(main_win, true);
    keypad(game_win, true);

    nodelay(main_win, true);
    nodelay(game_win, true);

    curs_set(0);

    if(!has_colors()) {
        endwin();
        printf("ERROR: Terminal does not support color.\n");
        exit(1);
    }

    start_color();

    attron(A_BOLD);
    box(main_win, 0, 0);
    attroff(A_BOLD);

    this->init_status = 0;
    this->game_over = false;
}

Board::~Board(void)
{
	endwin();
}

void Board::run()
{
    ObjectField stars;
    ObjectField asteroids;
    int weaponCount = 0;
    int starsCount = 0;
	int in_char;

    wattron(main_win, A_BOLD);
    box(main_win, 0, 0);
    wattroff(main_win, A_BOLD);
    wmove(main_win, 19, 1);
    whline(main_win, '-', 78);

    wrefresh(game_win);
    wrefresh(main_win);
    Player player;
	Weapon weapon[15];
    bool exit_requested = false;
    while(!game_over)
    {
		in_char = wgetch(main_win);
        werase(game_win);

		// mvaddch(player.y, player.x, ' ');

		switch(in_char) {
            case 'q':
                exit_requested = true;
                break;
            case KEY_UP:
            case 'w':
                if (player.y > 1)
                    player.y -= 1;
                break;
            case KEY_DOWN:
            case 's':
                if (player.y < 18)
                    player.y += 1;
                break;
            case KEY_LEFT:
            case 'a':
                if (player.x > 1)
                    player.x -= 1;
                break;
            case KEY_RIGHT:
            case 'd':
                if (player.x < 78)
                    player.x += 1;
                break;
            case ' ':
            {
            	for (int cur = 0; cur < 15; cur++)
                {
                    if (weapon[cur].exist == false)
                    {
                        weapon[cur].exist = true;
                        weapon[cur].x = player.x;
                        weapon[cur].y = player.y - 1;
                        break ;
                    }
                }
            }
            default:
                break;
        }
        player.display();
        refresh();

        SpaceObject* s1 = stars.getData();
        SpaceObject* s2 = asteroids.getData();
        if (starsCount > 100 && starsCount % 7 == 0)
            stars.update();
        for(int i = 0; i < 18; i++) {

            mvwaddch(game_win, s1[i].getPos().y, s1[i].getPos().x, '.');
        }
        if (starsCount > 100 && starsCount % 18 == 0)
            asteroids.update();
        for(int i = 0; i < 18; i++) {

            mvwaddch(game_win, s2[i].getPos().y, s2[i].getPos().x, '*');
            if (s2[i].getPos().y == player.y - 1 && s2[i].getPos().x == player.x - 1)
                game_over = true;
            for (int cur = 0; cur < 15; cur++)
            {
                if (weapon[cur].exist && weapon[cur].y - 1 == s2[i].getPos().y && weapon[cur].x - 1 == s2[i].getPos().x)
                {
                    vec2i a = {-1, rand() % 78};
                    s2[i].setPos(a);
                    weapon[cur].exist = false;
                    continue ;
                }
            }
        }
        refresh();
        for (int cur = 0; cur < 15; cur++)
            weapon[cur].clean();
        if (weaponCount % 5 == 0)
        {
            for (int cur = 0; cur < 15; cur++)
                weapon[cur].update();
            weaponCount = 0;
        }
        for (int cur = 0; cur < 15; cur++)
            if (weapon[cur].exist == true)
                weapon[cur].drow();

        if(exit_requested) break;
        weaponCount += 1;
        starsCount += 1;
        usleep(10000);
        wrefresh(main_win);
        wrefresh(game_win);
        refresh();
    }
}
