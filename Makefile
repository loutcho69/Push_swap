# verifier le relink a la fin qund on aura tout le makefile

SRC = parser.c \
	disorder.c \
	utils/nodes_utils.c \
	utils/parser_flags_utils.c \
	utils/parser_utils.c \
	utils/split.c \
	utils/split_utils.c \
	utils/utils.c \
	utils/parser_utils2.c \
	main.c \

SRC_BONUS =	bonus/checker.c \
	bonus/GNL/get_next_line_utils.c \
	bonus/GNL/get_next_line.c \
	bonus/opps/opps.c \
	bonus/parser_bonus.c \

CC = cc

CFLAGS = -Wall -Wextra -Werror -I.

NAME = push_swap

NAME_BONUS = checker

OBJDIR = build

OBJ = $(patsubst %.c,$(OBJDIR)/%.o,$(SRC))

OBJ_BONUS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRC) $(SRC_BONUS))

DEP = $(OBJ:.o=.d)
DEP_BONUS = $(OBJ_BONUS:.o=.d)

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	rm -f *.o *.d utils/*.o utils/*.d

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus

-include $(DEP)
-include $(DEP_BONUS)
