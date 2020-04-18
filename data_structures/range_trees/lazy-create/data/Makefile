.PHONY: all clean input output

all: input output check zip

input:
	python3 gen.py 1000000000 100000 AT 3247 > r01.in
	python3 gen.py 1000000000 100000 AT 3248 > r02.in
	python3 gen.py 1000000000 100000 SM 3249 > r03.in
	python3 gen.py 1000000000 100000 SM 3250 > r04.in
	python3 gen.py 1000000000 100000 ASTM 3251 > r05.in
	python3 gen.py 900000000 100000 ASTM 3252 > r06.in
	python3 gen.py 999999999 99999 ASTM 3253 > r07.in
	python3 gen.py 1000000000 100000 ASTM 3254 > r08.in
	python3 gen.py 1000000000 100000 ASTM 3255 > r09.in
	python3 gen.py 1000000000 100000 ASTM 3256 > r10.in
	python3 gen.py 1000000000 100000 ASTM 3257 > r11.in
	python3 gen.py 1000000000 100000 ASTM 3258 > r12.in
	cp handmade/* .

output: input
	./make-output.sh

check: input

zip: input output check
	zip data.zip *.in *.out

clean:
	-rm *.in *.out
	-rm data.zip
