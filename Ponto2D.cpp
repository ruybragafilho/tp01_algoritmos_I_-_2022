/*  Definicoes dos métodos do tipo abstrato de dados Ponto2D,        */
/*  utilizado para representar um ponto (x, y) no plano cartesiano.  */
/*                                                                   */
/*  Autor: Ruy Braga Filho                                           */



#include <sstream>
#include <iomanip>
#include <cmath>
#include "Ponto2D.h"



/* métodos Sets e Gets para as coordenadas (x, y) */
void Ponto2D::setX( long x ) { this->x = x; }
long Ponto2D::getX() { return x; }

void Ponto2D::setY( long y ) { this->y = y; }
long Ponto2D::getY() { return y; }



/* Representação de string do ponto.                                          */
/* retorna uma string que representa o ponto, como uma tupla de n-dimensões.  */ 
std::string Ponto2D::toString()  { 

    std::ostringstream aux;
    
    aux << "(" << this->x << "," << this->y << ")";

    return( aux.str() );

}  /*  Fim da definicao do metodo toString.  */



/* A distância entre pontos de duas dimensões é calculada da seguinte forma:  */
/* d = sqrt((x1 - x2)^2 + (y1 - y2)^2).                                       */
double Ponto2D::distanciaEuclidiana( Ponto2D p )  { 
    
    return sqrt( static_cast<double>(  (this->x - p.x ) * (this->x - p.x)  + 
                                       (this->y - p.y ) * (this->y - p.y)  )); 
                                       
}  /*  Fim da definicao do metodo distanciaEuclidiana.  */



/* A distância entre pontos em um grid de duas dimensões é calculada da seguinte forma: */
/* d = menor(deltaX, deltaY) + ( maior(deltaX, deltaY) - menor(deltaX, deltaY) )        */
/* onde deltaX = abs( x2 - x1 - 1) e deltaY = abs( y2 - y1 - 1)                         */
long Ponto2D::distanciaGrid( Ponto2D p )  {

    long deltaX = abs( this->x - p.x ) - 1;
    long deltaY = abs( this->y - p.y ) - 1;

    long maior;
    long menor;

    if( deltaX > deltaY )  {

        maior = deltaX;
        menor = deltaY;

    } else {

        maior = deltaY;
        menor = deltaX;
    }

    return ( menor + (maior - menor) );

}  /*  Fim da definicao do metodo distanciaGrid.  */


/*  Fim das definicoes dos métodos do tipo abstrato de dados Ponto2D  */