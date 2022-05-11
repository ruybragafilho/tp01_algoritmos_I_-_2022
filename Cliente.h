/*  Cabecalho com a declaracao do tipo abstrato de dados Cliente.  */
/*                                                                 */
/*  Autor: Ruy Braga Filho                                         */




#ifndef  CLIENTE_H
#define  CLIENTE_H

#include "Ponto2D.h"




/*  Definicao do tipo abstrato de dados Cliente.                                                  */
/*                                                                                                */
/*  id - id do cliente.                                                                           */
/*  ticket - valor calculado com base na idade, estado de oritem e forma de pagamento do cliente  */
/*  localizacao - coordenadas (x,y) do cliente.                                                   */
/*                                                                                                */
class Cliente   {
	
	private: 
    
        long  id;
        double  ticket;      
        Ponto2D  localizacao;
        

    public:
    
        /*  Construtores  */
        Cliente(): id(-1), ticket(-1.0), localizacao( Ponto2D(-1, -1) ) {}    

        Cliente( long  id, 
                 double  ticket, 
                 Ponto2D  localizacao ) : id(id), ticket(ticket), localizacao(localizacao) {}
    	
    
        /*  Método que ajusta o atributo id com */
        /*  o valor passado como parametro.     */
        void setID( long id );    
        
        /*  Método que retorna o atributo id  */
        long getID();
            
        /*  Método que ajusta o atributo ticket com  */
        /*  o valor passado como parametro.           */
        void setTicket( double ticket );    
        
        /*  Método que retorna o atributo ticket  */
        double getTicket();          

        /*  Método que ajusta o atributo localizacao com  */
        /*  o valor passado como parametro.               */
        void setLocalizacao( Ponto2D&  localizacao );    
        
        /*  Método que retorna o atributo localizacao  */
        Ponto2D getLocalizacao();          

        /*  Método que imprime o cliente  */
        void imprimir();

        /* Sobrecarga de operadores relacionais. A comparação é feita pelo ticket da loja */
        bool operator<=(Cliente& i) const;
        bool operator>=(Cliente& i) const;              
};


#endif	/* CLIENTE_H */


/*  Fim do cabecalho com a declaracao do tipo abstrato de dados Cliente  */


