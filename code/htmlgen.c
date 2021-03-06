
#include "pagina.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void imprimeLinkInternos(FILE * out,Pagina pagina){
	Links olink = pagina->linksInternos;
	
	while(olink){
		
		fprintf(out, "<br><a href=\"http://www.wikipedia.pt/wiki/%s\">%s</a>", olink->link, olink->link);
		olink=olink->proximo;
			}
	
	
}

void troca(char * w, char c, char x){
	int i;
	for(i=0;i<strlen(w);i++){
		if(w[i]==c){
			w[i]=x;
		}
	}

}






void imprimeSeccoes(FILE * out,Pagina pagina){
	Seccoes aux = pagina->seccoes;
	if(aux){
	aux=inverte(aux);
	
	while(aux){
		fputs("<details>", out);
		fprintf(out, "<summary><strong>%s</strong>	(%d)</summary>", aux->seccao,aux->numSubseccoes);
		SubSeccoes auxSub = aux->subSeccoes;
		auxSub=inverteSub(auxSub);
		

		while(auxSub){
			fprintf(out, "<br>&nbsp &nbsp %s", auxSub->subSeccao);
			auxSub=auxSub->proximo;
		} 
		
		
		aux=aux->proxima;
		fputs("</details>", out);
	}
	}else{
		fputs("<strong>Não exitem secções!</strong>", out);
	}
	
}

void imprimeLinkExternos(FILE * out,Pagina pagina){
	Links olink = pagina->linksExternos;
	
	while(olink){

		fprintf(out, "<br><a href=\"http://www.%s\">%s</a>", olink->link, olink->link);
		olink=olink->proximo;
			}
	

}






//imprime artigo na pagina para func criarpagina





