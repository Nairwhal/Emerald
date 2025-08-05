#include <vector>
#include "Context.h"
#include <stdexcept>
#include <iostream>

struct token {
	public:
		bool isChar;
		bool isContext;
		char littleChar;
		Context* littleContext;

		token(char);
		token(Context*);
		~token();
};

class Content {
	public: 
		std::vector<token> tokens;

		Content();
		Content(std::vector<token>);
		~Content();
		bool isChar(int);
		bool isContext(int);
		token getToken(int);
		char getChar(int);
		Context* getContext(int);
		int getSize();
		bool isValidIndex(int);
		void addChar(char);
		void addContext(Context*);
		void print();
};