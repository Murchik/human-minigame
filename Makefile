all:

configure:
	cmake -S . -B build

clean:
	rm -rf build
