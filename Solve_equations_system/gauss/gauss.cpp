#include <iostream>


//attention to set the column number at each parameter of the functions below after changing the default matrix.  

void funcao_printar(int qtdlinha,int qtdcoluna,float matriz[][4]){
	int i,j;
	printf("\n");
	for(i=0;i<qtdlinha;i++){                             
		for(j=0;j<qtdcoluna;j++){
			printf("  %.3f",matriz[i][j]);
		}
	printf("\n");
	}
	return;
}

void funcao_variavel(int qtdlinha,int qtdcoluna,float matriz[][4]){
	int i;
	printf("\n");
	for(i=0;i<qtdlinha;i++){
		printf("a variavel %d e: %.3f",i,matriz[i][qtdcoluna-1]);
	printf("\n");
	}
	
}

void sistema_impossivel_infinitas(int qtdlinha,int qtdcoluna,float matriz[][4]){
	int variavel=0;	
	for(int i=0;i<qtdlinha;i++){
		for(int j=0;j<qtdcoluna;j++){
			if(matriz[i][j]==0){
				variavel++;
			}                                           
		}
		if(variavel==qtdcoluna){			
			printf("MATRIZ POSSUE INFINITAS SOLUCOES!!!");
			exit(1);
			}
		if((variavel==(qtdcoluna-1)&&matriz[i][qtdcoluna-1]!=0)){
			printf("\nSISTEMA IMPOSSIVEL!!!\n");
			exit(1);
		}
		variavel=0;
	}	
}

bool pivor_zero(int contador1,int contador2,int qtdlinha,int qtdcoluna, float matriz[][4]){
	int contador3=0;
	for(int i=contador1;i<qtdlinha;i++){
		if(matriz[i][contador2]!=0){              
			contador3++;
			float *armazenar=new float[qtdcoluna+1];                     
			for(int z=0;z<qtdcoluna;z++){
				armazenar[z]=matriz[contador1][z];
				matriz[contador1][z]=matriz[i][z];
				matriz[i][z]=armazenar[z];
			}
			delete[] armazenar;
			break;
		}
	}
	
	if(contador3==0&&(contador2<qtdcoluna)){ 
		return true;		                 
	}
	printf("\npivor 0.Portanto, troca de  linha necessaria:\n");
	
	funcao_printar(qtdlinha,qtdcoluna,matriz);
	
	return false;
		  
}

int main(int argc, char** argv) {
	//float matriz[6][7] = {0.866,0,-0.5,0,0,0,0,0.5,0,0.866,0,0,0,-1000,-0.866,-1,0,-1,0,0,0,-0.5,0,0,0,-1,0,0,0,1,0.5,0,0,0,0,0,0,-0.866,0,0,-1,0},aux2,aux1; 
	float matriz[3][4] = {{30,-20,0,19.6},{-20,30,-10,29.4},{0,-10,10,24.5}},aux2,aux1; 
	int i,j,contador1=0,contador2=0,contador3=0,posicao=1,z=1,condicao;
	int qtdlinha=3,qtdcoluna=4;
	
	printf("Digite 1 se deseja usar a matriz padrão e 0 caso contrario\n");
	scanf("%d",&condicao);
	
	
	printf("qtd linha: %d qtd coluna: %d",qtdlinha,qtdcoluna);
	funcao_printar(qtdlinha,qtdcoluna,matriz);
	
	
			
	while(contador2!=(qtdcoluna-1)){
	printf("\n");
	
	if(matriz[contador1][contador2]==0){
		if(pivor_zero(contador1,contador2,qtdlinha,qtdcoluna,matriz)==true){
		contador2++; printf("entrei!!");
		}						
	}
	if(matriz[contador1][contador2]!=1){
		aux2=matriz[contador1][contador2];
		for(j=0;j<qtdcoluna;j++){
			matriz[contador1][j]=matriz[contador1][j]/aux2;            
			contador3++;
		}
	}
	
	for(i=0;i<qtdlinha;i++){
		aux1=matriz[i][contador2];
		for(j=0;j<qtdcoluna;j++){
			if(i!=contador1){
				matriz[i][j]=matriz[i][j]-aux1*matriz[contador1][j];
			}	
		}
	}
	contador1++;contador2++;
	funcao_printar(qtdlinha,qtdcoluna,matriz);
	sistema_impossivel_infinitas(qtdlinha,qtdcoluna,matriz);
	printf("\n");

	}
	printf("\n");
	printf("matriz resultante:\n");
	funcao_printar(qtdlinha,qtdcoluna,matriz);
    funcao_variavel(qtdlinha,qtdcoluna,matriz);
	return 0;
}
