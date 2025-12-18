all: build_lib build_funcional_test build_unit_test

# --- Build da Shared Library (.so) ---
build_lib:
	g++ -std=c++11 -Wall -fPIC -Isrc \
		./src/SystemImpl.cpp ./src/FlowImpl.cpp ./src/ModelImpl.cpp \
		-shared -o ./bin/libMyVensim.so

# --- Teste Funcional ---
build_funcional_test: build_lib
	g++ -std=c++11 -Wall -Isrc \
		./test/funcional/main.cpp ./test/funcional/funcional_tests.cpp \
		-L./bin -lMyVensim -o ./bin/funcional_test

run_funcional_test: build_funcional_test
	LD_LIBRARY_PATH=./bin ./bin/funcional_test

# --- Teste Unitário ---
build_unit_test: build_lib
	g++ -std=c++11 -Wall -Isrc \
		./test/unit/main.cpp \
		./test/unit/unit_Flow.cpp ./test/unit/unit_Model.cpp ./test/unit/unit_System.cpp \
		-L./bin -lMyVensim -o ./bin/unit_test

run_unit_test: build_unit_test
	LD_LIBRARY_PATH=./bin ./bin/unit_test

clean:
	rm -f ./bin/*