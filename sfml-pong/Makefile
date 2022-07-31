CC = g++
DEPS = headers/frame.cpp headers/paddle.cpp headers/ball.cpp
LDFLAGS =  -lsfml-graphics -lsfml-window -lsfml-system 
CFLAGS  = -g -Wall -pthread 

APPNAME = pong
TARGET = main
#all: $(APPNAME)

$(APPNAME): $(TARGET).cpp
	$(CC) $(CFLAGS) $(DEPS) $(TARGET).cpp -o $(APPNAME) $(LDFLAGS)

clean:
	$(RM) $(TARGET)