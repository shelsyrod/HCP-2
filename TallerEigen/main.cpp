/*************************************************
 * Fecha: 20 de agosto de 2022
 * Autor: Shelsy Rodriguez
 * Materia HPC-2
 * Taller en lenguaje de programacion c++
 ************************************************/

#include <iostream>
#include <vector>
#include <eigen3/Eigen/Dense>

void punto1(Eigen::MatrixXd A, Eigen::MatrixXd B, Eigen::MatrixXd X){
    std::cout<<"\nPunto 1"<<std::endl;
    A.resize(2,2);
    B.resize(2,2);
    X.resize(2,2);
    A << 4,-2,
         1,7;
    B << -1,2,
          6,-5;
    X = 3*A - 4*B;
    std::cout<<"\nX=3A-4B\n"<<std::endl;
    std::cout<<X<<std::endl;
    std::cout<<"\n"<<std::endl;
}

void punto2(Eigen::MatrixXd A, Eigen::MatrixXd B, Eigen::MatrixXd X){
    std::cout<<"\nPunto 2"<<std::endl;
    A.resize(2,2);
    B.resize(2,2);
    X.resize(2,2);
    A << 0,-1,
         2,1;
    B << 1,2,
         3,4;
    X = (3*B*A - 4*A) / 2;
    std::cout<<"\n2X+4A=3BA\n"<<std::endl;
    std::cout<<"X = (3BA-4A)/2\n"<<std::endl;
    std::cout<<X<<std::endl;
    std::cout<<"\n"<<std::endl;
}

void punto3(){
    std::cout<<"\nPunto 3"<<std::endl;
}

void punto4(Eigen::MatrixXd A, Eigen::MatrixXd B, Eigen::MatrixXd X){
    A.resize(2,2);
    B.resize(2,2);
    X.resize(2,2);
    A << 2,1,
        -4,-3;
    B << 2,2,
         6,4;
    X = B*A.inverse();
    std::cout<<"\nXA = B\n"<<std::endl;
    std::cout<<X<<std::endl;
    std::cout<<"\n"<<std::endl;
}

void punto5(Eigen::MatrixXd A, Eigen::MatrixXd B, Eigen::MatrixXd C, Eigen::MatrixXd X){
    A.resize(2,3);
    B.resize(3,2);
    C.resize(2,2);
    X.resize(2,2);
    A << 3,0,-1,
         0,2,1;
    B << 1,2,
         1,0,
         0,6;
    C << -2,0,
         -2,-5;
    X = 2*(A*B + C);
    std::cout<<"\nX=2(BC+C)\n"<<std::endl;
    std::cout<<X<<std::endl;
    std::cout<<"\n"<<std::endl;
}

void punto6(Eigen::MatrixXd A, Eigen::MatrixXd B, Eigen::MatrixXd X){
    A.resize(3,3);
    B.resize(3,3);
    X.resize(3,3);
    A << 1,5,-1,
        -1,2,2,
         0,-3,3;
    B << -1,-4,3,
          1,-2,-2,
         -3,3,-5;
    X = A + 3*B;
    std::cout << "\nX = A + 3B\n" << std::endl;
    std::cout << X << std::endl;
    std::cout<<"\n"<<std::endl;
}

void punto7(Eigen::MatrixXd A, Eigen::MatrixXd B, Eigen::MatrixXd X){
    A.resize(3,3);
    B.resize(3,3);
    X.resize(3,3);
    A << 2,7,3,
         3,9,4,
         1,5,3;
    B << 1,0,2,
         0,1,0,
         0,0,1;
    X = B*A.inverse();
    std::cout<<"\nXA = B\n"<<std::endl;
    std::cout<<X<< std::endl;
    std::cout<<"\n"<<std::endl;
}

