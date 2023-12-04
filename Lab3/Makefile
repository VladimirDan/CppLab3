CXX = g++
CXXFLAGS = -Wall -g
LIBS = -lsqlite3

SRCDIR = .
INCDIR = .
BUILDDIR = build
BINDIR = bin

TARGET = $(BINDIR)/my_program
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))
DEPS = $(OBJECTS:.o=.d)

LIBDIR = lib
LIBNAME = libemployee.a
STATICLIB = $(LIBDIR)/$(LIBNAME)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(STATICLIB) $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ $(LIBS) -L$(LIBDIR) -lemployee

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -MMD -MP -c $< -o $@

$(STATICLIB): $(BUILDDIR)/Employee.o
	@mkdir -p $(LIBDIR)
	ar rcs $@ $<

clean:
	rm -rf $(BUILDDIR) $(BINDIR) $(LIBDIR)

-include $(DEPS)