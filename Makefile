CASE=a1-cli.txt
RANDOM:=$(shell date +%s)

all: bitset-tests.zip lab8
	@echo "Done"

lab8: lab8.cpp
	@g++ -o lab8 lab8.cpp -g -Wall -std=c++11

tests: bitset-tests.zip lab8
	@bash scripts/test.bash lab8.cpp

test: bitset-tests.zip lab8
	@./lab8 < tests/in/$(CASE)

clean:
	rm -rf scripts tests bitset-tests.zip bitset

Makefile: FORCE
	@echo "Checking for updates to Makefile..."
	@curl --silent https://raw.githubusercontent.com/Ethan0429/COSC102-Lab-Writeups/main/labs/lab8/Makefile?$(RANDOM) -o Makefile.tmp
	@cmp -s Makefile.tmp Makefile && rm Makefile.tmp || (mv -f Makefile.tmp Makefile && echo "Updated Makefile - Restarting Makefile...")

bitset-tests.zip: FORCE
	@echo "Checking for updates to bitset-tests.zip..."
	@curl --silent -L https://github.com/Ethan0429/COSC102-Lab-Writeups/raw/main/labs/lab8/bitset-tests.zip?$(RANDOM) -o bitset-tests.zip.tmp
	@cmp -s bitset-tests.zip.tmp bitset-tests.zip && rm bitset-tests.zip.tmp || (mv -f bitset-tests.zip.tmp bitset-tests.zip && echo "Updated bitset-tests.zip")
	@rm -rf tests
	@unzip -o -q bitset-tests.zip

FORCE:
