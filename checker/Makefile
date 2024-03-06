NAME		=	checker
ARCH_NAME	=	../push_swap/push_swap.a

SRCDIR		=	./srcs/
INCLUDE		=	-I/includes/checker.h
LIBFT		=	../push_swap/libft/libft.a

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf
ARCH_FLAGS	=	ar -rcs

SRC			=	$(SRCDIR)checker.c $(SRCDIR)checker_utils.c $(SRCDIR)errors_handling_checker.c
OBJ			=	$(SRC:.c=.o)

GREEN		=	\033[0;32m

all:			$(NAME)

%.o:			%.c
				@$(CC) $(CFLAGS) $(INCLUDE) -c $^ -o $@

$(NAME):		$(OBJ) $(ARCH_NAME)
				@$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) $(LIBFT) $(ARCH_NAME)  -o $@
				@cp $(NAME) ../push_swap
				@$(MAKE) finish

$(ARCH_NAME) :
				@make -C ../push_swap/

clean:
				@$(RM) $(OBJ)

fclean:			clean
				@$(RM) $(NAME)
				@$(RM) ../push_swap/$(NAME)
re:				fclean all

finish	:
				@clear
				@echo "${GREEN}▀█▀ █ █ █▀▀   █▀▀ █ █ █▀▀ █▀▀ █▄▀   █▀█ █   █▀▀ ▄▀█ █▀ █▀▀"
				@echo "${GREEN} █  █▀█ ██▄   █▄▄ █▀█ ██▄ █▄▄ █ █   █▀▀ █▄▄ ██▄ █▀█ ▄█ ██▄"

.PHONY:			 all clean fclean re finsih