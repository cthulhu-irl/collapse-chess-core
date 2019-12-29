# Project Name: Collapse Chess Core (Chess Engine)
# Author(s): xh4x0r3r
# Target Platform(s): GNU/Linux (development on Ubunutu 18.04 x86_64)
# Programming Language(s): C++

CXX := g++
SRCDIR := src
BUILDDIR := build
TARGET := libcollapse-core.so

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst \
                $(SRCDIR)/%.$(SRCEXT),$(BUILDDIR)/%.o,$(SOURCES))
CXXFLAGS := -std=c++11 -Wall -O3 -fstack-protector -fPIE -pie
LIB := -lm
INC := -Iinclude/

$(TARGET): $(OBJECTS)
	@echo -n " [$(TARGET)] : "
	$(CXX) $(CXXFLAGS) -shared -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo -n " [$@] : "
	$(CXX) $(CXXFLAGS) $(INC) -c -o $@ $<
	@echo

.PHONY: build
build: $(TARGET)

.PHONY: clean
clean:
	rm -r $(BUILDDIR)
	rm -r $(TARGET)