NAME		=	push_swap
ARCH_NAME	=	push_swap.a

SRCDIR		=	srcs/
LIBFT		=	./libft/libft.a
INCLUDE		=	-I/includes/push_swap.h

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf
ARCH_FLAGS	=	ar -rcs

SRC			=	$(SRCDIR)main.c \
				$(SRCDIR)stack_init.c \
				$(SRCDIR)errors_handling.c \
				$(SRCDIR)errors_input.c \
				$(SRCDIR)cmd_push.c \
				$(SRCDIR)cmd_rev_rotate.c \
				$(SRCDIR)cmd_rotate.c \
				$(SRCDIR)cmd_swap.c \
				$(SRCDIR)set_data_a.c \
				$(SRCDIR)set_data_b.c \
				$(SRCDIR)sort_tiny.c \
				$(SRCDIR)sort_utils.c \
				$(SRCDIR)sort.c \
				$(SRCDIR)stack_utils.c

OBJ			=	$(SRC:.c=.o)

RED			=	\033[0;31m
GREEN		=	\033[0;32m
SUCCESS		=	\033[30;42;1m
END			=	\033[0m

all:			$(NAME)

$(LIBFT):
				@make -C ./libft

$(NAME):		$(LIBFT) $(OBJ) $(ARCH_NAME)
				@$(CC) $(CFLAGS) $(INCLUDE) $(LIBFT) $(OBJ) -o $@
				@$(MAKE) loading
				@sleep 0.5
				@$(MAKE) finish

$(ARCH_NAME) : $(OBJ)
				@$(ARCH_FLAGS) $@ $^

%.o:			%.c
				@$(CC) $(CFLAGS) -c $^ -o $@

bonus :
				@make -C ../checker/


clean:
				@$(RM) $(OBJ)
				@make clean -C ./libft
				@make clean -C ../checker/

fclean:			clean
				@$(RM) $(NAME)
				@$(RM) $(LIBFT)
				@$(RM) $(ARCH_NAME)
				@make fclean -C ../checker


re:				fclean all

finish	:
				@clear
				@echo "${GREEN}█▀█ █▀█ █ █ █▀ █ █    █▀ █▀█ █ █ ▄▀█ █▀█"
				@echo "${GREEN}█▀▀ █▄█ █▄█ ▄█ █▀█    ▄█ █▄█ █▄█ █▀█ █▀▀"

loading	:
				@echo "Start compiling Push_swap"
				@sleep 0.1
				@echo "Compiling Push_swap"
				@echo "[${RED}░░░░░░░░░░░░░░░░░${END}]"
				@sleep 0.1
				@clear
				@echo "Compiling Push_swap"
				@echo "[${RED}▒░░░░░░░░░░░░░░░░${END}]"
				@sleep 0.1
				@clear
				@echo "Compiling Push_swap"
				@echo "[${RED}█▒░░░░░░░░░░░░░░░${END}]"
				@sleep 0.1
				@clear
				@echo "Compiling Push_swap"
				@echo "[${RED}██▒░░░░░░░░░░░░░░${END}]"
				@sleep 0.1
				@clear
				@echo "Compiling Push_swap"
				@echo "[${RED}███▒░░░░░░░░░░░░░${END}]"
				@sleep 0.1
				@clear
				@echo "Compiling Push_swap"
				@echo "[${RED}████▒░░░░░░░░░░░░${END}]"
				@sleep 0.1
				@clear
				@echo "Compiling Push_swap"
				@echo "[${RED}█████▒░░░░░░░░░░░${END}]"
				@sleep 0.1
				@clear
				@echo "Compiling Push_swap"
				@echo "[${RED}██████▒░░░░░░░░░░${END}]"
				@sleep 0.5
				@clear
				@echo "Compiling Push_swap"
				@echo "[${RED}███████▒░░░░░░░░░${END}]"
				@sleep 0.23
				@clear
				@echo "Compiling Push_swap"
				@echo "[${RED}████████▒░░░░░░░░${END}]"
				@sleep 0.03
				@clear
				@echo "Compiling Push_swap"
				@echo "[${RED}█████████▒░░░░░░░${END}]"
				@sleep 0.05
				@clear
				@echo "Compiling Push_swap"
				@echo "[${RED}██████████▒░░░░░░${END}]"
				@sleep 0.09
				@clear
				@echo "Compiling Push_swap"
				@echo "[${RED}███████████▒░░░░░${END}]"
				@sleep 0.05
				@clear
				@echo "Compiling Push_swap"
				@echo "[${RED}████████████▒░░░░${END}]"
				@sleep 0.05
				@clear
				@echo "Compiling Push_swap"
				@echo "[${RED}█████████████▒░░░${END}]"
				@sleep 0.05
				@clear
				@echo "Compiling Push_swap"
				@echo "[${RED}██████████████▒░░${END}]"
				@sleep 0.05
				@clear
				@echo "Compiling Push_swap"
				@echo "[${RED}███████████████▒░${END}]"
				@sleep 0.05
				@clear
				@echo "Compiling Push_swap"
				@echo "[${RED}████████████████▒${END}]"
				@sleep 0.05
				@clear
				@echo "Finish compiling Push_swap"
				@echo "[${SUCCESS}  PUSH_SWAP ok   ${END}]"

.PHONY:			 all clean fclean re loading finish bonus