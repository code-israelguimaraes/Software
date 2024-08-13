/*	
 * 	AUTHOR: ISRAEL SOUSA GUIMARAES
 *  CREATION DATE 12/08/2024
 *  VERSION CGAME: 0.1	
 *  OPERATION SYSTEM: LINUX
 * 	WRITTER IN: C++
 *  MODO: CONSOLE
 *  FONT: TERMINUS 
 *  SIZE: 13
 * -------------------------------------------------------------------
 *
 * USE THE CHARACTERES DRAWING: █
 * 
 * -------------------------------------------------------------------
 * 
 * FUNCTIONS 5
 * 
 * 1-KEYBOARD MAPPING BUTTON
 * 2-KBHIT
 * 3-GOTOXY
 * 4-CLSBUFFER
 * 5-FPS
 * 
 * 1-KEYBOARD MAPPING BUTTON
 * KEYBOARD BUTTONS FOR CONTROL
 * 
 * 2-KBHIT
 * SIMULATE A USER WITHOUT ACTION REGARDING KEYS PRESSED, ENTER LOOP AND RUN SOMETHING BACK
 * 
 * 3-GOTOXY
 * MOVES SOMETHING ON THE X AND Y AXES
 * 
 * 4-CLSBUFFER
 * CLEAR SCREEN
 * 
 * 5-FPS
 * CONTROLS THE PROGRAM EXECUTION TIME, WORKING AS A SHARE REGULATOR
 *  
 * */

#include <string.h>
#include <stdlib.h> // FUNCTION RAND
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <fcntl.h>
#include <linux/joystick.h>
#include <errno.h>

#define JOYSTICK_DEV "/dev/input/js0"

int js_fd;
struct js_event js;

/*KEYBOARD MAPPING*/

#define key_up 65 
#define key_down 66 
#define key_left 68
#define key_right 67
#define key_enter 10
#define key_spacebar 32
#define key_esc 27
#define key_tab 9

static struct termios old, current;

/* Initialize new terminal i/o settings */
void initTermios(int echo) {
	
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  current = old; /* make new settings same as old settings */
  current.c_lflag &= ~ICANON; /* disable buffered i/o */
  if (echo) {
      current.c_lflag |= ECHO; /* set echo mode */
  } else {
      current.c_lflag &= ~ECHO; /* set no echo mode */
  }
  tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */

void resetTermios(void) {
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) {

  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) {
	
  return getch_(0);
}

/* Read 1 character with echo */
char getche(void) {
	
  return getch_(1);
}

int kbhit(void){
  
  struct termios oldt, newt;
  int ch;
  int oldf;
 
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getchar();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }

	return 0;  

}

void gotoxy(int x,int y){
	printf("%c[%d;%df",0x1B,y,x);
}

void cls_buffer(){
	printf("\033[2J");	
}

void FPS(char n[]){
	
	char command[100];
	sprintf(command,"sleep 0.0%s",n);
	system(command);
	
}
