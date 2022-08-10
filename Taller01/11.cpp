/*****************************************
* Fecha: 06 de agosto de 2022
* Autor: Shelsy Rodriguez
* Materia HPC-2
* Taller en lenguaje de programacion c++
*****************************************/

// 11. Realizar un programa que calcule el importe a pagar por un
// vehículo al circular por una autopista.

#include <stdio.h>
#include <math.h>
#include <iostream>

void bicicletasOp(){

	int importe = 100;

	std::cout<<"\nBICICLETA"<<std::endl;
	std::cout<<"Importe: "<<importe<<std::endl;
}

void motoOp(){

	int importe, km;

	std::cout<<"\nMOTO"<<std::endl;

	std::cout<<"Digite los km recorridos: ";
	std::cin>>km;

	importe = km*30;

	std::cout<<"Importe: "<<importe<<std::endl;
}

void cocheOp(){

	int importe, km;

	std::cout<<"\nCOCHE"<<std::endl;

	std::cout<<"Digite los km recorridos: ";
	std::cin>>km;

	importe = km*30;

	std::cout<<"Importe: "<<importe<<std::endl;
}

void camionOp(){

	int importe, km, tn;

	std::cout<<"\nCAMION"<<std::endl;

	std::cout<<"Digite los km recorridos: ";
	std::cin>>km;

	std::cout<<"Digite las Tn del camion: ";
	std::cin>>tn;

	importe = (km*30) + (tn * 25);

	std::cout<<"Importe: "<<importe<<std::endl;
}

void menu(){
	int opcion;
	std::cout<<"MENU:\n"<<std::endl;
	std::cout<<"1) Bicicleta"<<std::endl;
	std::cout<<"2) Moto"<<std::endl;
	std::cout<<"3) Coche"<<std::endl;
	std::cout<<"4) Camion"<<std::endl;
	std::cout<<"0) Salir"<<std::endl;
	std::cout<<"\nSeleccione la opcion deseada: ";
	std::cin>>opcion;

	switch(opcion){
		case 1:
			bicicletasOp();
			break;

		case 2:
			motoOp();
			break;

		case 3:
			cocheOp();
			break;

		case 4:
			camionOp();
			break;

		case 0:
			exit(0);
			break;

		default:
			std::cout<<"\n\n\t\t\tDigite una opcion valida\n"<<std::endl;
		break;
	}
	menu();
}

int main(){
	menu();
}
