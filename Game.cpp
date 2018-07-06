// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/23 18:19:00 by sperkhun          #+#    #+#             //
//   Updated: 2018/06/23 18:19:00 by sperkhun         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Game.hpp"
#include <unistd.h>

Game::Game() {
	setlocale(LC_ALL, "");
	initscr();
	cbreak();
	noecho();
	clear();
	refresh();
	curs_set(0);


	game_win = newwin(18, 78, 1, 1);
	main_win = newwin(24, 80, 0, 0);

	player = new Player(game_win, 10, 10, 'o');
	stars = new Enemies();
	asteroids = new Enemies();

	keypad(main_win, true);
	keypad(game_win, true);

	nodelay(main_win, true);
	nodelay(game_win, true);
	
	if (!has_colors()) {
		endwin();
		exit(1);
	}
	start_color();

	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLACK);

	return ;
}

Game::Game(const Game & src) {

	*this = src;
	
	return ;
}

Game::~Game(void) {

	delete player;
	delete stars;
	delete asteroids;
	endwin();
}

Game &	Game::operator=(Game const & raw) {

	if (this != &raw) {

		main_win = raw.main_win;
		game_win = raw.game_win;
		player = raw.player;
		stars = raw.stars;
		asteroids = raw.asteroids;
	}

	return *this;
}

void 	Game::run() {

	int		t = 0;
	int weaponCount = 0;
	int bossCount = 0;
	time_t	start;
	bool	g_o = false;
	Weapon weapon[15];
	Boss boss;
	

	
	wattron(main_win, A_BOLD);
	box(main_win, 0, 0);
	wattroff(main_win, A_BOLD);
	wmove(main_win, 19, 1);
	whline(main_win, '_', 78);
	
	wrefresh(main_win);
	
	while(!g_o) {

		if (t == 0)
			start = time(0);

		werase(game_win);
		int 	in_char;

		in_char = player->getMove(wgetch(main_win));
		if (in_char == 'q')
			break ;
		else if (in_char == ' ') {
			for (int cur = 0; cur < 15; cur++)
			{
				if (weapon[cur].exist == false)
 				{
					weapon[cur].exist = true;
					weapon[cur].x = player->xLoc;
					weapon[cur].y = player->yLoc - 1;
					break ;
				}
			}
		}
		
		SpaceObject* s1 = stars->getData();
		SpaceObject* s2 = asteroids->getData();


		if (t % 7 == 0)
			stars->update();
		for(int i = 0; i < 18; i++) {

			mvwaddch(game_win, s1[i].getPos().y, s1[i].getPos().x, '.');
		}
		if (t > 100 && t % 18 == 0)
			asteroids->update();
		for(int i = 0; i < 18; i++) {

			mvwaddch(game_win, s2[i].getPos().y, s2[i].getPos().x, '*');
			if (s2[i].getPos().y == player->yLoc && s2[i].getPos().x == player->xLoc) {
				vec p = {-1, rand() % 78};
            	s2[i].setPos(p);
				player->health -= 20;
			}
			for (int cur = 0; cur < 15; cur++)
            {
                if (weapon[cur].exist && weapon[cur].y - 1 == s2[i].getPos().y && weapon[cur].x == s2[i].getPos().x)
                {
                    vec a = {-1, rand() % 78};
                    s2[i].setPos(a);
                    weapon[cur].exist = false;
                    player->score += 10;
                    continue ;
                }
            }
		}
		player->display();
		for (int i = 0; i < 9; i++)
		{
			mvwprintw(game_win, boss.y, boss.x[i], "%lc", boss.dispChar[i]);
		}
		if (bossCount % 15 == 0)
		{
			if (boss.x[8] < 76 && !boss.yy)
			{
				for (int i = 0; i < 9; i++)
				{
					boss.x[i] += 1;
				}
			}
			else
			{
				boss.yy = true;
				for (int i = 0; i < 9; i++)
				{
					boss.x[i] += -1;
				}
				if (boss.x[0] == 1)
					boss.yy = false;
			}
		}
		for (int cur = 0; cur < 15; cur++)
            weapon[cur].clean();
        if (weaponCount % 5 == 0)
        {
            for (int cur = 0; cur < 15; cur++)
                weapon[cur].update();
            weaponCount = 0;
        }
        for (int cur = 0; cur < 15; cur++)
            if (weapon[cur].exist == true) {
            	wattron(game_win, COLOR_PAIR(4));
                mvwaddch(game_win, weapon[cur].y, weapon[cur].x, weapon[cur].dispChar);
                wattroff(game_win, COLOR_PAIR(4));
            }
		if (player->health <= 0)
			g_o = true;
		
		display_menu(start);

		wrefresh(main_win);
		wrefresh(game_win);

		t++;
		weaponCount += 1;
		bossCount += 1;
		if (g_o) {

			g_o = game_over();
			t = 0;
		}
		
		usleep(10000);
	}

}

void	Game::display_menu(time_t start) {

	int col;
	if (player->health <= 30)
		col = 4;
	else if (player->health <= 60 && player->health > 30)
		col = 3;
	else
		col = 2;
	wattron(main_win, COLOR_PAIR(col));
	wattron(main_win, A_BOLD);
	wmove(main_win, 20, 1);
	whline(main_win, ' ', 40);
	whline(main_win, '|', player->health / 10 * 4);
	mvwprintw(main_win, 21, 1, "HEALTH: %3d%%", player->health);
	wattron(main_win, A_BOLD);
	wattroff(main_win, COLOR_PAIR(col));

	wattron(main_win, COLOR_PAIR(5));
	wattron(main_win, A_BOLD);
	mvwprintw(main_win, 20, 60, "time:  %02d:%02d", (time(0) - start) / 60, (time(0) - start) % 60);
	wmove(main_win, 21, 60);
	whline(main_win, ' ', 19);
	mvwprintw(main_win, 21, 60, "score: %d", player->score);
	wattroff(main_win, A_BOLD);
	wattroff(main_win, COLOR_PAIR(5));


}

bool	Game::game_over(void) {

	int x = 33;
	int y = 7;
	bool game_over = true;

	wattron(game_win, COLOR_PAIR(4));
	wattron(game_win, A_BOLD);
	mvwprintw(game_win, y, x, "GAME OVER");
	mvwprintw(game_win, y + 2, x - 7, "Press SPACE to play again");
	mvwprintw(game_win, y + 4, x - 7, "Press Q to quite the game");
	wattron(game_win, A_BOLD);
	wattroff(game_win, COLOR_PAIR(4));

	while(1) {

		int c = wgetch(main_win);
		if (c == ' ') {
	
			game_over = false;
			player->health = 100;
			player->score = 0;
			werase(game_win);
			delete this->asteroids;
			this->asteroids = new Enemies();
			break;
		}
		else if (c == 'q')
			break ;

		wrefresh(game_win);
		// usleep(10000);
	}

	return game_over;
}