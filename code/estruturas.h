


typedef struct links{
	char * link;
	struct links * proximo;
}*Links;

typedef struct subSeccoes{
	char * subSeccao;
	struct subSeccoes * proximo;
}*SubSeccoes;

typedef struct seccoes{
	char * seccao;
	int numSubseccoes;
	SubSeccoes subSeccoes;
	struct seccoes * proxima;
}*Seccoes;


typedef struct pagina{
	char * titulo;
	char * data;
	char * hora;
	char * nomeAutor;
	int numSeccoes;
	int numLinksExt;
	int numLinksInt;
	Links linksExternos;
	Links linksInternos;
	Seccoes seccoes;
	struct pagina *proxima;
}*Pagina;


typedef struct arrayPaginas{
	Pagina paginas[27];
}*ArrayPaginas;




