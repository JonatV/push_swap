CC 		= 	gcc
CFLAGS	= 	-Wall -Wextra -Werror
NAME 	= 	libft.a
SRCS	= 	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
			ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
			ft_calloc.c ft_strdup.c ft_toupper.c ft_tolower.c \
			ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
			ft_atoi.c ft_atol.c ft_strrchr.c ft_substr.c ft_split.c\
			ft_strjoin.c ft_strtrim.c ft_itoa.c \
			ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_strnstr.c ft_strcmp.c \
			ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

OBJS 	= 	${SRCS:.c=.o}
RM 		= 	rm -f
AR 		= 	ar rcs

RED		=	\033[0;31m
SUCCESS	=	\033[30;42;1m
END		=	\033[0m

.PHONY 	:	all clean fclean re loading
.c.o	:
			@${CC} ${CFLAGS} -c $< -o $@

all 	:	${NAME}
			@clear

${NAME} :	${OBJS}
			@${AR}	${NAME} ${OBJS}
			@$(MAKE) loading


clean 	:
			@${RM} 	${OBJS} ${OBJSB}
fclean 	: 	clean
			@${RM} ${NAME} ${bonus}
re		: 	fclean all

loading	:
			@echo "Start compiling libft"
			@sleep 0.1
			@echo "Compiling libft"
			@echo "[${RED}░░░░░░░░░░░░░░░░░${END}]"
			@sleep 0.1
			@clear
			@echo "Compiling libft"
			@echo "[${RED}▒░░░░░░░░░░░░░░░░${END}]"
			@sleep 0.1
			@clear
			@echo "Compiling libft"
			@echo "[${RED}█▒░░░░░░░░░░░░░░░${END}]"
			@sleep 0.1
			@clear
			@echo "Compiling libft"
			@echo "[${RED}██▒░░░░░░░░░░░░░░${END}]"
			@sleep 0.1
			@clear
			@echo "Compiling libft"
			@echo "[${RED}███▒░░░░░░░░░░░░░${END}]"
			@sleep 0.1
			@clear
			@echo "Compiling libft"
			@echo "[${RED}████▒░░░░░░░░░░░░${END}]"
			@sleep 0.1
			@clear
			@echo "Compiling libft"
			@echo "[${RED}█████▒░░░░░░░░░░░${END}]"
			@sleep 0.1
			@clear
			@echo "Compiling libft"
			@echo "[${RED}██████▒░░░░░░░░░░${END}]"
			@sleep 0.5
			@clear
			@echo "Compiling libft"
			@echo "[${RED}███████▒░░░░░░░░░${END}]"
			@sleep 0.23
			@clear
			@echo "Compiling libft"
			@echo "[${RED}████████▒░░░░░░░░${END}]"
			@sleep 0.03
			@clear
			@echo "Compiling libft"
			@echo "[${RED}█████████▒░░░░░░░${END}]"
			@sleep 0.05
			@clear
			@echo "Compiling libft"
			@echo "[${RED}██████████▒░░░░░░${END}]"
			@sleep 0.09
			@clear
			@echo "Compiling libft"
			@echo "[${RED}███████████▒░░░░░${END}]"
			@sleep 0.05
			@clear
			@echo "Compiling libft"
			@echo "[${RED}████████████▒░░░░${END}]"
			@sleep 0.05
			@clear
			@echo "Compiling libft"
			@echo "[${RED}█████████████▒░░░${END}]"
			@sleep 0.05
			@clear
			@echo "Compiling libft"
			@echo "[${RED}██████████████▒░░${END}]"
			@sleep 0.05
			@clear
			@echo "Compiling libft"
			@echo "[${RED}███████████████▒░${END}]"
			@sleep 0.05
			@clear
			@echo "Compiling libft"
			@echo "[${RED}████████████████▒${END}]"
			@sleep 0.05
			@clear
			@echo "Finish compiling libft"
			@echo "[${SUCCESS}    LIBFT ok     ${END}]"
			@sleep 0.5