#include <iostream>
#include <string>
#include <unistd.h>
#include <stdio.h>  
#include <stdlib.h>     
#include <time.h> 
#include <ncursesw/curses.h>
using namespace std;
void ncurses_init_colors(){

	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
}

void ncurses_config(){
	ncurses_init_colors();
	keypad(stdscr, TRUE);
	timeout(0);
	noecho();
}



	
int main(){
	
	initscr();
	
	int yMax, xMax, start_y, start_x;
	yMax = 29;
	xMax = 33;
	start_y = start_x = 0;
	
	
	
	bool game = true;
	
	int rows = 28;
	int cols = 16;
	char gameBoard[rows][cols]; 
	
	int Score = 0;
	
	
	for (int i = 0; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            gameBoard[i][j] = ' ';
        }
    }
	
	
	
	
	WINDOW * mainwin = newwin(yMax, xMax, start_y, start_x);
	refresh();
	ncurses_config();
	
	box(mainwin, 0, 0);
	
	
	mvwprintw(mainwin, 14, 5, "Press any key to start");
	mvwprintw(mainwin, 15, 5, "Move with the arrow keys");
	mvwprintw(mainwin, 16, 5, "Rotate with the up arrow");
	wrefresh(mainwin);
	
	
	WINDOW *scorewin = newwin(5, 25, start_y, xMax);
    box(scorewin, 0, 0);
  
  
    wrefresh(scorewin);
	
    WINDOW *gameOverWin = newwin(30, 80, 0, 0);
    box(gameOverWin, 0, 0);
	
	getch();
	
	while(game){
		
		wattron(scorewin, A_BOLD);
		mvwprintw(scorewin, 2, 1, "Your Score: %d", Score); 
		wrefresh(scorewin);
		wattroff(scorewin, A_BOLD);
		
		int  x1 = 0;  int y1 = 0;
		int  x2 = 0;  int y2 = 0;
		int  x3 = 0;  int y3 = 0;
		int  x4 = 0;  int y4 = 0;
		
		srand(time(0));
		int random_shape = (rand() % 7) + 1; 
		
		/*
    
    O
    O O
      O 
      
        O
      O O
      O
      
          O
      O O O 
       
      O
      O
      O
      O
      
       O O 
       O O
       
         O 
       O O O
      
      
      O   
      O O O 
      
      
    */
		
		int press= 1;
		
		
		
		
		if (random_shape == 1){
            x1 = 1;
            x2 = 2;
            x3 = 2;
            x4 = 3;
            y1 = 8;
            y2 = 8;
            y3 = 9;
            y4 = 9;
        }
        else if(random_shape == 2){
            x1 = 1;
            x2 = 2;
            x3 = 2;
            x4 = 3;
            y1 = 8;
            y2 = 8;
            y3 = 7;
            y4 = 7;
        }
        else if(random_shape == 3){
            x1 = 2;
            x2 = 2;
            x3 = 2;
            x4 = 1;
            y1 = 7;
            y2 = 8;
            y3 = 9;
            y4 = 9;
        }
        else if(random_shape == 4){
            x1 = 1;
            x2 = 2;
            x3 = 3;
            x4 = 4;
            y1 = 8;
            y2 = 8;
            y3 = 8;
            y4 = 8;
        }
        else if(random_shape == 5){
            x1 = 1;
            x2 = 1;
            x3 = 2;
            x4 = 2;
            y1 = 8;
            y2 = 9;
            y3 = 8;
            y4 = 9;
        }
        else if(random_shape == 6){
            x1 = 1;
            x2 = 2;
            x3 = 2;
            x4 = 2;
            y1 = 8;
            y2 = 7;
            y3 = 8;
            y4 = 9;
        }
		else if(random_shape == 7){
            x1 = 1;
            x2 = 2;
            x3 = 2;
            x4 = 2;
            y1 = 7;
            y2 = 7;
            y3 = 8;
            y4 = 9;
        }
		
		
		
		
		
		if(gameBoard[4][0]=='X' || 
				gameBoard[4][1]=='X' ||
				gameBoard[4][2]=='X' ||
				gameBoard[4][3]=='X' ||
				gameBoard[4][4]=='X' ||
				gameBoard[4][5]=='X' ||
				gameBoard[4][6]=='X' ||
				gameBoard[4][7]=='X' ||
				gameBoard[4][8]=='X' ||
				gameBoard[4][9]=='X' ||
				gameBoard[4][10]=='X' ||
				gameBoard[4][11]=='X' ||
				gameBoard[4][12]=='X' ||
				gameBoard[4][13]=='X' ||
				gameBoard[4][14]=='X' ||
				gameBoard[4][15]=='X'){
					
						game=false;
						break;
					
				}
	
			
		
		
		for (int n = 0; n < rows ; n++){
			
			
		
			
			
			
				int input = getch();

		switch (input) {
   			case KEY_RIGHT:
   				if (y1 + 1 < cols && y2 + 1 < cols && y3 + 1 < cols && y4 + 1 < cols){
   					if (gameBoard[x1][y1 + 1] == ' ' && gameBoard[x2][y2 + 1] == ' ' &&
                        gameBoard[x3][y3 + 1] == ' ' && gameBoard[x4][y4 + 1] == ' ') {
			    	y1++;
			    	y2++;
			   		y3++;
			   		y4++;
			   		}
			   }
			   	refresh();
			    break;
			        
    		case KEY_LEFT:
    			if (y1 - 2 >= 0 && y2 - 2 >= 0 && y3 - 2 >= 0 && y4 - 2 >= 0) {
    				if (gameBoard[x1][y1 - 1] == ' ' && gameBoard[x2][y2 - 1] == ' ' &&
                        gameBoard[x3][y3 - 1] == ' ' && gameBoard[x4][y4 - 1] == ' ') {
                    y1--;
                    y2--;
                    y3--;
                    y4--;
                	}
    			}
			   	refresh();
			    break;
			    
			case KEY_DOWN:
				if (x1 + 1 < rows && x2 + 1 < rows && x3 + 1 < rows && x4 + 1 < rows && gameBoard[rows][cols] != 'X') {
					 if (gameBoard[x1 + 1][y1] == ' ' && gameBoard[x2 + 1][y2] == ' ' &&
                        gameBoard[x3 + 1][y3] == ' ' && gameBoard[x4 + 1][y4] == ' ') {
			    	x1++;
			    	x2++;
			    	x3++;
			    	x4++;
			    	}
			    }
			   	refresh();
			    break;
			    
			case KEY_UP:
				
			if (!(gameBoard[x2][y2 + 2] == ' ' && gameBoard[x3][y3 + 1] == ' ' &&
              gameBoard[x4][y4 - 1] == ' ')) {
            break; 
        }
        
        else{
		
				
				if(random_shape==1 && press == 1){
					
					
					y1 = y1+2;
					x2 = x2-1;
					y2 = y2+1;
					x4 = x4-1;
					y4 = y4-1;
				
					
					
						
					press= 2;
					break;
				}
				
			
					if(random_shape==1 && press == 2){
						
					x1 = x1+2;
					y1 = y1-1;
					x2 = x2+1;
					y3 = y3-1;
					x4 = x4-1;
					
					
					press = 3;
					break;
				}
				
					if(random_shape==1 && press == 3){
					x1 = x1-1;
					y1 = y1-1;
					x3 = x3-1;
					y3 = y3+1;
					y4 = y4+2;
					
					
					press = 4;
					break;
				}
				
				
					if(random_shape==1 && press == 4){
					x1 = x1-1;
					y2 = y2-1;
					x3 = x3+1;
					x4 = x4+2;
					y4 = y4-1;
					
					
					press = 1;
					break;
				}
				
			if(random_shape==2 && press == 1){
					
					
					x1 = x1+1;
					y1 = y1+1;
					x3 = x3-1;
					y3 = y3+1;
					x4 = x4-2;
				
					
						
					press= 2;
					break;
				}
				
				if(random_shape==2 && press == 2){
					x1 = x1+1;
					y1 = y1-2;
					y2 = y2-1;
					x3 = x3+1;
					y4 = y4+1;
					
					
					
					
					press = 3;
					break;
				}
				
				if(random_shape==2 && press == 3){
					x1 = x1-2;
					x2 = x2-1;
					y2 = y2+1;
					x4 = x4+1;
					y4 = y4+1;
					
					
					press = 4;
					break;
				}
				
				
				
				
				if(random_shape==2 && press == 4){
					y1 = y1+1;
					x2 = x2+1;
					y3 = y3-1;
					x4 = x4+1;
					y4 = y4-2;
					
					
					press = 1;
					break;
				}
			
			
			
			if(random_shape==3 && press == 1){
					
					
					x1 = x1-2;
					y1 = y1+2;
					x2 = x2-1;
					y2 = y2+1;
					x4 = x4+1;
					y4 = y4+1;
				
					
						
					press= 2;
					break;
				}
				
				if(random_shape==3 && press == 2){
					x1 = x1+1;
					y1 = y1+2;
					y2 = y2+1;
					x3 = x3-1;
					y4 = y4-1;
					
					
					
					
					press = 3;
					break;
				}
				
				if(random_shape==3 && press == 3){
					x1 = x1+3;
					y1 = y1-1;
					x2 = x2+2;
					x3 = x3+1;
					y3 = y3+1;
					
					
					press = 4;
					break;
				}
			
				if(random_shape==3 && press == 4){
					x1 = x1-2;
					y1 = y1-3;
					x2 = x2-1;
					y2 = y2-2;
					y3 = y3-1;
					x4 = x4-1;
				
					
					
					press = 1;
					break;
				}
				
				
				
				
			
			
			if(random_shape==4 && press == 1){
					
					
					x1 = x1+1;
					y1 = y1+3;
					y2 = y2+2;
					x3 = x3-1;
					y3 = y3+1;
					x4 = x4-2;
				
					
						
					press= 2;
					break;
				}
				
				if(random_shape==4 && press == 2){
					x1 = x1+3;
					y1 = y1-3;
					x2 = x2+2;
					y2 = y2-2;
					x3 = x3+1;
					y3 = y3-1;
					
					
					
					press = 3;
					break;
				}
				
				if(random_shape==4 && press == 3){
					x1 = x1-3;
					y1 = y1-3;
					x2 = x2-2;
					y2 = y2-2;
					x3 = x3-1;
					y3 = y3-1;
					
					
					press = 4;
					break;
				}
				
				
				if(random_shape==4 && press == 4){
					x1 = x1-1;
					y1 = y1+3;
					y2 = y2+2;
					x3 = x3+1;
					y3 = y3+1;
					x4 = x4+2;
					
					
					press = 1;
					break;
				}
				
				
				if(random_shape==6 && press == 1){
					
					
					y1 = y1+1;
					x2 = x2-2;
					y2 = y2+1;
					x3 = x3-1;
					y4 = y4-1;
					
				
					
						
					press= 2;
					break;
				}
				
				if(random_shape==6 && press == 2){
					x1 = x1+1;
					y1 = y1-1;
					x2 = x2+1;
					y2 = y2+1;
					x4 = x4-1;
					y4 = y4-1;
					
					
					
					
					press = 3;
					break;
				}
				
				if(random_shape==6 && press == 3){
					x1 = x1-1;
					y1 = y1-1;
					x2 = x2+1;
					y2 = y2-1;
					x4 = x4-1;
					y4 = y4+1;
					
					
					
					press = 4;
					break;
				}
				
				
				if(random_shape==6 && press == 4){
					y1 = y1+1;
					y2 = y2-1;
					x3 = x3+1;
					x4 = x4+2;
					y4 = y4+1;
					
					
					press = 1;
					break;
				}
				
				
				if(random_shape==7 && press == 1){
					
					x1 = x1-1;
					y1 = y1+3;
					x2 = x2-2;
					y2 = y2+2;
					x3 = x3-1;
					y3 = y3+1;
					
					
				
					
						
					press= 2;
					break;
				}
				
				if(random_shape==7 && press == 2){
					
					x1 = x1+3;
					y1 = y1+1;
					x2 = x2+2;
					y2 = y2+2;
					x3 = x3+1;
					y3 = y3+1;
					
					
					
					
					press = 3;
					break;
				}
				
				if(random_shape==7 && press == 3){
					
					x1 = x1+1;
					y1 = y1-3;
					x2 = x2+2;
					y2 = y2-2;
					x3 = x3+1;
					y3 = y3-1;
					
					
					
					press = 4;
					break;
				}
				
				
				if(random_shape==7 && press == 4){
					x1 = x1-3;
					y1 = y1-1;
					x2 = x2-2;
					y2 = y2-2;
					x3 = x3-1;
					y3 = y3-1;
					
					
					press = 1;
					break;
				}
				
				
				
				
				refresh();
				break;
			
		}
		}
	
			
			
			
			if(x1+1 == rows || x2+1 == rows || x3+1 == rows || x4+1 == rows  ||
			gameBoard[x1+1][y1] == 'X'||
			gameBoard[x2+1][y2] == 'X'||
			gameBoard[x3+1][y3] == 'X'||
			gameBoard[x4+1][y4] == 'X'){
			
			gameBoard[x1][y1] = 'X';
			gameBoard[x2][y2] = 'X';
			gameBoard[x3][y3] = 'X';
			gameBoard[x4][y4] = 'X';
			
			
			
			
			
			
			
            for (int i = rows - 1; i >= 0; --i) {
                bool rowFilled = true;
                for (int j = 1; j < cols; ++j) {
                    if (gameBoard[i][j] != 'X') {
                        rowFilled = false;
                        break;
                    }
                }

                if (rowFilled) {
                    Score = Score+100;
                    for (int k = i; k > 0; --k) {
                        for (int j = 1; j < cols; ++j) {
                            gameBoard[k][j] = gameBoard[k - 1][j];
                        }
                    }
                    
                    for (int j = 1; j < cols; ++j) {
                        gameBoard[0][j] = ' ';
                    }
                }
            }
			
			
			
			
			
			
			
			
			
				break;
			}
			else{
				
			
			x1++;
			x2++;
			x3++;
			x4++;
		
			gameBoard[x1][y1] = 'I';
			gameBoard[x2][y2] = 'I';
			gameBoard[x3][y3] = 'I';
			gameBoard[x4][y4] = 'I';
			
			
			
			
			
			
		}
		
		
		
			
		
		
		
		
		
		for (int i = 0; i < rows; ++i) {
        		for (int j = 1; j < cols; ++j) {
        	    mvprintw(i, j * 2, "%c", gameBoard[i][j]); 
        										}		
    										}
		
			for (int i = 0; i < rows; ++i) {
       			 for (int j = 1; j < cols; ++j) {
            			if(gameBoard[i][j]!='X'){
						
							gameBoard[i][j] = ' ';
						}
        }
    }
		
		
		
		
		refresh();
		usleep(89500);
		
	}
	
		
	
	
		mvwprintw(scorewin, 2, 1, "Your Score: %d", Score); 
        wrefresh(scorewin);
			
			
    	
			
			
			
			
			
		
			
					}				
			
			
	wattron(scorewin, A_BOLD);		
	mvwprintw(gameOverWin, 14, 35, "GAME OVER");
	mvwprintw(gameOverWin, 16, 33, "Your Score: %d", Score);
	wrefresh(gameOverWin);
	wattroff(gameOverWin, A_BOLD);
	usleep(3000000);
		
	
	
	
	
	
	

	
	
	
	
	
	
	// zakaĹczamy prace ncurses
	delwin(mainwin);
	endwin();
	refresh();
	return EXIT_SUCCESS;
}