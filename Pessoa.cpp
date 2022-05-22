/*  Definicoes dos metodos do tipo abstrato de dados Pessoa.   */
/*                                                             */
/*  Autor: Ruy Braga Filho                                     */

#include "Pessoa.h"
#include "Ponto2D.h"

#include <iostream>

using std::cout;

  	
    
/*  Método que ajusta o atributo id com */
/*  o valor passado como parametro.     */
void Pessoa::setID( long id ) { this->id = id; }
        
/*  Método que retorna o atributo id  */
long Pessoa::getID()  { return this->id; }

/*  Método que ajusta o atributo localizacao com  */
/*  o valor passado como parametro.               */
void Pessoa::setLocalizacao( Ponto2D&  localizacao )  { this->localizacao = localizacao; }
        
/*  Método que retorna o atributo localizacao  */
Ponto2D Pessoa::getLocalizacao()  { return this->localizacao; } 

/*  Método que imprime o id da pessoa  */
void Pessoa::imprimir() { cout << this->id; }

/* Sobrecarga de operadores relacionais. A comparação é feita pelo id da pessoa */
bool Pessoa::operator<=(Pessoa& i) const  { return (this->id <= i.id); }
bool Pessoa::operator>=(Pessoa& i) const  { return (this->id >= i.id); }



/*  Fim das definicoes dos métodos do tipo abstrato de dados Pessoa  */