# Compilador
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Diretórios
SRCDIR = src
FUNCTESTDIR = test/funcional
UNITTESTDIR = test/unit
BINDIR = bin
OBJDIR = $(BINDIR)/obj

# Fontes principais
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/src_%.o,$(SRCS))

# Testes funcionais
FUNC_TEST_SRCS = $(wildcard $(FUNCTESTDIR)/*.cpp)
FUNC_TEST_OBJS = $(patsubst $(FUNCTESTDIR)/%.cpp,$(OBJDIR)/func_%.o,$(FUNC_TEST_SRCS))
FUNC_TEST_EXE = $(BINDIR)/funcional_tests

# Testes unitários
UNIT_TEST_SRCS = $(wildcard $(UNITTESTDIR)/*.cpp)
UNIT_TEST_OBJS = $(patsubst $(UNITTESTDIR)/%.cpp,$(OBJDIR)/unit_%.o,$(UNIT_TEST_SRCS))
UNIT_TEST_EXE = $(BINDIR)/unit_tests

# Biblioteca
LIB = $(BINDIR)/libmylib.a

.PHONY: all test unit clean

all: $(LIB) $(FUNC_TEST_EXE) $(UNIT_TEST_EXE)

# cria biblioteca com os .o principais
$(LIB): $(OBJS) | $(BINDIR)
	ar rcs $@ $^

# executável de testes funcionais
$(FUNC_TEST_EXE): $(OBJS) $(FUNC_TEST_OBJS) | $(BINDIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# executável de testes unitários
$(UNIT_TEST_EXE): $(OBJS) $(UNIT_TEST_OBJS) | $(BINDIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# regra para src → bin/obj com prefixo src_
$(OBJDIR)/src_%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# regra para testes funcionais → bin/obj com prefixo func_
$(OBJDIR)/func_%.o: $(FUNCTESTDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# regra para testes unitários → bin/obj com prefixo unit_
$(OBJDIR)/unit_%.o: $(UNITTESTDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# cria diretórios
$(BINDIR):
	mkdir -p $(BINDIR)

$(OBJDIR): | $(BINDIR)
	mkdir -p $(OBJDIR)

# rodar testes funcionais
test: $(FUNC_TEST_EXE)
	@echo "Executando testes funcionais..."
	./$(FUNC_TEST_EXE)

# rodar testes unitários
unit: $(UNIT_TEST_EXE)
	@echo "Executando testes unitários..."
	./$(UNIT_TEST_EXE)

clean:
	rm -rf $(BINDIR)