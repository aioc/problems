.PHONY: all clean input output

all: input output check

input:
	./make-input.sh

output: input
	./make-output.sh

check: input
	./check.sh

clean:
	-rm *.in *.out
