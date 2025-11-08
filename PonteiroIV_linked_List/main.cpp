#include <iostream>
#include <string>


struct registro
{
    std::string nome;
    std::string curso;
    int ID;
    int cpf;
};

struct aluno
{
    registro dados;
    aluno *proximo;
};


int main()
{


//=====Instanciandoo primeiro espaço do tipo head na memória=================
    aluno* head=nullptr;//Em algum lugar na memria tem um espaço para head
    std::cout<< "Endereco de HEAD...................................................." << &head << std::endl;
//====== A PRIMEIRO NÓ INSERIDO SERÁ O ÚLTIMA DA LISTA=======================
//===========================================================================
//=====Instanciando o promeiro nó(ou indice) da lista========================
//===========================================================================
    aluno* indice= new aluno;  //agora temos outro espaço na momória do mesmo tipo de estrutura aluno chamado indice
    std::cout<< "Endereco de indice.................................................." << &indice << std::endl;

    indice->dados.nome="Maria";
    indice->dados.curso="Eng.Eletronica";
    indice->dados.ID=152002015-2;
    indice->dados.cpf=03245643212;


    std::cout<< "Endereco de indice->proximo........................................." << &indice->proximo << std::endl;
//lIGA O ESTE NÓ AO QUE ERA O HEAD
    indice->proximo=head;//indice->head=0x000014
    std::cout<< "Endereco de indice->proximo=head...................................." << &indice->proximo << std::endl;

//ESTE INDICE SE TORNA A CABEÇA DA LISTA
    head=indice;
    std::cout<< "Endereco de head=indice............................................." << &indice << std::endl;


    std::cout<< "\n\n...................Segundo nó..................................."  << std::endl;


    indice= new aluno;
    std::cout<< "Endereco de indice.................................................." << &indice << std::endl;

    indice->dados.nome="Douglas";

    std::cout<< "Endereco de indice->proximo........................................." << &indice->proximo << std::endl;

    indice->proximo=head;
    std::cout<< "Endereco de indice->proximo=head...................................." << &indice->proximo << std::endl;

    head=indice;
    std::cout<< "Endereco de head...................................................." << &head << std::endl;


//===========================================================
//--PERCURSO E IMPRESSÃO--
//===========================================================
    aluno* currunt=head;
    int counter=1;

    //currunt=indice;

    while(currunt != nullptr)
    {

        std::cout<<"\n:"<< currunt->dados.nome<<std::endl;
        currunt=currunt->proximo;
        counter++;
    }

//===========================================================
//----LIMPEZA DE MEMÓRIA  (Obrigtório em c++)
//===========================================================
//Percorre a lista
    currunt=head;
    aluno* temp= nullptr;
    while(currunt != nullptr)
    {
        temp=currunt->proximo;
        delete currunt;
        currunt=temp;

    }

    return 0;
}







/*
#include <iostream>
#include <string>

// Estruturas do seu código
struct registro {
    std::string nome;
    std::string curso;
    int ID;
    int cpf;
};

struct aluno {
    registro dados;
    aluno *proximo;
};

int main() {
    // 1. Ponteiro de entrada da lista (HEAD)
    aluno* head = nullptr;

    // =======================================================================
    // --- NÓ 1: MARIA (O primeiro a ser inserido, será o último na ordem final) ---
    // =======================================================================
    aluno* no_maria = new aluno;
    no_maria->dados.nome = "Maria";
    no_maria->dados.curso = "Eng. Eletronica";

    // Liga o nó Maria ao que era a cabeça (nullptr)
    no_maria->proximo = head;

    // Maria se torna a nova cabeça
    head = no_maria;

    std::cout << "[INFO] Primeiro nó criado: Maria (Endereço: " << head << ")\n";

    // =======================================================================
    // --- NÓ 2: JOÃO (O segundo a ser inserido, será o primeiro na ordem) ---
    // =======================================================================
    aluno* no_joao = new aluno;
    no_joao->dados.nome = "João";
    no_joao->dados.curso = "Ciência da Computação";

    // Liga o nó João à cabeça antiga (que era o nó Maria)
    no_joao->proximo = head;

    // João se torna a nova cabeça
    head = no_joao;

    std::cout << "[INFO] Segundo nó criado: João (Novo Head: " << head << ")\n";
    std::cout << "------------------------------------------\n";

    // =======================================================================
    // --- PERCURSO E IMPRESSÃO ---
    // =======================================================================

    aluno* currunt = head;
    int count = 1;

    std::cout << "Ordem da Lista:\n";
    while(currunt != nullptr)
    {
        std::cout << count << ". Nome: " << currunt->dados.nome
                  << " (Próximo: " << currunt->proximo << ")\n";

        // Avance para o próximo nó
        currunt = currunt->proximo;
        count++;
    }
    std::cout << "FIM da Lista (NULL)\n";

    // =======================================================================
    // --- LIMPEZA DE MEMÓRIA (Obrigatório em C++) ---
    // =======================================================================
    // Percorre a lista para deletar cada nó e evitar memory leak
    currunt = head;
    aluno* temp = nullptr;
    while(currunt != nullptr) {
        temp = currunt->proximo;
        delete currunt;
        currunt = temp;
    }
    head = nullptr;
    std::cout << "\n[INFO] Memória de ambos os nós liberada.\n";

    return 0;
}

*/




















