/*  Cabecalho com a declaracao do tipo abstrato de dados Ponto2D,   */
/*  utilizado para representar um ponto (linha, coluna) no grid.    */
/*                                                                  */
/*  Autor: Ruy Braga Filho                                          */



#ifndef PONTO_2D
#define PONTO_2D

#include <string>



/**
 * Um ponto bidimensional.
 */
class Ponto2D {
	
    protected:

        /* Coordenadas (linha, coluna) do ponto no grid */
	    long linha;
        long coluna;	

    public:

        /* Construtores da classe Ponto2D */
		Ponto2D(): linha(0), coluna(0) {}
        Ponto2D(long linha, long coluna): linha(linha), coluna(coluna) {}

        
        /* métodos Sets e Gets para as coordenadas (linha, coluna) */
        void setLinha( long linha );
        long getLinha();

		void setColuna( long coluna );
		long getColuna();
		
	    
        /* Representação de string do ponto.                                          */
        /* retorna uma string que representa o ponto, como uma tupla de n-dimensões.  */      
        std::string toString();
};

#endif



/*  Fim do cabecalho com a declaracao do tipo abstrato de dados Ponto2D  */