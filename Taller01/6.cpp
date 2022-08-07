/*****************************************
* Fecha: 06 de agosto de 2022
* Autor: Shelsy Rodriguez
* Materia HPC-2
* Taller en lenguaje de programacion c++
*****************************************/

// 5. Realizar un programa que calcule e imprima la suma
// de los múltiplos de 5 comprendidos entre dos valores a y b.
// El programa no permitirá introducir valores negativos para a y b,
// y verificará que a es menor que b. Si a es mayor que b,
// intercambiará estos valores.

#include <stdio.h>
#include <math.h>
#include <iostream>

int main(){

	int a,b,aux;
	int cont=0, suma=0;

	do{ //Para recibir solo positivos
		std::cout<<"Ingrese el primer numero: ";
		std::cin>>a;
	} while (a < 0);

	do{
		std::cout<<"Ingrese el segundo numero: ";
		std::cin>>b;
	}while (b < 0);

	std::cout<<"\nEl valor ingresado para a es: "<<a<<std::endl;
	std::cout<<"El valor ingresado para b es: "<<b<<std::endl;

	if (a>b){
		aux = a;
		a = b;
		b = aux;
		std::cout<<"\nEl valor de a es mayor que b, se intercambiaran los valores"<<std::endl;

		std::cout<<"\nNuevo valor de a: "<<a<<std::endl;
		std::cout<<"Nuevo valor de b: "<<b<<std::endl;
	}

	for (int i=a; i<=b; i++){
		if (i%5==0){
			cont++;
			suma+=i;
		}
	}

	std::cout<<"\nLa cantidad de multiplos de 5 entre "<<a<<" y "<<b<<" es de: "<<cont<<std::endl;
	std::cout<<"La suma de los multiplos de 5 es de: "<<suma<<std::endl;

}


