#include<stdio.h>
#include<string.h>
#define N 500

void banner(){
	
		printf("			------********---**********----*******-----****----**-**-------****-------\n");
		printf("			------**-------------**------**-------------**-----**----**-----**--------\n");	
		printf("			------**-------------**------**-------------**-----**-----**----**--------\n");
		printf("			------********-------**--------**--**-------**-----**-----**----**--------\n");
		printf("			------**-------------**--------------**-----**-----**-----**----**--------\n");                                  
		printf("			------**-------------**--------------**-----**-----**----**-----**--------\n");
		printf("			------********-------**-------******-------****----**-**-------****-------\n");

}
struct listado{
	   
	char titulo[50];
	char autor[50];
	char genero[30];
	char editorial[30];
	int npaginas;
	int edicion;
	int anio;
};
int main(){
	system("COLOR CF"); 	
	FILE * fentrada, * fclave;
		
	struct listado libro[N];	
	
	int parametro, encontrados, resultado, lineas;
	int opcionmenuprincipal; 
	char titulo[50];
	char autor[50];
	char genero[30];
	char editorial[30];
	int npaginas, edicion, anio;
	char usuario[15], usuario1[10];
	int i, clave, clave1;	

		printf("\n");
		printf("\n");
		printf("\n");	
		printf("\n");
		printf("\n");
		printf("\n"); 
		banner();                                 
		printf("\n");
		printf("\n");
		printf("\n");	
		printf("                               Introduzca nombre de usuario y clave para iniciar sesion\n");
		printf("\n");
		printf("\n");
		printf("\n");
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
				
				case 1:{//CONSULTA
					
					system("cls");
					printf("MENU INICIO/CONSULTA\n");


					fentrada = fopen("entrada.txt","r");
					if(fentrada==NULL){
					printf("Error: el fichero no se ha encontrado");
					return 0;
					}
					i=0;
					lineas=0;
					while(fscanf(fentrada,"%s %s %s %s %d %d %d",libro[i].titulo, libro[i].autor, libro[i].genero, libro[i].editorial, &libro[i].npaginas, &libro[i].edicion, &libro[i].anio)!=EOF){
					printf("%s %s %s %s %d %d %d\n", libro[i].titulo, libro[i].autor, libro[i].genero, libro[i].editorial, libro[i].npaginas, libro[i].edicion, libro[i].anio);
					i++;
					lineas++;
					}
					fclose(fentrada);
					
					printf("\nNumero total de archivos encontrados: %d\n",lineas);					
					
						printf("\nIntroduzca la opcion de busqueda para filtrado de datos:\n");
						//printf("Nota: la primera letra en mayuscula y uniendo las palabras con _");
						printf("\nOpcion 1: buscar por titulo\n");
						printf("Opcion 2: buscar por autor\n");
						printf("Opcion 3: buscar por genero\n");
						printf("Opcion 4: buscar por editorial\n");
						printf("Opcion 5: buscar por anio\n");					
						scanf("%d",&parametro);
					
						switch(parametro){
							
								case 1:{			                       				
								printf("Introduzca el titulo: ");
								fflush(stdin);
								gets(titulo);
								printf("\n");
								system("cls");						
								encontrados=0;
								for(i=0;i<lineas;i++){									    						
									resultado=strcmp(titulo, libro[i].titulo);
									if(resultado==0){								
										printf("%s %s %s %s %d %d %d\n", libro[i].titulo, libro[i].autor, libro[i].genero, libro[i].editorial, libro[i].npaginas, libro[i].edicion, libro[i].anio);
										encontrados++;
									}
								}									
									if(encontrados==0)
										printf("No existen coincidencias con tu busqueda\n");
									else
										printf("\nSe han encontrado %d coincidencias\n", encontrados);							
						
								break;
								}
								case 2:{			                       				
								printf("Introduzca el autor: ");
								fflush(stdin);
								gets(autor);
								printf("\n");
								system("cls");						
								encontrados=0;
								for(i=0;i<lineas;i++){									    						
									resultado=strcmp(autor, libro[i].autor);
									if(resultado==0){								
										printf("%s %s %s %s %d %d %d\n", libro[i].titulo, libro[i].autor, libro[i].genero, libro[i].editorial, libro[i].npaginas, libro[i].edicion, libro[i].anio);
										encontrados++;
									}
								}									
									if(encontrados==0)
										printf("No existen coincidencias con tu busqueda\n");
									else
										printf("\nSe han encontrado %d coincidencias\n", encontrados);							
						
								break;
								}
								case 3:{			                       				
								printf("Introduzca el genero: ");
								fflush(stdin);
								gets(genero);
								printf("\n");
								system("cls");						
								encontrados=0;
								for(i=0;i<lineas;i++){									    						
									resultado=strcmp(genero, libro[i].genero);
									if(resultado==0){								
										printf("%s %s %s %s %d %d %d\n", libro[i].titulo, libro[i].autor, libro[i].genero, libro[i].editorial, libro[i].npaginas, libro[i].edicion, libro[i].anio);
										encontrados++;
									}
								}									
									if(encontrados==0)
										printf("No existen coincidencias con tu busqueda\n");
									else
										printf("\nSe han encontrado %d coincidencias\n", encontrados);							
						
								break;
								}
								case 4:{			                       				
								printf("Introduzca la editorial: ");
								fflush(stdin);
								gets(editorial);
								printf("\n");
								system("cls");						
								encontrados=0;
								for(i=0;i<lineas;i++){									    						
									resultado=strcmp(editorial, libro[i].editorial);
									if(resultado==0){								
										printf("%s %s %s %s %d %d %d\n", libro[i].titulo, libro[i].autor, libro[i].genero, libro[i].editorial, libro[i].npaginas, libro[i].edicion, libro[i].anio);
										encontrados++;
									}
								}									
									if(encontrados==0)
										printf("No existen coincidencias con tu busqueda\n");
									else
										printf("\nSe han encontrado %d coincidencias\n", encontrados);							
						
								break;
								}
								case 5:{						
															
									printf("Introduzca anio de lanzamiento: ");
									scanf("%d",&anio);
										system("cls");			
										encontrados=0;
										for(i=0;i<lineas;i++){
											if(anio==libro[i].anio){
												printf("%s %s %s %s %d %d %d\n", libro[i].titulo, libro[i].autor, libro[i].genero, libro[i].editorial, libro[i].npaginas, libro[i].edicion, libro[i].anio);
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
				case 2:{//NUEVA ENTRADA
					system("cls");
					printf("MENU INICIO/NUEVA ENTRADA\n");
					
					fentrada = fopen("entrada.txt","w");
						if(fentrada == NULL){ 
						printf("Error abriendo el fichero para escritura"); 
						return 0;						
						}
																
						printf("Introduzca el titulo, autor, genero, editorial, numero de paginas, edicion y anio de la obra:\n");
						fflush(stdin);
						scanf("%s %s %s %s %d %d %d",libro[i].titulo, libro[i].autor, libro[i].genero, libro[i].editorial, &libro[i].npaginas, &libro[i].edicion, &libro[i].anio);
					for(i=0;i<lineas+1;i++){
						fprintf(fentrada,"%s %s %s %s %d %d %d\n",libro[i].titulo, libro[i].autor, libro[i].genero, libro[i].editorial, libro[i].npaginas, libro[i].edicion, libro[i].anio);			
					}
					fclose(fentrada);
					
					getchar();
					printf("\nPulse una tecla para volver al menu principal\n");
					getchar();
					system("cls");
					break;
				}	
				case 3:	//SALIR DEL PROGRAMA
					system("cls");
					//getchar();
					printf("MENU INICIO/SALIR DEL PROGRAMA\n");	
					printf("HASTA PRONTO!\n");	
					banner();   		
					//printf("Pulse una tecla para finalizar\n");
					//getchar();
					
				return 0;		
			}//switch menu principal

	}//while
	
}//main
		
		

	
		

		
	
