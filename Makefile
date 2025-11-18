# Makefile simples para sua estrutura
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

SRCDIR = src
TESTDIR = test/funcional
BINDIR = bin

SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(BINDIR)/%.o,$(SRCS))

TEST_SRCS = $(wildcard $(TESTDIR)/*.cpp)
TEST_OBJS = $(patsubst $(TESTDIR)/%.cpp,$(BINDIR)/%.o,$(TEST_SRCS))

LIB = $(BINDIR)/libmylib.a
TEST_EXE = $(BINDIR)/funcional_tests

.PHONY: all test clean

all: $(LIB) $(TEST_EXE)

# cria biblioteca estática com os objetos de src
$(LIB): $(OBJS) | $(BINDIR)
	ar rcs $@ $^

# executável de testes: linka os objetos de src + os objetos dos testes
$(TEST_EXE): $(OBJS) $(TEST_OBJS) | $(BINDIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# regra genérica para compilar src/*.cpp -> bin/*.o
$(BINDIR)/%.o: $(SRCDIR)/%.cpp | $(BINDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# regra para compilar test/funcional/*.cpp -> bin/*.o
$(BINDIR)/%.o: $(TESTDIR)/%.cpp | $(BINDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# garante existência do diretório bin
$(BINDIR):
	mkdir -p $(BINDIR)

# target para rodar os testes (opcional)
test: $(TEST_EXE)
	@echo "Executando testes funcionais..."
	./$(TEST_EXE)

clean:
	rm -rf $(BINDIR)/*.o $(LIB) $(TEST_EXE)