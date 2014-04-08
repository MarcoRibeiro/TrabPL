#include "estruturas.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

Pagina iniciarPagina() {

	Pagina pagina = (Pagina) malloc(sizeof(struct pagina));

	pagina->linksExternos = NULL;
	pagina->linksInternos = NULL;
	pagina->seccoes = NULL;
	pagina->numLinksExt = 0;
	pagina->numLinksInt = 0;
	pagina->numSeccoes = 0;
	pagina->proxima=NULL;
	return pagina;

}

void inserirTitulo(Pagina pagina, char * titulo) {
	char * verdTitulo = (char *) malloc(sizeof(char*[strlen(titulo) + 1]));
	strcpy(verdTitulo, titulo);
	pagina->titulo = verdTitulo;
}

void inserirNomeAutor(Pagina pagina, char *nome) {
	char* nomeAutor = (char*) malloc(sizeof(char*[strlen(nome) + 1]));
	strcpy(nomeAutor, nome);
	pagina->nomeAutor = nomeAutor;
}
void inserirData(Pagina pagina, char * data) {
	char* dataRevisao = (char*) malloc(sizeof(char*[strlen(data) + 1]));
	strcpy(dataRevisao, data);
	pagina->data = dataRevisao;
}

void inserirLinkInterno(Pagina pagina, char* linkInterno) {
	Links novoLink = (Links) malloc(sizeof(struct links));
	Links aux = pagina->linksInternos;
	char *link = (char *) malloc(sizeof(char *[strlen(linkInterno) + 1]));
	strcpy(link,linkInterno);
	novoLink->link=link;

	novoLink->proximo=aux;
	pagina->linksInternos=novoLink;
	pagina->numLinksInt++;
}


void inserirLinkExterno(Pagina pagina, char* linkExterno) {
	Links novoLink = (Links) malloc(sizeof(struct links));
	Links aux = pagina->linksExternos;
	char *link = (char *) malloc(sizeof(char *[strlen(linkExterno) + 1]));
	strcpy(link,linkExterno);
	novoLink->link=link;

	novoLink->proximo=aux;
	pagina->linksExternos=novoLink;
	pagina->numLinksExt++;
}
void inserirSeccao(Pagina pagina, char* seccao) {
	Seccoes novaSeccao= (Seccoes) malloc(sizeof(struct seccoes));
	Seccoes aux = pagina->seccoes;
	char *sec = (char *) malloc(sizeof(char *[strlen(seccao) + 1]));
	strcpy(sec,seccao);
	novaSeccao->seccao=sec;
	novaSeccao->subSeccoes=NULL;
	novaSeccao->proxima=aux;
	pagina->seccoes=novaSeccao;
	pagina->numSeccoes++;
}
void inserirSubseccao(Pagina pagina, char* subseccao){
	Seccoes seccao = pagina->seccoes;
	SubSeccoes novaSub = (SubSeccoes)malloc(sizeof(struct subSeccoes));
	char *subsec = (char *) malloc(sizeof(char *[strlen(subseccao) + 1]));
	strcpy(subsec,subseccao);
	SubSeccoes aux = seccao->subSeccoes;
	novaSub->subSeccao=subsec;
	seccao->subSeccoes=novaSub;
	novaSub->proximo=aux;
	seccao->numSubseccoes++;

}

int getIndex(Pagina pagina){
	char pChar = toupper(pagina->titulo[0]);
	if (pChar < 65 || pChar > 91) {
			return 26;
		} else {
			return pChar - 65;
		}
}

ArrayPaginas iniciar(){
	int ini;
		ArrayPaginas array = malloc(sizeof(struct arrayPaginas));
		for (ini = 0; ini < 26; ini++) {
			array->paginas[ini] = NULL;
		}
		return array;
}

int comparar(const char* s1, const char* s2) {
	for (; *s1 == *s2; ++s1, ++s2) {
		if (*s1 == '\0') {
			return 0;
		}
	}
	if (*s1 < *s2) {
		return -1;
	} else {
		return +1;
	}
}

ArrayPaginas inserirPagina(ArrayPaginas paginas, Pagina pagina) {
	int ordem;
	int index = getIndex(pagina);
	Pagina aux = paginas->paginas[index];
	Pagina paginaAnterior = NULL;

	if (aux == NULL ) {
		paginas->paginas[index] = pagina;
		return paginas;
	}

	ordem = comparar(pagina->titulo, aux->titulo);

	if (ordem == 0)
		return paginas;

	if (ordem == -1) {

		paginas->paginas[index] = pagina;
		pagina->proxima = aux;
		return paginas;
	}

	while (aux != NULL ) {
		ordem = comparar(pagina->titulo, aux->titulo);
		if (ordem == 0)
			return paginas;
		if (ordem == -1) {
			paginaAnterior->proxima = pagina;
			pagina->proxima = aux;
			return paginas;
		}

		paginaAnterior = aux;
		aux = aux->proxima;
	}

	paginaAnterior->proxima = pagina;
	pagina->proxima = NULL;

	return paginas;

}



