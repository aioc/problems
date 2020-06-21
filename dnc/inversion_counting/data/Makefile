.PHONY: all clean input output

all: input output zip

input:
	g++ -std=c++14 gen/main.cpp -Igen -o inputs
	./inputs
	cp handmade/* .

output: input
	./make-output.sh

zip: input output
	zip data.zip *.in *.out

clean:
	-rm *.in *.out
	-rm inputs
	-rm data.zip
