#include <iostream>
#include <cstdlib>

using namespace std;
int pardevertices[100][3]; //la arista con su peso
int vertices, aristas, temp1, temp2, temp3, i,j;
int arbol[100][3];
void leergrafo(void);
void imprimegrafo(void);
void ordenarmayor(void);
void imprimearbol(void);
int main(int argc, char *argv[])
{
	int aristarbol,U[100],a,b,num_aristas;
	leergrafo();
	imprimegrafo();
	ordenarmayor();
	imprimegrafo();
	aristarbol=0;
	num_aristas=0;
	for(i=0;i<vertices; i++){
		U[i]=i;
	}
	while(aristarbol< vertices-1){
            a=pardevertices[num_aristas][0];//primer verice
            b=pardevertices[num_aristas][1];//segundo vertice
            i=a;
            while(U[i]!=i) i=U[i];
            j=b;
            while(U[j]!=j) j=U[j];
            
            if(i!=j){

            	if(i < j) U[j]=i;
            	else U[i]=j;

            	arbol[aristarbol][0]=a;
            	arbol[aristarbol][1]=b;
            	arbol[aristarbol][2]=pardevertices[num_aristas][2];
            	aristarbol++;               
            }
            num_aristas++;            
    }//fin while
    
    imprimearbol();
    system("PAUSE");
    return 0;
  }

  void leergrafo(void){
  	printf("Cuantos vertices tiene el grafo\n");
  	scanf("%d", &vertices);
  	printf("Cuantos aristas tiene el grafo\n");
  	scanf("%d", &aristas);
  	for(int i=0; i<aristas; i++){
  		printf("Dame la arista %d \n", i+1);
  		scanf("%d", &pardevertices[i][0]);
  		scanf("%d", &pardevertices[i][1]);
  		pardevertices[i][0]=pardevertices[i][0]-1;
  		pardevertices[i][1]=pardevertices[i][1]-1;
  		printf("Valor de la arista: \n");
  		scanf("%d", &pardevertices[i][2]);
  	} 
  }

  void imprimegrafo(void){
  	int i;
  	printf("\nGrafo: \n");
  	for(int i=0; i<aristas; i++){
  		printf("%d %d %d\n", pardevertices[i][0]+1, pardevertices[i][1]+1, pardevertices[i][2]);
  	}
  }

  void ordenarmayor(void){
  	for(i=0;i< aristas; i++){
  		for(j=i+1; j< aristas; j++){
  			if(pardevertices[j][2]<pardevertices[i][2]){
  				temp1=pardevertices[i][0];
  				temp2=pardevertices[i][1];
  				temp3=pardevertices[i][2];
  				pardevertices[i][0]=pardevertices[j][0];
  				pardevertices[i][1]=pardevertices[j][1];
  				pardevertices[i][2]=pardevertices[j][2];
  				pardevertices[j][0]=temp1;
  				pardevertices[j][1]=temp2;
  				pardevertices[j][2]=temp3;                                                     
  			}                           
  		}                     
  	}     
  }

  void imprimearbol(void){
  	int i;
  	printf("\nArbol de expancion Minima: \n");
  	for(int i=0; i<vertices-1; i++){
  		printf("%d %d %d\n", arbol[i][0]+1, arbol[i][1]+1, arbol[i][2]);
  	}
  }
