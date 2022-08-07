/*****************************************
* Fecha: 06 de agosto de 2022
* Autor: Shelsy Rodriguez
* Materia HPC-2
* Taller en lenguaje de programacion c++
*****************************************/

// 4. ¿Cuál es el resultado del siguiente programa?

#include <stdio.h>
#include <math.h>
#include <iostream>

int main(){

	int x = 0, y = 0;
	for (x = 6; x > 0; x -= 2)
		for (y = 0; y < 2; y++)
			std::cout<<"El resulado es: "<<x-y<<std::endl;
}
