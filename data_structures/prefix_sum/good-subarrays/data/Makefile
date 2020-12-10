.PHONY: all clean input output

all: input output check

input:
	./make-input.sh

output: input
	./make-output.sh

check: input
	./run-validator.sh

zip: input output check
	zip data.zip *.in *.out

clean:
	-rm *.in *.out
