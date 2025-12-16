all:
	g++ main.cpp -o FightGame.exe -I. -L. -lraylib -lopengl32 -lgdi32 -lwinmm

run:
	g++ main.cpp -o FightGame.exe -I. -L. -lraylib -lopengl32 -lgdi32 -lwinmm
	.\FightGame.exe

clean:
	del /Q FightGame.exe 2>nul

.PHONY: all run clean