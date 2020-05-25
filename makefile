
# Makefile有三个非常有用的变量。分别是$@，$^，$<代表的意义分别是： 

# $@--目标文件，$^--所有的依赖文件，$<--第一个依赖文件。 
# $?--所有的依赖文件，以空格分开，这些依赖文件的修改日期比目标的创建日期晚。

# CXXFLAGS=g++  -std=c++11 -c     #-Wall -pedantic #CXXFLAGS 表示用于 C++ 编译器的选项
# LDFLAGS=-pthread                #有线程 必须加上
CC  =gcc

INCL=-I/home/w/Mycode/My_leetcode/incl
BIN =/home/w/Mycode/My_leetcode/bin
LIB =-L/usr/local/lib -lcs50

file0=000_begain
OBJ0=$(file0).o

file3=5_23_dominantIndex
OBJ3=$(file3).o

OBJ1=pivotsum.o
OBJ2=megersort.o


.SUFFIXES: .c 
.c.o:
	$(CC) -c   $<   
#-------------------------
.PHONY : all
all: clean  $(file0) $(file3) 5_21_recursion 
#C编译
$(file3):$(OBJ3)  
	$(CC) -o  $@  $? $(LIB) 
$(file0):$(OBJ0)  
	$(CC) -o  $@  $? $(LIB) 
pivotsum:$(OBJ1)
	echo ""
	echo "======开始编译======"
	$(CC) -o  $@ $?
	mv   $@  ${BIN}
	rm   -f  ${OBJ1}
	echo "======编译结束======"
	echo ""
megersort:$(OBJ2)
	$(CC) -o  $@ $?

.PHONY: clean
clean:
	rm -f *.o $(file0)
  

