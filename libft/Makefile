# 1st makefile
NAME = libft.a

# Mandatory .c Files
C_SOURCES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
			ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
			ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
			ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
			ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c

# Bonus .c Files
BONUS_SOURCES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
				ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
				ft_lstclear.c ft_lstiter.c ft_lstmap.c


# Object Files
OBJ = $(C_SOURCES:.c=.o)

#Bonus Object Files:
OBJ_BONUS = $(BONUS_SOURCES:.c=.o)

#Command to Create:
CREATE = @ar -rc

#Command to Remove:
REMOVE = @rm -f

# Flags for the Compiler
CFLAGS = -Wall -Wextra -Werror

#Compilation and Linking
all: $(NAME)

$(NAME):	$(OBJ)
			$(CREATE) $(NAME) $(OBJ)


bonus:	$(NAME) $(OBJ_BONUS)
		$(CREATE) $(NAME) $(OBJ_BONUS)

clean:	
		$(REMOVE) *.o

fclean:	clean
		$(REMOVE) $(NAME)

re:		clean all

.PHONY: all bonus clean fclean re