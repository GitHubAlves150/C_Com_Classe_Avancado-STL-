# Exemplo de um Makefile simples
CC = g++
CFLAGS = -Wall
TARGET = programa

# Regra padrão para compilar tudo
all: $(TARGET)

# Regra para vincular os arquivos objeto ao executável
#$(TARGET): main.o funcao.o
$(TARGET): main.o
#	$(CC) main.o funcao.o -o $(TARGET)
	$(CC) main.o -o $(TARGET)
# Regra para compilar main.cpp
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

# Regra para compilar funcao.cpp
#funcao.o: funcao.cpp
#	$(CC) $(CFLAGS) -c funcao.cpp

# Regra para limpar os arquivos gerados
clean:
	rm -f *.o $(TARGET)
