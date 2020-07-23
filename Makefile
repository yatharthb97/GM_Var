################################################################################
#
#  File :          Makefile (GNU LINUX makefile for GM_Var)                    #
#  Author :        Biplab Ghosh                                                #
#  Creation date : May 19, 2006                                                #
#
################################################################################
#!/bin/sh

#local source dir:
SRCDIR= .

#Directory path of source:
BASEDIR= .

#C++ compilers and flags:
CPP = g++
OPTIONS = -o
CPPFLAGS = -c -O3 -std=c++11

#executable target:
NAME=gerry

#Destination of the final binary file:
DEST=$(BASEDIR)/$(NAME)

#SHELL commands:
RM= /bin/rm -f
MV= /bin/mv -f

#Source files:
CPPFILES = $(SRCDIR)/main.cpp \


#Object files:
OFILES = $(CPPFILES:.cpp=.o) 
	  
.cpp.o :
	$(CPP) $(CPPFLAGS) $<
	
$(NAME): $(OFILES)
	$(CPP) $(OFILES) $(OPTIONS) $(DEST)
	
#Prompt : Compilation Done
	@tput enacs; tput smacs; tput bold; echo "lqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk"; echo -n "x"; tput rmacs; \
        echo -n "    Compilation Successful    ";    \
        tput smacs; echo "x"; echo "mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj";tput rmacs;tput sgr0


# enacs = Enable alternate character set
# smacs = Begin alternate character set
# rmacs = End alternate character set
# bold  = Begin double intensity mode
# sgr0  = Turn off all attributes
	

clean:
	$(RM) $(OFILES)  *.gch 

allclean:
	$(RM) $(OFILES) $(DEST)
