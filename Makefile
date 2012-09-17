CC = gcc

CFLAGS = -Wall -Lsrc

RM = rm -f

OBJS = src/tp0.c src/arquivos.c src/matriz.c src/kronecker.c

VALGRIND = valgrind -v --read-var-info=yes --tool=memcheck --leak-check=yes --show-reachable=yes --track-origins=yes
#VALGRIND = valgrind  --read-var-info=yes --tool=memcheck --leak-check=yes -v 
#VALGRIND = valgrind  --track-origins=yes --tool=memcheck --leak-check=yes -v 
#VALGRIND = valgrind  --tool=memcheck 

MAIN = tp0

$(MAIN): $(OBJS)
	@echo ""
	@echo "------------------------"
	@echo " Compilando programa..."
	@echo "------------------------"
	@$(CC) $(CFLAGS) $(OBJS) -g3 -std=c99 -o $(MAIN)
	@echo "------------------------"
	@echo " Compilacao feita com sucesso!"
	@echo "------------------------"

%.o: %.c %.h
	@echo "------------------------"
	@echo " Compilando objeto \"$@\""
	@echo "------------------------"
	@$(CC) $(CFLAGS) $< -c 

clean:
	$(RM) $(MAIN) *.o
	clear

val: $(MAIN)
	$(VALGRIND) ./$(MAIN)

run: $(MAIN)
	@echo " Executando programa..."
	@echo "------------------------"
	@echo ""
	./$(MAIN) entrada/tp0.in 1

all: clean run val