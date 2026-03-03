# verifier le relink a la fin qund on aura tout le makefile

SRC = parser.c \
	disorder.c \
	utils/nodes_utils.c \
	utils/parser_flags_utils.c \
	utils/parser_utils.c \
	utils/parsing_index.c \
	utils/split.c \
	utils/split_utils.c \
	utils/utils.c \
	utils/parser_utils2.c \
	main.c \
	utils/simple_sort.c \
	utils/sorting_opps.c \
#tu captes la syntaxe pour les fonctions dans un fichier pour que le nakefile les retrouve

SRC_BONUS =

CC = cc

CFLAGS = -Wall -Wextra -Werror -I.

NAME = push_swap

NAME_BONUS = checker

OBJDIR = build
# nom du dossier ou je veux mettre mes .o et .d crees pour fair eplus propre #

OBJ = $(patsubst %.c,$(OBJDIR)/%.o,$(SRC))
# transforme ta liste de .c en liste de .o, mais en les mettant dans build, patsubst ca permet de substituer par pattern genre $(patsubst <motif>, <remplacement>, <liste>) #

OBJ_BONUS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRC) $(SRC_BONUS))
#ici a voir si on garde que les src_bonus ou quon met les deux

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
