#include<stdio.h>
#include<string.h>


int main(){
	
	int opcion;
	
		system("COLOR CF"); 
		
		printf("\n");
		printf("\n");	
		printf("\n");
		printf("\n");
		printf("                                      BIENVENIDO A TU BIBLIOTECA PERSONAL\n");
		printf("\n");
		printf("\n");
		printf("\n");	
		printf("                                        POR FAVOR SELECCIONA UNA OPCION\n");
		printf("\n");
		printf("\n");
		printf("                                              ******************\n");
		printf("                                              *   1.CONSULTA   *\n");
		printf("                                              *   2.EDICION    *\n");
		printf("                                              ******************\n");
		
	
			
		do{
			scanf("%d",&opcion);
				if(opcion<1||opcion>2)
				printf("OPCION INCORRECTA. VUELVA A INTENTARLO\n");			
			}while(opcion<1||opcion>2);
				
			switch(opcion){
			case 1:
					system("cls");
					printf("HA SELECCIONADO CONSULTAR UN DOCUMENTO");
					
					printf("\n");
					printf("\n");	
					printf("\n");
					printf("\n");
										
					printf("                                          POR FAVOR ELIGE UNA OPCION\n");
					printf("\n");
					printf("\n");
					printf("                                        ******************************\n");
					printf("                                        *   1.BUSQUEDA               *\n");
					printf("                                        *   2.VOLVER AL MENU INICIO  *\n");
					printf("                                        ******************************\n");
					break;
			case 2:
					system("cls");
					printf("HA SELECCIONADO EDITAR UN DOCUMENTO");
										
					printf("\n");
					printf("\n");	
					printf("\n");
					printf("\n");
										
					printf("                                             POR FAVOR ELIGE UNA OPCION\n");
					printf("\n");
					printf("\n");
					printf("                                         ***********************************\n");
					printf("                                         *   1.NUEVA ENTRADA               *\n");
					printf("                                         *   2.MODIFICAR DATOS/COMENTARIOS *\n");
					printf("                                         *   3.ELIMINAR UN DOCUMENTO       *\n");
					printf("                                         *   4.VOLVER AL MENU INICIO       *\n");
					printf("                                         ***********************************\n");
					break;
					
			}
		
			
		}
			
						
			
		
	
		

		
	
	

