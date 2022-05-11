/*  Definicoes dos metodos do tipo abstrato de dados Cliente.   */
/*                                                              */
/*  Autor: Ruy Braga Filho                                      */

#include "Cliente.h"
#include "Ponto2D.h"

#include <iostream>

using std::cout;

  	
    
/*  Método que ajusta o atributo id com */
/*  o valor passado como parametro.     */
void Cliente::setID( long id ) { this->id = id; }
        
/*  Método que retorna o atributo id  */
long Cliente::getID()  { return this->id; }
            
/*  Método que ajusta o atributo ticket com  */
/*  o valor passado como parametro.           */
void Cliente::setTicket( double ticket )  { this->ticket = ticket; }
        
/*  Método que retorna o atributo ticket  */
double Cliente::getTicket()  { return this->ticket; }

/*  Método que ajusta o atributo localizacao com  */
/*  o valor passado como parametro.               */
void Cliente::setLocalizacao( Ponto2D&  localizacao )  { this->localizacao = localizacao; }
        
/*  Método que retorna o atributo localizacao  */
Ponto2D Cliente::getLocalizacao()  { return this->localizacao; } 

/*  Método que imprime o cliente  */
void Cliente::imprimir() { cout << this->id; }

/* Sobrecarga de operadores relacionais. A comparação é feita pelo ticket do cliente */
bool Cliente::operator<=(Cliente& i) const  { return (this->ticket <= i.ticket); }
bool Cliente::operator>=(Cliente& i) const  { return (this->ticket >= i.ticket); }



/*  Fim das definicoes dos métodos do tipo abstrato de dados Loja  */