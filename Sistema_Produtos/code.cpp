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
int quantidade = 0;

void adicionarProduto(Produto produtos[], int& quantidadeAtual){
    cout << "Nome do produto: ";
    cin >> produtos[quantidadeAtual].nome;
    cout << "Preco do produto: ";
    cin >> produtos[quantidadeAtual].preco;
    cout << "Quantidade do produto: ";
    cin >> produtos[quantidadeAtual].quantidade;

    system("clear");
    quantidadeAtual++;
}

void exibirProduto(const Produto produtos[], int quantidadeAtual){
    for(int x = 0; x < quantidadeAtual; x++){
        cout << "----------------------------\n";
        cout << "Nome produto: " << produtos[x].nome << endl;
        cout << "Preco produto: " << produtos[x].preco << endl;
        cout << "Quantidade produto: " << produtos[x].quantidade << endl;
    }
    cout << "----------------------------\n";
}


float calcularValorTotal(const Produto produtos[], int quantidadeAtual){
    float total = 0;
    
    for(int x = 0; x < quantidadeAtual; x++){
        total += produtos[x].preco * produtos[x].quantidade;
    }

    return total;
}


void menu(){
    system("clear");
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
            float total_stock = calcularValorTotal(items, quantidade);
            cout << "O valor total do stock e: " << total_stock << " $\n";
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