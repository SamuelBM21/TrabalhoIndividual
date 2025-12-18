all: build_lib build_funcional_test build_unit_test

# --- Build da Shared Library (.so) ---
# Compila todos os arquivos .cpp que estiverem dentro da pasta src/
build_lib:
	g++ -std=c++11 -Wall -fPIC -Isrc -Isrc/include \
		src/lib/*.cpp \
		-shared -o ./bin/libMyVensim.so

# --- Teste Funcional ---
# Compila todos os .cpp dentro de test/funcional/ 
build_funcional_test: build_lib
	g++ -std=c++11 -Wall -Isrc -Isrc/include \
		test/funcional/*.cpp \
		-L./bin -lMyVensim -o ./bin/funcional_test

run_funcional_test: build_funcional_test
	LD_LIBRARY_PATH=./bin ./bin/funcional_test

# --- Teste Unitário ---
# Compila todos os .cpp dentro de test/unit/
build_unit_test: build_lib
	g++ -std=c++11 -Wall -Isrc -Isrc/include \
		test/unit/*.cpp \
		-L./bin -lMyVensim -o ./bin/unit_test

run_unit_test: build_unit_test
	LD_LIBRARY_PATH=./bin ./bin/unit_test

clean:
	rm -f ./bin/*