##
## Makefile for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice
## 
## Made by vincent.mesquita
## Login   <vincy@epitech.net>
## 
## Started on  Mon Jan 30 19:07:34 2017 vincent.mesquita
## Last update Mon Apr 17 17:34:46 2017 vincent.mesquita@epitech.eu
##

NAME 		=	nanotekspice

GCC		=	g++

RM		=	rm -rf

LIB		=	./lib

LIB_INCLUDE	=	$(LIB)/includes

CPPFLAGS	+=	-std=c++14 -W -Wall -Werror -Wextra -I$(LIB_INCLUDE) -g3

LDFLAGS		=	-L./ -lnanotekspice

SRCS		=	main.cpp

OBJS		=	$(SRCS:.cpp=.o)

GCC		=	g++

OBJS		=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIB);
	$(GCC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	make clean -C $(LIB);
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIB);
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
