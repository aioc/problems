.PHONY: all input output clean

all: input output data.zip

tkgen: tkgen.cpp
	g++ -std=c++11 -O2 tkgen.cpp -o tkgen

input: tkgen
	python3 generator.py
	cp handmade/* .

output: input
	./make-output.sh

data.zip: input output
	zip data.zip *.in *.out

clean:
	rm -f *.in *.out tkgen data.zip
