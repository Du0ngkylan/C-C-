CXX=g++
CPPFLAGS=-I . -g
LDFLAGS=-lm
OBJS=main.o a.o b.o

default:main
main.o:main.cpp a.h b.h
	$(CXX) -c -o $@ $< $(CPPFLAGS)

a.o:a.cpp a.h
	$(CXX) -c -o $@ $< $(CPPFLAGS)

b.o:b.cpp b.h
	$(CXX) -c -o $@ $< $(CPPFLAGS)

main:$(OBJS)
	$(CXX) -o $@ $^ $(CPPFLAGS) $(LDFLAGS)

.PHONY:clean
clean:
	rm -f *.o *~ main
