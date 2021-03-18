#include<stdio.h>


int main(){
	
	int opcion;
	
	
		system("COLOR CF"); 
		printf("\n");
		printf("\n");	
		printf("\n");
		printf("\n");
		printf("                                    BIENVENIDO A TU BIBLIOTECA PERSONAL\n");
		printf("\n");
		printf("\n");
		printf("\n");	
		printf("                                      POR FAVOR SELECCIONA UNA OPCION\n");
		printf("\n");
		printf("                                           ******************\n");
		printf("                                           *   1.CONSULTA   *\n");
		printf("                                           *   2.EDICION    *\n");
		printf("                                           ******************\n");
		
	
			
		do{
			scanf("%d",&opcion);
				if(opcion<1||opcion>2)
				printf("OPCION INCORRECTA. VUELVA A INTENTARLO\n");			
			}while(opcion<1||opcion>2);
				
			switch(opcion){
			case 1:
			printf("USTED HA SELECCIONADO CONSULTAR UN DOCUMENTO");
				break;
			case 2:
			printf("USTED HA SELECCIONADO EDITAR UN DOCUMENTO");
				break;
					
			}
		
			//system("cls");
		}
			
						
			
		
	
		

		
	
	