void geraArtigo(FILE *artpage, Pagina artigo){


fputs("<!DOCTYPE html>", artpage);
fputs("<html lang=\"en\">", artpage);
fputs("<head>", artpage);
fputs("<title>SUPERwiki</title>", artpage);
fputs("<meta charset=\"utf-8\">", artpage);
fputs("<link rel=\"stylesheet\" href=\"css/reset.css\" type=\"text/css\" media=\"all\">", artpage);
fputs("<link rel=\"stylesheet\" href=\"css/layout.css\" type=\"text/css\" media=\"all\">", artpage);
fputs("<link rel=\"stylesheet\" href=\"css/style.css\" type=\"text/css\" media=\"all\">", artpage);
fputs("<script type=\"text/javascript\" src=\"js/jquery-1.5.2.js\" ></script>", artpage);
fputs("<script type=\"text/javascript\" src=\"js/cufon-yui.js\"></script>", artpage);
fputs("<script type=\"text/javascript\" src=\"js/cufon-replace.js\"></script>", artpage);
fputs("<script type=\"text/javascript\" src=\"js/Molengo_400.font.js\"></script>", artpage);
fputs("<script type=\"text/javascript\" src=\"js/Expletus_Sans_400.font.js\"></script>", artpage);
fputs("<!--[if lt IE 9]>", artpage);
fputs("<script type=\"text/javascript\" src=\"js/html5.js\"></script>", artpage);
fputs("<style type=\"text/css\">.bg, .box2{behavior:url(\"js/PIE.htc\");}</style>", artpage);
fputs("<![endif]-->", artpage);
fputs("</head>", artpage);
fputs("<body id=\"page3\">", artpage);
fputs("<div class=\"body1\">", artpage);
fputs("<div class=\"main\">", artpage);
fputs("<!-- header -->", artpage);
    fputs("<header>", artpage);
      fputs("<div class=\"wrapper\">", artpage);
        fputs("<nav>", artpage);
          fputs("<ul id=\"menu\">", artpage);
           fputs("<li><a href=\"index.html\">home</a></li>", artpage);
           fputs("<li><a href=\"sobre.html\">sobre</a></li>", artpage);
           fputs("<li><a href=\"indice.html\">Índice</a></li>", artpage);
            fputs("<li><a href=\"enunciado.html\">enunciado</a></li>", artpage);
            fputs("<li><a href=\"relatorio.html\">relatÓrio</a></li>", artpage);
            fputs("<li class=\"end\"></li>", artpage);
         fputs(" </ul>", artpage);
        fputs("</nav>", artpage);
      fputs("</div>", artpage);
      fputs("<div class=\"wrapper\">", artpage);
        fputs("<h1>&nbsp;</h1>", artpage);
      fputs("</div>", artpage);
      fputs("<div id=\"slogan\"> SUPERwiki </div>", artpage);
    fputs("</header>", artpage);
    fputs("<!-- / header -->", artpage);
  fputs("</div>", artpage);
fputs("</div>", artpage);
fputs("<div class=\"body2\">", artpage);
  fputs("<div class=\"main\">", artpage);
    fputs("<!-- content -->", artpage);
    fputs("<section id=\"content\">", artpage);
      fputs("<div class=\"box1\">", artpage);
        fputs("<div class=\"wrapper\">", artpage);
          fputs("<article class=\"col1\">", artpage);
           fputs("<div class=\"pad_left1\">", artpage);
           
              fprintf(artpage,"<a href=\"http://www.wikipedia.pt/wiki/%s\"><h2 class=\"pad_bot1\">%s</h2></a>" , artigo->titulo,artigo->titulo);//aqui o titulo do artigo
            fputs("</div>", artpage);
            fputs("<div class=\"wrapper\">", artpage);
              fputs("<figure class=\"left marg_right1\"></figure>", artpage);
             
                
                

                fputs("<details>", artpage);
               
                fprintf(artpage, "<summary><strong>Links Internos</strong>    (%d)</summary>",artigo->numLinksInt);
                imprimeLinkInternos(artpage,artigo);
                fputs("</details>", artpage);
                
                

                 fputs("<details>", artpage);
                
                fprintf(artpage, "<summary><strong>Links Externos</strong>    (%d)</summary>",artigo->numLinksExt);
              
                imprimeLinkExternos(artpage,artigo);
                fputs("</details>", artpage);
		

		fputs("<p class=\"pad_bot1 pad_top2\"><strong>Autor</strong> <br>", artpage);
                fputs("</p>", artpage);
                fprintf(artpage,"%s",artigo->nomeAutor );//insereautor
		fputs("<p class=\"pad_bot1 pad_top2\"><strong>Última revisão</strong> <br>", artpage);
                fputs("</p>", artpage);
		fprintf(artpage, "%s - %s\n", artigo->data,artigo->hora);//insere revisao	 
		           if(strcmp(artigo->imagem,"")){
		           fputs("<p class=\"pad_bot1 pad_top2\"><strong>Imagem:</strong> <br>", artpage);
                fputs("</p>", artpage);

		           troca(artigo->imagem,' ','_');
               fprintf(artpage,"<a href=\"http://pt.wikipedia.org/wiki/Ficheiro:%s.jpg\" alt=\"\" title=\"\" border=\"none\">Link para a imagem</a>", artigo->imagem);
                }
                fputs("</div>", artpage);
          fputs("</article>", artpage);
          fputs("<article class=\"col2 pad_left2\">", artpage);
            fputs("<div class=\"pad_left1\">", artpage);
              fputs("<h2>SecÇÕes</h2>", artpage);
            fputs("</div>", artpage);
            	fputs("<ul class=\"circle\">", artpage);
            	
           	  imprimeSeccoes(artpage,artigo);//insere seccoes
           	  
           	  fputs("</ul>", artpage);      
          fputs("</article>", artpage);
        fputs("</div>", artpage);
      fputs("</div>", artpage);
    fputs("</section>", artpage);
    fputs("<!-- content -->", artpage);
    fputs("<!-- footer -->", artpage);
    fputs("<footer></footer>", artpage);
    fputs("<!-- / footer -->", artpage);
  fputs("</div>", artpage);
fputs("</div>", artpage);
fputs("<script type=\"text/javascript\">Cufon.now();</script>", artpage);
fputs("<div align=center>Trabalho Prático 1 - Processamento de Linguagens 2014</div></body>", artpage);
fputs("</html>",artpage);


} 


void imprimeIndex(FILE *out,ArrayPaginas array,int i){
	
		Pagina aux = array->paginas[i];
		while(aux){
			fprintf(out, "<li><a href=\"%s.html\">%s</a></li>",aux->titulo,aux->titulo);
			aux=aux->proxima;
		}
		

}



void imprimeIndice(FILE *indice,ArrayPaginas array){
	int i=0;
	int letra = 'A';
	while(i<26){
		if(!(array->paginas[i])){
		fprintf(indice,"<li><a>%c</a></li>",letra);
		}else{
		fprintf(indice,"<li><a><font color=\"black\"><strong>%c</strong></font> <span color=\"black\" class=\"caret\"></span></a>",letra);
			fputs("<div>",indice);
				fputs("<ul>",indice);
				imprimeIndex(indice,array,i);
				fputs("</ul>",indice);
			fputs("</div>",indice);
		fputs("</li>",indice);
		}
		letra++;
		i++;
	}
}
//criar o indice

