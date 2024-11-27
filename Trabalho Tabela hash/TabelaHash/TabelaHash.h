#ifndef TABELAHASH_H
#define TABELAHASH_H

#include <string>
using namespace std;

void HASH_COSTRUTOR();

void AumentarTabela();

int funcaohash(string chave);

int funcaohash2(string chave);

void HASH_INSERIR_SONDAGEM_LINEAR(string chave);

void HASH_INSERIR_SONDAGEM_QUADRATICA(string chave);

void HASH_INSERIR_SONDAGEM_DUPLA(string chave);

void HASH_REMOVER(string chave);

void HASH_BUSCAR(string chave);


#endif //TABELAHASH_H
