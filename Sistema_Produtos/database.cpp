#include <iostream>
#include <fstream>  // Combination of ifstream to read from files and ofstream to create and write to files
#include <sstream>
#include <stdlib.h>

using namespace std;

struct Produto{
    int ID;
    string NOME_PRODUTO;
    int QUANTIDADE;
    float PRECO;
    char STATUS;            // D - deleted ; A - Active 
};

Produto items[100] = {};    
int quantidade_produtos = 0;

void gravarProdutosFicheiro(){
    ofstream ficheiro("BaseDados_Shop.csv");

    if(ficheiro.is_open()){
        for(int x = 0; x < quantidade_produtos; x++){
            ficheiro << items[x].ID << ","
                     << items[x].NOME_PRODUTO << ","
                     << items[x].QUANTIDADE << ","
                     << items[x].PRECO << ","
                     << items[x].STATUS << "\n";
        }
    }
    ficheiro.close();
}

void carregarProdutos(){
    ifstream ficheiro("BaseDados_Shop.csv");

    if(ficheiro.is_open()){
        string linha;
        while(getline(ficheiro, linha)){
            stringstream ss(linha);
            string valor;
            
            Produto artigo;
            getline(ss, valor, ',');
            artigo.ID = stoi(valor);
            getline(ss, artigo.NOME_PRODUTO, ',');
            getline(ss, valor, ',');
            artigo.QUANTIDADE = stoi(valor);
            getline(ss, valor, ',');
            artigo.PRECO = stof(valor);
            getline(ss, valor, ',');
            artigo.STATUS = valor[0];
            
            items[quantidade_produtos] = artigo;
            quantidade_produtos ++;
        }
        ficheiro.close();
    }
}

void adicionarProduto(){
    Produto novo_Produto;
    novo_Produto.ID = quantidade_produtos + 1;

    cout << "Nome do produto: ";
    cin >> novo_Produto.NOME_PRODUTO;
    cout << "Quantidade do produto: ";
    cin >> novo_Produto.QUANTIDADE;
    cout << "Preco do produto: ";
    cin >> novo_Produto.PRECO;
    novo_Produto.STATUS = 'A';

    items[quantidade_produtos] = novo_Produto;
    quantidade_produtos++;
    gravarProdutosFicheiro();
    system("clear");
}

void exibirProdutos(){
    if(quantidade_produtos == 0){
        cout << "Whopsies ainda nao existem produtos no sistema !\n";
    }
    else{
        for(int x = 0; x < quantidade_produtos ; x++){
            if(items[x].STATUS == 'A'){
                cout << "ID: " << items[x].ID << " | "
                     << "Nome: " << items[x].NOME_PRODUTO << " | "
                     << "Preco: " << items[x].PRECO << " | "
                     << "Quantidade: " << items[x].QUANTIDADE << " | "
                     << "\n";
            }
        }
    }
}

void alterarProduto(){
    int id;
    cout << "Qual o ID do produto que desejas alterar: ";
    cin >> id;

    for(int x = 0; x < quantidade_produtos; x++){
        if(items[x].ID == id && items[x].STATUS == 'A'){
            cout << "Novo nome do produto: ";
            cin >> items[x].NOME_PRODUTO;
            cout << "Novo preco do produto: ";
            cin >> items[x].PRECO;
            cout << "Nova quantidade do produto: ";
            cin >> items[x].QUANTIDADE;

            gravarProdutosFicheiro();
            //return;
            break;
        }
    }
    cout << "Nenhum produto associado a esse ID !\n";
}

void eliminarProduto(){
    int id;
    cout << "Qual o ID do produto que desejas eliminar: ";
    cin >> id;

    for(int x = 0; x < quantidade_produtos; x++){
        if(items[x].ID == id && items[x].STATUS == 'A'){
            items[x].STATUS = 'D';
            gravarProdutosFicheiro();
            cout << "Produto eliminado com sucesso";
            //return;
            break;
        }
    }
    cout << "Nenhum produto associado a esse ID !\n";
}

void consultarProduto() {
    int id;
    cout << "Digite o ID do produto que deseja consultar: ";
    cin >> id;
    
    for (int x = 0; x < quantidade_produtos; x++) {
        if (items[x].ID == id && items[x].STATUS == 'A') {
            cout << "\nProduto encontrado:\n";
            cout << "ID: " << items[x].ID << " | "
                 << "Nome: " << items[x].NOME_PRODUTO << " | "
                 << "Preco: " << items[x].PRECO << " | "
                 << "Quantidade: " << items[x].QUANTIDADE << " | "
                 << "Status: " << items[x].STATUS << "\n";
            return;
        }
    }
    cout << "Produto com ID " << id << " nao encontrado ou eliminado.\n";
}



void menu(){
    carregarProdutos();

    int menu_choice;
    system("clear");
    cout << "-----------------------------------------\n";
    cout << "|   Bem vindo ao sistema da lojinha !   |\n";
    cout << "-----------------------------------------\n";
    do{
        cout << endl;
        cout << "1. Adicionar Produto \n2. Listar Produtos \n3. Consultar Produtos \n4. Alterar um Produto \n5. Apagar Produto \n6. Sair \nR: ";
        cin >> menu_choice;
        cout << endl;

        if(menu_choice == 1){
            system("clear");
            adicionarProduto();
        }
        else if (menu_choice == 2){
            system("clear");
            exibirProdutos();
        }
        else if(menu_choice == 3){
            system("clear");
            consultarProduto();
        }
        else if(menu_choice == 4){
            system("clear");
            alterarProduto();
        }
        else if(menu_choice == 5){
            system("clear");
            eliminarProduto();  
        }
        else if(menu_choice == 6){
            system("clear");
            break;
        }
        else if(menu_choice > 6 || menu_choice < 1){
            cout << "Escolhe uma opcao elegivel !\n";
        }
        
    }while(menu_choice != 6);
}

int main(){
    menu();
    return 0;
}