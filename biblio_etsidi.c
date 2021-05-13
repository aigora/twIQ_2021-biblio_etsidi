#include<stdio.h>
#include<string.h>
#define N 500

struct libro{//Estructura con los elementos característicos de cada libro
	   
	char titulo[50];
	char autor[50];
	char genero[30];
	char editorial[30];
	int npaginas;
	int edicion;
	int anio;
};
//PROTOTIPOS de funciones
void Banner();
void MenuClave(); 
void MenuInicio();
void MenuFiltrado(struct libro listado[], int lineas);
void ConsultaTitulo(struct libro listado[], int lineas);
void ConsultaAutor(struct libro listado[], int lineas);
void ConsultaGenero(struct libro listado[], int lineas);
void ConsultaEditorial(struct libro listado[], int lineas);
void ConsultaAnio(struct libro listado[], int lineas);

int main(){
	system("COLOR CF"); 	
	FILE * fentrada, * fclave;//Declaración de punteros tipo FILE llamados fentrada y fclave
		
	struct libro listado[N];//Vector de estructuras. Listado de N libros
	
	int parametro, encontrados, resultado, lineas;
	int opcionmenuprincipal; 
	char titulo[50];
	char autor[50];
	char genero[30];
	char editorial[30];
	int npaginas, edicion, anio;
	int i, clave, clave1, comparador=0;//clave1 y usuario1 son los datos previamente registrados en el fuchero "fclave"
	char usuario[20], usuario1[20];	

		printf("\n");
		printf("\n");
		printf("\n");	
		printf("\n");
		printf("\n");
		printf("\n"); 
		Banner();    //Llamada a funcion Banner 
		MenuClave(); // Llamada a función MenuClave	                         

		fclave = fopen("clave.txt","r");//Abre fichero fclave
		if(fclave==NULL){
			printf("Error en la apertura de fichero\n");
		}
		fscanf(fclave,"%s %d",usuario1, &clave1);//Copia fichero fclave en memoria		
		fclose(fclave);//Cierra fichero fclave
				
		do{	//Compara datos de fclave con datos introducidos por teclado para inicio sesión
			scanf("%s %d",usuario, &clave);	
			comparador = strcmp(usuario,usuario1);	
			if(clave1!=clave || comparador!=0){
				printf("Clave de acceso incorrecta. Vuelva a intentarlo\n");					
			}						
		}while(clave1!=clave || comparador!=0);
		
		if(clave1==clave && comparador==0)
			printf("Los datos introducidos son correctos\n");	
			getchar();
			printf("Pulse una tecla para continuar");
			getchar();						
			
    while(1){
    
		system("cls");
		MenuInicio();	//Llamada a funcion del menu inicio			

		do{//Selección de opción del menú principal
			scanf("%d",&opcionmenuprincipal);
				if(opcionmenuprincipal<1||opcionmenuprincipal>3)
				printf("OPCION INCORRECTA. VUELVA A INTENTARLO\n");			
			}while(opcionmenuprincipal<1||opcionmenuprincipal>3);			
				
			switch(opcionmenuprincipal){
				
				case 1:{//Opción consulta de los datos existentes en fichero fentrada					
					system("cls");
					printf("MENU INICIO/CONSULTA\n");

					fentrada = fopen("entrada.txt","r");//Apertura fichero fentrada
					if(fentrada==NULL){
					printf("Error: el fichero no se ha encontrado");
					return 0;
					}
					i=0;
					lineas=0;//Trabajamos con los datos del fichero fentrada en memoria a partir de la siguiente linea
					while(fscanf(fentrada,"%s %s %s %s %d %d %d",listado[i].titulo, listado[i].autor, listado[i].genero, listado[i].editorial, &listado[i].npaginas, &listado[i].edicion, &listado[i].anio)!=EOF){
					printf("%s %s %s %s %d %d %d\n", listado[i].titulo, listado[i].autor, listado[i].genero, listado[i].editorial, listado[i].npaginas, listado[i].edicion, listado[i].anio);
					i++;
					lineas++;
					}
					fclose(fentrada);//Cierre fichero fentrada
					
					printf("\nNumero total de archivos encontrados: %d\n",lineas);//"lineas" nos ayudará a concretar la extensión del listado					
					
					MenuFiltrado(listado, lineas); //Llamada a funcion MenuFiltrado								
					
					printf("\nPulse una tecla para volver al menu principal\n");
					getchar();
					system("cls");
					break;//gracias al while inicial, al salir con break se repite todo el proceso desde menú inicial.
				}//Cierra opción consulta				
				case 2:{//Opción nueva entrada
					system("cls");
					printf("MENU INICIO/NUEVA ENTRADA\n");
					
					fentrada = fopen("entrada.txt","w");//Abre fichero fentrada en modo escritura
						if(fentrada == NULL){ 
						printf("Error abriendo el fichero para escritura"); 
						return 0;						
						}
																
						printf("Introduzca el titulo, autor, genero, editorial, numero de paginas, edicion y anio de la obra:\n");
						fflush(stdin);//Podemos hacer una nueva entrada que incluya cada uno de los elementos de la estructura libro. Se guarda en memoria
						scanf("%s %s %s %s %d %d %d",listado[i].titulo, listado[i].autor, listado[i].genero, listado[i].editorial, &listado[i].npaginas, &listado[i].edicion, &listado[i].anio);
					for(i=0;i<lineas+1;i++){//Guardamos en fichero los datos anteriores más la nueva entrada
						fprintf(fentrada,"%s %s %s %s %d %d %d\n",listado[i].titulo, listado[i].autor, listado[i].genero, listado[i].editorial, listado[i].npaginas, listado[i].edicion, listado[i].anio);			
					}
					fclose(fentrada);//cierra fichero fentrada
					
					getchar();
					printf("\nPulse una tecla para volver al menu principal\n");
					getchar();
					system("cls");
					break;//Vuelve a menu inicial
				}	
				case 3:	//Opcion salir del programa
					system("cls");					
					printf("MENU INICIO/SALIR DEL PROGRAMA\n");	
					printf("HASTA PRONTO!\n");	
					Banner(); //Llamada a funcion Banner  					
				return 0;		
			}//cierra switch menu principal

	}//cierra while
	
}//cierra función main
		
