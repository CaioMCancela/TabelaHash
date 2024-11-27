#include <iostream>
#include <string>
#include "TabelaHash.h"
using namespace std;

int main() {
    int escolha;
    string frase;

    HASH_COSTRUTOR();
    cout << "TABELA HASH COM  TRES TRATAMENTOS DE COLISOES" << endl <<endl;
    do {
        cout << "1- Inserir com sondagem linear\n2- Inserir com sondagem quadratica\n3- Inserir com sondagem dupla\n";
        cout << "4- Remover\n5-Buscar\n6-sair\nopcao: ";
        cin >> escolha;
        switch (escolha) {
            case 1:
                cout << "Digite a frase que deseja inserir: ";
                cin >> frase;
                HASH_INSERIR_SONDAGEM_LINEAR(frase);
                break;
            case 2:
                cout << "Digite a frase que deseja inserir: ";
                cin >> frase;
                HASH_INSERIR_SONDAGEM_QUADRATICA(frase);
                break;
            case 3:
                cout << "Digite a frase que deseja inserir: ";
                cin >> frase;
                HASH_INSERIR_SONDAGEM_DUPLA(frase);
                break;
            case 4:
                cout << "Digite a frase que deseja remover: ";
                cin >> frase;
                HASH_REMOVER(frase);
                break;
            case 5:
                cout << "Digite a frase que deseja buscar: ";
                cin >> frase;
                HASH_BUSCAR(frase);
                break;
            case 6:
                break;

            default:
                cout << endl << "Opcao nao encontrada!" << endl;
            break;
        }

    }while (escolha != 6);
    system("pause");
    return 0;
}