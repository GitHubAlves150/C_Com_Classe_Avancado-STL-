#include <iostream>
#include <cstdlib>
using namespace std;
struct Node
{
    int16_t dado;
    Node *proximo;
};


//======FUNCAO INSERIR======
void inserir(Node*& head, int dado)
{
    Node* novo_no=new Node;

    novo_no->dado=dado;

    novo_no->proximo=head;

    head= novo_no;

}

int main()
{

    Node *head=nullptr;  //instancio um ponteiro de tipo struct Node. E aponto para o groud da memória. O head serve como uma referência para os proximos ponteiros apontarem
    Node *novo_no=nullptr;//n que sempre será criado em cada indice. E a cada indice terá um endereço de memória defirente

    //=====================Criado um Nó=========================
    novo_no=new Node;//Endereço 0x100
    novo_no->dado=2;
    //----------------------
    //No final os dois tem que apontar uma para o outro
    //A cabeça aponta para o final do corpo e o corpo aponta para a cabeça
    novo_no->proximo=head;//aponta para uma estrutura nula tanto os dados quanto o ponteiro interno de Node
    head= novo_no;  //a cabeça apoonta para outro indice
    //----------------------
    //=====================Fim do primeiro Nò====================




    novo_no=new Node;// Endereço 0x 2005
    novo_no->dado=21;//
    //--------------------------------
    novo_no->proximo=head;//o corpo aponta para a cabeça
    head= novo_no;
    novo_no=new Node;
    novo_no->dado=121;

    novo_no->proximo=head;

    head= novo_no;



    std::cout << ": " << head->dado << std::endl;
    head= head->proximo;
    std::cout << ": " << head->dado << std::endl;
    head= head->proximo;

    std::cout << ": " << head->dado << std::endl;



    return 0;
}

//================Exemplo gereado pelo gemini====================================
/*
#include <iostream>
#include <cstdlib> // Necessário para a função malloc ou new (em C++)

//==================================================
// 1. ESTRUTURA DO NÓ (struct Node)
//==================================================
struct Node {
    int dado;
    Node* proximo;   // Ponteiro que armazena o endereço do próximo Node
};

//==================================================
// 2. FUNÇÃO: Inserir um novo nó no início da lista
//==================================================
// Observação: Usamos Node** (ponteiro para ponteiro) ou Node*& (referência para ponteiro)
// para modificar o ponteiro 'cabeca' original que foi passado.
void inserirNoInicio(Node*& cabeca, int dado) {

    // 1. Aloca memória para o novo nó (na heap)
    Node* novo_no = new Node; // new substitui malloc em C++

    // 2. Atribui os dados ao novo nó
    novo_no->dado = dado;

    // 3. O ponteiro 'proximo' do novo nó aponta para onde a 'cabeca' está apontando (a lista antiga)
    // Se a lista estava vazia, novo_no->proximo será nullptr.
    novo_no->proximo = cabeca;

    // 4. A 'cabeca' agora aponta para o novo nó (tornando-o o primeiro)
    // Esta é a mudança mais importante, pois atualiza o ponto de entrada da lista
    cabeca = novo_no;
}

//==================================================
// 3. FUNÇÃO: Exibir todos os elementos da lista
//==================================================
void exibirLista(Node* cabeca) {
    Node* atual = cabeca; // Ponteiro auxiliar para percorrer a lista

    std::cout << "Lista: ";
    if (atual == nullptr) {
        std::cout << "Vazia\n";
        return;
    }

    // Percorre a lista até que o ponteiro auxiliar chegue ao fim (nullptr)
    while (atual != nullptr) {
        std::cout << atual->dado;

        if (atual->proximo != nullptr) {
            std::cout << " -> ";
        } else {
            std::cout << " -> NULL"; // Indica o fim da lista
        }

        // Move o ponteiro auxiliar para o endereço armazenado em 'proximo'
        atual = atual->proximo;
    }
    std::cout << "\n";
}

//==================================================
// 4. FUNÇÃO: Limpeza de memória (Para evitar memory leak)
//==================================================
void liberarMemoria(Node*& cabeca) {
    Node* atual = cabeca;
    Node* proximo_no = nullptr;

    while (atual != nullptr) {
        proximo_no = atual->proximo; // Salva o endereço do próximo
        delete atual;                // Libera a memória do nó atual
        atual = proximo_no;          // Avança para o próximo
    }
    cabeca = nullptr; // Define a cabeça como nula após a limpeza
    std::cout << "[INFO] Memória liberada.\n";
}


//==================================================
// 5. FUNÇÃO PRINCIPAL (MAIN)
//==================================================
int main() {
    // Declara o ponteiro de entrada da lista (a Cabeça)
    // Inicialmente, aponta para nada.
    Node* cabeca = nullptr;

    // Inserção 1: O primeiro nó se torna a cabeça
    std::cout << "Inserindo 10...\n";
    inserirNoInicio(cabeca, 10); // Lista: 10
    exibirLista(cabeca);

    // Inserção 2: 20 aponta para o nó que contém 10. 20 se torna a nova cabeça.
    std::cout << "Inserindo 20...\n";
    inserirNoInicio(cabeca, 20); // Lista: 20 -> 10
    exibirLista(cabeca);

    // Inserção 3: 5 aponta para o nó que contém 20. 5 se torna a nova cabeça.
    std::cout << "Inserindo 5...\n";
    inserirNoInicio(cabeca, 5);  // Lista: 5 -> 20 -> 10
    exibirLista(cabeca);

    // Libera a memória alocada na heap antes de encerrar o programa
    liberarMemoria(cabeca);

    return 0;
}

*/



