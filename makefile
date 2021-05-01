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
	@echo '/****************************************************************/'
	@echo '/*****    C Project ALEXIS BOUDIN and ALEXANDRE DAUMARD     *****/'
	@echo '/****************************************************************/'
	@echo ''
	@echo '	make install : install the dependencies and build'
	@echo '	make build : build the game'
	@echo '	make clean : uninstall the game'
	@echo ''
	@echo '/****************************************************************/'


$(OBJdir)/%.o : $(_SRCdir)/%.c $(INC)
	$(CC) -c -o $@ $< $(FLAGS)

build: $(OBJ) 
	$(CC) -o $@ $^ $(FLAGS) $(libs)

install:
	sudo apt install libsdl2-2.0-0 libsdl2-dev libsdl2-gfx-dev libsdl2-image-dev libsdl2-image-2.0-0 libsdl2-ttf-dev -y


clean:
	rm -f $(OBJdir)/*.o build 