#BULD COMMAND:
build:
	@g++ include/SDLX/*.cpp src/main.cpp -Iinclude -Isrc -Llib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -o main && echo Compiled Successfully

#RUN COMMAND:
run:
	@main

#BUILD AND RUN COMMAND:
build_run:
	@g++ include/SDLX/*.cpp src/main.cpp -Iinclude -Isrc -Llib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -o main && echo Compiled and Runned Successfully && main 