void punto8(Eigen::MatrixXd A, Eigen::MatrixXd B, Eigen::MatrixXd X){
    A.resize(3,3);
    B.resize(3,3);
    X.resize(3,3);
    A << 1,1,1,
         6,5,4,
         13,10,8;
    B << 0,1,2,
         1,0,2,
         1,2,0;
    X = A.inverse() * B;
    std::cout<<"\nXA = B\n"<<std::endl;
    std::cout<<X<<std::endl;
    std::cout<<"\n"<<std::endl;
}

void punto9(Eigen::MatrixXd A, Eigen::MatrixXd X){
    A.resize(2,2);
    X.resize(2,2);
    A << 3,-1,
         0,2;
    X = A.transpose()*A - 2*A;
    std::cout<<"\nX = A^(T)A - 2A\n"<<std::endl;
    std::cout<<X<<std::endl;
    std::cout<<"\n"<<std::endl;
}

void punto10(Eigen::MatrixXd A, Eigen::MatrixXd X){
    A.resize(2,2);
    X.resize(2,2);
    A << 4,2,
        -1,0;
    X = A*A*A;
    std::cout<<"\nX = A^(3)\n"<<std::endl;
    std::cout<<X<<std::endl;
    std::cout<<"\n"<<std::endl;
}

void punto11(Eigen::MatrixXd A, Eigen::MatrixXd B, Eigen::MatrixXd C, Eigen::MatrixXd X){
    A.resize(2,2);
    B.resize(2,2);
    C.resize(2,2);
    X.resize(2,2);
    A << 2,4,
         3,2;
    B << 1,0,
         2,1;
    C << 7,5,   
         6,1;
    X = ((A.transpose()).inverse())*(C*(B.inverse()));
    std::cout<<"\nA^T XB = C\n"<<std::endl;
    std::cout<<"A = [2,4;3,2]\n"<<std::endl;
    std::cout<<"B = [1,0;2,1]\n"<<std::endl;
    std::cout<<"C = [7,5;6,1]\n"<<std::endl;
    std::cout<<"X = A^T B\n" << std::endl;
    std::cout<<X<<std::endl;
    std::cout<<"\n"<<std::endl;
}

void punto12(Eigen::MatrixXd A, Eigen::MatrixXd B, Eigen::MatrixXd X){
    A.resize(2,3);
    B.resize(3,2);
    X.resize(2,2);
    A << 1,0,-2,
         2,-1,3;
    B << 2,-3,
        -2,0,
        -1,-2;
    X = A*A.transpose() - 2*A*B;
    std::cout<<"\nX = AA^T -2AB\n"<<std::endl;
    std::cout<<"A = [1,0,-2;2,-1,3]\n"<<std::endl;
    std::cout<<"B = [2,-3;2-2,0;-1,-2]\n"<<std::endl;
    std::cout<<X<< std::endl;
    std::cout<<"\n"<<std::endl;
}

void punto13(Eigen::MatrixXd A, Eigen::MatrixXd B, Eigen::MatrixXd C, Eigen::MatrixXd X){
    A.resize(1,3);
    B.resize(3,2);
    C.resize(2,1);
    X.resize(1,1);
    A << 4,8,12;
    B << 3,2,
         0,1,
        -1,0;
    C << 3,-1;
    X = A*B*C;
    std::cout<<"\nX = ABC\n"<<std::endl;
    std::cout<<"A = [4,8,12]\n"<<std::endl;
    std::cout<<"B = [3,2;0,1;-1,0]\n"<<std::endl;
    std::cout<<"C = [3;-1]\n"<<std::endl;
    std::cout<<X << std::endl;
    std::cout<<"\n"<<std::endl;
}

void punto14(Eigen::MatrixXd A, Eigen::MatrixXd B, Eigen::MatrixXd X){
    A.resize(3,3);
    B.resize(3,3);
    X.resize(3,3);
    A << 2,5,7,
         6,3,4,
         5,-2,-3;
    B << -1,1,0,
          0,1,1,
          1,0,1;
    X = (A.transpose()).inverse()*B;
    std::cout<<"\nA^T X = B\n"<<std::endl;
    std::cout<<"A = [2,5,7;6,3,4;5,-2,-3]\n"<<std::endl;
    std::cout<<"B = [-1,1,0;0,1,1;1,0,-1]\n"<<std::endl;
    std::cout<<"X = A^T\n"<<std::endl;
    std::cout<<X<<std::endl;
    std::cout<<"\n"<<std::endl;
}

