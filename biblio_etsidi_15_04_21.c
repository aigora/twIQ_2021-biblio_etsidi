#include<stdio.h>
#include<string.h>
#define N 100

struct listado{
	
	char titulo[50];
	//char autor[50];
	//char genero[30];
	//char editorial[30];
	//int npaginas;
	//int edicion;
	int anio;
};

int main(){
	system("COLOR CF"); 	
	FILE * fentrada, * fnueva_entrada;
		
	struct listado libro[N];
	
	int volver;
	int opcionmenuprincipal; 
	int entradas;//numero de entradas cada vez que se ingresan unos datos
	int i;	
	
	do{
		
		printf("MENU INICIO");
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
		printf("                                           ***************************\n");
		printf("                                           *   1.CONSULTA            *\n");
		printf("                                           *   2.NUEVA ENTRADA       *\n");
		printf("                                           *   3.SALIR DEL PROGRAMA  *\n");
		printf("                                           ***************************\n");
		do{
			scanf("%d",&opcionmenuprincipal);
				if(opcionmenuprincipal<1||opcionmenuprincipal>3)
				printf("OPCION INCORRECTA. VUELVA A INTENTARLO\n");			
			}while(opcionmenuprincipal<1||opcionmenuprincipal>3);			
			
				
			switch(opcionmenuprincipal){
				
				case 1:{//Se abre fichero en modo lectura
					
					system("cls");
					printf("MENU INICIO/CONSULTA\n");
					fentrada = fopen("entrada.txt","r");
					if(fentrada==NULL){
					printf("Error: el fichero no se ha encontrado");
					}
					while(fscanf(fentrada,"%s %d",libro[i].titulo,&libro[i].anio)!=EOF){
						printf("%s %d\n", libro[i].titulo,libro[i].anio);
						i++;
					}
					fclose(fentrada);
					printf("Pulse 1 para volver al menu principal\n");
					scanf("%d",&volver);
					system("cls");
					break;
				}
								
				case 2:{
					system("cls");
					printf("MENU INICIO/NUEVA ENTRADA\n");
					
					fnueva_entrada = fopen("nueva_entrada.txt","w");
						if(fnueva_entrada == NULL){ 
						printf("Error abriendo el fichero para escritura"); 						
						}
						
					printf("Cuantas entradas va a realizar?\n");
					scanf("%d",&entradas);					
					for(i=0;i<entradas;i++){						
						printf("Introduzca el titulo y el anio de la obra:\n");
						scanf("%s %d",libro[i].titulo,&libro[i].anio);
						fprintf(fnueva_entrada,"%s %d\n",libro[i].titulo,libro[i].anio);
					}				
					fclose(fnueva_entrada);
					
					printf("Pulse 1 para volver al menu principal\n");
					scanf("%d",&volver);
					system("cls");
					break;
				}					
					
			}
			
}while(volver=1);
}
					
					
/*
					
					
					switch(opcionedicion){						
										
						case 1:{		
								                                           //////////////EDICION/  NUEVA ENTRADAAAAAAAAAAAAAAAAAAAAAAAAAa
								printf("MENU EDICION/NUEVA ENTRADA\n");
								for(i=0;i<N;i++){
									
									printf("\nIntroduzca el titulo de la obra:\n");
									gets(libro[i].titulo);
									fflush(stdin);
									printf("Introduzca el autor de la obra:\n");
									gets(libro[i].autor);
									fflush(stdin);
									printf("Introduzca el genero de la obra:\n");
									gets(libro[i].genero);
									fflush(stdin);
									printf("Introduzca la editorial:\n");
									gets(libro[i].editorial);
									fflush(stdin);
									printf("Introduzca el numero de paginas:\n");
									scanf("%d",&libro[i].npaginas);
									fflush(stdin);
									printf("Introduzca el numero de edicion:\n");
									scanf("%d",&libro[i].edicion);
									fflush(stdin);
									printf("Introduzca el anio de lanzamiento de la obra:\n");
									scanf("%d",&libro[i].anio);
									fflush(stdin);
		
									printf("\n");
									printf("%d.TITULO: %s\n",i+1, libro[i].titulo);
									printf("AUTOR: %s\n", libro[i].autor);
									printf("GENERO: %s\n", libro[i].genero);
									printf("EDITORIAL: %s\n", libro[i].editorial);									
									printf("NUMERO DE PAGINAS: %d\n", libro[i].npaginas);
									printf("EDICION: %d\n", libro[i].edicion);									
									printf("ANIO: %d\n", libro[i].anio);
									
								do{
									printf("\n");
									printf("Marque la opcion:\n");
									printf("\n");
									printf("1 - Realizar otra entrada\n");
									printf("2 - Ver listado de los documentos introducidos\n");
									printf("3 - Volver al menu inicio\n");
								
									scanf("%d", &opcionfinalmenuentrada);
									fflush(stdin);
		
									switch(opcionfinalmenuentrada){			
											case 1: 
											break;	
											case 2:{
												
												do{
														printf("\nIndique el numero de documentos que quiere ver\n");
														scanf("%d",&entradas);
													    	if(entradas>i+1 || entradas<=0){
													    	printf("Numero incorrecto");
															}
														}while(entradas>i+1 || entradas<=0);							
												
															
													system("cls");
													printf("\n");
													printf("LISTADO ENTRADAS:\n");//MUESTRA LISTADO DE ENTRADAS
													printf("\n");
													
													for(i=0;i<entradas;i++){
													printf("%d. %s %s %s %s %d paginas edicion %d %d\n",i+1,libro[i].titulo, libro[i].autor, libro[i].genero, libro[i].editorial, libro[i].npaginas, libro[i].edicion, libro[i].anio);	
													}
																									
												}
												break;// AQUI DEBE VOLVER AL MENU PRINCIPAL. NO HAY OTRA OPCION
											
											case 3: 
												system("cls"); //VOLVER A MENU INICIALLLLLLLLLLLLLLLL
												break;
									}																
								 }while(opcionfinalmenuentrada==2);
								}										
															
															
						break;
						} //CIERRA SWITCH 1 NUEVA ENTRADA
					//	case 2:MODIFICAR DATOS 
					//	case 3:ELIMINAR UN DOCUMENTO
						case 4:
							system("cls");
						break;
					}//CIERRA SWITCH MENU EDICIOOOOOOO													
								
				break;//cierra CASE 2 EDICIOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
				case 3: //SALIR DEL PROGRAMAAAAAAAAAAAAAAAAAAAAAAAAAAAA
					printf("HAVE A NICE DAY\n");
				return 0;
			}//CIERRA SWITCH MENU PRINCIPAL
		
	}while(opcionconsulta==2 || opcionedicion==4);
	
	*/	

			
						

		
	
		

		
	
