INFO = -Minfo=all
LIBS = -cudalib=cublas -lboost_program_options
GPU = -acc=gpu
CXX = pgc++
all:blas

blas:
	$(CXX) $(GPU) $(LIBS) $(INFO) -o $@ task7.cpp 

clean:all
	rm blas