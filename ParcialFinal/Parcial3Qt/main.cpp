/*********************************************************
 * Fecha: 20-11-2022
 * Autor: Shelsy Rodriguez
 * Materia: HPC-2
 * Tema: Parcial 3 - Regresion Logistica
 * Requerimientos:
 *      1.- Crear una clase que permita la manipulacion
 *          de kits de datos(extraccion, normalizacion,
 *          entre otros) con Eigen.
 *      2.- Crear una clase que permita implementar el
 *          modelo o algoritmo de Regresion Logistica con
 *          Eigen.
 * ******************************************************/

// EL interfaz representa el menu de funciones disponible en las clases/biblioteca

#include "Extraccion/extraction.h"
#include <iostream>
#include "Clase_Logistica/regressionlogistic.h"

/*Principal: Captura los argumentos de entrada
 * Lugar en donde se encuentra el dataset
 * Separador: Delimitador del dataset (;/,/./ /etc)
 * Header: si tiene o no cabecera <Se elimina si se tiene>
 */

int main(int argc, char *argv[])
{
    Extraction extraerData(argv[1],argv[2],argv[3]);

    std::vector<std::vector<std::string>> dataSET = extraerData.ReadCSV();
        int filas = dataSET.size()+1;
        int columnas = dataSET[0].size();

    std::cout << "Cantidad filas: " << std::endl;
    std::cout << dataSET.size()+1 <<std::endl;
    std::cout << "Cantidad columnas: " << std::endl;
    std::cout <<  dataSET[0].size()<<std::endl;

    Eigen::MatrixXd matrizDatos = extraerData.CSVToEigen(dataSET,filas,columnas);

    //normalizar en sklearn y aca para validar TODO
    Eigen::MatrixXd datosNormalizados = extraerData.Normalizador(matrizDatos,true);


    /*Una vez normalizada se procede a dividir en 4 conjuntos los datos:*/
    Eigen::MatrixXd X_train, y_train, X_test, y_test;

    std::cout<<"Se ha dividido el dataset en 2 grupos:\n"
               "* X_train\n"
               "* y_train\n"
               "* X_test\n"
               "* y_test"<<std::endl;

    std::tuple<Eigen::MatrixXd,Eigen::MatrixXd,Eigen::MatrixXd,Eigen::MatrixXd> datos_divididos = extraerData.train_test_split(datosNormalizados, 0.8);

/*Datos_dividios presenta la tupla comptimido con 4 matrices. A continuacion se debe descomprimir para las 4 matrices*/

     std::tie(X_train,y_train,X_test,y_test) = datos_divididos;

     /*A continuación se instancia el objeto regresion lineal */
     RegressionLogistic modelo_lr;

     /*Se ajustan los parametros */
     int dimension = X_train.cols();
     Eigen::MatrixXd W = Eigen::VectorXd::Zero(dimension);
     double b=0;
     double lambda=0.0;
     bool banderita=true;
     double learning_rate=0.01;
     int num_iter = 100;

     Eigen::MatrixXd dw;
     double db;
     std::list<double> lista_costos;

//     std::tuple<Eigen::MatrixXd, double, Eigen::MatrixXd, double,std::list<double>> optimo = modelo_lr.Optimization( W, b,  X_train,  y_train,  num_iter,
//                                                                                                                     learning_rate,  lambda,
//                                                                                                                   banderita);

     /*Se desempaqueta el conjunto de valores de optimo*/
     std::tie(W,b,dw,db,lista_costos) = optimo;

     /*Se crean las matrices de prediccion, (prueba y entrenamiento).*/
     Eigen::MatrixXd y_pred_test = modelo_lr.Prediction(W,b,X_test);
     Eigen::MatrixXd y_pred_train = modelo_lr.Prediction(W,b,X_train);

     /*A continuacion se calcula la metrica de accuracy para evaluar el rendimieno del modelo.*/
     auto train_accuracy = 100 - ((y_pred_train - y_train).cwiseAbs().mean() * 100);
     auto test_accuracy = 100 - ((y_pred_test - y_test).cwiseAbs().mean() * 100);
     std::cout<<"Accuracy de entrenamiento: "<<train_accuracy<<std::endl;
     std::cout<<"Accuracy de prueba: "<<test_accuracy<<std::endl;

     std::cout<<"Filas de entrenamiento: "<<X_train.rows()<<std::endl;
     std::cout<<"Filas de prueba: "<<X_test.rows()<<std::endl;
     std::cout<<"Filas totales: "<<datosNormalizados.rows()<<std::endl;

     std::vector<double> lista_costos_vector(lista_costos.begin(),lista_costos.end());

     std::ofstream archivo;
     archivo.open("lista_costos.txt");
     for (int i = 0; i < lista_costos_vector.size(); ++i) {
        archivo<<lista_costos_vector[i]<<std::endl;
     }
     archivo.close();

    return EXIT_SUCCESS;
}
