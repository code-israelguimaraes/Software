/*	
 * 	AUTHOR: ISRAEL SOUSA GUIMARAES
 *  CREATION DATE 12/08/2024
 *  VERSION CGUI: 0.1	
 *  OPERATION SYSTEM: LINUX
 * 	WRITTER IN: C
 *  MODO: CONSOLE
 *  FONT: TERMINUS 
 *  SIZE: 13
 * -------------------------------------------------------------------
 *
 * USE THE CHARACTERES DRAWING: █
 * 
 * -------------------------------------------------------------------
 *  
 * */

// LIBRARIES CGUI 0.1

/*CHANGE YOUR PATH,TO ACESS CGUI FILE*
 * 
 * EXEMPLE:#include "/home/user/xxxx/xxxxx/xxxxx/cgame_in.h"
 * 					/home/israelguimaraes/C/Games/Cgame/cgame_in.h 
 *
 */
  
#include "/home/israelguimaraes/C/Softwares/Cgui/cgui_in.h"
#include "/home/israelguimaraes/C/Softwares/Cgui/cgui_sys.h"
#include "/home/israelguimaraes/C/Softwares/Cgui/cgui_color.h"
#include "/home/israelguimaraes/C/Softwares/Cgui/cgui_arduino.h"

// CGAME VARIABLES
char tecla;						// VARIABLE TO CAPTURE KEYBOARD
int start_software = 1;			// START SOFTWARE, BEING START = TRUE
int clocks = 0; 				// CLOCK VARIABLE FOR IN-GAME CONTROL			
int background = 0; 			// TERMINAL BACKGROUND COLOR (1 TO 16 COLORS)
int once=1;					    // LOOP VARIABLE ONLY ONCE, IF A FUNCTION IS REPEATED, IF NEEDED
int logic_controller = 0;       // GAME CONTROL VARIABLE

/*MY SOFTWARE LIBRARY YOU CAN CREATE YOUR LIBRARIES AND PUT BELOW FOR ORGANIZATION
 * 
 * EXEMPLE:
 * 
 * #include GUI.H
 * #include BUTTON.H
 * #include MOUSE.H
 * 
 * */

//----------------------------------------------------------------------

int main(){

	//MY WINDOW TITLE
	system("echo '\033]0;My Title \007'");
	
	cgui_fullscreen();			  //FULLSCREEN
	cgui_background(background); //BACKGROUND COLOR
	cgui_clear();				  //CLEAR SCREEN

	//OPEN JSX FILE OF JOYSTICK
	js_fd=open(JOYSTICK_DEV,O_RDONLY | O_NONBLOCK);	
	while(start_software==1){

		//READ FILE JS
		read(js_fd,&js,sizeof(struct js_event));

		// TURN OFF TERMINAL FUNCTION CURSOR OFF
		cgui_curso(0);
		cgui_echo(0);
		//--------------------------------------------------------------
		
		// USE ARDUINO GET VARIABLE 
		//arduinoIO=cgui_arduinoinit("/dev/ttyUSB0");
		
		// ** YOUR CODE HERE BELOW **
	
		//--------------------------------------------------------------	
		while(kbhit()){
		
			// KBHIT() = COMMAND FOR KEYBOARD DATA ENTRY
			tecla = getch();
			
			// KYBOARD INPUT
			
			
		//--------------------------------------------------------------	
		}	
		
		//JOYSTICK INPUT	
		switch(js.type & ~JS_EVENT_INIT){
		
			case JS_EVENT_BUTTON:
				
				//UNCOMMENT TO DISPLAY ALL BUTTONS
				//gotoxy(0,2),printf("Button %d, Value %d\n", js.number, js.value);
				
				if(js.number==0 && js.value==1){
					//CODE HERE
					//gotoxy(0,2),printf("Button X PRESSED\n");
				}
				
				if(js.number==1 && js.value==1){
					//CODE HERE
					//gotoxy(0,2),printf("Button A PRESSED\n");
				}
				
				if(js.number==2 && js.value==1){
					//CODE HERE
					//gotoxy(0,2),printf("Button B PRESSED\n");
				}
				
				
				if(js.number==3 && js.value==1){
					//CODE HERE
					//gotoxy(0,2),printf("Button Y PRESSED\n");
				}
				
				if(js.number==4 && js.value==1){
					//CODE HERE
					//gotoxy(0,2),printf("Button L PRESSED\n");
				}
				
				if(js.number==5 && js.value==1){
					//CODE HERE
					//gotoxy(0,2),printf("Button R PRESSED\n");
				}
				
				if(js.number==8 && js.value==1){
					//CODE HERE
					//gotoxy(0,2),printf("Button SELECT PRESSED\n");
				}
				
				if(js.number==9 && js.value==1){
					//CODE HERE
					//gotoxy(0,2),printf("Button START PRESSED\n");
				}
			break;
		
			case JS_EVENT_AXIS:
				
				//UNCOMMENT TO DISPLAY ALL BUTTONS
				//gotoxy(0,2),printf("Eixo %d, Value %d\n", js.number, js.value);
				
				//BUTTON RIGHT
				if(js.number==0 && js.value==32767){
					//CODE HERE
					//gotoxy(0,2),printf("Button RIGHT PRESSED\n");
				}
				
				//BUTTON LEFT
				if(js.number==0 && js.value==-32767){
					//CODE HERE
					//gotoxy(0,2),printf("Button LEFT PRESSED\n");
				}
				
				//BUTTON UP
				if(js.number==1 && js.value==32767){
					//CODE HERE
					//gotoxy(0,2),printf("Button UP PRESSED\n");
				}
				
				//BUTTON DOWN
				if(js.number==1 && js.value==-32767){
					//CODE HERE
					//gotoxy(0,2),printf("Button DOWN PRESSED\n");
				}
		
		}	
					
		//--------------------------------------------------------------

		// GAME LOOPS (PUT ALL THE ANIMATION AND LOGIC FUNCTIONS BELOW KBHIT)
		srand(time(NULL));
		clocks++;
		if(clocks==100)clocks=0; //TIME CONTROL AT THE TERMINAL
		
		//--------------------------------------------------------------
		
		// ** CODE LOOP FUNCTIONS BELOW**
		
		//--------------------------------------------------------------
		
		cls_buffer(); // SCREEN CLEANING
		
		//--------------------------------------------------------------
		
		once=0; // VARIABLE TO PERFORM CODE ONCE IN THE PROGRAM
		
		//--------------------------------------------------------------
	
		//  TERMINAL FPS
		FPS("10");

	}
	
	// CONNECT TERMINAL FUNCTION
	cgui_curso(1);
	cgui_echo(1);
	
  return 0;

}
