
# Makefile有三个非常有用的变量。分别是$@，$^，$<代表的意义分别是： 

# $@--目标文件，$^--所有的依赖文件，$<--第一个依赖文件。 
# $?--所有的依赖文件，以空格分开，这些依赖文件的修改日期比目标的创建日期晚。

# CXXFLAGS=g++  -std=c++11 -c     #-Wall -pedantic #CXXFLAGS 表示用于 C++ 编译器的选项
# LDFLAGS=-pthread                #有线程 必须加上
CC  =gcc

INCL=-I/home/w/Mycode/My_leetcode/incl
BIN =/home/w/Mycode/My_leetcode/bin
LIB =-L/usr/local/lib -lcs50

file7=longestCommonPrefix
OBJ7=$(file7).o

file6=strStr_5_26
OBJ6=$(file6).o

file0=findDiagonalOrder
OBJ0=$(file0).o

file3=reverseString
OBJ3=$(file3).o

file4=plusone_5_23
OBJ4=$(file4).o

file5=addBinary_5_26
OBJ5=$(file5).o

OBJ1=pivotsum.o
OBJ2=megersort.o


.SUFFIXES: .c 
.c.o:
	$(CC) -c   $<   
#-------------------------
.PHONY : all
all:  $(file0) $(file3) $(file4)  $(file5) $(file6) $(file7) clean 5_21_recursion 
#C编译
$(file7):$(OBJ7)  
	$(CC) -o  $@  $? $(LIB) 
$(file6):$(OBJ6)  
	$(CC) -o  $@  $? $(LIB) 
$(file5):$(OBJ5)  
	$(CC) -o  $@  $? $(LIB) 
$(file4):$(OBJ4)  
	$(CC) -o  $@  $? $(LIB) 
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
	rm -f *.o 
