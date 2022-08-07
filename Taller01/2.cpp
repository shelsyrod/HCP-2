/*****************************************
* Fecha: 06 de agosto de 2022
* Autor: Shelsy Rodriguez
* Materia HPC-2
* Taller en lenguaje de programacion c++
*****************************************/

// 2. ¿Cuál es el resultado del siguiente programa?

#include <stdio.h>
#include <iostream>
#include <math.h>

int main(){
	int x = 1, y = 1;
	if (x == 1)
		if (y == 0)
			x = 10;
	else
		x = -1;
	std::cout<<"El resultado es: "<<x<<std::endl;
}
