CC=gcc
CXX=g++
CFLAGS=-g -Wall
#wildcard *.c 把当前目录下的.c 文件全部展开
SRCS=$(wildcard *.c)
OBJS=$(patsubst %c, %o,$(SRCS))
TARGETS=tcpclient
# $@ -->目标文件的完整名称
# $^ -->所有不重复的依赖文件
# $< -->第一个依赖文件
$(TARGETS):$(OBJS)
	$(CC) -o $@ $^ -lpthread
%.o:%.c
	$(CC) $(CFLAGS) -c $<
#伪目标
clean:
#	echo "$(SRCS)"
#	echo "$(OBJS)"
	@rm *.o $(TARGETS)
	