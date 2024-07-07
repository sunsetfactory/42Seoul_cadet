#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class RPN {
	private:
		RPN();
		RPN(const RPN&);
		RPN& operator=(const RPN&);
		~RPN();

		static bool	isop(char op);
		static void	print_error();
		static void	perform_operation(std::stack<int>&, char op);
	public:
		static void	calculate(std::string);
};

#endif