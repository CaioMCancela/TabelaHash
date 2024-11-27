#include "TabelaHash.h"
#include <iostream>
#include <string>
using namespace std;

int TAM = 21,contador =0;
string *tabela = new string[TAM];

void AumentarTabela() {
    int tamanhoAnterior = TAM;

    TAM *= 2;
    string *novatabela = new string[TAM];

    for (int i = 0; i < TAM; i++) {
        novatabela[i] = "";
    }
    for (int i = 0; i < tamanhoAnterior; i++) {
            novatabela[i] = tabela[i];
    }
    tabela = novatabela;
}

void HASH_COSTRUTOR() {
    for (int i = 0; i < TAM; i++) {
        tabela[i] = "";
    }
}

int funcaohash(string chave) {
    int SomaCaracter = 0;
    for (int i =0;i < chave.size();i++) {
        SomaCaracter += chave[i];
    }
    return SomaCaracter % TAM;
}
int funcaohash2(string chave) {
    int SomaCaracter = 0;
    int peso = 1;
    for (int i =0;i < chave.size();i++) {
        SomaCaracter +=  chave[i] * peso;
        peso += 2;
    }
    return SomaCaracter % TAM;
}

void HASH_INSERIR_SONDAGEM_LINEAR(string chave) {
    int indice = funcaohash(chave);

    if (contador >= 0.75 * TAM) {
        AumentarTabela();
    }

    if (tabela[indice] == "") {
        tabela[indice] = chave;
        contador++;
        cout << "Chave '" << chave << "' inserida no indice " << indice << "." << endl << endl;
    } else if (tabela[indice] == chave) {
        cout << "Elemento ja adicionado, por favor tente adicionar outro." << endl << endl;
    } else {

        cout << "Colisao detectada no indice " << indice << ", procurando proximo espaco disponivel..." << endl;
        int posicao = (indice + 1) % TAM;
        while (tabela[posicao] != "" && tabela[posicao] != chave) {
            posicao = (posicao + 1) % TAM;
        }

        if (tabela[posicao] == chave) {
            cout << "Elemento ja adicionado, por favor tente adicionar outro." << endl << endl;
        } else {
            tabela[posicao] = chave;
            contador++;
            cout << "Chave '" << chave << "' inserida no indice " << posicao << "." << endl << endl;
        }
    }
}

void HASH_INSERIR_SONDAGEM_QUADRATICA(string chave) {
    int indice = funcaohash(chave);

    if (contador >= 0.75 * TAM) {
        AumentarTabela();
    }

    if (tabela[indice] == "") {
        tabela[indice] = chave;
        contador++;
        cout << "chave '" << chave << "' inserida no indice " << indice << "." << endl << endl;
    } else if (tabela[indice] == chave) {
        cout << "Elemento ja adicionado, por favor tente adicionar outro." << endl << endl;
    } else {
        cout << "Colisao detectada no indice " << indice << ", procurando proximo espaco disponivel..." << endl;

        int i = 1;
        int posicao = indice;
        while (tabela[posicao] != "" && tabela[posicao] != chave) {
            // Aplica a sondagem quadrática
            posicao = (indice + i * i) % TAM;
            i++;
        }

        if (tabela[posicao] == chave) {
            cout << "Elemento ja adicionado, por favor tente adicionar outro." << endl << endl;
        } else {
            tabela[posicao] = chave;
            contador++;
            cout << "chave '" << chave << "' inserida no indice " << posicao << "." << endl << endl;
        }
    }
}

void HASH_INSERIR_SONDAGEM_DUPLA(string chave) {
    int indice = funcaohash(chave);
    int deslocamento = funcaohash2(chave);

    if (contador >= 0.75 * TAM) {
        AumentarTabela();
    }

    if (tabela[indice] == "") {
        tabela[indice] = chave;
        contador++;
        cout << "Chave '" << chave << "' inserida no indice " << indice << "." << endl << endl;
    }

    else if (tabela[indice] == chave) {
        cout << "Elemento ja adicionado, por favor tente adicionar outro." << endl << endl;
    }

    else {
        cout << "Colisao detectada no indice " << indice << ", procurando proximo espaco disponivel..." << endl;

        int i = 1;
        int posicao = indice;

        while (tabela[posicao] != "" && tabela[posicao] != chave) {
            posicao = (indice + i * deslocamento) % TAM;
            i++;
        }

        if (tabela[posicao] == chave) {
            cout << "Elemento ja adicionado, por favor tente adicionar outro." << endl << endl;
        } else {

            tabela[posicao] = chave;
            contador++;
            cout << "Chave '" << chave << "' inserida no indice " << posicao << "." << endl << endl;
        }
    }
}


void HASH_REMOVER(string chave) {
    int indice = funcaohash(chave);
    if (tabela[indice] == chave) {
        tabela [indice] = "";
        contador--;
        cout << "Elemento " << chave << " na posicao " << indice << " removido com sucesso!" << endl << endl;
    }else {
        int indiceinicial = indice;
        while (tabela[indice] != "" && tabela[indice] != chave && indice != indiceinicial) {
                indice = (indice +1) %TAM;
        }
        if (tabela[indice] == chave) {
            tabela[indice] = "";
            contador--;
            cout << "Elemento " << chave << " na posicao " << indice << " removido com sucesso!" << endl << endl;
        }else {
            cout << "Elemento " << chave << " nao encontrado na tabela." << endl << endl;
        }
    }
}

void HASH_BUSCAR(string chave) {
    int indice = funcaohash(chave);
    if (tabela[indice] == chave) {
        cout << "Elemento " << chave << " encontrado na posicao " << indice << "." << endl << endl;
    }else {
        int indiceinicial = indice;
        while (tabela[indice] != "" && tabela[indice] != chave && indice != indiceinicial) {
                indice = (indice +1) %TAM;
        }
        if (tabela[indice] == chave) {
            cout << "Elemento " << chave << " encontrado na posicao " << indice << "." << endl << endl;
        }else {
            cout << "Elemento " << chave << " nao encontrado na tabela." << endl << endl;
        }
    }
}