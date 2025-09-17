pdfs:
	@for ff in $(file); do \
		num=$$(echo $$ff | sed 's/_.*$$//'); \
		section=$$(echo $$num | sed 's/\..*$$//g'); \
		subsect=$$(echo $$num | sed 's/.*\.//g'); \
		[[ $$subsect -gt 0 ]] && subsect=$$((subsect-1)) || section=$$((section-1)); \
		sed -i '1i\\' $$ff; \
		sed -i "1i \\\\\setcounter{section}{$$section}\\\\\setcounter{subsection}{$$subsect}" $$ff; \
		pandoc2notebook -f $$ff; \
		sed -i "1,2d" $$ff; \
		done;

TITLE="Experiential Learning of Robotics"
book:
	@echo "Compailing all chapters into book... $(TITLE)."
	@cat $$(ls --color=never -v [0-9]*.md) > ./pdf/Experiential_Learning_of_Robotics.md && echo ".. Done."
	@file_name=$$(echo $(TITLE) | sed 's/\ /_/g'); \
	pandoc ./pdf/Experiential_Learning_of_Robotics.md --to latex -o ./pdf/Experiential_Learning_of_Robotics.pdf \
		--from markdown \
		--template skripta.tex \
		-V lang=en \
		-M title=$(TITLE) \
		-M subtitle="This book is designed for beginners to introduce them to the field of robotics. The content is based on the integration of electronics, computing, and mechanics." \
		-M author:"dr. David Rihtaršič" \
		-M date:"$(date '+%Y-%B')" \
		--listings \
		-M listings=True \
		-M listings-no-page-break=True \
		-M codeBlockCaptions=True \
		-M listingTitle="Programing Exapmle" \
		-M figureTitle=Figure \
		-M figPrefix=fig. \
		-M eqnPrefix=eq. \
		-M lstPrefix="prog. example" \
		-M lol=True \
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
		--toc-depth=2 \
		-M titlepage;
	@rm -f ./pdf

clean:
	@mv -f *.pdf ./pdf/

file := $(shell find ./ -maxdepth 1 -type f -name "[0-9]*.md"|sed 's/\.\///g'|sort --numeric-sort)
all: pdfs book clean


CHAPTER_DIR := chapters
CHAPTER_PREFIXES := $(shell ls *.md | cut -d'_' -f1 | cut -d'.' -f1 | sort -nu)
.PHONY: chapters
chapters:
	mkdir -p $(CHAPTER_DIR)
	@for prefix in $(CHAPTER_PREFIXES); do \
		files=$$(ls $$prefix.*.md 2>/dev/null | sort); \
		if [ -n "$$files" ]; then \
			outfile=$$(echo $$files | grep -oE "$$prefix\.0_[^ ]+"); \
			if [ -z "$$outfile" ]; then \
				outfile=$$prefix.0_CHAPTER.md; \
			fi; \
			dest=$(CHAPTER_DIR)/$$outfile; \
			echo "---" > $$dest; \
			echo "published: false" >> $$dest; \
			echo "---" >> $$dest; \
			for file in $$files; do \
				awk 'BEGIN {skip=0} \
					/^---$$/ {n++; if(n==1) {skip=1; next} else if(n==2) {skip=0; next}} \
					!skip {print}' $$file >> $$dest; \
				echo "" >> $$dest; \
			done; \
			echo "Created chapter: $$dest"; \
		fi \
	done

