/*****************************************
* Fecha: 06 de agosto de 2022
* Autor: Shelsy Rodriguez
* Materia HPC-2
* Taller en lenguaje de programacion c++
*****************************************/

// 9. Realizar un programa que genere la siguiente secuencia de dígitos:

#include <stdio.h>
#include <math.h>
#include <iostream>

int main(){

	int filas;

	std::cout<<"Ingrese el numero de filas: ";
	std::cin >> filas;

	for (int x = 1; x <=filas; x++){
        	for (int k=10 ; k>=x; k--){
            		std::cout << "   ";
        	}

	if(x==1){
            std::cout << x << std::endl;
        } else{
        	int z = ((x*2))-1;
		for (int y = 0; y <= ((x*2)-2); y++){
                	if((x+y) >= x*2){
                    		z-=1;
                    		if(z>9){
                        		std::cout << z%10 << "  ";
                    		} else{
					std::cout << z << "  ";
                    		}
                	} else{
                    		if(x+y >9){
                        		std::cout << (x+y)%10 << "  ";
                    		} else{
                        		std::cout << x+y << "  ";
                    		}
			}
            	}
            std::cout << std::endl;
	}//cierra for
}

}//cierra main
