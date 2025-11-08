#include <iostream>

using namespace std;
struct Node
{
    int dado;
    Node *proximo;
};


int main()
{


    Node *aluno, *tempPtr, *inicio;
    aluno=new Node;//crio uma instancia d eponteiro, ou seja! head aponta para alguma estrutura de tipo Struct Node
    inicio = aluno;//meu inicio tem o mesmo apontamento para head;
    aluno->dado=20;
    aluno->proximo=nullptr;
    tempPtr=aluno;


    aluno= new Node;
    tempPtr->proximo=aluno;
    aluno->dado=30;
    aluno->proximo=nullptr;
    tempPtr=aluno;


    aluno= new Node;
    tempPtr->proximo=aluno;
    aluno->dado=370;
    aluno->proximo=nullptr;
    tempPtr=aluno;
    tempPtr=inicio;


    do{
        std::cout << ":" << tempPtr->dado << std::endl;
        tempPtr=tempPtr->proximo;
    }while(tempPtr->proximo != NULL);


    return 0;
}
