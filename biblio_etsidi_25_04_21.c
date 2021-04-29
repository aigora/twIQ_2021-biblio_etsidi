#include<stdio.h>
#include<string.h>
#define N 100

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
	//char autor[50];
	char genero[30];
	//char editorial[30];
	//int npaginas;
	//int edicion;
	int anio;
};

int main(){
	system("COLOR CF"); 	
	FILE * fentrada, * fclave;
		
	struct listado libro[N];
	
	int parametro, encontrados, resultado, anio, lineas;
	int opcionmenuprincipal; 
	char genero[30];
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
				
				case 1:{//Se abre fichero en modo lectura CONSULTA
					
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
					
					printf("\nNumero total de archivos encontrados: %d\n",lineas);					
					
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
								system("cls");						
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
										system("cls");			
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
					
					fentrada = fopen("entrada.txt","w");
						if(fentrada == NULL){ 
						printf("Error abriendo el fichero para escritura"); 
						return 0;						
						}
																
						printf("Introduzca el titulo, genero y anio de la obra:\n");
						scanf("%s %s %d",libro[i].titulo, libro[i].genero,&libro[i].anio);
					for(i=0;i<lineas+1;i++){
						fprintf(fentrada,"%s %s %d\n",libro[i].titulo, libro[i].genero,libro[i].anio);			
					}
					fclose(fentrada);
					
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
					banner();   		
					//printf("Pulse una tecla para finalizar\n");
					//getchar();
					
				return 0;		
			}//switch menu principal

	}//while
	
}//main
		
		

	
		

		
	
