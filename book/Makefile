book:
	@echo -n "Jojning files .."
	@cat [0-9]*.md > ./pdf/Experiential_Learning_of_Robotics.md && echo ".. Done."
	@echo -n "Experiential_Learning_of_Robotics.md -> PDF .."
	@pandoc  ./pdf/Experiential_Learning_of_Robotics.md \
		-o ./pdf/Experiential_Learning_of_Robotics.pdf \
		--to latex \
    --from markdown \
    --template skripta\
    -V lang=sl \
    -M title="EXPERIENTIAL LEARNING OF ROBOTICS" \
    -M subtitle="GUIDANCE AND RECOMMENDATIONS" \
    -M author:"dr. David Rihtaršič" \
    -M date:"$(date '+%Y-%B')" \
    --listings \
    -M listings=True \
    -M listings-no-page-break=True \
    -M codeBlockCaptions=True \
    -M listingTitle=Program \
    -M lstPrefix=prog. \
    -V table-use-row-colors \
    -V urlcolor=violet \
    -V caption-justification=centering \
    --number-sections \
    --bibliography="/home/david/Files/Work/UL-PeF/Articles/00-BibTex/bibtex.bib" \
    -F pandoc-crossref \
    --citeproc \
    -V documentclass=book \
    -V book \
    --toc \
    --toc-depth=2 \
    -M titlepage \
		&& echo -e ".. Done."

chapters:
	pandoc2notebook -f "[0-9]*.md"
	mv *.pdf ./pdf/
