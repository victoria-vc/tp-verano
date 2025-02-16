BIN_DIR = BIN_DIR
SRC = main.cpp archivo.cpp
OUT = $(BIN_DIR)/main

$(OUT): $(SRC)
 -mkdir -p $(BIN_DIR)
 g++ $(SRC) -o $(OUT)

clean:
 rm -rf $(BIN_DIR)