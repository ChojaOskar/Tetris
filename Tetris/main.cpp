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

int x1,x2,x3,x4,y1,y2,y3,y4;

void changeShapeValues(int a1,int a2,int a3,int a4,int b1,int b2,int b3,int b4){
	x1 = a1; y1 = b1;
	x2 = a2; y2 = b2;
	x3 = a3; y3 = b3;
	x4 = a4; y4 = b4;	
}	
	
	
void generateShape(int randomShapeValue){
	if (randomShapeValue == 1){
			changeShapeValues(1,2,2,3,8,8,9,9);  
        }
    else if(randomShapeValue == 2){
			changeShapeValues(1,2,2,3,8,8,7,7);     
        }
    else if(randomShapeValue == 3){
			changeShapeValues(2,2,2,1,7,8,9,9);
        }
    else if(randomShapeValue == 4){
			changeShapeValues(1,2,3,4,8,8,8,8);
        }
    else if(randomShapeValue == 5){
			changeShapeValues(1,1,2,2,8,9,8,9);
        }
    else if(randomShapeValue == 6){
			changeShapeValues(1,2,2,2,8,7,8,9);
        }
	else if(randomShapeValue == 7){
			changeShapeValues(1,2,2,2,7,7,8,9);
        }
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
	bool reachedFourthRow = false;
	
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
		
		srand(time(0));
		int random_shape = (rand() % 7) + 1; 
		int press= 1;
		
		generateShape(random_shape);


 if (x1 + 1 == rows || x2 + 1 == rows || x3 + 1 == rows || x4 + 1 == rows ||
        gameBoard[x1 + 1][y1] == 'X' || gameBoard[x2 + 1][y2] == 'X' ||
        gameBoard[x3 + 1][y3] == 'X' || gameBoard[x4 + 1][y4] == 'X') {

        reachedFourthRow = true;
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
					changeShapeValues(x1,x2-1,x3,x4-1,y1+2,y2+1,y3,y4-1);
					press= 2;
					break;
				}
				
			
				if(random_shape==1 && press == 2){
					changeShapeValues(x1+2,x2+1,x3,x4-1,y1-1,y2,y3-1,y4);	
					press = 3;
					break;
				}
				
				if(random_shape==1 && press == 3){
					changeShapeValues(x1-1,x2,x3-1,x4,y1-1,y2,y3+1,y4+2);	
					press = 4;
					break;
				}

				if(random_shape==1 && press == 4){
					changeShapeValues(x1-1,x2,x3+1,x4+2,y1,y2-1,y3,y4-1);	
					press = 1;
					break;
				}
				
				if(random_shape==2 && press == 1){
					changeShapeValues(x1+1,x2,x3-1,x4-2,y1+1,y2,y3+1,y4);	
					press= 2;
					break;
				}
				
				if(random_shape==2 && press == 2){
					changeShapeValues(x1+1,x2,x3+1,x4,y1-2,y2-1,y3,y4+1);
					press = 3;
					break;
				}
				
				if(random_shape==2 && press == 3){
					changeShapeValues(x1-2,x2-1,x3,x4+1,y1,y2+1,y3,y4+1);
					press = 4;
					break;
				}

				if(random_shape==2 && press == 4){
					changeShapeValues(x1,x2+1,x3,x4+1,y1+1,y2,y3-1,y4-2);	
					press = 1;
					break;
				}

				if(random_shape==3 && press == 1){
					changeShapeValues(x1-2,x2-1,x3,x4+1,y1+2,y2+1,y3,y4+1);	
					press= 2;
					break;
				}
				
				if(random_shape==3 && press == 2){
					changeShapeValues(x1+1,x2,x3-1,x4,y1+2,y2+1,y3,y4-1);	
					press = 3;
					break;
				}
				
				if(random_shape==3 && press == 3){
					changeShapeValues(x1+3,x2+2,x3+1,x4,y1-1,y2,y3+1,y4);	
					press = 4;
					break;
				}
			
				if(random_shape==3 && press == 4){
					changeShapeValues(x1-2,x2-1,x3,x4-1,y1-3,y2-2,y3-1,y4);	
					press = 1;
					break;
				}

				if(random_shape==4 && press == 1){
					changeShapeValues(x1+1,x2,x3-1,x4-2,y1+3,y2+2,y3+1,y4);	
					press= 2;
					break;
				}
				
				if(random_shape==4 && press == 2){
					changeShapeValues(x1+3,x2+2,x3+1,x4,y1-3,y2-2,y3-1,y4);	
					press = 3;
					break;
				}
				
				if(random_shape==4 && press == 3){
					changeShapeValues(x1-3,x2-2,x3-1,x4,y1-3,y2-2,y3-1,y4);	
					press = 4;
					break;
				}

				if(random_shape==4 && press == 4){
					changeShapeValues(x1-1,x2,x3+1,x4+2,y1+3,y2+2,y3+1,y4);
					press = 1;
					break;
				}

				if(random_shape==6 && press == 1){	
				changeShapeValues(x1,x2-2,x3-1,x4,y1+1,y2+1,y3,y4-1);	
					press= 2;
					break;
				}
				
				if(random_shape==6 && press == 2){
					changeShapeValues(x1+1,x2+1,x3,x4-1,y1-1,y2+1,y3,y4-1);	
					press = 3;
					break;
				}
				
				if(random_shape==6 && press == 3){
					changeShapeValues(x1-1,x2+1,x3,x4-1,y1-1,y2-1,y3,y4+1);	
					press = 4;
					break;
				}

				if(random_shape==6 && press == 4){
					changeShapeValues(x1,x2,x3+1,x4+2,y1+1,y2-1,y3,y4+1);	
					press = 1;
					break;
				}

				if(random_shape==7 && press == 1){
					changeShapeValues(x1-1,x2-2,x3-1,x4,y1+3,y2+2,y3+1,y4);	
					press= 2;
					break;
				}
				
				if(random_shape==7 && press == 2){
					changeShapeValues(x1+3,x2+2,x3+1,x4,y1+1,y2+2,y3+1,y4);	
					press = 3;
					break;
				}
				
				if(random_shape==7 && press == 3){
					changeShapeValues(x1+1,x2+2,x3+1,x4,y1-3,y2-2,y3-1,y4);
					press = 4;
					break;
				}
				
				if(random_shape==7 && press == 4){
					changeShapeValues(x1-3,x2-2,x3-1,x4,y1-1,y2-2,y3-1,y4);	
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
			
		
			if (reachedFourthRow) {
		        game = false;
		        break;
		    }
			
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
		

	delwin(mainwin);
	endwin();
	refresh();
	return EXIT_SUCCESS;
}