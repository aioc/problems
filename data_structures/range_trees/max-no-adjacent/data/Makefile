.PHONY: all clean input output

all: input output check zip

input:
	cp handmade/* .
	./gen.py 100000 100000 random 7428 > r1.in
	./gen.py 100000 100000 random 7429 > r2.in
	./gen.py 100000 100000 random 7430 > r3.in
	./gen.py 100000 100000 random 7431 > r4.in
	./gen.py 100000 100000 sequential 7432 > s1.in
	./gen.py 100000 100000 sequential 7433 > s2.in
	./gen.py 100 100000 random 7434 > g1.in
	./gen.py 1000 100000 random 7435 > g2.in
	./gen.py 10000 100000 random 7436 > g3.in

output: input
	./make-output.sh

check: input
	./run-validator.sh

zip: input output check
	zip data.zip *.in *.out

clean:
	-rm *.in *.out
	-rm inputs
	-rm data.zip
	make -C ../validator clean
