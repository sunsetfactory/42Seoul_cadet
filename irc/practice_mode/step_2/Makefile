SERVER=server
CLIENT=client

MAKEFLAGS += -j

RED="\033[0;31m Warining: "
GREEN="\033[3;32m"
ANCI_INIT="\033[0m"

DEP_DIR=depend
OBJ_DIR=objs

CXX=c++

CXXFLAGS=-Wall -Wextra -Werror
CXXFLAGS+=-std=c++98
#$CXXFLAGS+=-g3 -fsanitize=address
CXXFLAGS+=-MMD -MP -MF $(DEP_DIR)/$*.d

RM=rm -rf

SRCS_SERVER=server.cpp
SRCS_CLIENT=client.cpp

OBJS_SERVER=$(addprefix $(OBJ_DIR)/, $(SRCS_SERVER:.cpp=.o))
OBJS_CLIENT=$(addprefix $(OBJ_DIR)/, $(SRCS_CLIENT:.cpp=.o))

DEPD=$(addprefix $(DEP_DIR)/, $(SRCS:.cpp=.d))

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_SERVER)
	@$(CXX) $(CXXFLAGS) $(OBJS_SERVER) $(LIBFT) -o $(SERVER)

$(CLIENT): $(OBJS_CLIENT)
	@$(CXX) $(CXXFLAGS) $(OBJS_CLIENT) $(LIBFT) -o $(CLIENT)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(DEP_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@ \
	&& echo $(GREEN)"Compiled successful!" $<$(ANCI_INIT) \
	|| echo $(RED)"Failed to compile $<"$(ANCI_INIT);

clean:
	@$(RM) $(OBJS_SERVER); $(RM) $(OBJS_CLIENT); $(RM) $(OBJ_DIR) $(DEPD) $(DEP_DIR)\
	&& echo $(GREEN)"Clean successful!"$(ANCI_INIT) \
	|| echo $(RED)"Clean failed!"$(ANCI_INIT);

fclean: clean
	@$(RM) $(SERVER); $(RM) $(CLIENT) \
	&& echo $(GREEN)"fclean successful!"$(ANCI_INIT) \
	|| echo $(RED)"fclean failed!"$(ANCI_INIT);

re: fclean all

.PHONY: all clean fclean re