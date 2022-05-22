/*  Definicoes dos metodos do tipo abstrato de dados Bicicleta.   */
/*                                                                */
/*  Autor: Ruy Braga Filho                                        */

#include "Bicicleta.h"
#include "Ponto2D.h"

#include <iostream>

using std::cout;

  	
    
/*  Método que ajusta o atributo id com */
/*  o valor passado como parametro.     */
void Bicicleta::setID( long id ) { this->id = id; }
        
/*  Método que retorna o atributo id  */
long Bicicleta::getID()  { return this->id; }

/*  Método que ajusta o atributo localizacao com  */
/*  o valor passado como parametro.               */
void Bicicleta::setLocalizacao( Ponto2D&  localizacao )  { this->localizacao = localizacao; }
        
/*  Método que retorna o atributo localizacao  */
Ponto2D Bicicleta::getLocalizacao()  { return this->localizacao; } 

/*  Método que imprime o id da Bicicleta  */
void Bicicleta::imprimir() { cout << this->id; }

/* Sobrecarga de operadores relacionais. A comparação é feita pelo id da bicicleta */
bool Bicicleta::operator<=(Bicicleta& i) const  { return (this->id <= i.id); }
bool Bicicleta::operator>=(Bicicleta& i) const  { return (this->id >= i.id); }



/*  Fim das definicoes dos métodos do tipo abstrato de dados Bicicleta  */