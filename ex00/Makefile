###############    variables    ###############

CFLAGS = -Wall -Wextra -Werror -g -std=c++98 -I./includes -I./libs -Ofast

SRC_DIR = ./srcs
OBJS_DIR = ./objs
OUTPUT_DIR ?= .
NAME ?= cub3d

###############    Files    ###############

SRC_GENERAL =	megaphone \

SRC	= $(addprefix $(SRC_DIR)/, $(addsuffix .cpp,	$(SRC_GENERAL) \
))

OBJS	:= $(patsubst $(SRC_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRC))

###############    Comilation    ###############
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(OUTPUT_DIR)/$(NAME) $(OBJS)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $<



###############    Cleaning    ###############
clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS)
	rm -f $(NAME)

###############    Re    ###############
re: fclean all