/*  Definicoes dos métodos do tipo abstrato de dados Ponto2D,     */
/*  utilizado para representar um ponto (linha, coluna) no grid.  */
/*                                                                */
/*  Autor: Ruy Braga Filho                                        */



#include <sstream>
#include "Ponto2D.h"



/* métodos Sets e Gets para as coordenadas (linha, coluna) */
void Ponto2D::setLinha( long linha ) { this->linha = linha; }
long Ponto2D::getLinha() { return linha; }

void Ponto2D::setColuna( long coluna ) { this->coluna = coluna; }
long Ponto2D::getColuna() { return coluna; }



/* Representação de string do ponto.                                          */
/* retorna uma string que representa o ponto, como uma tupla de n-dimensões.  */ 
std::string Ponto2D::toString()  { 

    std::ostringstream aux;
    
    aux << "(" << this->linha << "," << this->coluna << ")";

    return( aux.str() );

}  /*  Fim da definicao do metodo toString.  */


/*  Fim das definicoes dos métodos do tipo abstrato de dados Ponto2D  */