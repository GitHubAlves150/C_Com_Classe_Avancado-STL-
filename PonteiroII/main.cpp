#include <iostream>
#include <cstddef>
using namespace std;

typedef struct
{
    int matricula;
    int idade;
    char sexo;
} Node;


int main()
{

    Node a1;
    a1.matricula=123;
    a1.sexo='c';
    a1.idade=30;

    int *g;
    int ft=90;
    g=&ft;

    //===                                    =============
    //===ESTA SESSÃO MOSTRA PONTEIROS BÁSICOS=============
    //===                                    =============
    cout<< "valor de f apontado po g:........"<<  *g   <<endl;
    cout<< "endereco de ft:.................."<<  &ft   <<endl;
    cout<< "endereco que g aponta:..........."<<   g   <<endl;
    cout<< "endereco que g está:............."<<  &g   <<endl;
    //===                                    =============
    //===           FIM                      =============
    //===                                    =============
    //====================================================
    cout<<"...."<<endl;
    //===                                    =============
    //===ESTA SESSÃO MOSTRA O TAMANHO DA
    //   STRUCT NÃO CONDIZ COM A SOMA DO TAMANHO
    //   DOS MONBROS ISSO POR CAUSA DOS PEDDING
    //   BYTES ENTRE OS MEMBROS
    //===                                    =============
    cout <<"matricula;......................."  << &a1.matricula                      << endl;
    cout <<"sexo............................."  << static_cast<void*>(&a1.sexo)       << endl;

    cout <<"Soma de todos os membros........."  << sizeof(a1.matricula)+sizeof(a1.sexo)  << endl;
    cout <<"Tamanho do Node.................."  << sizeof(Node)  << endl;
cout << "offsetof..."<<  offsetof(Node, sexo)<<endl;//quantos byts o monbro sexo está da struct Node
    //===                                    =============
    //===           FIM                      =============
    //===                                    =============
    return 0;
}
