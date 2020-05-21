
# Makefile有三个非常有用的变量。分别是$@，$^，$<代表的意义分别是： 

# $@--目标文件，$^--所有的依赖文件，$<--第一个依赖文件。 
# $?--所有的依赖文件，以空格分开，这些依赖文件的修改日期比目标的创建日期晚。

# CXXFLAGS=g++  -std=c++11 -c     #-Wall -pedantic #CXXFLAGS 表示用于 C++ 编译器的选项
# LDFLAGS=-pthread                #有线程 必须加上

INCL=-I/home/w/Mycode/My_leetcode/incl
BIN =/home/w/Mycode/My_leetcode/bin
OBJ1=pivotsum.o
CC  =gcc

.SUFFIXES: .c
.c.o:
	$(CC) ${INCL} -c $<

all: 5_18_pivotsum
#C编译
pivotsum:$(OBJ1)
	echo ""
	echo "======开始编译======"
	$(CC) -o  $@ $?
	mv   $@  ${BIN}
	rm   -f  ${OBJ1}
	echo "======编译结束======"
	echo ""
clean:
	rm -f *.o
  
