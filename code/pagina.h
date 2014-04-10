#ifndef _H_ESTRUTURAS
#define _H_ESTRUTURAS
#include "estruturas.h"


Pagina iniciarPagina();
void inserirTitulo(Pagina pagina, char * titulo);
void inserirNomeAutor(Pagina pagina, char *nome);
void inserirData(Pagina pagina, char * data);
void inserirHora(Pagina pagina, char * hora);
void inserirLinkInterno(Pagina pagina, char* linkInterno);
void inserirLinkExterno(Pagina pagina, char* linkExterno);
void inserirSeccao(Pagina pagina, char* seccao);
void inserirImagem(Pagina pagina, char* imagem);
void inserirSubseccao(Pagina pagina, char* subseccao);
void inserirPagina(ArrayPaginas paginas,Pagina pagina);
void freeSeccoes(Seccoes sec);
void freelink(Links link);
void freePagina(Pagina pagina);
Seccoes inverte(Seccoes sec);
SubSeccoes inverteSub(SubSeccoes sec);
ArrayPaginas iniciar();
#endif