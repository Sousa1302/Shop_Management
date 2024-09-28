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

void alterarProdutos(){
    
}





int dataBase_Status(){
    string filename = "Shop_Database.csv";
    int database_choice;

    // Verificar se o ficheiro existe, tentando-o abrir
    ifstream file(filename);

    // caso o ficheiro ja exista
    if(file){
        cout << "Parece que ja tens a base de dados criada... baril !\n";

    }

    // caso o ficheiro nao esteja criado yet 
    else{
        cout << "Queres criar uma nova base dados ? \n1. SIM \n2. NAO \nR: ";
        cin >> database_choice;
        
        if(database_choice == 1){
            ofstream novo_ficheiro(filename);
            if(novo_ficheiro){
                cout << "Base de dados criada com sucesso !\n";
            }
            else{
                cout << "Whopsies... parece que algo deu errado !\n";
            }
        }
        else if(database_choice == 2){
            return 0;
        }
        else if(database_choice > 2 || database_choice < 1){
            cout << "Escolha uma opcao elegivel !\n";
        }
    }
}


void menu(){
    
    int menu_choice;
    cout << "-----------------------------------------\n";
    cout << "|   Bem vindo ao sistema da lojinha !   |\n";
    cout << "-----------------------------------------\n";
    do{
        cout << endl;
        cout << "1. Listar Produtos \n2. Consultar \n3. Alterar um Produto \n4. Apagar Produto \nR: ";
        cin >> menu_choice;
        cout << endl;

        if(menu_choice == 1){
            // listar 
        }
        else if (menu_choice == 2){
            // Consultar
        }
        else if(menu_choice == 3){
            // Alterar 
        }
        else if(menu_choice == 4){
            // Apagar 
        }
        else if(menu_choice == 5){
            break; 
        }
        else if(menu_choice > 5 || menu_choice < 1){
            cout << "Escolhe uma opcao elegivel !\n";
        }
        
    }while(menu_choice != 5);
}


int main(){
    dataBase_Status();
    return 0;
}