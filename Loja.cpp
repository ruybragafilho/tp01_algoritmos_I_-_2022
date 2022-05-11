/*  Definicoes dos metodos do tipo abstrato de dados Loja.   */
/*                                                           */
/*  Autor: Ruy Braga Filho                                   */

#include "Loja.h"
#include "Ponto2D.h"

#include <iostream>

using std::cout;

  	
    
/*  Método que ajusta o atributo id com */
/*  o valor passado como parametro.     */
void Loja::setID( long id ) { this->id = id; }
        
/*  Método que retorna o atributo id  */
long Loja::getID()  { return this->id; }
            
/*  Método que ajusta o atributo estoque com  */
/*  o valor passado como parametro.           */
void Loja::setEstoque( long estoque )  { this->estoque = estoque; }
        
/*  Método que retorna o atributo estoque  */
long Loja::getEstoque()  { return this->estoque; }

/*  Método que ajusta o atributo localizacao com  */
/*  o valor passado como parametro.               */
void Loja::setLocalizacao( Ponto2D&  localizacao )  { this->localizacao = localizacao; }
        
/*  Método que retorna o atributo localizacao  */
Ponto2D Loja::getLocalizacao()  { return this->localizacao; } 

/*  Método que imprime a loja  */
void Loja::imprimir() { cout << this->id; }

/* Sobrecarga de operadores relacionais. A comparação é feita pelo id da loja */
bool Loja::operator<=(Loja& i) const  { return (this->id <= i.id); }
bool Loja::operator>=(Loja& i) const  { return (this->id >= i.id); }



/*  Fim das definicoes dos métodos do tipo abstrato de dados Loja  */