//=========================Duvida======================================
/*
 nao entendi! A cada inserção o no criado um um novo endereço aponta para a cabeça? e os outros nos como eles apontam um para o outro?

Sua confusão é muito comum e aponta exatamente para o ponto central da Lista Encadeada! Vamos detalhar o que acontece na inserção no início e como os nós mantêm a ordem correta.

Sim, você está correto: a cada inserção, o novo nó criado aponta para a cabeça antiga.

1. Entendendo a Inserção no Início (LIFO - Last In, First Out)

O método inserirNoInicio é o mais simples porque ele sempre faz o mesmo processo, independentemente do tamanho da lista: ele "empurra" o novo nó para a frente.

Vamos rastrear a lista passo a passo e o que acontece com os ponteiros.

Cenário Inicial: Lista Vazia

    Node* cabeca = nullptr;

1ª Inserção: inserirNoInicio(cabeca, 10)

    Criação: É alocado um novo nó (Node* novo_no) com dado = 10.

        Endereço: 0x1000 (exemplo).

    Ligação: novo_no->proximo = cabeca;

        O proximo de 0x1000 recebe nullptr (que é o valor de cabeca).

    Nova Cabeça: cabeca = novo_no;

        cabeca agora armazena 0x1000.

HEAD→[10∣NULL]

2ª Inserção: inserirNoInicio(cabeca, 20)

    Criação: É alocado um novo nó (Node* novo_no) com dado = 20.

        Endereço: 0x2000 (exemplo).

    Ligação: novo_no->proximo = cabeca;

        O proximo de 0x2000 recebe 0x1000 (que é o valor de cabeca). Este é o elo!

    Nova Cabeça: cabeca = novo_no;

        cabeca agora armazena 0x2000.

HEAD(0x2000)→[20∣0x1000]→[10∣NULL]

3ª Inserção: inserirNoInicio(cabeca, 5)

    Criação: É alocado um novo nó (Node* novo_no) com dado = 5.

        Endereço: 0x3000 (exemplo).

    Ligação: novo_no->proximo = cabeca;

        O proximo de 0x3000 recebe 0x2000 (que é o valor de cabeca).

    Nova Cabeça: cabeca = novo_no;

        cabeca agora armazena 0x3000.

HEAD(0x3000)→[5∣0x2000]→[20∣0x1000]→[10∣NULL]

2. A Resposta: Como os Outros Nós Apontam um Para o Outro?

Eles apontam um para o outro porque o nó recém-inserido só se liga à cabeça atual, mas nunca quebra as ligações dos nós que já existiam.

Na 3ª Inserção, o nó que contém 5 aponta para o nó que contém 20.

    O nó 20 já apontava para o nó 10.

O campo proximo do nó 20 foi definido na 2ª Inserção e nunca mais foi tocado! O nó 5 simplesmente foi colocado à frente de toda a cadeia existente, que permaneceu intacta.

O Rastreamento (Percurso)

Quando você chama exibirLista(cabeca), a função faz o seguinte:

    Começa em cabeca (0x3000, nó 5).

    Imprime 5.

    Move para atual = atual->proximo; (Lê o 0x2000 do nó 5 e vai para o nó 20).

    Imprime 20.

    Move para atual = atual->proximo; (Lê o 0x1000 do nó 20 e vai para o nó 10).

    Imprime 10.

    Move para atual = atual->proximo; (Lê o nullptr do nó 10 e para).

A cadeia é mantida pelas ligações internas dos nós mais antigos. O nó novo só precisa se ligar ao que era o primeiro elemento antes dele.





*/


