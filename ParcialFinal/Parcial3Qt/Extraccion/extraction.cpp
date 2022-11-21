#include "extraction.h"
#include <iostream>
#include <fstream>
#include <eigen3/Eigen/Dense>
#include <vector>
#include <boost/algorithm/string.hpp>

/* Implementación de los métodos de la clase Extraction */

/* Primera funcion miembro: Lectura de fichero csv.
 * Se presenta como un vector de vectores del
 * tipo string.
 * La idea es leer linea por linea y almacenar
 * cada una en un vector de vectores del
 * tipo string. */

std::vector<std::vector<std::string>> Extraction::ReadCSV()
{
    /* Abrir el fichero para lectura solamente */
    std::fstream Fichero(setDatos);

    /* Vector de vectores tipo string a entregar por
     * parte de la funcion */
    std::vector<std::vector<std::string>> datosString;

    /* Se itera a traves de cada linea, y se divide
     * el contenido dado por el separador( argumento
     * de entrada) provisto por el constructor */

    std::string linea = ""; // Almacenar cada linea
    while (getline(Fichero, linea))
    {
        /* Se crea un vector para almacenar la fila */
        std::vector<std::string> vectorFila;

        /* Se separa segun el delimitador */
        boost::algorithm::split(vectorFila,
                                linea,
                                boost::is_any_of(delimitador));
        datosString.push_back(vectorFila);
    }

    /* Se cierra el fichero .csv */
    Fichero.close();

    /* Se retorna el vector de
     * vectores del tipo string */
    return datosString;
}

/* Se implementa la segunda funcion miembro
 * la cual tiene como mision transformar el
 * vector de vectores del tipo String, en
 * una matrix Eigen. La idea es simular un
 * objeto DATAFRAME de pandas para poder
 * manipular los datos */

Eigen::MatrixXd Extraction::CSVToEigen(
    std::vector<std::vector<std::string>> SETdatos,
    int filas, int columnas)
{
    /* Se hace la pregunta si tiene cabezera o no
     * el vector de vectores del tipo String.
     * Si tiene cabecera, se debe eliminar */
    if (header == true)
    {
        filas = filas - 1;
    }

    /* Se itera sobre cada registro del fichero,
     * a la vez que se almacena en una matrixXd,
     * de dimension filas por columnas. Principalmente,
     * se almacenara Strings (porque llega un vector de
     * vectores del tipo String. La idea es
     * hacer un casting de String a float. */
    Eigen::MatrixXd MatrizDF(columnas, filas);
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            MatrizDF(j, i) = atof(SETdatos[i][j].c_str());
        }
    }
    // return MatrizDF;
    /* Se transpodatane la matriz, dado que viene
     * columnas por filas, para retornarla */
    return MatrizDF.transpose();
}

auto Extraction::Promedio(Eigen::MatrixXd datos) -> decltype(datos.colwise().mean())
{
    return datos.colwise().mean();
}

// Funcion para calcular la desviacion estandar

auto Extraction::DesvStand(Eigen::MatrixXd data) -> decltype(((data.array().square().colwise().sum()) / (data.rows() - 1)).sqrt())
{
    return (((data.array().square().colwise().sum()) / (data.rows() - 1)).sqrt());
}

/* Acto seguido se procede a hacer el cálculo o la función de normalización: La idea
 * es vitar los cambios en orden de magnitud. Lo anterior representa un deterioro para
 * la prediccion sobre la base de cualquier modelo de machine laearning. Evita los outliers */
Eigen::MatrixXd Extraction::Normalizador(Eigen::MatrixXd datos, bool target)
{

    if (target)
    {
        // extraer todos los datos menos la ultima columna
        Eigen::MatrixXd datosSinTarget = datos.leftCols(datos.cols() - 1);

        Eigen::MatrixXd DataEscalado = datosSinTarget.rowwise() - Promedio(datosSinTarget);

        Eigen::MatrixXd matrixNorm = DataEscalado.array().rowwise() / DesvStand(DataEscalado);

        /* Se retorna cada dato escalado */
        // unir la ultima columna con la matriz escalada
        matrixNorm.conservativeResize(matrixNorm.rows(),matrixNorm.cols()+1);
        matrixNorm.col(matrixNorm.cols()-1)=datos.rightCols(1);
        return matrixNorm;
    }

    /* Normalización:
     * MatrixNorm = xi - x.mean() / desviacionEstandar */
    Eigen::MatrixXd DataEscalado = datos.rowwise() - Promedio(datos);

    Eigen::MatrixXd matrixNorm = DataEscalado.array().rowwise() / DesvStand(DataEscalado);

    /* Se retorna cada dato escalado */
    return matrixNorm;
}

// funcion para dividir el conjunto de entrnamiento y conjunto de prueba 

/*Se crean 4 matrices que representan los 4 conjuntos 
* - variables independientes de entrenamiento
* - variables dependientes de entrenamiento
* - variables independientes de prueba
* - variables dependientes de prueba
* Recibe como argumento la  matriz normalizada, y el tamaño a dividir los conjuntos.
* Se retorna 4 matrices con los conjuntos de entrenamiento y prueba */

 std::tuple<Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd> Extraction::train_test_split(Eigen::MatrixXd datos, float train_size){
    /*Cantidad filas totales de data*/
    int filas_totales = datos.rows();
    
    /*Cantididad filas para entrenamiento*/
    int filas_train = round(filas_totales* train_size);

    /*Cantididad filas para prueba*/
    int filas_test = filas_totales - filas_train;

    Eigen::MatrixXd Train = datos.topRows(filas_train);
    Eigen::MatrixXd X_train = Train.leftCols(datos.cols()-1);
    Eigen::MatrixXd y_train = Train.rightCols(1);

    Eigen::MatrixXd Test = datos.bottomRows(filas_test);
    Eigen::MatrixXd X_test = Test.leftCols(datos.cols()-1);
    Eigen::MatrixXd y_test = Test.rightCols(1);

    /* Se retorna la tupla comprimida*/

    return std::make_tuple(X_train,y_train,X_test,y_test);
}

/*Funcion para pasar de vector iostream a fichero, para visualizar en graficas.
    La funcion recibe el vector y el nombre del fichero a exportar*/

void Extraction::Vector_to_file(std::vector<float> vector, std::string nombre_fichero){
    /*Se nombra el fichero */
    std::ofstream fichero_salida(nombre_fichero);
    /* Se itera por cada vector, para imprimirlo en el fichero */
    std::ostream_iterator<float> iterador_salida(fichero_salida, "\n");
    std::copy(vector.begin(),vector.end(),iterador_salida);

    /* Se entrega la copia a un fichero*/
}

/*Funcion para convertir de matriz a fichero*/

void Extraction::Eigen_to_file(Eigen::MatrixXd datos, std::string nombre_fichero){
    /*Se nombra el fichero */
    std::ofstream fichero_salida(nombre_fichero);

    /*Si el fichero esta abierto almacene datos*/
    if(fichero_salida.is_open()){
        fichero_salida << datos << "\n";
    }

}
