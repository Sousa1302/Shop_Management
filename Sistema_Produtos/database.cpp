#include <iostream>
#include <fstream>  // Combination of ifstream to read from files and ofstream tocreate and write to files

using namespace std;

bool database_existance;

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