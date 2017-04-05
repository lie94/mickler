all : mickler

mickler : main.cpp wordmickler.cpp micklerclassic.cpp
	g++ main.cpp -o mickler

testw : mickler
	./mickler -w < test.txt
