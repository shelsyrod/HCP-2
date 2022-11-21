# Regresion Logistica

En este repositorio se encuentra el trabajo, el cual corresponde a el parcial final de la materia High Computing programing (HPC - Metricas de rendimientos).

En este repositorio se encuentra:

- El dataset original (data.csv): Cuenta con 32 caracteristicas de las cuales 31 son numericas y 1 categorica. Las características se calculan a partir de una imagen digitalizada de una aspiración con aguja fina (FNA) de una masa mamaria. Describen características de los núcleos celulares presentes en la imagen. En la segunda posicion se encuentra la variable objetivo ['Diagnosis']

- El dataset con las caracteristicas importantes (cancer.csv): Cuenta con 10 caracteristicas importantes del dataset original y la variable a predecir, en este dataset la variable objetivo se encunetra en la ultima posicion, para trabajar con este en el framework Qt Creator

- El codigo en python de un cuaderno notebook (Parcial3.ipynb)

  Link Codigo Python - [Colab](https://drive.google.com/file/d/18pbiR1fy1isYys_Z-fCWyoBY6-Ve8sJB/view?usp=sharing)

- Codigo fuentes del Programa LR en C++

  Link Codigo Qt - [c++](https://drive.google.com/drive/folders/10yH5o6RZcQMhwSifKfBAcXa7mkDRXn8f?usp=sharing)

- El documento (Readme.md) que presenta el contenido 

## Desarrollo ⚙️

- Se hizo una implemetacion en Python (Parcial3.ipynb)

1. Se importan los modulos necesarios para la implementacion
2. Se leen los datos del dataset seleccionado
3. Se hace un analisis exploratorio de los datos
4. Se normalizan los datos
5. Se separan los datos de entrenamiento y de prueba
6. Se entrena el modelo de regresion logistica
7. Se aplican metricas para medir el rendimeino del modelo

Se toma la decision de entrenar el modelo con otros datos

5. Se separan los datos de entrenamiento y de prueba
6. Se entrena el modelo de regresion logistica
7. Se aplican metricas para medir el rendimeino del modelo
8. Conclusiones de los modelos
9. Referencias 

- A su vez se hace una implementacioon en c++

1. Lectura del archivo
2. Se leen los datos del dataset seleccionado
3. Se hace un analisis exploratorio de los datos
4. Se normalizan los datos
5. Se separan los datos de entrenamiento y de prueba
6. Se entrena el modelo de regresion logistica
7. Se aplican metricas para medir el rendimeino del modelo

## Conclusiones generales 📋

* El modelo inicial que fue entrenado con todas las variables del dataframe no era el mas optimo, por lo que se optó por seleccionar unicamente las variables mas influyentes (con unas mayor correlación) y este segundo modelo, dio mejores resultados, con un acuraccy casi del doble de valor, con esto se puede concluir que para tener un mejor modelo es importante entrenarlo con variables importantes, con altos pesos que en lugar entrenarlo con una alta cantidad de caracteristicas que no representan nada

* La distancia a la que se va a desplazar el algoritmo (learning rate)  en cada iteración de búsqueda es muy importante debido a que si es muy pequeño, se tardará demasiado en llegar al mínimo y, si es demasiado grande, el algoritmo saltará de una región a otra pasando por encima del mínimo sin alcanzarlo.

* La presicion y el acuraccy del modelo son altos, lo que representa que el modelo de regresion logistica es aceptable y se ajusta

## Construido con 🛠️

Herramientas que utilizamos para el proyecto

* [Colab](https://colab.research.google.com/drive/122yDvWKHggehFmqg5oM2CqJUsyJcTAjH#scrollTo=M2Z55G32TwQL) - Notebook
* [Qt](https://qr.io/) - Framework

## Fuentes de informacion 📖

* https://scikit-learn.org/stable/modules/generated/sklearn.linear_model.LogisticRegression.html
* https://eigen.tuxfamily.org/index.php?title=Main_Page
* https://www.kaggle.com/datasets/uciml/breast-cancer-wisconsin-data

## Autor ✒️

* **Shelsy Natalia Rodriguez Barajas**  - [Correo](shelsy46rodriguez01@gmail.com)
