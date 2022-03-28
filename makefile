EXECUTAVEIS = teste

MODULOS = lista polinomio

OBJETOS = $(addsuffix .o,$(MODULOS)) $(addsuffix .o,$(EXECUTAVEIS))

#------------------------------------------------------------------------------
.PHONY : default clean

#------------------------------------------------------------------------------
default : teste
	./teste

#------------------------------------------------------------------------------
teste : teste.o lista.o polinomio.o
	$(CC) $^ -lm -o $@

#------------------------------------------------------------------------------
clean :
	$(RM) -v $(EXECUTAVEIS) $(OBJETOS)

