int GRADEFIXA=8; 	//TAMANHO GRADE FIXA 8X8
int grade_x=2;		//GUI X
int grade_y=2;		//GUI Y

int pintar=0;		//CLICK ENTER
int save=0;			//CHAMA FUNÇÃO DE GRAVAR DADOS EM .TXT SE FOR == 1

int draw[8][8]={0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,
				0,0,0,0,0,0,0};

void gravardesenho(const char *nomearquivo){
    
    FILE *file = fopen(nomearquivo,"w"); //ESCREVER = W

    for(int i=0;i<GRADEFIXA;i++){
		
		if(i>=0 && i<8)fprintf(file,"B");//GRAVAR NO INICIO DAS LINHAS
		
        for (int j=0;j<GRADEFIXA;j++){
            fprintf(file,"%d",draw[j][i]);
        }
        
        fprintf(file,",\n");//ADICIONAR NO FIM DAS LINHAS
    }

    fclose(file);
}

void guigrade(int x,int y){
	
	/*
	 * LE A MATRIZ 8X8 CHAMADA DRAW
	 * E SE FOR DE VALOR 1 MOSTRA UM CARACTER
	 * DE UMA COR, CASO SEJA O VALOR DE 0
	 * MOSTRA OUTRA COR
	 * 
	 * */
	
	for(int i=0;i<GRADEFIXA;i++){
		for(int j=0;j<GRADEFIXA;j++){
			
			//GRADE:PINTADO
			if(draw[i][j]==1){
				cgui_color(9);
				gotoxy(x+i,y+j),printf("█");
			}
			
			//GRADE:NAO PINTADO
			if(draw[i][j]==0){
				cgui_color(0);
				gotoxy(x+i,y+j),printf("█");
			}
			
			if(draw[i][j]%8==0)printf("\n");
			
		}	
	}	
}
