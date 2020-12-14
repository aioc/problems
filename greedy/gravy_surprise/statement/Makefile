all: statement.pdf

statement.pdf: statement.md
	pandoc -o statement.pdf --from markdown+raw_tex --latex-engine-opt=--shell-escape < statement.md ||\
	pandoc -o statement.pdf --from markdown+raw_tex --pdf-engine-opt=--shell-escape < statement.md
