.PHONY: all clean input output

all: input output check zip

input:
	python3 generator.py
	cp handmade/* .

# ulimit to prevent stack overflow
output: input
	sh ./make-output.sh

check: input

zip: input output check
	zip data.zip *.in *.out

clean:
	-rm *.in *.out
	-rm data.zip

