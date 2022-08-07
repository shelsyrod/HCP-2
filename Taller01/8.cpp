/*****************************************
* Fecha: 06 de agosto de 2022
* Autor: Shelsy Rodriguez
* Materia HPC-2
* Taller en lenguaje de programacion c++
*****************************************/

// 8. Numero del Tarot

#include <stdio.h>
#include <math.h>
#include <iostream>

int main(){

	int d,m,a;
	int x=0,y=0,z=0;
	std::cout<<"Ingrese el dia que nacio: ";
	std::cin>>d;
	std::cout<<"Ingrese el mes que nacio: ";
	std::cin>>m;
	std::cout<<"Ingrese el año que nacio: ";
	std::cin>>a;

	std::cout<<"Nacio el: "<<d<<" del mes "<<m<<" de el año "<<a<<std::endl;

	if((d>0 && d<=31) && (m>0 && m <=12) && (a>=1950 && a<=2021)){
		x=d+m+a;
		std::cout<<d<<" + "<<m<<" + "<<a<<" = "<<x<<std::endl;
		y=(x%10)+((x/10)%10)+((x/100)%10)+(x/1000);
		z=(y%10)+(y/10);
		std::cout<<"Su numero de tarot es el: "<<z<<std::endl;
	}else{
		std::cout<<"La fecha ingresada no es correcta"<<std::endl;
	}
}
