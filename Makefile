# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/18 14:38:23 by eunskim           #+#    #+#              #
#    Updated: 2023/08/26 19:19:27 by sawang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#//= Colors =//#
BLACK   := \033[30;1m
RED     := \033[31;1m
GREEN   := \033[32;1m
YELLOW  := \033[33;1m
BLUE    := \033[34;1m
MAGENTA := \033[35;1m
CYAN    := \033[36;1m
WHITE   := \033[37;1m
RESET   := \033[0m

#//= Mandatory part =//#
NAME        := cub3D
CC          := cc
CFLAGS      := -Wextra -Wall -Werror
CFLAGS      += -Wunreachable-code -Ofast
#CFLAGS      += -g3 -fsanitize=address

LIBMLX_DIR  := lib/MLX42
MLX42       := $(LIBMLX_DIR)/libmlx42.a

LIBFT_DIR   := lib/libft
LIBFT       := $(LIBFT_DIR)/libft.a

LIBGNL_DIR  := lib/get_next_line
GNL         := $(LIBGNL_DIR)/get_next_line.a

INCLUDE_DIR := include

HEADERS     := -I $(INCLUDE_DIR) -I $(LIBMLX_DIR)/include/MLX42/ -I $(LIBFT_DIR) -I $(LIBGNL_DIR)
FRAMEWORKS  := -framework Cocoa -framework OpenGL -framework IOKit

SRC_DIR     := src/
SRC         := \
render_test.c

SRC_DIR_PARSER	:= parser/
SRC_PARSER      := \
parser.c \
parser_2.c \
parser_utils.c \
parser_utils_2.c \
parser_error.c \
parser_free.c

SRC_DIR_RAYCAST	:= raycast/
SRC_RAYCAST     := \
calculate_utils.c \
hit_point.c \
initializer.c \
raycast.c \
mock_map.c

SRC_DIR_RENDER	:= render/
SRC_RENDER      := \
draw_verti_line.c \
draw_wall.c \
render_error_handler.c \
render.c \
render_utils.c

SRCS := $(addprefix $(SRC_DIR),$(SRC))
SRCS_PARSER := $(addprefix $(SRC_DIR_PARSER),$(SRC_PARSER))
SRCS_RAYCAST := $(addprefix $(SRC_DIR_RAYCAST),$(SRC_RAYCAST))
SRCS_RENDER := $(addprefix $(SRC_DIR_RENDER),$(SRC_RENDER))

OBJ_DIR = obj/
OBJS := $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)$(SRC_DIR)%.o,$(SRCS))
OBJS += $(patsubst $(SRC_DIR_PARSER)%.c,$(OBJ_DIR)$(SRC_DIR_PARSER)%.o,$(SRCS_PARSER))
OBJS += $(patsubst $(SRC_DIR_RAYCAST)%.c,$(OBJ_DIR)$(SRC_DIR_RAYCAST)%.o,$(SRCS_RAYCAST))
OBJS += $(patsubst $(SRC_DIR_RENDER)%.c,$(OBJ_DIR)$(SRC_DIR_RENDER)%.o,$(SRCS_RENDER))

#//= Make Rules =//#
all: libmlx libft libgnl $(NAME)

libmlx:
	@$(MAKE) -lglfw -C $(LIBMLX_DIR)

libft:
	@$(MAKE) -C $(LIBFT_DIR)

libgnl:
	@$(MAKE) -C $(LIBGNL_DIR)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX42) $(LIBFT) $(GNL) -lglfw $(FRAMEWORKS) -o $(NAME) && \
	echo "$(BLUE)Compilation of $(CYAN)>>$(NAME)<<$(RESET)$(BLUE) successful!$(RESET)"

$(OBJ_DIR)$(SRC_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(OBJ_DIR)$(SRC_DIR_PARSER)%.o: $(SRC_DIR_PARSER)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(OBJ_DIR)$(SRC_DIR_RAYCAST)%.o: $(SRC_DIR_RAYCAST)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(OBJ_DIR)$(SRC_DIR_RENDER)%.o: $(SRC_DIR_RENDER)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBMLX_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(LIBGNL_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(MLX42)
	@rm -f $(LIBFT)
	@rm -f $(GNL)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, libft, libgnl
