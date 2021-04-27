_SRCdir = ./src
Idir = $(_SRCdir)/include

CC=gcc
FLAGS= -I$(Idir) 

libs= -lSDL2 -lSDL2_image -lSDL2_ttf

_INC = $(patsubst $(Idir)/%, %,$(wildcard $(Idir)/*.h))
INC = $(patsubst %,$(Idir)/%,$(_INC))

OBJdir = $(_SRCdir)/obj
SRC = $(wildcard $(_SRCdir)/*.c)
_OBJ = $(patsubst $(_SRCdir)/%.c, %.o,$(SRC))

OBJ = $(patsubst %,$(OBJdir)/%,$(_OBJ))

LIBdir = $(_SRCdir)/libs

all:
	@echo 'Use make build to build the game and make clean to uninstall it'

$(OBJdir)/%.o : $(_SRCdir)/%.c $(INC)
	$(CC) -c -o $@ $< $(FLAGS)

build: $(OBJ)
	$(CC) -o $@ $^ $(FLAGS) $(libs)

clean:
	rm -f $(OBJdir)/*.o build 