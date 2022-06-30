CPPC := clang
CPPFLAGS := -std=c11 -Wall -O3

SRCDIR := src
BINDIR := bin
BUILDDIR := build
TARGET := build/emulator

SRCEXT := c
HDREXT := h
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
HEADERS := $(shell find $(SRCDIR) -type f -name *.$(HDREXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BINDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
LIB := # nothing for now
INC := # nothing for now

$(TARGET): $(OBJECTS)
	@echo "Linking..."
	$(CPPC) $^ -o $(TARGET) $(LIB)

$(BINDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BINDIR)
	$(CPPC) $(CPPFLAGS) $(INC) -c -o $@ $<

clean:
	@echo "Cleaning..."
	rm -r $(BINDIR) $(TARGET)

run:
	$(TARGET)

# Tests
#tester:
#  $(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester

# Spikes
#ticket:
#  $(CC) $(CFLAGS) spikes/ticket.cpp $(INC) $(LIB) -o bin/ticket

.PHONY: clean
	

