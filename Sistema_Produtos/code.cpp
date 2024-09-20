#include <iostream>

using namespace std;

struct Produto
{
    string nome;
    float preco;
    int quantidade;
};

Produto items[] = {};
int qunatidade = 0;

void adicionarProduto(Produto produtos[], int& quantidadeAtual){
    cout << "Nome: ";
    cin >> produtos->nome;
    cout << "Preco: ";
    cin >> produtos->preco;
    cout << "Quantidade: ";
    cin >> produtos->quantidade;

    // ? Produto new_product_1;
}

void exibirProduto(const Produto produtos[], int quantidadeAtual){
    for(int x = 0; x < quantidadeAtual; x++){
        cout << "Nome produto: " << produtos->nome << endl;
        cout << "Preco produto: " << produtos->preco << endl;
        cout << "Quantidade produto: " << produtos->quantidade << endl;
    }
}

float calcularValorTotal(const Produto produtos[], int quantidadeAtual){
    float total;

    for(int x = 0; x < quantidadeAtual; x++){
        //total = total + produtos[x];
    }
}

void menu(){
    int menu_choice;

    do{
        cout << "Bem vindo ao sistema da lojinha !\n";
        cout << "1. Adicionar Produtor \n2. Exibir Produtos \n3. Calcular Valor Total do Stock \n4. Sair \n";
        cin >> menu_choice;

        switch (menu_choice)
        {
        case 0:
            break;
        case 1:
            adicionarProduto(items, qunatidade);
            break;
        case 2:

            break;
        case 3:

            break;
        default:
            cout << "Escolhe uma opção !\n";
            break;
        }
    }while(menu_choice > 0 || menu_choice < 5);

}

int main(){
    //Produto
    menu();

    return 0;
}