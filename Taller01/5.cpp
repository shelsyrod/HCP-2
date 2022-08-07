/*****************************************
* Fecha: 06 de agosto de 2022
* Autor: Shelsy Rodriguez
* Materia HPC-2
* Taller en lenguaje de programacion c++
*****************************************/

// 5. ¿Cuál es el resultado del siguiente programa?

#include <stdio.h>
#include <math.h>
#include <iostream>

void fnx(int x){
	if (x)
		std::cout<<"El resultado es: "<<x<<std::endl;
}

int main() {
	int i, a = 1234;
	for (i = 0; i < 4; i++)
		fnx(a = a/10);
}
