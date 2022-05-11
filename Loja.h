/*  Cabecalho com a declaracao do tipo abstrato de dados Loja.  */
/*                                                              */
/*  Autor: Ruy Braga Filho                                      */




#ifndef  LOJA_H
#define  LOJA_H

#include "Ponto2D.h"




/*  Definicao do tipo abstrato de dados Loja.    */
/*                                               */
/*  id - id da loja.                             */
/*  estoque - Estoque disponível na loja.        */
/*  localizacao - coordenadas (x,y) da loja.     */
/*                                               */
class Loja   {
	
	private: 
    
        long  id;
        long  estoque;      
        Ponto2D  localizacao;
        

    public:
    
        /*  Construtores  */
        Loja(): id(-1), estoque(-1), localizacao( Ponto2D(-1, -1) ) {}    

        Loja( long id, 
              long  estoque, 
              Ponto2D&  localizacao ) : id(id), estoque(estoque), localizacao(localizacao) {}
    	
    
        /*  Método que ajusta o atributo id com */
        /*  o valor passado como parametro.     */
        void setID( long id );    
        
        /*  Método que retorna o atributo id  */
        long getID();
            
        /*  Método que ajusta o atributo estoque com  */
        /*  o valor passado como parametro.           */
        void setEstoque( long estoque );    
        
        /*  Método que retorna o atributo estoque  */
        long getEstoque();          

        /*  Método que ajusta o atributo localizacao com  */
        /*  o valor passado como parametro.               */
        void setLocalizacao( Ponto2D&  localizacao );    
        
        /*  Método que retorna o atributo localizacao  */
        Ponto2D getLocalizacao();          

        /*  Método que imprime a loja  */
        void imprimir();

        /* Sobrecarga de operadores relacionais. A comparação é feita pelo id da loja */
        bool operator<=(Loja& i) const;
        bool operator>=(Loja& i) const;              
};


#endif	/* LOJA_H */


/*  Fim do cabecalho com a declaracao do tipo abstrato de dados Loja  */


