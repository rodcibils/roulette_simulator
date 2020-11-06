INCDIR = -Iinclude
CPP = g++
CPPFLAGS = -g -std=gnu++0x 

SRC = $(wildcard src/*.cpp)
TMP := $(SRC:.cpp=.o)
OBJS := $(subst src,obj,$(TMP))
$(info $(OBJS))

OBJDIR=obj
SDIR=src
BINDIR=bin

TARGET=$(BINDIR)/roulette_simulator

$(TARGET):$(OBJS)
	$(CPP) $(INCDIR) $^ -o $@

$(OBJDIR)/%.o: $(SDIR)/%.cpp
	$(CPP) $(CWARNS) $(CPPFLAGS) $(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJDIR)/*.o 
	rm -f $(TARGET)