void geraIndice(ArrayPaginas array){
	
	FILE * indice = fopen("final/indice.html", "w+");

fputs("<!DOCTYPE html>", indice);
fputs("<html lang=\"en\">", indice);
fputs("<head>",indice);
fputs("<title>SUPERwiki</title>",indice);
fputs("<meta charset=\"utf-8\">",indice);
fputs("<link rel=\"stylesheet\" href=\"css/reset.css\" type=\"text/css\" media=\"all\">",indice);
fputs("<link rel=\"stylesheet\" href=\"css/layout.css\" type=\"text/css\" media=\"all\">",indice);
fputs("<link rel=\"stylesheet\" href=\"css/style.css\" type=\"text/css\" media=\"all\">",indice);
fputs("<script type=\"text/javascript\" src=\"js/jquery-1.5.2.js\" ></script>",indice);
fputs("<script type=\"text/javascript\" src=\"js/cufon-yui.js\"></script>",indice);
fputs("<script type=\"text/javascript\" src=\"js/cufon-replace.js\"></script>",indice);
fputs("<script type=\"text/javascript\" src=\"js/Molengo_400.font.js\"></script>",indice);
fputs("<script type=\"text/javascript\" src=\"js/Expletus_Sans_400.font.js\"></script>",indice);
fputs("<!--[if lt IE 9]>",indice);
fputs("<script type=\"text/javascript\" src=\"js/html5.js\"></script>",indice);
fputs("<style type=\"text/css\">.bg, .box2{behavior:url(\"js/PIE.htc\");}</style>",indice);
fputs("<![endif]-->",indice);
fputs("</head>",indice);
fputs("<body id=\"page3\">",indice);
fputs("<div class=\"body1\">",indice);
  	fputs("<div class=\"main\">",indice);
    	fputs("<!-- header -->",indice);
    	fputs("<header>",indice);
      	fputs("<div class=\"wrapper\">",indice);
        fputs("<nav>",indice);
        fputs("<ul id=\"menu\">",indice);
        fputs("<li><a href=\"index.html\">home</a></li>",indice);
        fputs("<li><a href=\"sobre.html\">sobre</a></li>",indice);
        fputs("<li><a href=\"indice.html\">Índice</a></li>",indice);
        fputs("<li><a href=\"enunciado.html\">enunciado</a></li>",indice);
        fputs("<li><a href=\"relatorio.html\">relatÓrio</a></li>",indice);
        fputs("<li class=\"end\"></li>",indice);
        fputs("</ul>",indice);
        fputs("</nav>",indice);
        fputs("<ul id=\"icons\">",indice);
        fputs("<li></li>",indice);
        fputs("<li></li>",indice);
        fputs("</ul>",indice);
      	fputs("</div>",indice);
     	fputs("<div class=\"wrapper\">",indice);
        fputs("<h1>&nbsp;</h1>",indice);
      	fputs("</div>",indice);
      	fputs("<div id=\"slogan\"> SUPERwiki </div>",indice);
    	fputs("</header>",indice);
   	fputs("<!-- / header -->",indice);
  	fputs("</div>",indice);
	fputs("</div>",indice);
	fputs("<div class=\"body2\">",indice);
  	fputs("<div class=\"main\">",indice);
  	fputs("<!-- content -->",indice);
 	fputs("<section id=\"content\">",indice);
	fputs("<div class=\"box1\">",indice);
        fputs("<div class=\"pad_left1\">",indice);
        fputs("<h2 class=\"pad_bot1\">Índice</h2>",indice);
        fputs("</div>",indice);
        fputs("<nav2>",indice);
	fputs("<ul>",indice);
	
	
	imprimeIndice(indice,array);				
	

	fputs("</ul>",indice);
	fputs("</nav2>",indice);
      	fputs("</div>",indice);
   	fputs("</section>",indice);
    	fputs("<!-- content -->",indice);
    	fputs("<!-- footer -->",indice);
    	fputs("<footer></footer>",indice);
    	fputs("<!-- / footer -->",indice);
  	fputs("</div>",indice);
	fputs("</div>",indice);
	fputs("<script type=\"text/javascript\">Cufon.now();</script>",indice);
	fputs("<div align=center>Trabalho Prático 1 - Processamento de Linguagens 2014</div></body>",indice);
	fputs("</html>",indice);
}

//cria página html para artigo processado




void criaPagina(Pagina pagina){

FILE * file;
char *nome = (char*)malloc(strlen(pagina->titulo)+30);
strcat(nome, "final/");
strcat(nome, pagina->titulo);
strcat(nome, ".html");
file = fopen(nome, "w+");
geraArtigo(file, pagina);
fclose(file);
//freePagina(pagina);

}

