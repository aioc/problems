.PHONY: all clean input output

all: input output check zip

input:
	python3 gen_random.py 1000 1000 1 6980 > st1_01.in
	python3 gen_random.py 1000 1000 2 6981 > st1_02.in
	python3 gen_incr.py 1000 1000 6982 > st1_03.in
	python3 gen_blocks.py 1000 1000 1 100 6983 > st1_04.in
	python3 gen_random.py 1000 1000 123454321 6984 > st1_05.in
	python3 gen_blocks.py 25000 25000 2 2 8989 > st2_01.in
	python3 gen_blocks.py 25000 25000 1 10 8990 > st2_02.in
	python3 gen_blocks.py 25000 25000 11 20 8991 > st2_03.in
	python3 gen_blocks.py 25000 25000 20 100 8992 > st2_04.in
	python3 gen_blocks.py 25000 25000 100 2000 8993 > st2_05.in
	python3 gen_random.py 100000 100000 5 23500 > st3_01.in
	python3 gen_random.py 100000 100000 123454321 23501 > st3_02.in
	python3 gen_blocks.py 100000 100000 2 2 23503 > st3_03.in
	python3 gen_blocks.py 100000 100000 2 4 23505 > st3_04.in
	python3 gen_blocks.py 100000 100000 1 60 23506 > st3_05.in
	python3 gen_blocks.py 99678 99987 60 200 23507 > st3_06.in
	python3 gen_blocks.py 100000 100000 200 300 23508 > st3_07.in
	python3 gen_blocks.py 100000 100000 300 2000 23509 > st3_08.in
	python3 gen_blocks.py 100000 100000 2000 10000 23510 > st3_09.in
	python3 gen_blocks.py 100000 100000 10000 50000 23511 > st3_10.in
	cp handmade/* .

output: input
	./make-output.sh

check: input

zip: input output check
	zip data.zip *.in *.out

clean:
	-rm *.in *.out
	-rm data.zip
