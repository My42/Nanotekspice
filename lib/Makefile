##
## Makefile for  in /home/vincy/rendu/Tek2/S3/NanoTekSpice/cpp_nanotekspice/lib
##
## Made by vincent.mesquita
## Login   <vincy@epitech.net>
##
## Started on  Fri Jan 27 16:58:57 2017 vincent.mesquita
## Last update Mon Apr 17 17:35:10 2017 vincent.mesquita@epitech.eu
##

AR_RC		=	ar rc

RANLIB		=	ranlib

INCLUDES_DIR	=	includes

SRC_DIR		=	src

EXCEPTION_DIR	=	exceptions

COMPONENTS_DIR	=	components

NAME 		=	../libnanotekspice.a

GCC		=	g++

RM		=	rm -rf

CPPFLAGS	+=	-std=c++14 -W -Wall -Werror -Wextra -I./$(INCLUDES_DIR) -g3

SRCS		=	$(SRC_DIR)/$(COMPONENTS_DIR)/pin/APin.cpp\
			$(SRC_DIR)/nanotekspice.cpp\
			$(SRC_DIR)/LogicalOperators.cpp\
			$(SRC_DIR)/parser.cpp\
			$(SRC_DIR)/$(COMPONENTS_DIR)/ComponentManager.cpp\
			$(SRC_DIR)/$(COMPONENTS_DIR)/pin/Input.cpp\
			$(SRC_DIR)/$(COMPONENTS_DIR)/pin/Clock.cpp\
			$(SRC_DIR)/$(COMPONENTS_DIR)/pin/True.cpp\
			$(SRC_DIR)/$(COMPONENTS_DIR)/pin/False.cpp\
			$(SRC_DIR)/$(COMPONENTS_DIR)/pin/Output.cpp\
			$(SRC_DIR)/$(COMPONENTS_DIR)/AComponent.cpp\
			$(SRC_DIR)/$(COMPONENTS_DIR)/ACLO/ACLO.cpp\
			$(SRC_DIR)/$(COMPONENTS_DIR)/ACLO/C4001.cpp\
			$(SRC_DIR)/$(COMPONENTS_DIR)/ACLO/C4011.cpp\
			$(SRC_DIR)/$(COMPONENTS_DIR)/ACLO/C4030.cpp\
			$(SRC_DIR)/$(COMPONENTS_DIR)/ACLO/C4069.cpp\
			$(SRC_DIR)/$(COMPONENTS_DIR)/ACLO/C4071.cpp\
			$(SRC_DIR)/$(COMPONENTS_DIR)/ACLO/C4081.cpp\
			$(SRC_DIR)/$(COMPONENTS_DIR)/C4008.cpp\
			$(SRC_DIR)/$(COMPONENTS_DIR)/C4013.cpp\
			$(SRC_DIR)/$(COMPONENTS_DIR)/C4017.cpp\
			$(SRC_DIR)/$(COMPONENTS_DIR)/C4040.cpp\
			$(SRC_DIR)/$(COMPONENTS_DIR)/C4514.cpp\
			$(EXCEPTION_DIR)/InputException.cpp\
			$(EXCEPTION_DIR)/OutputException.cpp\
			$(EXCEPTION_DIR)/PinException.cpp\
			$(EXCEPTION_DIR)/ParserException.cpp\
			$(EXCEPTION_DIR)/ComponentManagerException.cpp\

OBJS		=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR_RC) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
