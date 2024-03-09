CC = g++
CFLAGS = -Wall -I include -I sdl/include
LDFLAGS = -L sdl/lib -lmingw32 -lSDL2main -lSDL2

SRCDIR = src
OBJDIR = obj

SRCS = $(wildcard $(SRCDIR)/*.cpp) 
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

main: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJDIR)/*.o main.exe