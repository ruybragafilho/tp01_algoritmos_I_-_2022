/*  Definições das funções do módulo CasamentoEstável.         */
/*  Esse módulo utiliza o algotimo Gale-Shapley para resolver  */
/*  o problem de casamento estável.                            */
/*                                                             */
/*  Autor: Ruy Braga Filho                                     */


#include "CasamentoEstavel.h"

#include <iostream>

using namespace std;


/* Construtor da classe CasamentoEstavel */
CasamentoEstavel::CasamentoEstavel(  TipoLista<Cliente>* cliente,
                                     TipoLista<Loja>* loja  )  {
 
    this->cliente = cliente;
    this->loja = loja;

    this->inicializarEstoque();

    this->gerarTabelaPreferenciaCliente();

    //cout << "\n\nTabela Cliente\n\n";
    //this->mostrarTabelaPreferenciaCliente();
   
}  /*  Fim da definicao do construtor da classe CasamentoEstavel.  */   



/* Destrutor da classe CasamentoEstavel */
CasamentoEstavel::~CasamentoEstavel()  {

    if( tabelaPreferenciaCliente != nullptr )  {

        delete[] tabelaPreferenciaCliente;
        tabelaPreferenciaCliente = nullptr;
    }

    if( estoque != nullptr )  {

        delete estoque;
        estoque = nullptr;
    }

}  /*  Fim da definicao do destrutor da classe CasamentoEstavel.  */   



/* Método que inicializa o vector contendo estoque de cada loja */
void CasamentoEstavel::inicializarEstoque()  {

    long numeroDeLojas = this->loja->tamanhoLista();
    long idLoja;

    /* Aloca o vector que armazenará o estoque de cada loja.          */
    /* Esse vector será usado para acessar o estoque a um custo O(1)  */
    this->estoque = new vector< long >( numeroDeLojas );

    /* Percorre a lista de lojas para obter o seu estoque  */
    /* e carregá-lo para o vector contendo os estoques.    */
    /* A posição i do vector conterá o estoque da loja i.  */
    this->loja->primeiro();
    for( idLoja=0; idLoja<numeroDeLojas; ++idLoja ) {

        try {   

            estoque->at( idLoja ) = this->loja->getItem().getEstoque() ;
            this->loja->proximo();

        } catch (out_of_range& ex) {
            cerr << "An exception occurred: " << ex.what() << endl;
        }
    }    

}  /*  Fim da definicao do metodo inicializarEstoque.  */



/* Metodos que geram as tabelas de preferências dos clientes */
void CasamentoEstavel::gerarTabelaPreferenciaCliente()  {

    /* Cria uma tabela onde o número de linhas é igual ao número de clientes  */
    this->tabelaPreferenciaCliente = new TipoLista<TipoItem>[ this->cliente->tamanhoLista() ];

    long idCliente;
    TipoItem item;
    Cliente c;
    Loja l;
    

    /* Percorre a lista de clientes  */
    this->cliente->primeiro();
    while( this->cliente->temMais() ) {

        c = this->cliente->getItem();
        idCliente = c.getID();

        /* Para cada cliente, percorre a lista de lojas, inserindo-as na lista de preferência do cliente,  */
        /* de forma ordenada decrescente, em função da distância da loja aa casa do cliente.               */
        this->loja->primeiro();
        while( this->loja->temMais() ) {
    
            l = this->loja->getItem();

            item.setID( l.getID() );
            item.setPeso( c.getLocalizacao().distanciaGrid( l.getLocalizacao() ) );
            this->tabelaPreferenciaCliente[ idCliente ].inserirOrdenadoCrescente( item );

            this->loja->proximo();
        }

        this->cliente->proximo();
    }

}  /*  Fim da definicao do metodo gerarTabelaPreferenciaCliente.  */



/* Metodo que mostra a tabela de preferência dos clientes */
void CasamentoEstavel::mostrarTabelaPreferenciaCliente()  {

    long numClientes = this->cliente->tamanhoLista();

    for( long idCliente=0; idCliente<numClientes; ++idCliente )  {
        cout << idCliente << endl;
        this->tabelaPreferenciaCliente[ idCliente ].imprimir();
    }

}  /*  Fim da definicao do metodo mostrarTabelaPreferenciaCliente.  */



/* Metodo que procura a loja com estoque disponivel na lista de preferencia de clientes.  */
/* Se encontar, retorna o id da loja. Senão, retorna -1                                   */
long CasamentoEstavel::lojaComEstoqueDisponivel( long idCliente )  {

    this->tabelaPreferenciaCliente[ idCliente ].primeiro();
        
    /* Percorre a lista de lojas da tabela de preferência do cliente i     */
    /* até encontrar uma com estoque disponível para atender esse cliente  */
    while( this->tabelaPreferenciaCliente[ idCliente ].temMais() )  {
 
        if( this->estoque->at( this->tabelaPreferenciaCliente[ idCliente ].getItem().getID() ) > 0 )  {

            return( this->tabelaPreferenciaCliente[ idCliente ].getItem().getID() );
        } 

        this->tabelaPreferenciaCliente[ idCliente ].proximo();
    }

    return -1;        

}  /*  Fim da definicao do metodo lojaComEstoqueDisponivel.  */



/* Metodo que implementa o algoritmo de Gale-Shapley  */
void CasamentoEstavel::galeShapley( TipoLista<Cliente>* match )  {

    long idCliente;
    long idLoja;


    /*** loop do algoritmo Gale_Shapley ***/

    /* Percorre a lista de clientes, que está ordenada de forma decrescente  */
    /* em função do ticket                                                   */
    this->cliente->primeiro();
    while( this->cliente->temMais() )  {

        /* Obtem o ID do cliente atual  */
        idCliente = this->cliente->getItem().getID();        

        /* Localiza a primeira loja com estoque disponível na lista de  */
        /* preferência do cliente                                       */
        idLoja = this->lojaComEstoqueDisponivel( idCliente );

        /* Se localizar uma loja com estoque disponivel na lista de preferencia  */
        /* do cliente, decrementa o estoque dessa loja e registra o match        */
        if( idLoja > -1 )  {

            --( this->estoque->at( idLoja ) );

            Cliente c = this->cliente->getItem();
            match[ idLoja ].inserirNoFim( c );
        } 

        /* Se nao localizar nenhuma loja com estoque disponível na lista de preferencia do cliente, */
        /* deu reject. Nesse caso, nao sera necessario verificar se a loja prefere o cliente,       */
        /* pois a todos as lojas teem a mesma lista de preferencia de clientes e a lista de         */
        /* clientes eh varrida de acordo com a preferencia da loja, do cliente de maior ticket      */
        /* para a de menor ticket.                                                                  */
        
        /* Vai para o próximo cliente  */
        this->cliente->proximo();
    }

}  /*  Fim da definicao do metodo galeShapley.  */ 