#include "Content.h"

token::token(char c) {
	isChar = true;
	isContext = false;
	littleChar = c;
	littleContext = {};
}

token::token(Context* c) {
	isChar = false;
	isContext = true;
	littleChar = {};
	littleContext = c;
}

token::~token() {}

//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------

Content::Content() {
	tokens = {};
}

Content::Content(std::vector<token> t) {
	tokens.insert(tokens.end(), t.begin(), t.end());
}

Content::~Content() {}

bool Content::isChar(int index) {
	return tokens[index].isChar;
}

bool Content::isContext(int index) {
	return tokens[index].isContext;
}

token Content::getToken(int index) {
	return tokens[index];
}

char Content::getChar(int index) {
	return tokens[index].littleChar;
}

Context* Content::getContext(int index) {
	return tokens[index].littleContext;
}

int Content::getSize() {
	return tokens.size();
}

bool Content::isValidIndex(int index) {
	return index < tokens.size();
}

void Content::addChar(char c) {
	tokens.push_back(token{c});
}

void Content::addContext(Context* c) {
	tokens.push_back(token{c});
}

void Content::print() {
	for(int i = 0; i < tokens.size(); ++i) {
		if(tokens[i].isChar) {
			std::cout << tokens[i].littleChar;
		} else if (tokens[i].isContext) {
			tokens[i].littleContext->print();
		}
	}
}