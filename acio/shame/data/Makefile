.PHONY: all input output check clean

all: input output check data.zip

tkgen2: tkgen2.cpp
	g++ -std=c++11 -O2 tkgen2.cpp -o tkgen2

checker-st4: checker-st4.cpp
	g++ -std=c++11 -O2 checker-st4.cpp -o checker-st4

input: tkgen2
	python3 generator.py
	cp handmade/* .

output: input
	./make-output.sh

# TODO we only check subtask 4 (i.e. all boxes are unique)
check: input checker-st4
	./check.sh

data.zip: input output check
	zip data.zip *.in *.out

clean:
	rm -f *.in *.out tkgen2 checker-st4 data.zip