//FUNCIONES	
void Banner(){
	
		printf("			------********---**********----*******-----****----**-**-------****-------\n");
		printf("			------**-------------**------**-------------**-----**----**-----**--------\n");	
		printf("			------**-------------**------**-------------**-----**-----**----**--------\n");
		printf("			------********-------**--------**--**-------**-----**-----**----**--------\n");
		printf("			------**-------------**--------------**-----**-----**-----**----**--------\n");                                  
		printf("			------**-------------**--------------**-----**-----**----**-----**--------\n");
		printf("			------********-------**-------******-------****----**-**-------****-------\n");

}
void MenuClave(){
	
		printf("\n");
		printf("\n");
		printf("\n");	
		printf("                               Introduzca nombre de usuario y clave para iniciar sesion\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
}
void MenuInicio(){
	
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
}
void MenuFiltrado(struct libro listado[], int lineas){//Funcion que contiene menu consulta y las funciones de filtrado de datos
	
	int parametro;

						printf("\nIntroduzca la opcion de busqueda para filtrado de datos:\n");
						printf("\nOpcion 1: buscar por titulo\n");
						printf("Opcion 2: buscar por autor\n");
						printf("Opcion 3: buscar por genero\n");
						printf("Opcion 4: buscar por editorial\n");
						printf("Opcion 5: buscar por anio\n");
						printf("Opcion 6: volver al menu inicial\n");					
						scanf("%d",&parametro);
					
						switch(parametro){	//Llamada a funciones de consulta. Filtrado según componentes de la estructura libro						
								case 1:			                       				
									ConsultaTitulo(listado, lineas);						
								break;								
								case 2:								
									ConsultaAutor(listado, lineas);               				
								break;								
								case 3:								
									ConsultaGenero(listado, lineas);		                       				
								break;
								case 4:
									ConsultaEditorial(listado, lineas);				                       				
								break;
								case 5:
									ConsultaAnio(listado, lineas);
								break;
								case 6:
								break;								
						}  //Cierra switch Consulta
}
void ConsultaTitulo(struct libro listado[], int lineas){//Funcion de filtrado por titulo
	
		int i, encontrados, resultado;
		char titulo[50];
	
		printf("Introduzca el titulo: ");
		fflush(stdin);
		gets(titulo);
		printf("\n");
		system("cls");						
		encontrados=0;
		for(i=0;i<lineas;i++){									    						
			resultado=strcmp(titulo, listado[i].titulo);
			if(resultado==0){								
				printf("%s %s %s %s %d %d %d\n", listado[i].titulo, listado[i].autor, listado[i].genero, listado[i].editorial, listado[i].npaginas, listado[i].edicion, listado[i].anio);
			encontrados++;
			}
		}									
			if(encontrados==0)
				printf("No existen coincidencias con tu busqueda\n");
			else
				printf("\nSe han encontrado %d coincidencias\n", encontrados);	
}
void ConsultaAutor(struct libro listado[], int lineas){//Funcion de fitrado por autor
	
	int i, encontrados, resultado;
	char autor[50];
	
		printf("Introduzca el autor: ");
		fflush(stdin);
		gets(autor);
		printf("\n");
		system("cls");						
		encontrados=0;
		for(i=0;i<lineas;i++){									    						
			resultado=strcmp(autor, listado[i].autor);
			if(resultado==0){								
				printf("%s %s %s %s %d %d %d\n", listado[i].titulo, listado[i].autor, listado[i].genero, listado[i].editorial, listado[i].npaginas, listado[i].edicion, listado[i].anio);
			encontrados++;
			}
		}									
			if(encontrados==0)
				printf("No existen coincidencias con tu busqueda\n");
			else
				printf("\nSe han encontrado %d coincidencias\n", encontrados);	
}
void ConsultaGenero(struct libro listado[], int lineas){//Función de filtrado por género
	
		int i, encontrados, resultado;
		char genero[30];
	
		printf("Introduzca el genero: ");
		fflush(stdin);
		gets(genero);
		printf("\n");
		system("cls");						
		encontrados=0;
		for(i=0;i<lineas;i++){									    						
			resultado=strcmp(genero, listado[i].genero);
			if(resultado==0){								
				printf("%s %s %s %s %d %d %d\n", listado[i].titulo, listado[i].autor, listado[i].genero, listado[i].editorial, listado[i].npaginas, listado[i].edicion, listado[i].anio);
			encontrados++;
   			}
		}									
			if(encontrados==0)
				printf("No existen coincidencias con tu busqueda\n");
			else
				printf("\nSe han encontrado %d coincidencias\n", encontrados);		
}
void ConsultaEditorial(struct libro listado[], int lineas){//Función de filtrado por editorial
	
		int i, encontrados, resultado;
		char editorial[30];
			printf("Introduzca la editorial: ");
			fflush(stdin);
			gets(editorial);
			printf("\n");
			system("cls");						
			encontrados=0;
			for(i=0;i<lineas;i++){									    						
				resultado=strcmp(editorial, listado[i].editorial);
				if(resultado==0){								
					printf("%s %s %s %s %d %d %d\n", listado[i].titulo, listado[i].autor, listado[i].genero, listado[i].editorial, listado[i].npaginas, listado[i].edicion, listado[i].anio);
				encontrados++;
				}
			}									
				if(encontrados==0)
					printf("No existen coincidencias con tu busqueda\n");
				else
					printf("\nSe han encontrado %d coincidencias\n", encontrados);				
}		
void ConsultaAnio(struct libro listado[], int lineas){//Función de filtrado por año
	
		int i, encontrados, resultado;
		int anio;
		
			printf("Introduzca anio de lanzamiento: ");
			scanf("%d",&anio);
			system("cls");			
			encontrados=0;
			for(i=0;i<lineas;i++){
				if(anio==listado[i].anio){
					printf("%s %s %s %s %d %d %d\n", listado[i].titulo, listado[i].autor, listado[i].genero, listado[i].editorial, listado[i].npaginas, listado[i].edicion, listado[i].anio);
				encontrados++;
				}											
			}
				if(encontrados==0)
					printf("\nNo existen coincidencias con tu busqueda\n");
				else
					printf("\nSe han encontrado %d coincidencias\n", encontrados);		
				getchar();	
}
	
