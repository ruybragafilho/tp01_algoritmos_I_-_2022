/*  Cabecalho com a declaracao do tipo abstrato de dados Ponto2D,    */
/*  utilizado para representar um ponto (x, y) no plano cartesiano.  */
/*                                                                   */
/*  Autor: Ruy Braga Filho                                           */



#ifndef PONTO_2D
#define PONTO_2D

#include <string>



/**
 * \Um ponto bidimensional.
 */
class Ponto2D {
	
    protected:

        /* Coordenadas (x, y) do ponto */
	    long x;
        long y;	

    public:

        /* Construtores da classe Ponto2D */
		Ponto2D(): x(0), y(0) {}
        Ponto2D(long x, long y): x(x), y(y) {}

        
        /* métodos Sets e Gets para as coordenadas (x, y) */
        void setX( long x );
        long getX();

		void setY( long y );
		long getY();
		

	    
        /* Representação de string do ponto.                                          */
        /* retorna uma string que representa o ponto, como uma tupla de n-dimensões.  */      
        std::string toString();
    
        
    	/* A distância entre pontos de duas dimensões é calculada da seguinte forma:  */
        /* d = sqrt((x1 - x2)^2 + (y1 - y2)^2).                                       */
        double distanciaEuclidiana( Ponto2D p );


    	/* A distância entre pontos em um grid de duas dimensões é calculada da seguinte forma: */
        /* d = menor(deltaX, deltaY) + ( maior(deltaX, deltaY) - menor(deltaX, deltaY) )        */
        /* onde deltaX = abs( x2 - x1 - 1) e deltaY = abs( y2 - y1 - 1)                         */
        long distanciaGrid( Ponto2D p );        
};

#endif



/*  Fim do cabecalho com a declaracao do tipo abstrato de dados Ponto2D  */