void punto15(Eigen::MatrixXd A, Eigen::MatrixXd B, Eigen::MatrixXd X){
    A.resize(3,3);
    B.resize(3,3);
    X.resize(3,3);
    A<< 2,5,7,
        6,3,4,
        5,-2,-3;
    B<< -1,1,0,
         0,1,1,
         1,0,1;
    X = B*A.inverse();
    std::cout<<"\nXA=B\n"<<std::endl;
    std::cout<<"A=[2,5,7;6,3,4;5,-2,-3]\n"<<std::endl;
    std::cout<<"B=[-1,1,0;0,1,1;1,0,-1]\n"<<std::endl;
    std::cout<<"X=A^-1\n"<<std::endl;
    std::cout<<X<<std::endl;
    std::cout<<"\n"<<std::endl;
}


int main(){
    Eigen::MatrixXd A,B,C,X;
    int opcion;
    bool repetir = true;
    do{
        std::cout<<"***********************************"<<std::endl;
        std::cout<<"             Bienvenido            "<<std::endl;
        std::cout<<"***********************************"<<std::endl;
        std::cout<<"\nMenu de opciones:                "<<std::endl;
        std::cout<<"\n1. Punto 1 -> X=3A-4B            "<<std::endl;
        std::cout<<"\n2. Punto 2 -> 2X+4A=3BA          "<<std::endl;
        std::cout<<"\n3. Punto 3 -> AXB^t=C            "<<std::endl;
        std::cout<<"\n4. Punto 4 -> XA=B               "<<std::endl;
        std::cout<<"\n5. Punto 5 -> X=2(AB+C)          "<<std::endl;
        std::cout<<"\n6. Punto 6 -> X=A+3B             "<<std::endl;
        std::cout<<"\n7. Punto 7 -> XA=B               "<<std::endl;
        std::cout<<"\n8. Punto 8 -> AX=B               "<<std::endl;
        std::cout<<"\n9. Punto 9 -> X=A^TA-2A          "<<std::endl;
        std::cout<<"\n10. Punto 10 -> X=A³             "<<std::endl;
        std::cout<<"\n11. Punto 11 -> A^TXB=C          "<<std::endl;
        std::cout<<"\n12. Punto 12 -> X=AA^T-2AB       "<<std::endl;
        std::cout<<"\n13. Punto 13 -> X=ABC            "<<std::endl;
        std::cout<<"\n14. Punto 14 -> A^TX=B           "<<std::endl;
        std::cout<<"\n15. Punto 15 -> XA=B             "<<std::endl;
        std::cout<<"\n16. Salir                        "<<std::endl;

        std::cout<<"\n\nDigite una opcion: ";
        std::cin>>opcion;

        switch(opcion){
            case 1:
                punto1(A,B,C);
                break;

            case 2:
                punto2(A,B,C);
                break;

            case 3:
                punto3();
                break;

            case 4:
                punto4(A,B,C);
                break;

            case 5:
                punto5(A,B,C,X);
                break;

            case 6:
                punto6(A,B,C);
                break;

            case 7:
                punto7(A,B,C);
                break;

            case 8:
                punto8(A,B,C);
                break;

            case 9:
                punto9(A,B);
                break;

            case 10:
                punto10(A,B);
                break;

            case 11:
                punto11(A,B,C,X);
                break;

            case 12:
                punto12(A,B,C);
                break;

            case 13:
                punto13(A,B,C,X);
                break;

            case 14:
                punto14(A,B,C);
                break;

            case 15:
                punto15(A,B,C);
                break;

            case 16:
                repetir = false;
                break;

            default:
                std::cout<<"\n\nDigite una opcion correcta"<<std::endl;
                break;
        }
    } while(repetir);
    return 0;
}
