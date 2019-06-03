CXX=g++
CPPFLAGS=-I . -g
LDFLAGS=-lm -L. -lmylib
OBJS=main.o

default:main
main.o:main.cpp a.h b.h
	$(CXX) -c -o $@ $< $(CPPFLAGS)

a.o:a.cpp a.h
	$(CXX) -c -fPIC -o $@ $< $(CPPFLAGS)

b.o:b.cpp b.h
	$(CXX) -c -fPIC -o $@ $< $(CPPFLAGS)

libmylib.so:a.o b.o
	$(CXX) -shared -fPIC -o $@ $^

main:$(OBJS) libmylib.so
	$(CXX) -o $@ $< $(CPPFLAGS) $(LDFLAGS)

.PHONY:clean
clean:
	rm -f *.o *~ main *.so
