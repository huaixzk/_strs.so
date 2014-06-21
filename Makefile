FLAGS += -g
all: libstrs.so test
libstrs.so: _strs.c 
	gcc -fPIC -shared $< -o $@
test: test.c _strs.h
	gcc $(FLAGS) $< -L. -lstrs -o $@
clean:
	rm -rf libstrs.so test
