#ifndef EXTRACTION_H
#define EXTRACTION_H

#include <iostream>
#include <fstream>
#include <eigen3/Eigen/Dense>
#include <vector>
#include <iostream>
#include <fstream>
#include <eigen3/Eigen/Dense>
#include <vector>

/* La clase extraction se compone de las funciones o métodos para manipular el dataset.
   Se presentan funciones para
   --> Lectura csv
   --> Promedios
   --> Normalización de datos
   --> Desviación Estandar

   La clase recibe como parametros de entrada
   --> El dataset (path del dataset ".csv")
   --> El delimitador (separador entre columnas)
   --> Si el datast tien o no cabecera (header)
*/

class Extraction
{
   /* Se presenta el constructor para los argumentos de entrada a la clase:
      nombre_dataset, delimitador, header
   */

   /* Nombre del dataset */
   std::string setDatos;
   /* Separador de columnas */
   std::string delimitador;
   /* Si el dataset tiene cabecera o no*/
   bool header;

public:
   Extraction(std::string datos,
              std::string separador,
              bool head) : setDatos(datos),
                           delimitador(separador),
                           header(head) {}

   /*** PROTOTIPO DE FUNCIONES PROPIAS DE LA CLASE ***/
   // Cabecera de la funcion para leer el CSV*/
   std::vector<std::vector<std::string>> ReadCSV();
   // Cabecera de la funcion para convertir a Eigen*/
   Eigen::MatrixXd CSVToEigen(
       std::vector<std::vector<std::string>> SETdatos,
       int filas, int columnas);

   auto Promedio(Eigen::MatrixXd datos) -> decltype(datos.colwise().mean());

   auto DesvStand(Eigen::MatrixXd data) -> decltype(((data.array().square().colwise().sum()) / (data.rows() - 1)).sqrt());
   Eigen::MatrixXd Normalizador(Eigen::MatrixXd datos, bool target);

    std::tuple<Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd> train_test_split(Eigen::MatrixXd datos, float train_size);
    void Vector_to_file(std::vector<float> vector, std::string nombre_fichero);

    void Eigen_to_file(Eigen::MatrixXd datos, std::string nombre_fichero);
};

#endif // EXTRACTION_H
