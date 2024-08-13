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
 * FUNCTIONS 2
 * 
 * 1-COLORING
 * 2-COLOR BACKGROUND
 * 
 * 1-COLOR
 * YOU CAN RUN THE COLOR FILE TO SEE AVAILABLE COLORS 256
 *
 * ./COLOR
 * 
 * 2-COLOR BACKGROUND 
 * CHANGE THE BACKGROUND IN 16 POSSIBLE COLORS
 *  
 * */

void cgui_color(int num_color){

	//256 AVAILABLE COLORS
	printf("\033[38;5;%im",num_color); 
	
	if(num_color==256)num_color=256;

}

void cgui_background(int num_color){

	switch(num_color){

	case 1:
	system("echo '\e[0;41m'");	
	break;

	case 2:system("echo '\e[0;42m'");	
	break;

	case 3:system("echo '\e[0;43m'");	
	break;

	case 4:system("echo '\e[0;44m'");	
	break;

	case 5:system("echo '\e[0;45m'");	
	break;

	case 6:system("echo '\e[0;46m'");	
	break;
	
	case 7:system("echo '\e[0;47m'");	
	break;
	
	case 8:system("echo '\e[0;48m'");	
	break;
	
	case 9:system("echo '\e[0;100m'");	
	break;
	
	case 10:system("echo '\e[0;101m'");
	break;
	
	case 11:system("echo '\e[0;102m'");
	break;

	case 12:system("echo '\e[0;103m'");
	break;
	
	case 13:system("echo '\e[0;104m'");
	break;
	
	case 14:system("echo '\e[0;105m'");
	break;
	
	case 15:system("echo '\e[0;106m'");
	break;
	
	case 16:system("echo '\e[0;107m'");
	break;

	}
	
}
