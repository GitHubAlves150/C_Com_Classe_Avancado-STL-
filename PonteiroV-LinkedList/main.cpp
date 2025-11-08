#include <iostream>

struct aluno{
    int id;
    std::string nome;
    std::string curso;
};
struct no{
    aluno novoAluno;
    no* proximo;
};

int main()
{
    no NODE;
    std::cout<<"Endereceo de struc no....................................."<< &NODE << std::endl;

    no* head= nullptr;
    std::cout<<"Endereceo de head........................................."<< &head << std::endl;
    std::cout<<"Valor de head............................................."<< head << std::endl;

    no* novo_No= nullptr;
    std::cout<<"Endereceo de novo_no=nullptr.............................."<< &novo_No << std::endl;
    std::cout<<"Valor de novo_no=nullptr.................................."<< novo_No << std::endl;

    novo_No= new no;
    std::cout<<"Endereceo de novo_no......................................"<< &novo_No << std::endl;
    std::cout<<"Endereceo de novo_no......................................"<< novo_No << std::endl;

    novo_No->novoAluno.curso="EngeEletronica";
    novo_No->novoAluno.nome="Lucas";
    novo_No->novoAluno.id=1250512025;

    std::cout<<"Endereceo de novo_no->proximo.............................."<< &novo_No->proximo << std::endl;//Imprime o endereço onde o ponteiro 'próximo' está armazenado(fixo)
    std::cout<<"valor de novo_no->proximo aponta..........................."<< novo_No->proximo << std::endl;//Imprime o VALOR para onde o ponteiro 'próximo' está apontando
    //Agora vem a atribuicao
    novo_No->proximo=head;
    std::cout<<"Endereceo de novo_no->proximo(Após atribuicao)............."<< &novo_No->proximo << std::endl;//Imprime o endereço onde o ponteiro 'próximo' está armazenado(fixo)
    std::cout<<"Valor de novo_no->proximo aponta(Após atribuicao).........."<< novo_No->proximo << std::endl;//Imprime o VALOR para onde o ponteiro 'próximo' está apontando
    head=novo_No;
    std::cout<<"Endereceo de head.........................................."<< &head << std::endl;
    std::cout<<"Valor de head.............................................."<< head << std::endl;




    std::cout<<"\n\n....segundo no da lista..............\n\n"<<  std::endl;

    novo_No= new no;
    std::cout<<"Endereceo do segundo no...................................."<< &novo_No << std::endl;
    std::cout<<"Valor do segundo no........................................"<< novo_No << std::endl;

    novo_No->novoAluno.curso="Eng. civil";
    novo_No->novoAluno.nome="Maria";
    novo_No->novoAluno.id=3409855;


    std::cout<<"Endereceo de novo_no->proximo aponta......................."<< &novo_No->proximo << std::endl;//Imprime o VALOR para onde o ponteiro 'próximo' está apontando    novo_No->proximo=head;
    std::cout<<"Valor de novo_no->proximo.................................."<< novo_No->proximo << std::endl;
    novo_No->proximo=head;
    std::cout<<"Endereceo de novo_no->proximo(Após atribuicao)............."<< &novo_No->proximo << std::endl;//Imprime o endereço onde o ponteiro 'próximo' está armazenado(fixo)
    std::cout<<"Valor de novo_no->proximo aponta(Após atribuicao).........."<< novo_No->proximo << std::endl;//Imprime o VALOR para onde o ponteiro 'próximo' está apontando
    head=novo_No;
    std::cout<<"Endereceo de head.........................................."<< &head << std::endl;
    std::cout<<"Valor de head.............................................."<< head << std::endl;

    std::cout<<"\n\n....terceiro no da lista..............\n\n"<<  std::endl;

    novo_No= new no;
    std::cout<<"Endereceo do segundo no...................................."<< &novo_No << std::endl;
    std::cout<<"Valor do segundo no........................................"<< novo_No << std::endl;

    novo_No->novoAluno.curso="Eng. cosmica";
    novo_No->novoAluno.nome="Maciel";
    novo_No->novoAluno.id=3409855;


    std::cout<<"Endereceo de novo_no->proximo aponta......................."<< &novo_No->proximo << std::endl;//Imprime o VALOR para onde o ponteiro 'próximo' está apontando    novo_No->proximo=head;
    std::cout<<"Valor de novo_no->proximo.................................."<< novo_No->proximo << std::endl;
    novo_No->proximo=head;
    std::cout<<"Endereceo de novo_no->proximo(Após atribuicao)............."<< &novo_No->proximo << std::endl;//Imprime o endereço onde o ponteiro 'próximo' está armazenado(fixo)
    std::cout<<"Valor de novo_no->proximo aponta(Após atribuicao).........."<< novo_No->proximo << std::endl;//Imprime o VALOR para onde o ponteiro 'próximo' está apontando
    head=novo_No;
    std::cout<<"Endereceo de head.........................................."<< &head << std::endl;
    std::cout<<"Valor de head.............................................."<< head << std::endl;



    no* currunt= head;
    int c=0;
    while(currunt != nullptr){
        std::cout<< "Curso:......" << currunt->novoAluno.curso << std::endl;
        std::cout<< "Nome:......." << currunt->novoAluno.nome << std::endl;
        std::cout<< "ID:........." << currunt->novoAluno.id << std::endl;
        std::cout<<c++<<std::endl;
        currunt= currunt->proximo;
    }
    //=================ESVAZIANDO A LISTA============================
    no* auxiliar=head;
    no* tmp=nullptr;
    while(auxiliar != nullptr){
        tmp=auxiliar->proximo;
        delete auxiliar;
        auxiliar=tmp;
    }

    std::cout << "Lista vazia"<<std::endl;
     while(currunt != nullptr){
        std::cout<< "Curso:......" << currunt->novoAluno.curso << std::endl;
        std::cout<< "Nome:......." << currunt->novoAluno.nome << std::endl;
        std::cout<< "ID:........." << currunt->novoAluno.id << std::endl;
        std::cout<<c++<<std::endl;
        currunt= currunt->proximo;
    }




    return 0;
}






























