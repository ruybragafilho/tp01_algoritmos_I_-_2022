/*  Cabecalho com a declaracao do tipo abstrato de dados Bicicleta.  */
/*                                                                   */
/*  Autor: Ruy Braga Filho                                           */




#ifndef  BICICLETA_H
#define  BICICLETA_H

#include "Ponto2D.h"




/*  Definicao do tipo abstrato de dados Bicicleta.            */
/*                                                            */
/*  id - id da bicicleta.                                     */
/*  localizacao - coordenadas (linha, coluna) da bicicleta.   */
/*                                                            */
class Bicicleta   {
	
	private: 
    
        long  id;
        Ponto2D  localizacao;
        

    public:
    
        /*  Construtores  */
        Bicicleta(): id(-1), localizacao( Ponto2D(-1, -1) ) {}    

        Bicicleta( long id,               
                   Ponto2D&  localizacao ) : id(id), localizacao(localizacao) {}
    	
    
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

        /*  Método que imprime o id da bicicleta  */
        void imprimir();

        /* Sobrecarga de operadores relacionais. A comparação é feita pelo id da bicicleta */
        bool operator<=(Bicicleta& i) const;
        bool operator>=(Bicicleta& i) const;              
};


#endif	/* BICICLETA_H */


/*  Fim do cabecalho com a declaracao do tipo abstrato de dados Bicicleta  */


