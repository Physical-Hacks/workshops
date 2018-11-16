# g++ -O3 -Wall -shared -std=c++11 -fPIC `python -m pybind11 --includes` vector2.cc -o testVector2.so

vector2: vector2.cc
	g++ -O3 -Wall -shared -std=c++11 -fPIC `python -m pybind11 --includes` $< -o testVector2.so

clean:
	rm -f *.so *.o
