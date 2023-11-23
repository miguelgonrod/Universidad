# Nombre de los programas finales
TARGET1 = pdispersa
TARGET2 = hdispersa

# Compilador
CC = gcc

# Opciones de compilación
CFLAGS = -pthread

# Archivos fuente
SRCS1 = pdispersa.c
SRCS2 = hdispersa.c

HEADER1 = pdispersa.h
HEADER2 = hdispersa.h

# Reglas para la compilación de los dos programas
$(TARGET1): $(SRCS1)
	$(CC) -o $(TARGET1) $(SRCS1) $(HEADER1)

$(TARGET2): $(SRCS2)
	$(CC) $(CFLAGS) -o $(TARGET2) $(SRCS2) $(HEADER2)

# Regla para limpiar archivos temporales y los programas compilados
clean:
	rm -f $(TARGET1) $(TARGET2)