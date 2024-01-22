SRCS_FILES =	ft_dblstadd_after \
				ft_dblstadd_before \
				ft_dblstfirst \
				ft_dblstnew \

INCLUDES_FILES =	dblist \

SOURCE_DIR =	./SOURCES/
INCLUDES_DIR =	./INCLUDES/
OBJS_DIR =		./OBJECTS/

SOURCES =	$(addprefix $(SOURCE_DIR), $(addsuffix .c, $(SRCS_FILES)))
INCLUDES =	$(addprefix $(INCLUDES_DIR), $(addsuffix .h, $(INCLUDES_FILES)))
OBJS =		$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))

NAME = libft_dblst.a

CC = cc

CC_FLAGS = -Wall -Wextra -Werror -g

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
