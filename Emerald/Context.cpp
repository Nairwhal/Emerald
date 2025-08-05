#include "Context.h"

Context::Context() {
	openerChars = openers::plain;
	closerChars = closers::plain;
	prev = nullptr;
}

Context::Context(char* openers, char* closers, Context* parent) {
	openerChars = openers;
	closerChars = closers;
	prev = parent;
}

Context::~Context() {}

char Context::grabNextChar(char* buf, int* index) {
	return buf[*index];
}

bool Context::isOpener(char c) {
	for(int i = 0; openerChars[i] != '\0'; ++i) {
		if(openerChars[i] == c) {
			return true;
		}
	}

	return false;
}

bool Context::isCloser(char c) {
	for(int i = 0; closerChars[i] != '\0'; ++i) {
		if(closerChars[i] == c) {
			return true;
		}
	}

	return false;
}

Context* Context::getPrev() {
	return prev;
}

Context* Context::createContext(char c) {
	switch(c) {
		case '"':
			return new Context{openers::doubleQuote, closers::doubleQuote, this};
		case '\'':
			return new Context{openers::singleQuote, closers::singleQuote, this};
		case '{':
			return new Context{openers::curlyBrace, closers::curlyBrace, this};
		case '(':
			return new Context{openers::parenthesis, closers::parenthesis, this};
		default:
			return new Context{openers::plain, closers::plain, this};
	}
}

void Context::print() {
	if(this->openerChars == openers::doubleQuote) {
		std::cout << "Context DQ";
	} else if(this->openerChars == openers::singleQuote) {
		std::cout << "Context SQ";
	} else if(this->openerChars == openers::curlyBrace) {
		std::cout << "Context Curly";
	} else if(this->openerChars == openers::parenthesis) {
		std::cout << "Context Parenthesis";
	} else {
		std::cout << "Context Plain";
	}
}

namespace openers {
	char* plain = new char[6]{'"', '\'', '{', '[', '(', '\0'};
	char* singleQuote = new char[1]{'\0'};
	char* doubleQuote = new char[1]{'\0'};
	char* curlyBrace = new char[6]{'"', '\'', '{', '[', '(', '\0'};
	char* squareBracket = new char[6] {'"', '\'', '{', '[', '(', '\0'};
	char* parenthesis = new char[6]{'"', '\'', '{', '[', '(', '\0'};
}

namespace closers {
	char* plain = new char[1]{'\0'};
	char* singleQuote = new char[2]{'\'', '\0'};
	char* doubleQuote = new char[2]{'"', '\0'};
	char* curlyBrace = new char[2]{'}', '\0'};
	char* squareBracket = new char[2] {']', '\0'};
	char* parenthesis = new char[2]{')', '\0'};
}