# --- CONFIGURAÇÕES GERAIS ---
CXX = g++
CXXFLAGS = -fPIC -Wall

# --- ALVOS PRINCIPAIS ---

all: folders bin/lib/libmyvensim.so bin/run/funcional_tests bin/run/unit_tests

folders:
	mkdir -p bin/lib bin/run

# --- 1. CRIAÇÃO DA BIBLIOTECA DINÂMICA (SO/DLL) ---

bin/lib/libmyvensim.so: bin/FlowImpl.o bin/ModelImpl.o bin/SystemImpl.o
	$(CXX) -shared -o bin/lib/libmyvensim.so bin/FlowImpl.o bin/ModelImpl.o bin/SystemImpl.o

# --- 2. LINKAGEM DOS EXECUTÁVEIS ---

# 1. -Lbin/lib: Diz ao compilador para procurar a lib na pasta bin/lib (tempo de compilação)
# 2. -Wl,-rpath,bin/lib: Diz ao Linux para procurar a lib na pasta bin/lib (tempo de execução)
# 3. -o bin/run/...: Salva o executável na pasta bin/run

bin/run/funcional_tests: bin/func_main.o bin/funcional_tests.o bin/lib/libmyvensim.so
	$(CXX) bin/func_main.o bin/funcional_tests.o -Lbin/lib -lmyvensim -Wl,-rpath,bin/lib -o bin/run/funcional_tests

bin/run/unit_tests: bin/unit_main.o bin/unit_Flow.o bin/unit_Model.o bin/unit_System.o bin/lib/libmyvensim.so
	$(CXX) bin/unit_main.o bin/unit_Flow.o bin/unit_Model.o bin/unit_System.o -Lbin/lib -lmyvensim -Wl,-rpath,bin/lib -o bin/run/unit_tests

# --- 3. COMPILAÇÃO DOS OBJETOS DO SISTEMA (SRC) -> BIN ---

bin/FlowImpl.o: src/FlowImpl.cpp src/FlowImpl.h src/Flow.h
	$(CXX) $(CXXFLAGS) -c src/FlowImpl.cpp -o bin/FlowImpl.o

bin/ModelImpl.o: src/ModelImpl.cpp src/ModelImpl.h src/Model.h
	$(CXX) $(CXXFLAGS) -c src/ModelImpl.cpp -o bin/ModelImpl.o

bin/SystemImpl.o: src/SystemImpl.cpp src/SystemImpl.h src/System.h
	$(CXX) $(CXXFLAGS) -c src/SystemImpl.cpp -o bin/SystemImpl.o

# --- 4. COMPILAÇÃO DOS OBJETOS DE TESTE FUNCIONAL -> BIN ---

bin/func_main.o: test/funcional/main.cpp
	$(CXX) $(CXXFLAGS) -c test/funcional/main.cpp -o bin/func_main.o

bin/funcional_tests.o: test/funcional/funcional_tests.cpp test/funcional/funcional_tests.h
	$(CXX) $(CXXFLAGS) -c test/funcional/funcional_tests.cpp -o bin/funcional_tests.o

# --- 5. COMPILAÇÃO DOS OBJETOS DE TESTE UNITÁRIO -> BIN ---

bin/unit_main.o: test/unit/main.cpp
	$(CXX) $(CXXFLAGS) -c test/unit/main.cpp -o bin/unit_main.o

bin/unit_Flow.o: test/unit/unit_Flow.cpp src/Flow.h
	$(CXX) $(CXXFLAGS) -c test/unit/unit_Flow.cpp -o bin/unit_Flow.o

bin/unit_Model.o: test/unit/unit_Model.cpp src/Model.h
	$(CXX) $(CXXFLAGS) -c test/unit/unit_Model.cpp -o bin/unit_Model.o

bin/unit_System.o: test/unit/unit_System.cpp src/System.h
	$(CXX) $(CXXFLAGS) -c test/unit/unit_System.cpp -o bin/unit_System.o

# --- LIMPEZA E EXECUÇÃO ---

clean:
	rm -rf bin

run: all
	@echo "--- Rodando Testes Funcionais ---"
	./bin/run/funcional_tests
	@echo "--- Rodando Testes Unitários ---"
	./bin/run/unit_tests