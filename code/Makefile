IN=test5.xml
NAME=superWiki
objects=pagina.o htmlgen.o
flag=-c
FLEX=flexWiki
PASTA=~/TrabaPL/code/final/

$(NAME):$(NAME).c $(objects)
	cc -o $(NAME) $(NAME).c $(objects) 
$(NAME).c:$(FLEX).fl 
	flex -o  $(NAME).c $(FLEX).fl  
pagina.o:pagina.c pagina.h estruturas.h
	gcc $(flag) pagina.c
htmlgen.o:htmlgen.c htmlgen.h estruturas.h
	gcc $(flag) htmlgen.c
clean:
	$(RM) $(objects) $(NAME).c 
	rm -f -r $(PASTA)
test:$(NAME)
	./$(NAME) < $(IN)

