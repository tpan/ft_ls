# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/31 18:58:43 by tpan              #+#    #+#              #
#    Updated: 2017/04/12 22:58:59 by tpan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_ls

CC		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

FT_LS_SRC_DIR = ./srcs/
LIB_SRC_DIR = ./srcs/libft
PRINTF_SRC_DIR = ./srcs/ft_printf

HEADER = -I ./includes

LIBFT_COMPILED 	=	ft_strlen.o \
					ft_strncpy.o \
					ft_strcpy.o \
					ft_strcmp.o \
					ft_putchar.o \
					ft_putstr.o \
					ft_atoi.o \
					ft_tolower.o \
					ft_isalpha.o \
		 			ft_toupper.o \
					ft_isdigit.o \
					ft_isalnum.o \
					ft_isprint.o \
					ft_isascii.o \
					ft_strdup.o \
					ft_memset.o \
					ft_bzero.o \
					ft_strstr.o \
					ft_memcmp.o \
					ft_memcpy.o \
					ft_memmove.o \
					ft_memccpy.o \
					ft_memchr.o \
					ft_strcat.o \
					ft_strncat.o \
					ft_strchr.o \
					ft_strrchr.o \
					ft_putendl.o \
					ft_putchar_fd.o \
					ft_putstr_fd.o \
					ft_putnbr.o \
					ft_putnbr_fd.o \
					ft_putendl_fd.o \
					ft_strclr.o \
					ft_memalloc.o \
					ft_memdel.o \
					ft_strnew.o \
					ft_strdel.o \
					ft_strncmp.o \
					ft_strequ.o \
					ft_strnequ.o \
					ft_strlcat.o \
					ft_strnstr.o \
					ft_striteri.o \
					ft_striter.o \
					ft_strmap.o \
					ft_strndup.o \
					ft_strjoin.o \
					ft_strmapi.o \
					ft_isspace.o \
					ft_strtrim.o \
					ft_strsplit.o \
					ft_wordlength.o \
					ft_wordcount.o \
					ft_lstnew.o \
					ft_lstdelone.o \
					ft_itoa.o \
					ft_lstdel.o \
					ft_lstiter.o \
					ft_lstmap.o \
					ft_strsub.o \
					ft_lstadd.o \
					ft_isnegative.o \
					ft_reverse.o \
					ft_realloc.o \
					ft_wstrlen.o \
					ft_wstrndup.o \
					ft_ishex.o \
					ft_wctomb.o \
					ft_wstrsize_utf8.o \
					ft_wstrnsize_utf8.o \
					ft_wstrdup.o \
					ft_wstrcpy.o \
					ft_wcharsize_utf8.o \
					ft_wcharbits.o \
					ft_wchar_memset.o \
					ft_utf8strnencode.o \
					ft_utf8strencode.o \
					ft_utf8charsize.o \
					ft_utf8charencode.o \
					ft_toupper_str.o \
					ft_tolower_str.o \
					ft_nbrlen.o \
					ft_itoa_base_ull.o \
					ft_itoa_base_uintmax.o \
					ft_itoa_base.o \
					ft_itoa_base_intmax.o \
					ft_lst_append.o \
					ft_lst_free.o \
					ft_lst_len.o \

FT_PRINTF_COMPILED =	read_flags.o \
						read_precision.o \
						read_width.o \
						read_length.o \
						read_specifier.o \
						app_wchar_width.o \
						apply_precision.o \
						apply_prefix.o \
						apply_width.o \
						compatible_flags.o \
						ft_printf.o \
						ft_vprintf.o \
						write_chars.o \
						write_conversion_substring.o \
						write_hex.o \
						write_octal.o \
						write_signed_int.o \
						write_unsigned_int.o \
						write_wchars.o \
						verify_flag_compatibility.o \
						fix_sign.o \

FT_LS_COMPILED =		ft_ls.o \

COMPILED =		$(LIBFT_COMPILED) $(FT_PRINTF_COMPILED) $(FT_LS_COMPILED)

all: $(NAME)

$(NAME): $(COMPILED) 
	@ar rc $(NAME) $(COMPILED)
	@ranlib $(NAME) 
	@echo "Made" $(NAME)

$(LIBFT_COMPILED): %.o: $(LIB_SRC_DIR)/%.c
	@$(CC) -c $(FLAGS) $(HEADER) $< -o $@

$(FT_PRINTF_COMPILED): %.o: $(PRINTF_SRC_DIR)/%.c
	@$(CC) -c $(FLAGS) $(HEADER) $< -o $@

$(FT_LS_COMPILED): %.o: $(FT_LS_SRC_DIR)/%.c
	@$(CC) -c $(FLAGS) $(HEADER) $< -o $@

clean:
	@-/bin/rm -rf $(COMPILED)
	@-/bin/rm -rf a.out a.out.dSYM
	@echo "Cleaned" $(NAME)

fclean: clean
	@-/bin/rm -rf $(NAME)
	@echo "Fcleaned" $(NAME)

re: fclean all 

.PHONY: $(NAME), all, clean, fclean, re
