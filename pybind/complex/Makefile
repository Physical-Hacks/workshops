examplebind: example_bind.cc
	g++ -O3 -Wall -shared -std=c++11 -fPIC `python -m pybind11 --includes` $< example.cc -o examplebind.so

clean:
	rm -f examplebind.so *.o
