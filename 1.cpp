/*****************************************
* Fecha: 06 de agosto de 2022
* Autor: Shelsy Rodriguez
* Materia HPC-2
* Taller en lenguaje de programacion c++
*****************************************/

// 1. ¿Cuál es el resultado del siguiente programa?

#include <stdio.h>
#include <iostream>
#include <math.h>

int main(){
	int x=1, y=1;
	if (x=y*5)
		x=0;
	else
		x=-1;
	std::cout<<"El resultado es: "<<x<<std::endl;
}
