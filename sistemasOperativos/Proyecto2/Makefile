# Nombre de los programas finales
TARGET1 = controlador
TARGET2 = agente

# Compilador
CC = gcc

# Opciones de compilación
CFLAGS = -pthread

# Archivos fuente
SRCS1 = controlador.c
SRCS2 = agente.c

HEADER1 = controlador.h
HEADER2 = agente.h

# Reglas para la compilación de los dos programas
$(TARGET1): $(SRCS1)
	$(CC) $(CFLAGS) -o $(TARGET1) $(SRCS1) $(HEADER1)

$(TARGET2): $(SRCS2)
	$(CC) -o $(TARGET2) $(SRCS2) $(HEADER2)

# Regla para limpiar archivos temporales y los programas compilados
clean:
	rm -f $(TARGET1) $(TARGET2)