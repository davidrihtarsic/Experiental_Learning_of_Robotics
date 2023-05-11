pdfs:
	@for ff in $(file); do \
		num=$$(echo $$ff | sed 's/_.*$$//'); \
		section=$$(echo $$num | sed 's/\..*$$//g'); \
		subsect=$$(echo $$num | sed 's/.*\.//g'); \
		[[ $$subsect -gt 0 ]] && subsect=$$((subsect-1)) || section=$$((section-1)); \
		sed -i "1i \\\\\setcounter{section}{$$section}\\\\\setcounter{subsection}{$$subsect}" $$ff; \
		pandoc2notebook -f $$ff; \
		sed -i "1d" $$ff; \
		done;

TITLE="Experiential Learning of Robotics"
book:
	@echo "Compailing all chapters into book... $(TITLE)."
	@cat $$(ls --color=never -v [0-9]*.md) > ./pdf/Experiential_Learning_of_Robotics.md && echo ".. Done."
	@file_name=$$(echo $(TITLE) | sed 's/\ /_/g'); \
	pandoc ./pdf/Experiential_Learning_of_Robotics.md --to latex -o ./pdf/Experiential_Learning_of_Robotics.pdf \
		--from markdown \
		--template skripta \
		-V lang=sl \
		-M title=$(TITLE) \
		-M subtitle="This book is designed for beginners to introduce them to the field of robotics. The contents are based on the integration of electronics, computing, and mechanics." \
		-M author:"dr. David Rihtaršič" \
		-M date:"$(date '+%Y-%B')" \
		--listings \
		-M listings=True \
		-M listings-no-page-break=True \
		-M codeBlockCaptions=True \
		-M listingTitle=Program \
		-M figureTitle=Slika \
		-M figPrefix=sl. \
		-M eqnPrefix=en. \
		-M lstPrefix=prog. \
		-V table-use-row-colors \
		-V urlcolor=violet \
		-V caption-justification=centering \
		--number-sections \
		-F pandoc-crossref \
		--citeproc \
		--bibliography=/home/david/Files/Work/UL-PeF/Articles/00-BibTex/bibtex.bib \
		-V documentclass=book \
		-V book \
		--toc \
		--toc-depth=2
		-M titlepage;

clean:
	@mv *.pdf ./pdf/

file := $(shell find ./ -type f -name "[0-9]*.md"|sed 's/\.\///g')
all: pdfs book clean
