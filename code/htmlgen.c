#include "estruturas.h"


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void imprimeLinkInternos(FILE * out,Pagina pagina){
	Links olink = pagina->linksInternos;
	while(olink){
		fprintf(out, "<tr><td><a href=\"http://www.wikipedia.pt/wiki/%s\">%s</a></tr></td><br>", olink->link, olink->link);
		olink=olink->proximo;
			}

}



void imprimeSeccoes(FILE * out,Pagina pagina){
	Seccoes aux = pagina->seccoes;
	while(aux){
		fprintf(out, "<li>%s", aux->seccao);
		SubSeccoes auxSub = aux->subSeccoes;
		fputs("<ul class=\"circle\">",out);

		while(auxSub){
			fprintf(out, "<li>-->%s</li>", auxSub->subSeccao);
			auxSub=auxSub->proximo;
		} 
		fputs("</ul>",out);
		fputs("</li>",out);
		aux=aux->proxima;
	}
}

void imprimeLinkExternos(FILE * out,Pagina pagina){
	Links olink = pagina->linksExternos;
	while(olink){
		fprintf(out, "<tr><td><a href=\"http://www.%s\">%s</a></tr></td><br>", olink->link, olink->link);
		olink=olink->proximo;
			}

}
void imprimeAutor(FILE * artpage, Pagina artigo){
	fprintf(artpage, "%s", artigo->nomeAutor);
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
              fputs("<p class=\"pad_bot1 pad_top2\"><strong>Links Internos</strong> <br>", artpage);
                fputs("</p>", artpage);
                //fprintf(artpage, "<a href=\"wikipedia.com\%s\">%s</a>", artigo->linksinternos);//inserelinksinternos
                imprimeLinkInternos(artpage,artigo);
                fputs("<p class=\"pad_bot1 pad_top2\"><strong>Links Externos</strong> <br>", artpage);
                fputs("</p>", artpage);
                //fputs("<a href=\"google.com\">insereLinksExternos</a>", artpage);//inserelinksexternos
                imprimeLinkExternos(artpage,artigo);
		fputs("<p class=\"pad_bot1 pad_top2\"><strong>Autor</strong> <br>", artpage);
                fputs("</p>", artpage);
                fprintf(artpage,"%s",artigo->nomeAutor );//insereautor
		fputs("<p class=\"pad_bot1 pad_top2\"><strong>Última revisão</strong> <br>", artpage);
                fputs("</p>", artpage);
		fputs("<a href=\"google.com\">insereRevision</a>", artpage);//insere revisao	            
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


//criar o indice

void geraIndice(/*o indice com os artigos ordenados*/){
	
	FILE * indice = fopen("indice.html", "w+");

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
	
	fputs("<li><a href=\"#a\">A <span class=\"caret\"></span></a>",indice);
			fputs("<div>",indice);
				fputs("<ul>",indice);
				fputs("<li><a href=\"artigos.html\">artigo</a></li>",indice);
				fputs("</ul>",indice);
			fputs("</div>",indice);
	fputs("</li>",indice);
        
	fputs("<li><a href=\"#b\">B <span class=\"caret\"></span></a>",indice);
			fputs("<div>",indice);
				fputs("<ul>",indice);
					fputs("<!--nesta linha sao impressos os restantes artigos genericamente-->",indice);
			
				fputs("</ul>",indice);
			fputs("</div>",indice);
	fputs("</li>",indice);
        fputs("<li><a href=\"#c\">C <span class=\"caret\"></span></a>",indice);
			fputs("<div>",indice);
				fputs("<ul>",indice);
					fputs("<!--nesta linha sao impressos os restantes artigos genericamente-->",indice);
					
				fputs("</ul>",indice);
			fputs("</div>",indice);
	fputs("</li>",indice);
        fputs("<li><a href=\"#d\">D <span class=\"caret\"></span></a>",indice);
			fputs("<div>",indice);
				fputs("<ul>",indice);
					fputs("<!--nesta linha sao impressos os restantes artigos genericamente-->",indice);
					
				fputs("</ul>",indice);
			fputs("</div>",indice);
	fputs("</li>",indice);
        fputs("<li><a href=\"#e\">E <span class=\"caret\"></span></a>",indice);
			fputs("<div>",indice);
				fputs("<ul>",indice);
					fputs("<!--nesta linha sao impressos os restantes artigos genericamente-->",indice);
					
				fputs("</ul>",indice);
			fputs("</div>",indice);
	fputs("</li>",indice);
        fputs("<li><a href=\"#f\">F <span class=\"caret\"></span></a>",indice);
			fputs("<div>",indice);
				fputs("<ul>",indice);
					fputs("<!--nesta linha sao impressos os restantes artigos genericamente-->",indice);
					
				fputs("</ul>",indice);
			fputs("</div>",indice);
	fputs("</li>",indice);
       fputs(" <li><a href=\"#g\">G <span class=\"caret\"></span></a>",indice);
			fputs("<div>",indice);
				fputs("<ul>",indice);
					fputs("<!--nesta linha sao impressos os restantes artigos genericamente-->",indice);
					
				fputs("</ul>",indice);
			fputs("</div>",indice);
	fputs("</li>",indice);
        fputs("<li><a href=\"#h\">H <span class=\"caret\"></span></a>",indice);
			fputs("<div>",indice);
				fputs("<ul>",indice);
					fputs("<!--nesta linha sao impressos os restantes artigos genericamente-->",indice);
					
				fputs("</ul>",indice);
			fputs("</div>",indice);
	fputs("</li>",indice);
        fputs("<li><a href=\"#i\">I <span class=\"caret\"></span></a>",indice);
			fputs("<div>",indice);
				fputs("<ul>",indice);
					fputs("<!--nesta linha sao impressos os restantes artigos genericamente-->",indice);
					
				fputs("</ul>",indice);
			fputs("</div>",indice);
	fputs("</li>",indice);
       fputs(" <li><a href=\"#j\">J <span class=\"caret\"></span></a>",indice);
			fputs("<div>",indice);
				fputs("<ul>",indice);
					fputs("<!--nesta linha sao impressos os restantes artigos genericamente-->",indice);
					
				fputs("</ul>",indice);
			fputs("</div>",indice);
	fputs("</li>",indice);
        fputs("<li><a href=\"#k\">K <span class=\"caret\"></span></a>",indice);
			fputs("<div>",indice);
				fputs("<ul>",indice);
					fputs("<!--nesta linha sao impressos os restantes artigos genericamente-->",indice);
					
				fputs("</ul>",indice);
			fputs("</div>",indice);
	fputs("</li>",indice);
        fputs("<li><a href=\"#l\">L <span class=\"caret\"></span></a>",indice);
			fputs("<div>",indice);
				fputs("<ul>",indice);
					fputs("<!--nesta linha sao impressos os restantes artigos genericamente-->",indice);
					
				fputs("</ul>",indice);
			fputs("</div>",indice);
	fputs("</li>",indice);
       fputs("<li><a href=\"#m\">M <span class=\"caret\"></span></a>",indice);
			fputs("<div>",indice);
				fputs("<ul>",indice);
					fputs("<!--nesta linha sao impressos os restantes artigos genericamente-->",indice);
					
				fputs("</ul>",indice);
			fputs("</div>",indice);
	fputs("</li>",indice);
       fputs(" <li><a href=\"#n\">N <span class=\"caret\"></span></a>",indice);
			fputs("<div>",indice);
				fputs("<ul>",indice);
					fputs("<!--nesta linha sao impressos os restantes artigos genericamente-->",indice);
					
				fputs("</ul>",indice);
			fputs("</div>",indice);
	fputs("</li>",indice);
        fputs("<li><a href=\"#o\">O <span class=\"caret\"></span></a>",indice);
			fputs("<div>",indice);
				fputs("<ul>",indice);
					fputs("<!--nesta linha sao impressos os restantes artigos genericamente-->",indice);
					
				fputs("</ul>",indice);
			fputs("</div>",indice);
	fputs("</li>",indice);
        fputs("<li><a href=\"#p\">P <span class=\"caret\"></span></a>",indice);
			fputs("<div>",indice);
				fputs("<ul>",indice);
					fputs("<!--nesta linha sao impressos os restantes artigos genericamente-->",indice);
					
				fputs("</ul>",indice);
			fputs("</div>",indice);
	fputs("</li>",indice);
        fputs("<li><a href=\"#q\">Q <span class=\"caret\"></span></a>",indice);
			fputs("<div>",indice);
				fputs("<ul>",indice);
					fputs("!--nesta linha sao impressos os restantes artigos genericamente-->",indice);
					
				fputs("</ul>",indice);
			fputs("</div>",indice);
	fputs("</li>",indice);
       fputs("<li><a href=\"#r\">R <span class=\"caret\"></span></a>",indice);
			fputs("<div>",indice);
				fputs("<ul>",indice);
					fputs("<!--nesta linha sao impressos os restantes artigos genericamente-->",indice);
					
				fputs("</ul>",indice);
			fputs("</div>",indice);
	fputs("</li>",indice);
        fputs("<li><a href=\"#s\">S <span class=\"caret\"></span></a>",indice);
			fputs("<div>",indice);
				fputs("<ul>",indice);
					fputs("<!--nesta linha sao impressos os restantes artigos genericamente-->",indice);
					
				fputs("</ul>",indice);
			fputs("</div>",indice);
	fputs("</li>",indice);
        fputs("<li><a href=\"#t\">T <span class=\"caret\"></span></a>",indice);
			fputs("<div>",indice);
				fputs("<ul>",indice);
					fputs("<!--nesta linha sao impressos os restantes artigos genericamente-->",indice);
					
				fputs("</ul>",indice);
			fputs("</div>",indice);
	fputs("</li>",indice);
       fputs("<li><a href=\"#u\">U <span class=\"caret\"></span></a>",indice);
			fputs("<div>",indice);
				fputs("<ul>",indice);
					fputs("<!--nesta linha sao impressos os restantes artigos genericamente-->",indice);
					
				fputs("</ul>",indice);
			fputs("</div>",indice);
	fputs("</li>",indice);
        fputs("<li><a href=\"#v\">V <span class=\"caret\"></span></a>",indice);
			fputs("<div>",indice);
				fputs("<ul>",indice);
					fputs("<!--nesta linha sao impressos os restantes artigos genericamente-->",indice);
					
				fputs("</ul>",indice);
			fputs("</div>",indice);
	fputs("</li>",indice);
       fputs(" <li><a href=\"#w\">W <span class=\"caret\"></span></a>",indice);
			fputs("<div>",indice);
				fputs("<ul>",indice);
					fputs("<!--nesta linha sao impressos os restantes artigos genericamente-->",indice);
					
				fputs("</ul>",indice);
			fputs("</div>",indice);
	fputs("</li>",indice);
       fputs("<li><a href=\"#x\">X <span class=\"caret\"></span></a>",indice);
			fputs("<div>",indice);
				fputs("<ul>",indice);
					fputs("<!--nesta linha sao impressos os restantes artigos genericamente-->",indice);
					
				fputs("</ul>",indice);
			fputs("</div>",indice);
	fputs("</li>",indice);
       fputs(" <li><a href=\"#y\">Y <span class=\"caret\"></span></a>",indice);
			fputs("<div>",indice);
				fputs("<ul>",indice);
					fputs("<!--nesta linha sao impressos os restantes artigos genericamente-->",indice);
					
				fputs("</ul>",indice);
			fputs("</div>",indice);
	fputs("</li>",indice);
      fputs("  <li><a href=\"#z\">Z <span class=\"caret\"></span></a>",indice);
			fputs("<div>",indice);
				fputs("<ul>",indice);
					fputs("<!--nesta linha sao impressos os restantes artigos genericamente-->",indice);
					
				fputs("</ul>",indice);
			fputs("</div>",indice);
	fputs("</li>",indice);


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
char *nome = (char*)malloc(strlen(pagina->titulo)+10);
//strcat(nome, "final/");
strcat(nome, pagina->titulo);
strcat(nome, ".html");
file = fopen(nome, "w+");
geraArtigo(file, pagina);
fclose(file);

}

