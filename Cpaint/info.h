void info(int x,int y){
	
	/*INFORMAÇÕES QUE PODEM SER EXIBIDAS*/
	
	cgui_color(15);
	gotoxy(x,y+1),printf("GRADE:8x8\n");
	gotoxy(x,y+2),printf("ARQUIVO:DESENHO.txt\n");
	gotoxy(x,y+3),printf("CURSOR: %d , %d\n",mouse_x,mouse_y);//X E Y PERCORRE MATRIZ
	gotoxy(x,y+4),printf("PINTAR: %d\n",pintar);
	
	cgui_color(11);
	gotoxy(x,y+6),printf("APAGAR 2X ENTER\n");
	gotoxy(x,y+7),printf("PINTAR ENTER\n");
	gotoxy(x,y+8),printf("SALVAR BARRA DE ESPAÇO\n");
	gotoxy(x,y+9),printf("NAVEGAR PELA GRADE DIRECIONAIS TECLADO\n");
}
