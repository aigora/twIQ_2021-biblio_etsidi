#include<stdio.h>
#include<string.h>
#define N 100

struct listado{
	
	char titulo[50];
	//char autor[50];
	char genero[30];
	//char editorial[30];
	//int npaginas;
	//int edicion;
	int anio;
};

int main(){
	system("COLOR CF"); 	
	FILE * fentrada, * fnueva_entrada, * fclave;
		
	struct listado libro[N];
	
	int volver, parametro,narchivos, encontrados, resultado, anio, lineas=0;
	int opcionmenuprincipal; 
	int entradas;//numero de entradas cada vez que se ingresan unos datos
	int i;	
	char genero[30];
	char usuario[15], usuario1[10];
	int clave, clave1;
	

		printf("\n");
		printf("\n");	
		printf("\n");
		printf("\n");
		printf("\n");                                  
		printf("\n");
		printf("\n");
		printf("\n");	
		printf("                               Introduzca nombre de usuario y clave para iniciar sesion\n");
		printf("\n");
		printf("\n");
		
		fclave = fopen("clave.txt","r");
		if(fclave==NULL){
			printf("Error en la apertura de fichero\n");
		}
		fscanf(fclave,"%s %d", usuario1, &clave1);		
		fclose(fclave);
		
		do{	
			scanf("%s %d",usuario, &clave);		
			if(usuario1!=usuario && clave1!=clave){
				printf("Clave incorrecta. Vuelva a intentarlo\n");					
			}						
		}while(usuario1!=usuario && clave1!=clave);
		
		do{
			printf("Los datos introducidos son correctos\n");
		}while(usuario1 == usuario && clave1==clave);
	
			getchar();
			printf("Pulse una tecla para continuar");
			getchar();
			
			
			
    while(1){	
    
		system("cls");				
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
				
				case 1:{//Se abre fichero en modo lectura CONSULTAAAAAAAAAAAAAAAAAAAAAAAAAAAAAa
					
					system("cls");
					printf("MENU INICIO/CONSULTA\n");


					fentrada = fopen("entrada.txt","r");
					if(fentrada==NULL){
					printf("Error: el fichero no se ha encontrado");
					return 0;
					}
					i=0;
					lineas=0;
					while(fscanf(fentrada,"%s %s %d",libro[i].titulo,libro[i].genero, &libro[i].anio)!=EOF){
					printf("%s %s %d\n", libro[i].titulo,libro[i].genero,libro[i].anio);
					i++;
					lineas++;
					}
					fclose(fentrada);
					
					printf("Numero total de archivos encontrados: %d\n",lineas);					
					
						printf("\nIntroduzca la opcion de busqueda para filtrado de datos:\n");
						printf("Opcion 1: buscar por genero\n");
						printf("Opcion 2: buscar por anio de lanzamiento\n");					
						scanf("%d",&parametro);
					
						switch(parametro){
							
								case 1:{			                       ///busqueda por genero				
								printf("Introduzca el genero: ");
								fflush(stdin);
								gets(genero);
								printf("\n");						
								encontrados=0;
								for(i=0;i<lineas;i++){		
								    						
									resultado=strcmp(genero, libro[i].genero);
									if(resultado==0){								
										printf("%s %s %d\n", libro[i].titulo,libro[i].genero,libro[i].anio);
										encontrados++;
									}
								}									
									if(encontrados==0)
										printf("No existen coincidencias con tu busqueda\n");
									else
										printf("\nSe han encontrado %d coincidencias\n", encontrados);							
						
								break;
								}
							
								case 2:{							///busqueda por aniooooooooooooooooooooooo
															
									printf("Introduzca anio de lanzamiento: ");
									scanf("%d",&anio);			
										encontrados=0;
										for(i=0;i<lineas;i++){
											if(anio==libro[i].anio){
												printf("%s %s %d\n", libro[i].titulo,libro[i].genero,libro[i].anio);
												encontrados++;
											}											
										}
											if(encontrados==0)
												printf("\nNo existen coincidencias con tu busqueda\n");
											else
												printf("\nSe han encontrado %d coincidencias\n", encontrados);		
											getchar();	
								break;
								}
						}  //SALIDA SWITCH BUSQUEDA									
					
					//getchar();
					printf("\nPulse una tecla para volver al menu principal\n");
					getchar();
					system("cls");
					break;
				}//CIERRA OPCION CONSULTA
				
				
				
								
				case 2:{//se abre fichero nueva_entrada en modo escritura
					system("cls");
					printf("MENU INICIO/NUEVA ENTRADA\n");
					
					fnueva_entrada = fopen("nueva_entrada.txt","w");
						if(fnueva_entrada == NULL){ 
						printf("Error abriendo el fichero para escritura"); 
						return 0;						
						}
						
					printf("Cuantas entradas va a realizar?\n");
					scanf("%d",&entradas);					
					for(i=0;i<entradas;i++){						
						printf("Introduzca el titulo, genero y anio de la obra:\n");
						scanf("%s %s %d",libro[i].titulo, libro[i].genero,&libro[i].anio);
						fprintf(fnueva_entrada,"%s %s %d\n",libro[i].titulo, libro[i].genero,libro[i].anio);			
					}
					fclose(fnueva_entrada);
					
					getchar();
					printf("\nPulse una tecla para volver al menu principal\n");
					getchar();
					system("cls");
					break;
				}	
				case 3:	
					system("cls");
					//getchar();
					printf("MENU INICIO/SALIR DEL PROGRAMA\n");	
					printf("HASTA PRONTO!\n");			
					//printf("Pulse una tecla para finalizar\n");
					//getchar();
					
				return 0;		
			}//switch menu principal

	}//while
	
}//main
		
		
		
		
	
					
					
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

			
						

		
	
		

		
	
