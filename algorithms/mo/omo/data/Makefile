.PHONY: all clean input output

all: input output check zip

input:
	python3 gen_random.py 100000 100000 1 23498 > 2_c01.in
	python3 gen_random.py 100000 100000 2 23499 > 2_c02.in
	python3 gen_random.py 100000 100000 5 23500 > 2_c03.in
	python3 gen_random.py 100000 100000 123454321 23501 > 2_c04.in
	python3 gen_incr.py 100000 100000 23502 > 2_c05.in
	python3 gen_blocks.py 100000 100000 2 2 23503 > 2_c06.in
	python3 gen_blocks.py 100000 100000 2 3 23504 > 2_c07.in
	python3 gen_blocks.py 100000 100000 2 4 23505 > 2_c08.in
	python3 gen_blocks.py 100000 100000 1 60 23506 > 2_c09.in
	python3 gen_blocks.py 99678 99987 60 200 23507 > 2_c10.in
	python3 gen_blocks.py 100000 100000 200 300 23508 > 2_c11.in
	python3 gen_blocks.py 100000 100000 300 2000 23509 > 2_c12.in
	python3 gen_blocks.py 100000 100000 2000 10000 23510 > 2_c13.in
	python3 gen_blocks.py 100000 100000 10000 50000 23511 > 2_c14.in
	cp handmade/* .

output: input
	./make-output.sh

check: input

zip: input output check
	zip data.zip *.in *.out

clean:
	-rm *.in *.out
	-rm data.zip
