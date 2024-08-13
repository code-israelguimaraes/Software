int mouse_x=0;
int mouse_y=0; 
					
/*
 * ADICIONA O VALOR DA GRADE (X,Y)
 * AO MOUSE,ASSIM O MOUSE SEMPRE INICIA
 * NO COMEÇO AO IMPRIMIR A GRADE
 * 
 * */

void mouse(int x,int y){
	
	//X = GRADE_X + MOUSE_X
	//Y = GRADE_Y + MOUSE_Y
	
	cgui_color(15);
	gotoxy(x,y),printf("█");
}
