#include <iostream>
#include <stdlib.h>

using namespace std;

struct Produto
{
    string nome;
    float preco;
    int quantidade;
};

                        // in c++ we cant just declare an array, it needs a num of indexes to know where to locate in the memory
Produto items[100] = {};    // array with a capacity of 100 indexes ( 100 products )
int quantidade = 1;

void adicionarProduto(Produto produtos[], int& quantidadeAtual){
    //mudar a condicao
    // maybe mudar a logica
    for(int x = 0; x < 1 ; x++){
        cout << "Nome: ";
        cin >> produtos[x].nome;
        cout << "Preco: ";
        cin >> produtos[x].preco;
        cout << "Quantidade: ";
        cin >> produtos[x].quantidade;
        //quantidadeAtual ++;
    }
        quantidade++;
    
}

// only shows the last item added to the array info ; ( the first product dissapears ? )
void exibirProduto(const Produto produtos[], int quantidadeAtual){
    for(int x = 0; x < quantidadeAtual; x++){
        cout << "Nome produto: " << produtos[x].nome << endl;
        cout << "Preco produto: " << produtos[x].preco << endl;
        cout << "Quantidade produto: " << produtos[x].quantidade << endl;
    }
}

// core dump issue
float calcularValorTotal(const Produto produtos[], int quantidadeAtual){
    float total = 0;

    for(int x = 0; x < quantidadeAtual; x++){
        total = produtos[x].preco * quantidadeAtual;
    }
}

// menu function ( complete )
void menu(){
    int menu_choice;

    cout << "Bem vindo ao sistema da lojinha !\n";
    
    do{
        cout << endl;
        cout << "1. Adicionar Produto \n2. Exibir Produtos \n3. Calcular Valor Total do Stock \n4. Sair \nR: ";
        cin >> menu_choice;
        cout << endl;

        if(menu_choice == 1){
            adicionarProduto(items, quantidade);
        }
        else if (menu_choice == 2){
            exibirProduto(items, quantidade);
        }
        else if(menu_choice == 3){
            calcularValorTotal(items, quantidade);
        }
        else if(menu_choice == 4){
            system("clear");
            break;
        }
        else if(menu_choice > 4 || menu_choice < 1){
            cout << "Escolhe uma opcao elegivel !\n";
        }
        
    }while(menu_choice != 4);
}

int main(){
    menu();

    return 0;
}