include .env
export
NAME = connect4

COLOR_ESC			= \033
COLOR_WHITE			= $(COLOR_ESC)[97m
COLOR_CYAN			= $(COLOR_ESC)[96m
COLOR_GREEN			= $(COLOR_ESC)[32m
COLOR_BLUE			= $(COLOR_ESC)[34m
COLOR_YELLOW		= $(COLOR_ESC)[33m
COLOR_MAGENTA 		= $(COLOR_ESC)[35m
COLOR_BOLD			= $(COLOR_ESC)[1m
COLOR_RESET			= $(COLOR_ESC)[0m
COLOR_RESET_BOLD	= $(COLOR_ESC)[21m

PATH_HEADER			= includes/
PATH_GAME			= src_game/
PATH_MINMAX			= src_minmax/
PATH_UTIL			= src_util/
PATH_OBJ			= objs/

HEADER				= 	includes.h game.h utils.h minmax.h
SRC_GAME			= 	main.c play_game.c has_won.c play_human.c print_board.c play_ai.c
SRC_MINMAX			= 	minmax.c calc_board_value.c
SRC_UTIL			= 	string.c util.c

SRC_GAMES			= $(addprefix $(PATH_GAME),$(SRC_GAME))
SRC_MINMAXS			= $(addprefix $(PATH_MINMAX),$(SRC_MINMAX))
SRC_UTILS			= $(addprefix $(PATH_UTIL),$(SRC_UTIL))

SRCS 				= $(SRC_GAMES) $(SRC_MINMAXS) $(SRC_UTILS)

OBJ					= $(SRCS:.c=.o)
OBJS				= $(addprefix $(PATH_OBJ),$(OBJ))
HEADERS				= $(addprefix $(PATH_HEADER),$(HEADER))

ifndef DEBUG
	DEBUG			= 0
endif

DEBUGING			= -g3 -fsanitize=address -fsanitize=undefined
CFLAGS				= -Wall -Wextra -Werror


OPTIONS				= -I$(PATH_HEADER)
LIBS				=
CC					= gcc
RM					= rm -rf

ifeq ($(DEBUG), 1)
	CFLAGS += $(DEBUGING)
endif

ifdef OPTIMISATION_LEVEL
	ifeq ($(OPTIMISATION_LEVEL),0)
		# Nothing
	else
		CFLAGS += -O$(OPTIMISATION_LEVEL)
	endif
else
	CFLAGS += -Ofast
endif

all			: $(NAME)

$(PATH_OBJ)$(PATH_GAME)%.o	: $(PATH_GAME)%.c $(HEADERS)
	@mkdir -p $(PATH_OBJ)$(PATH_GAME)
	@$(CC) $(CFLAGS) $(OPTIONS) -o $(@) -c $(<)
	@printf "$(COLOR_GREEN)[$(COLOR_WHITE)INFO$(COLOR_GREEN)] COMPILATION $(COLOR_CYAN)DEBUG => [%s] $(COLOR_BOLD)GAME\t\t=>\t$(COLOR_WHITE)%s$(COLOR_RESET)\n" $(DEBUG) $<

$(PATH_OBJ)$(PATH_MINMAX)%.o	: $(PATH_MINMAX)%.c $(HEADERS)
	@mkdir -p $(PATH_OBJ)$(PATH_MINMAX)
	@$(CC) $(CFLAGS) $(OPTIONS) -o $(@) -c $(<)
	@printf "$(COLOR_GREEN)[$(COLOR_WHITE)INFO$(COLOR_GREEN)] COMPILATION $(COLOR_BLUE)DEBUG => [%s] $(COLOR_BOLD)MINMAX\t\t=>\t$(COLOR_WHITE)%s$(COLOR_RESET)\n" $(DEBUG) $<

$(PATH_OBJ)$(PATH_UTIL)%.o		: $(PATH_UTIL)%.c $(HEADERS)
	@mkdir -p $(PATH_OBJ)$(PATH_UTIL)
	@$(CC) $(CFLAGS) $(OPTIONS) -o $(@) -c $(<)
	@printf "$(COLOR_GREEN)[$(COLOR_WHITE)INFO$(COLOR_GREEN)] COMPILATION $(COLOR_MAGENTA)DEBUG => [%s] $(COLOR_BOLD)UTIL\t\t=>\t$(COLOR_WHITE)%s$(COLOR_RESET)\n" $(DEBUG) $<

$(NAME)		: $(OBJS)
	@$(CC) $(CFLAGS) $(OPTIONS) -o $(@) $(OBJS) $(LIBS)
	@echo "$(COLOR_GREEN)[$(COLOR_WHITE)INFO$(COLOR_GREEN)] LINKAGE $(COLOR_BOLD)ALL OBJS FILE =>\n\t $(COLOR_WHITE)$(^:.o=.o\n\t)"
	@echo "$(COLOR_GREEN)[$(COLOR_WHITE)INFO$(COLOR_GREEN)] COMPILATION FINISH !$(COLOR_WHITE)$(COLOR_RESET_BOLD)"

clean		:
	@$(RM) $(OBJS)
	@$(RM) $(PATH_OBJ)
	@echo "$(COLOR_GREEN)[$(COLOR_WHITE)INFO$(COLOR_GREEN)] DELETE $(COLOR_BOLD)ALL OBJS FILE =>\n\t $(COLOR_WHITE)$(OBJS:.o=.o\n\t)"
	@echo "$(COLOR_GREEN)[$(COLOR_WHITE)INFO$(COLOR_GREEN)] CLEAN FINISH !$(COLOR_RESET)"

fclean		: clean
	@$(RM) $(NAME)
	@echo "$(COLOR_GREEN)[$(COLOR_WHITE)INFO$(COLOR_GREEN)] DELETE $(COLOR_BOLD)PROGRAMME =>\n\t $(COLOR_WHITE)$(NAME)"
	@echo "$(COLOR_GREEN)[$(COLOR_WHITE)INFO$(COLOR_GREEN)] FCLEAN FINISH !$(COLOR_RESET)"

re			: fclean all

.PHONY: all fclean clean re