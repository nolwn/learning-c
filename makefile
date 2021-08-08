CALC_BIN = bin/calculator
LIB_BIN = bin/lib

CALC_SRC = src/calculator
LIB_SRC = src/lib

CALC_OBJS = $(CALC_BIN)/main.o
LIB_OBJS = $(LIB_BIN)/lib.o

BIN_DIRS = $(CALC_BIN) $(LIB_BIN)
MKDIR = mkdir -p

lib: $(LIB_OBJS) directories

calculator: directories lib $(CALC_OBJS) 
	$(CC) $(CFLAGS) $(LIB_OBJS) $(CALC_OBJS) -o $(CALC_BIN)/$@

directories: $(BIN_DIRS)

$(BIN_DIRS):
	$(MKDIR) $@

$(CALC_OBJS): $(CALC_BIN)/%.o: $(CALC_SRC)/%.c
	$(CC) -c $^ -o $@

$(LIB_OBJS): $(LIB_BIN)/%.o: $(LIB_SRC)/%.c
	$(CC) -c $^ -o $@

clean:
	rm -fr $(BIN_DIRS)
