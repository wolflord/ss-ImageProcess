
CC=gcc
PROG_NAME=main
INCS=project.h defines.h interface.h

SRCS=main.c file_op.c drawui.c callback.c

# 从xx.c 文件得到 xx.o 文件
OBJS=${SRCS:.c=.o}

#编译GTK程序时要用到的库
LIBS=gtk+-2.0
#---- 用户修改区域 结束

# -O2
CFLAGS=`pkg-config --cflags ${LIBS}` -O0 -DDEBUG -Wall -g
LDFLAGS=`pkg-config --libs ${LIBS}` -Wall -g

all: ${PROG_NAME}

${PROG_NAME}:${OBJS}
	${CC} -o ${PROG_NAME} ${OBJS} ${LDFLAGS}
#注意：上边”${CC}" 的前边有一个TAB键，而不是空格

#如果有头文件进行修改，则自动编译源文件
${OBJS}:${INCS}

.c.o:
	${CC} -c $<  ${CFLAGS}

.PHONY:clean
clean:
	rm -f ${PROG_NAME} ${OBJS} .CONFIG

rebuild: clean all
