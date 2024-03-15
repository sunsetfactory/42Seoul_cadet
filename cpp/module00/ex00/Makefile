MEGAPHONE=megaphone

RED=\033[1;31;4m Warning:
GREEN=\033[1;32;3m
ANCI_INIT=\033[0m

OBJ_DIR=objs

CXX=c++

CXXFLAGS=-Wall -Wextra -Werror
CXXFLAGS+=-std=c++98

RM=rm -rf

SRCS=$(wildcard *.cpp)
OBJS=$(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

$(MEGAPHONE): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(MEGAPHONE)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@ \
	&& echo "$(GREEN)Compiled successful! $<$(ANCI_INIT)" \
	|| echo "$(RED)Failed to compile $<$(ANCI_INIT)";

all: $(MEGAPHONE)

clean:
	@$(RM) $(OBJS)$(OBJ_DIR) \
	&& echo "$(GREEN)Clean successful!$(ANCI_INIT)" \
	|| echo "$(RED)Clean failed!$(ANCI_INIT)";

fclean:
	@$(RM) $(OBJS) $(OBJ_DIR) \
	&& echo "$(GREEN)fclean successful!$(ANCI_INIT)" \
	|| echo "$(RED)fclean failed!$(ANCI_INIT)";

re:
	@make fclean
	@make all

.PHONY: all clean fclean re
