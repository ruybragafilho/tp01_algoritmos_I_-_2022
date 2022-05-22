/*  Cabecalho com a declaracao do tipo abstrato de dados Pessoa.  */
/*                                                                */
/*  Autor: Ruy Braga Filho                                        */




#ifndef  PESSOA_H
#define  PESSOA_H

#include "Ponto2D.h"




/*  Definicao do tipo abstrato de dados Pessoa.             */
/*                                                          */
/*  id - id da Pessoa.                                      */
/*  localizacao - coordenadas (linha, coluna) da pessoa.    */
/*                                                          */
class Pessoa   {
	
	private: 
    
        long  id;
        Ponto2D  localizacao;
        

    public:
    
        /*  Construtores  */
        Pessoa(): id(-1), localizacao( Ponto2D(-1, -1) ) {}    

        Pessoa( long  id, 
                Ponto2D  localizacao ) : id(id), localizacao(localizacao) {}
    	
    
        /*  Método que ajusta o atributo id com */
        /*  o valor passado como parametro.     */
        void setID( long id );    
        
        /*  Método que retorna o atributo id  */
        long getID();

        /*  Método que ajusta o atributo localizacao com  */
        /*  o valor passado como parametro.               */
        void setLocalizacao( Ponto2D&  localizacao );    
        
        /*  Método que retorna o atributo localizacao  */
        Ponto2D getLocalizacao();          

        /*  Método que imprime o id da Pessoa  */
        void imprimir();

        /* Sobrecarga de operadores relacionais. A comparação é feita pelo id da pessoa */
        bool operator<=(Pessoa& i) const;
        bool operator>=(Pessoa& i) const;              
};


#endif	/* PESSOA_H */


/*  Fim do cabecalho com a declaracao do tipo abstrato de dados Pessoa  */


