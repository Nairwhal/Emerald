#pragma once
#include <iostream>

class Context {
public:
	char* openerChars;
	char* closerChars;
	Context* prev;

	Context();
	Context(char*, char*, Context*);
	~Context();
	char grabNextChar(char*, int*);
	bool isOpener(char);
	bool isCloser(char);
	Context* getPrev();
	Context* createContext(char);
	void print();
};

namespace openers {
	extern char* plain;
	extern char* singleQuote;
	extern char* doubleQuote;
	extern char* curlyBrace;
	extern char* squareBracket;
	extern char* parenthesis;
}

namespace closers {
	extern char* plain;
	extern char* singleQuote;
	extern char* doubleQuote;
	extern char* curlyBrace;
	extern char* squareBracket;
	extern char* parenthesis;
}