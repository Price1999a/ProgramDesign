target = mySQL
source = $(wildcard *.cpp)
OBJS = $(source:%.cpp=%.o)

$(target) : $(OBJS)
	g++ -g -o $(target) $(OBJS)
%.o:%.cpp
	g++ -c -o $@ $<

clean:
	rm *.o
