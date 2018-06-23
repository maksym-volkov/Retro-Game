// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   game.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vpalyvod <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/05 19:15:51 by vpalyvod          #+#    #+#             //
//   Updated: 2017/11/05 19:15:52 by vpalyvod         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#include "game.hpp"

WINDOW* wnd;

int init() {
  wnd = initscr();
  cbreak();
  noecho();
  keypad(wnd, true);
  curs_set(0);
  if(!has_colors())
    {
      endwin();
      printf("ERROR: Terminal does not support color.\n");
      return (0);
    }
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  wbkgd(wnd, COLOR_PAIR(1));
  attron(A_BOLD);
  box(wnd, 0, 0);
  attroff(A_BOLD);
  return 0;
}

void run() {
  
  Asteroid ast[40];
  Blaster blast[100];
  Background st[40];
  Player player;
  
  player.disp_char = '^';
  player.posx = 10;
  player.hp = 100;
  player.score = 0;
  player.posy = 45;
  struct winsize w;
  nodelay(wnd, true);
  int game_over = 0;
  int go_next_lvl = 0;
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  int in_char;
  bool exit_requested = false;
  int count = 0;
  std::clock_t start;
  double duration;
  while(count < 40)
    {
      ast[count].posx = rand() % (w.ws_col - 2);
      ast[count].posy = rand() % 50;
      ast[count].posy = -ast[count].posy;
      ast[count].val = '@';
      count++;
    }
  count = 0;
  while(count < 10)
    {
      blast[count].posx = rand() % (w.ws_col - 2);
      blast[count].posy = rand() % 50;
      blast[count].posy = -blast[count].posy;
      blast[count].val = '|';
      blast[count].fire = 0;
      count++;
    }
  count = 0;
  while(count < 40)
    {
      st[count].posx = rand() % (w.ws_col - 2);
      st[count].posy = rand() % 50;
      st[count].posy = -st[count].posy;
      st[count].val = '.';
      count++;
    }
  start = std::clock();
  in_char = wgetch(wnd);
  while(1) {
    in_char = wgetch(wnd);
    
    switch(in_char) {
    case ' ':
      {
	int c = 0;
	while ( c < 10)
	  {
	    if (blast[c].fire == 0)
	      {
		blast[c].fire = 1;
		blast[c].posx = player.posx;
		blast[c].posy = player.posy;
		break;
	      }
	    c++;
	  }
	break;
      }
    case 'q':
      exit_requested = true;
      break;
    case KEY_UP:
    case 'w':
      {
	if (player.posy > 0)
	  player.posy -= 1;
	break;
      }
    case KEY_DOWN:
    case 's':
      {
	if (player.posy < w.ws_row - 1)
	  player.posy += 1;
	break;
      }
    case KEY_LEFT:
    case 'a':
      {
	if (player.posx >= 1)
	  player.posx -= 1;
	break;
      }
    case KEY_RIGHT:
    case 'd':
      {
	if (player.posx <= w.ws_col - 2)
	  player.posx += 1;
	
	break;
      }
    default:
      break;
    }
    clear();
    mvaddch(player.posy, player.posx, player.disp_char | COLOR_PAIR(2));
    int i = 0;
    count = 0;
    while(count < 10)
      {
	i = 0;
	if (blast[count].fire == 1)
	  {
	    blast[count].posy--;
	    mvaddch(blast[count].posy, blast[count].posx, blast[count].val);   
	  }
	if (blast[count].fire == 1 && blast[count].posy == -1)
	  {
	    blast[count].posx = -1;
	    blast[count].posy = -1;
	    blast[count].fire = 0;
	  }
	while(i < 40)
	  {
	    if (blast[count].posx == ast[i].posx && blast[count].posy == ast[i].posy)
	      {
		ast[i].val = ' ';
		ast[i].posx = -3;
		player.score += 20;
		blast[count].posx = -2;
	      }
	    i++;
	  }
        count++;
      }
    count = 0;
    game_over = 0;
    go_next_lvl = 0;
    while(count < 40)
      {
	ast[count].posy++;
	if (ast[count].posy > w.ws_row)
	  {
	    ast[count].posx = rand() % (w.ws_col - 2);//80;
	    ast[count].posy = rand() % 50;
	    ast[count].posy = -ast[count].posy;
	  }
	
	mvaddch(ast[count].posy, ast[count].posx, ast[count].val);
	if ( ast[count].posy == player.posy && ast[count].posx == player.posx)
	  {
	    player.hp -= 10;
	    if (player.hp == 0)
	      {game_over = 1;
                break;}
	  }
	count++;
      }
    count = 0;
    while(count < 40)
      {
	st[count].posy++;
	if (st[count].posy > w.ws_row)
	  {
	    st[count].posx = rand() % (w.ws_col - 2);//80;
	    st[count].posy = rand() % 50;
	    st[count].posy = -st[count].posy;
	  }
	mvaddch(st[count].posy, st[count].posx, st[count].val | COLOR_PAIR(2));
	count++;
      }
    std::string text = "HP: ";
                move(2, 2);
		for(int i = 0; i < (int)text.size(); i++) {
		  addch(text[i]);
		  addch(' ');
		}
		std::string hp = std::to_string(player.hp); 
		for(int i = 0; i < (int)hp.size(); i++) {
		  addch(hp[i]);
		  addch(' ');
		}
                std::string tex = "Score: ";
                move(2, 50);
		for(int i = 0; i < (int)tex.size(); i++) {
		  addch(tex[i]);
		  addch(' ');
		}
		std::string h = std::to_string(player.score); 
		for(int i = 0; i < (int)h.size(); i++) {
		  addch(h[i]);
		  addch(' ');
		}
		duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
		if (duration > 0.52)
		  go_next_lvl = 1;
		if (player.hp == 0)
		  game_over = 1;
		std::string tim = std::to_string(duration);
		move(70, (w.ws_col - 10)/2);
		for(int i = 0; i < (int)tim.size() - 4; i++) {
		  addch(tim[i]);
		  addch(' ');
		}
		refresh();
		
		if(exit_requested) break;
		if(game_over == 1 || go_next_lvl == 1)
		  break;
		usleep(40000);
		refresh();
  }
  clear();
  refresh();
  if (game_over == 1)
    {
      move(40, ((w.ws_col - 10)/2));
      std::string text = "Game over!";
      move(40, ((w.ws_col - (int)text.size() - 2)/2));
      for(int i = 0; i < (int)text.size(); i++) {
	addch(text[i]);
	addch(' ');
      }
    }
  std::string tsext = "Your best time is: ";
  move(40, ((w.ws_col - (int)tsext.size() - 2)/2));
  for(int i = 0; i < (int)tsext.size(); i++) {
    addch(tsext[i]);
    addch(' ');
    }
  std::string tim = std::to_string(duration);
  move(44, (w.ws_col - 10)/2);
  for(int i = 0; i < (int)tim.size() - 4; i++) {
    addch(tim[i]);
    addch(' ');
  }
  if (duration > 0.52)
    {
      std::string tsext = "Get ready for Level 2! ";
      move(50, ((w.ws_col - tsext.size() - 2)/2));
      for(int i = 0; i < (int)tsext.size(); i++) {
        addch(tsext[i]);
        addch(' ');
      }
      refresh();
      sleep(5);
      run_level2();
    }    
  
  refresh();
  while(1);
}

