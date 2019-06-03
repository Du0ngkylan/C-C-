CXX=g++
AR=ar
ARFLAGS=cr
CPPFLAGS=-I . -g
LDFLAGS=-lm -L. -lmylib -static
OBJS=main.o

default:main
main.o:main.cpp a.h b.h
	$(CXX) -c -o $@ $< $(CPPFLAGS)

a.o:a.cpp a.h
	$(CXX) -c -o $@ $< $(CPPFLAGS)

b.o:b.cpp b.h
	$(CXX) -c -o $@ $< $(CPPFLAGS)

libmylib.a:a.o b.o
	$(AR) $(ARFLAGS) $@ $^

main:$(OBJS) libmylib.a
	$(CXX) -o $@ $< $(CPPFLAGS) $(LDFLAGS)

.PHONY:clean
clean:
	rm -f *.o *~ main *.a
