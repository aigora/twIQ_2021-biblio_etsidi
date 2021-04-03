#include<stdio.h>
#include<string.h>
#define N 100

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
	
	struct listado libro[N];
	int opcionmenuprincipal; //menu principal opciones 1 o 2
	int entradas;//numero de entradas cada vez que se ingresan unos datos
	int opcionfinalmenuentrada;//opciones al salir de submenu entrada
	int opcionconsulta;//Opciones en el submenu consulta
	int opcionedicion;//Opciones en el submenu edicion
	int i;
	
	
	
	do{
	
		system("COLOR CF"); 
		
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
		printf("                                           *   2.EDICION             *\n");
		printf("                                           *   3.SALIR DEL PROGRAMA  *\n");
		printf("                                           ***************************\n");
		
	
			
		do{
			scanf("%d",&opcionmenuprincipal);
				if(opcionmenuprincipal<1||opcionmenuprincipal>3)
				printf("OPCION INCORRECTA. VUELVA A INTENTARLO\n");			
			}while(opcionmenuprincipal<1||opcionmenuprincipal>3);
				
			switch(opcionmenuprincipal){
				case 1:////////////////////////////////////////////////////////////////////////////////////////////////CONSULTA
					system("cls");
					printf("MENU CONSULTA");
					
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
					
					
									
											do{
												scanf("%d",&opcionconsulta);
													if(opcionconsulta<1||opcionconsulta>2)
														printf("OPCION INCORRECTA. VUELVA A INTENTARLO\n");			
											}while(opcionconsulta<1||opcionconsulta>2);
											
											switch(opcionconsulta){
												case 1:
													system("cls");
													printf("CONSULTA/BUSQUEDA");// BUSQUEDAAAAAAAAAAAAAAAAAAAAAAA
												break;
												case 2:// VUELVE A MENU PRINCIPALLLLLLLLLLLLLLLL
													system("cls");	
													break;
											}
					
				break;				
				case 2://///////////////////////////////////////////////////////EDICION
					system("cls");
					printf("MENU EDICION");
										
					printf("\n");
					printf("\n");	
					printf("\n");
					printf("\n");
										
					printf("                                             POR FAVOR ELIGE UNA OPCION\n");
					printf("\n");
					printf("\n");
					printf("                                         ***********************************\n");
					printf("                                         *   1.NUEVA ENTRADA               *\n");
					printf("                                         *   2.MODIFICAR DATOS             *\n");
					printf("                                         *   3.ELIMINAR UN DOCUMENTO       *\n");
					printf("                                         *   4.VOLVER AL MENU INICIO       *\n");
					printf("                                         ***********************************\n");
					
					
					
						do{
							scanf("%d",&opcionedicion);
							if(opcionedicion<1||opcionedicion>4)
								printf("OPCION INCORRECTA. VUELVA A INTENTARLO\n");			
						}while(opcionedicion<1||opcionconsulta>4);
					
					system("cls");
					fflush(stdin);		
					
					
					
					
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
}//CIERRA INT MAIN
			
						
			
		
	
		

		
	
	

