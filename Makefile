# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tbruinem <tbruinem@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/30 11:07:31 by tbruinem       #+#    #+#                 #
#    Updated: 2020/02/10 17:00:43 by tbruinem      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#----------------------------------VARIABLES-----------------------------------

NAME = cub3D
OS = $(shell uname)

#----------------------------------PATHS---------------------------------------

SRC_DIR = ./src
LIB_DIR = ./lib
INCLUDE_DIR = ./include
GNL = $(LIB_DIR)/get_next_line
MLX_MAC = $(LIB_DIR)/minilibx_mac
MLX_LINUX = $(LIB_DIR)/minilibx_linux

#----------------------------------SOURCES-------------------------------------

SRC =	$(SRC_DIR)/cub3d.c \
		$(SRC_DIR)/ft_bmp.c \
		$(SRC_DIR)/ft_map_closecheck.c \
		$(SRC_DIR)/ft_color.c \
		$(SRC_DIR)/ft_coord.c \
		$(SRC_DIR)/ft_data.c \
		$(SRC_DIR)/ft_data_read.c \
		$(SRC_DIR)/ft_digit_utils.c \
		$(SRC_DIR)/ft_distcalc.c \
		$(SRC_DIR)/ft_drawer_init.c \
		$(SRC_DIR)/ft_error.c \
		$(SRC_DIR)/ft_freedom.c \
		$(SRC_DIR)/ft_identifier.c \
		$(SRC_DIR)/ft_init_ceiling.c \
		$(SRC_DIR)/ft_init_east.c \
		$(SRC_DIR)/ft_init_floor.c \
		$(SRC_DIR)/ft_init_funct.c \
		$(SRC_DIR)/ft_init_map.c \
		$(SRC_DIR)/ft_init_north.c \
		$(SRC_DIR)/ft_init_res.c \
		$(SRC_DIR)/ft_init_south.c \
		$(SRC_DIR)/ft_init_sprite.c \
		$(SRC_DIR)/ft_init_west.c \
		$(SRC_DIR)/ft_input_key.c \
		$(SRC_DIR)/ft_linedraw.c \
		$(SRC_DIR)/ft_mlx.c \
		$(SRC_DIR)/ft_ray.c \
		$(SRC_DIR)/ft_sprite_render.c \
		$(SRC_DIR)/ft_sprite_sort.c \
		$(SRC_DIR)/ft_string_utils.c \
		$(SRC_DIR)/ft_stringcomp.c \
		$(SRC_DIR)/ft_stringprint.c \
		$(SRC_DIR)/ft_texture.c \
		$(SRC_DIR)/ft_texture_fd.c \
		$(SRC_DIR)/ft_update.c \
		$(SRC_DIR)/ft_utils.c \
		$(SRC_DIR)/ft_validate_data.c \
		$(SRC_DIR)/ft_validate_input.c \

#----------------------------------FLAGS---------------------------------------

C_FLAGS = -O0 -I $(INCLUDE_DIR)
C_FLAGS += -Wall -Wextra -Werror
ifeq ($(OS),Linux)
	C_FLAGS += $(addprefix $(GNL)/, *.c) -D BUFFER_SIZE=40
else
	C_FLAGS += -L $(GNL) -lgnl
endif
ifeq ($(DEBUG),1)
	C_FLAGS += -g
endif
ifeq ($(DEBUG),2)
	C_FLAGS += -g -fsanitize=address
endif

#----------------------------------TAIL----------------------------------------

ifeq ($(OS),Linux)
	C_TAIL += -L $(MLX_LINUX) -I $(MLX_LINUX) \
	-lmlx_x86_64 -lXext -lX11 -lm -lz
else
	C_TAIL += -I $(MLX_MAC) -L $(MLX_MAC) \
	-lmlx -framework OpenGL -framework AppKit
endif

#----------------------------------DEFINES-------------------------------------

ifeq ($(OS),Linux)
	DEFINES += -D LINUX=1
endif
ifdef WIDTH
	DEFINES += -D MAX_WIDTH=$(WIDTH)
endif
ifdef HEIGHT
	DEFINES += -D MAX_HEIGHT=$(HEIGHT)
endif
ifdef S_SCALE
	DEFINES += -D SPRITESCALE=$(S_SCALE)
endif
ifdef S_HEIGHT
	DEFINES += -D SPRITEHEIGHT=$(S_HEIGHT)
endif

#----------------------------------RULES---------------------------------------

all: $(NAME)

$(NAME):
	@echo "Compiling.."
ifeq ($(OS),Linux)
	$(info Linux detected)
	@make -C $(MLX_LINUX) all
else
	$(info Mac detected)
	@make -C $(MLX_MAC) all
	@make -C $(GNL) all
	@cp -rf $(MLX_MAC)/libmlx.dylib .
endif
	@gcc $(C_FLAGS) $(SRC) -o $(NAME) $(C_TAIL) $(DEFINES)
	@echo "Done compiling"

clean:
	@echo "Cleaning"
ifdef LIB
 ifeq ($(OS),Linux)
	@make -C $(MLX_LINUX) clean
 else
	@make -C $(MLX_MAC) clean
	@make -C $(GNL) clean
 endif
	@rm -rf $(NAME).dSYM
endif
	@echo "Done cleaning"

fclean: clean
ifdef LIB
	@echo "Force cleaning"
	@make -C $(GNL) fclean
	@rm -rf libmlx.dylib
endif
	@rm -rf $(NAME)
	@echo "Done force cleaning"

re: fclean all
