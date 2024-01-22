SRCS_FILES =	ft_memset	\
				ft_bzero	\
				ft_memcpy	\
				ft_memmove	\
				ft_memchr	\
				ft_memcmp	\
				ft_strlen	\
				ft_isalpha	\
				ft_isdigit	\
				ft_isalnum	\
				ft_isascii	\
				ft_isprint	\
				ft_toupper	\
				ft_tolower	\
				ft_strchr	\
				ft_strrchr	\
				ft_striteri	\
				ft_strncmp	\
				ft_strlcpy	\
				ft_strlcat	\
				ft_strnstr	\
				ft_atoi	\
				ft_calloc	\
				ft_strdup	\
				ft_substr	\
				ft_strjoin	\
				ft_strtrim	\
				ft_split	\
				ft_itoa	\
				ft_strmapi	\
				ft_putchar_fd	\
				ft_putstr_fd	\
				ft_putendl_fd	\
				ft_putnbr_fd	\
				ft_lstnew_bonus	\
				ft_lstadd_front_bonus	\
				ft_lstsize_bonus		\
				ft_lstlast_bonus		\
				ft_lstadd_back_bonus	\
				ft_lstclear_bonus		\
				ft_lstdelone_bonus	\
				ft_lstiter_bonus		\
				ft_lstmap_bonus		\

INCLUDES_FILES = libft

SOURCE_DIR =	./SOURCES/
INCLUDES_DIR =	./INCLUDES/
OBJS_DIR =		./OBJECTS/

SOURCES =	$(addprefix $(SOURCE_DIR), $(addsuffix .c, $(SRCS_FILES)))
INCLUDES =	$(addprefix $(INCLUDES_DIR), $(addsuffix .h, $(INCLUDES_FILES)))
OBJS =		$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))

NAME = libft.a

CC = cc

CC_FLAGS = -Wall -Wextra -Werror

$(OBJS_DIR)%.o : $(SOURCE_DIR)%.c
	mkdir -p $(OBJS_DIR)
	@clang $(CC_FLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJS)
	@ar r $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)
	$(RM) -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
