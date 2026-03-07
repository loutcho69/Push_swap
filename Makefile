# verifier le relink a la fin qund on aura tout le makefile

SRC = bench.c \
	disorder.c \
	main.c \
	opps_push.c \
	opps_rev.c \
	opps_rot.c \
	opps_swap.c \
	parser.c \
	parsing_index.c \
	push_swap.c \
	simple_sort.c \
	split.c \
	utils_algo.c \
	utils_flags.c \
	utils_init_data.c \
	utils_node.c \
	utils_parsing.c \
	utils_parsing2.c \
	utils_str.c \

SRC_BONUS =	checker.c \

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