/*****************************************
* Fecha: 06 de agosto de 2022
* Autor: Shelsy Rodriguez
* Materia HPC-2
* Taller en lenguaje de programacion c++
*****************************************/

// 3. ¿Cuál es el resultado del siguiente programa?

#include <stdio.h>
#include <iostream>
#include <math.h>

int main(){

	int x = 0;
	for(x = 'a'; x <= 'z'; x += 10){
		std::cout<<"El resultado es: "<<x<<std::endl;
	}
}


