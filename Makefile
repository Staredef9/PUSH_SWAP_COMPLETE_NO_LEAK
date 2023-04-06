# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 17:49:20 by ggiannit          #+#    #+#              #
#    Updated: 2023/04/03 09:51:11 by ggiannit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####### NAME #########

NAME = push_swap
PRNAME = push_swap

BNUS = checker

INCLUDE = include

###### VARIABLE ######

DIRSRCS =
DIROBJS = obj/

FLSRCS = push_swap.c operations.c operations_2.c lists_op.c push_swap_2.c radix.c \
		 utils.c utils_2.c utils_3.c

FLOBJS = ${FLSRCS:.c=.o}

FLBNSRCS = 

FLBNOBJS = ${FLBNSRCS:.c=.o}

OBJS = $(addprefix $(DIROBJS),$(FLOBJS))
BNOBJS = $(addprefix $(DIROBJS),$(FLBNOBJS))

ARUSD = libft.a
ARUSDDIR = 

ARINC = $(addprefix $(ARUSDDIR),$(ARUSD))

CC = cc
AR = ar
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

###### COLORS ########

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

######## EXT #########

# make a .o file using a .c file
# $< for the .c file
# $@ for the .o file

# .inextention.outextention:

#.c.o:
$(DIROBJS)%.o: $(DIRSRCS)%.c
	@echo "$(YELLOW)Compiling:$(BLUE) $< $(DEF_COLOR)"
	@${CC} ${CFLAGS} -c $< -o $@

#$(DIRBNOBJS)%.o: $(DIRBNSRCS)%.c
#	@echo "$(YELLOW)Compiling:$(BLUE) $< $(DEF_COLOR)"
#	@${CC} ${CFLAGS} -I ${INCLUDE} -c $< -o $@

####### RULES ########

all: libft ${NAME}

${NAME}: ${OBJS}
	@echo ""
	@echo "$(GREEN)*******************************************$(DEF_COLOR)"
	@echo "$(YELLOW)- Compiler: $(WHITE)${CC}$(DEF_COLOR)"
	@echo "$(YELLOW)- Flags: $(WHITE)${CFLAGS}$(DEF_COLOR)"
	@echo "$(GREEN)*******************************************$(DEF_COLOR)"
	@echo ""
	@${CC} ${CFLAGS} -o $(PRNAME) $(OBJS) $(ARINC)
	@echo "$(YELLOW)Program created with $(WHITE)${CC}$(YELLOW) as $(CYAN)${PRNAME}$(DEF_COLOR)"
	@echo ""

bonus: ${OBJS} ${BNOBJS}
	@echo ""
	@echo "$(GREEN)*******************************************$(DEF_COLOR)"
	@echo "$(YELLOW)- Compiler: $(WHITE)${CC}$(DEF_COLOR)"
	@echo "$(YELLOW)- Flags: $(WHITE)${CFLAGS}$(DEF_COLOR)"
	@echo "$(GREEN)*******************************************$(DEF_COLOR)"
	@echo ""
	@${CC} ${CFLAGS} -o $(BNUS) $(OBJS) $(BNOBJS) $(ARINC)
	@echo "$(YELLOW)Program created with $(WHITE)${CC}$(YELLOW) as $(CYAN)${BNUS}$(DEF_COLOR)"
	@echo ""

clean: libftclean
	@echo "$(WHITE)\"wait.. is $(CYAN)${PRNAME}$(WHITE) all trash? 🧹\" $(DEF_COLOR)"
	@${RM} ${OBJS} ${BNOBJS}
	@echo "$(RED)All objects removed with $(WHITE)${RM}$(DEF_COLOR)"
	@echo ""

fclean: clean
	@echo "$(WHITE)\"...it's always as been 🚮\" $(DEF_COLOR)"
	@${RM} ${PRNAME} ${BNUS}
	@echo "$(RED)..and $(CYAN)${ARNAME}, ${BNUS} $(RED)as been removed$(DEF_COLOR)"
	@echo ""

libft:
	@make -sC Libft

libftclean:
	@make -sC Libft clean

libftre:
	@make -sC Libft re

re: fclean all

.PHONY: all clean fclean re bonus .c.o libft libftclean libftre
.SUFFIXES: .c .o 