void run_level2() {

    Asteroid ast[70];
    Boss boss[41];
    Blaster blast[5];
    Background st[40];
    Player player;

    player.disp_char = '^';
    player.posx = 10;
    player.hp = 100;
    player.score = 0;
    player.posy = 45;
    player.boss_health = 2000;
    struct winsize w;
    nodelay(wnd, true);
    int dead_boss = 0;
    int game_over = 0;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int in_char;


        bool exit_requested = false;

        int count = 0;
        while(count < 70)
        {
            ast[count].posx = rand() % 39 + 36;//80;
            ast[count].posy = rand() % 50;
            ast[count].posy = -ast[count].posy;
            ast[count].val = '8';
            count++;
        }
        count = 0;
        while(count < 5)
        {
            blast[count].posx = rand() % (w.ws_col - 2);//80;
            blast[count].posy = rand() % 50;
            blast[count].posy = -blast[count].posy;
            blast[count].val = '|';
            blast[count].fire = 0;
            count++;
        }
        count = 0;
         while(count < 40)
        {
            st[count].posx = rand() % (w.ws_col - 2);//80;
            st[count].posy = rand() % 50;
            st[count].posy = -st[count].posy;
            st[count].val = '.';
            count++;
        }
        std::clock_t start;
        double duration;
        start = std::clock();
        in_char = wgetch(wnd);
        while(1)
        {
        in_char = wgetch(wnd);
        
        switch(in_char) {
            case ' ':
                {
                    int c = 0;
                    while ( c < 5)
                    {
                        if (blast[c].fire == 0)
                        {
                            blast[c].fire = 1;
                            blast[c].posx = player.posx;
                            blast[c].posy = player.posy;
                            break;
                        }
                        c++;
                    }
                    break;
                }
            case 'q':
                exit_requested = true;
                break;
            case KEY_UP:
            case 'w':
            {
                if (player.posy > 0)
                    player.posy -= 1;
                break;
            }
            case KEY_DOWN:
            case 's':
            {
                if (player.posy < w.ws_row - 1)
                    player.posy += 1;
                break;
            }
            case KEY_LEFT:
            case 'a':
            {
                if (player.posx >= 1)
                    player.posx -= 1;
                break;
            }
            case KEY_RIGHT:
            case 'd':
            {
                if (player.posx <= w.ws_col - 2)
                    player.posx += 1;
            
                break;
            }
            default:
                break;
        }
        clear();
        mvaddch(player.posy, player.posx, player.disp_char);
        int i = 0;
        count = 0;
        while(count < 5)
        {
            i = 0;
            if (blast[count].fire == 1)
            {
                blast[count].posy--;
                mvaddch(blast[count].posy, blast[count].posx, blast[count].val);   
            }
            if (blast[count].fire == 1 && blast[count].posy == -1)
            {
                blast[count].posx = -1;
                blast[count].posy = -1;
                blast[count].fire = 0;
            }
            while(i < 70)
            {
                if (blast[count].posx == ast[i].posx && blast[count].posy == ast[i].posy)
                {
                    ast[i].val = ' ';
                    ast[i].posx = -3;
                    blast[count].posx = -4;
                    player.score += 20;
                }
                i++;
            }
            i = 0;
            while(i < 41)
            {
                if ((blast[count].posx == boss[i].posx && blast[count].posy == 7) || \
                (blast[count].posx == 34 && blast[count].posy == 5) || \
                (blast[count].posx == 76 && blast[count].posy == 5))
                {
                    blast[count].posx = -4;
                    player.boss_health -= 20;
                }
                i++;
            }
            count++;
        }
        count = 0;
        game_over = 0;
        init_pair(1, COLOR_RED, COLOR_BLACK);
        while(count < 70)
        {
            ast[count].posy++;
            if (ast[count].posy > w.ws_row)
            {
                ast[count].posx = rand() % 39 + 36;
                ast[count].posy = rand() % 50;
                ast[count].posy = -ast[count].posy;
            }
            if (ast[count].posy == 0)
            {
                
                ast[count].posy = 8;
               
            }

            mvaddch(ast[count].posy, ast[count].posx, ast[count].val | COLOR_PAIR(1));
            if ( ast[count].posy == player.posy && ast[count].posx == player.posx)
            {
                player.hp -= 10;
                if (player.hp == 0)
                {game_over = 1;
                break;}
            }
            count++;
        }
        count = 0;
         while(count < 40)
        {
            st[count].posy++;
            if (st[count].posy > w.ws_row)
            {
                st[count].posx = rand() % (w.ws_col - 2);
                st[count].posy = rand() % 50;
                st[count].posy = -st[count].posy;
            }
            mvaddch(st[count].posy, st[count].posx, st[count].val);
            count++;
        }
        int k = 35;
        while (k < 76)
        {
            mvaddch(4, k, '=');
            k++;
        }
        mvaddch(5, 34, '@');
        mvaddch(5, 35, '|');
        mvaddch(6, 35, '|');
        mvaddch(5, 40, '>');
        mvaddch(5, 41, '>');
        mvaddch(5, 70, '<');
        mvaddch(5, 69, '<');
        k = 43;
        while (k < 68)
        {
            mvaddch(6, k, '-');
            k++;
        }
        mvaddch(5, 76, '@');
        mvaddch(5, 75, '|');
        mvaddch(6, 75, '|');
        int b = 0;
        k = 35;
        while (k < 76)
        {
            boss[b].posx = k;
            boss[b].posy = k;
            mvaddch(7, k, '=');
            k++;
            b++;
        }
        std::string text = "HP: ";
        move(2, 2);
            for(int i = 0; i < (int)text.size(); i++) {
                addch(text[i]);
                addch(' ');
            }
            std::string hp = std::to_string(player.hp); 
            for(int i = 0; i < (int)hp.size(); i++) {
                addch(hp[i]);
                addch(' ');
            }
        std::string tex = "Score: ";
        move(2, 50);
            for(int i = 0; i < (int)tex.size(); i++) {
                addch(tex[i]);
                addch(' ');
            }
            std::string h = std::to_string(player.score); 
            for(int i = 0; i < (int)h.size(); i++) {
                addch(h[i]);
                addch(' ');
            }
        std::string text1 = "BOSS HP: ";
        move(2, 80);
            for(int i = 0; i < (int)text1.size(); i++) {
                addch(text1[i]);
                addch(' ');
            }
            std::string bhp = std::to_string(player.boss_health); 
            for(int i = 0; i < (int)bhp.size(); i++) {
                addch(bhp[i]);
                addch(' ');
            }   
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    if (player.boss_health  == 0)
        dead_boss = 1;
    if (player.hp == 0)
        game_over = 1;
    std::string tim = std::to_string(duration);
    move(70, (w.ws_col - 10)/2);
                    for(int i = 0; i < (int)tim.size() - 4; i++) {
                        addch(tim[i]);
                        addch(' ');
                    }
        refresh();

        if(exit_requested) break;
        if(game_over == 1 || dead_boss == 1)
            break;
        usleep(40000);
        refresh();
    }
    clear();
    refresh();
    if (dead_boss == 1)
    {
        move(40, ((w.ws_col - 10)/2));
        std::string text = "Damn! Boss is dead! WTF!!!???";
        move(42, ((w.ws_col - text.size() - 2)/2));
        for(int i = 0; i < (int)text.size(); i++) {
            addch(text[i]);
            addch(' ');
        }
        std::string tsext = "Your best time is: ";
        move(44, ((w.ws_col - tsext.size() - 2)/2));
        for(int i = 0; i < (int)tsext.size(); i++) {
            addch(tsext[i]);
            addch(' ');
        }
        std::string tim = std::to_string(duration);
        move(46, (w.ws_col - 10)/2);
        for(int i = 0; i < (int)tim.size() - 4; i++) {
            addch(tim[i]);
            addch(' ');
        }
    }
    if(game_over == 1)
    {
        move(40, ((w.ws_col - 10)/2));
        std::string t = "Dude...You are dead. Try again...";
        move(42, ((w.ws_col - t.size() - 2)/2));
        for(int i = 0; i < (int)t.size(); i++) {
            addch(t[i]);
            addch(' ');
        }
    }
    refresh();
    while(1);
}

void close() {
    endwin();
}
