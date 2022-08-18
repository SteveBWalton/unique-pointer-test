#
# Makefile for the unique_pointer_test program.
# 

#
# The processor that this computer is using
#
PROCESSOR = $(shell uname -m)

#
# Libraries 
# 	prefix LIBS with -l
# 	prefix LIBDIR with -L
#
LIBS :=  
LIBDIR := 

OPTIONS := -Wall -std=c++17

#
# Source objects (prefix with obj/)
#
OBJS := \
obj/unique_pointer_test.o \
obj/simple_class.o 

bin/unique_pointer_test : $(OBJS)
	@mkdir -p $(@D)
	g++ $(OPTIONS) -o bin/unique_pointer_test $(OBJS) $(LIBDIR) $(LIBS)

obj/unique_pointer_test.o : unique_pointer_test.cpp
	@mkdir -p $(@D)
	g++ -c $(OPTIONS) -o obj/unique_pointer_test.o unique_pointer_test.cpp

obj/simple_class.o : simple_class.cpp simple_class.h
	@mkdir -p $(@D)
	g++ -c $(OPTIONS) -o obj/simple_class.o simple_class.cpp

clean:
	-rm -f bin/unique_pointer_test
	-rm -f $(OBJS)

# Add a link from /usr/local/bin/keysync to this file
# eg. ln -s /home/steve/Documents/bin/keysync.exe /usr/local/bin/keysync
install:
	-cp bin/unique_pointer_test ~/Public/bin/unique_pointer_test 2>/dev/null

