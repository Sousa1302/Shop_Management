#include <iostream>
#include <fstream>  // Combination of ifstream to read from files and ofstream to create and write to files
#include <sstream>

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
bool database_existance;

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
            
            Produto produto;
            getline(ss, valor, ',');
            produto.ID = stoi(valor);
            getline(ss, produto.NOME_PRODUTO, ',');
            getline(ss, valor, ',');
            produto.QUANTIDADE = stoi(valor);
            getline(ss, valor, ',');
            produto.PRECO = stof(valor);
            getline(ss, valor, ',');
            produto.STATUS = valor[0];
            
            items[quantidade_produtos] = produto;
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
                     << "Quantidade: " << items[x].QUANTIDADE << "\n";
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
    
    for (int i = 0; i < quantidade_produtos; i++) {
        if (items[i].ID == id && items[i].STATUS == 'A') {
            cout << "Produto encontrado:\n";
            cout << "ID: " << items[i].ID << " | "
                 << "Nome: " << items[i].NOME_PRODUTO << " | "
                 << "Preco: " << items[i].PRECO << " | "
                 << "Quantidade: " << items[i].QUANTIDADE << "\n";
            return;
        }
    }
    cout << "Produto com ID " << id << " nao encontrado ou eliminado.\n";
}



void menu(){
    carregarProdutos();

    int menu_choice;
    cout << "-----------------------------------------\n";
    cout << "|   Bem vindo ao sistema da lojinha !   |\n";
    cout << "-----------------------------------------\n";
    do{
        cout << endl;
        cout << "1. Adicionar Produto \n2. Listar Produtos \n3. Consultar Produtos \n4. Alterar um Produto \n5. Apagar Produto \n6. Sair \nR: ";
        cin >> menu_choice;
        cout << endl;

        if(menu_choice == 1){
            adicionarProduto();
        }
        else if (menu_choice == 2){
            exibirProdutos();
        }
        else if(menu_choice == 3){
            consultarProduto();
        }
        else if(menu_choice == 4){
            alterarProduto();
        }
        else if(menu_choice == 5){
            eliminarProduto();  
        }
        else if(menu_choice == 6){
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