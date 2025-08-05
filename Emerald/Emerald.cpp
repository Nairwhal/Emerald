#include "Emerald.h"

int main() {
	int* sampleCPPBufferLength = new int;
	char* sampleCPPBuffer = fileToBuffer("C:/Users/noahs/source/repos/Emerald/Emerald/HelloWorld.mrld", sampleCPPBufferLength);
	std::vector<Context*>* contexts = new std::vector<Context*>{};
	std::vector<Content*>* contents = new std::vector<Content*>{};

	createCNC(contexts, contents, sampleCPPBuffer, sampleCPPBufferLength);

	delete sampleCPPBufferLength;
	delete sampleCPPBuffer;
	delete contexts;
	delete contents;
	return 0;
}

char* fileToBuffer(const char* name, int* length) {
	std::ifstream file(name);
	file.seekg(0, std::ios::end);
	*length = file.tellg();
	file.seekg(0, std::ios::beg);
	char* buf = new char[*length + 1];
	//buf[*length - 4] = '\0';
	//*length = *length - 4;
	file.read(buf, *length);
	file.close();

	return buf;
}

void createCNC(std::vector<Context*>* contexts, std::vector<Content*>* contents, char* buf, int* bufLength) {
	Context* currentContext = new Context{openers::plain, closers::plain, nullptr};
	Content* currentContent = new Content{};
	int vectorIndex = 0;
	char currentChar;

	contexts->push_back(currentContext);
	contents->push_back(currentContent);

	for(int i = 0; i < *bufLength; ++i) {
		currentChar = buf[i];

		if(currentContext->isOpener(currentChar)) {
			vectorIndex = contexts->size();
			currentContext = currentContext->createContext(currentChar);
			contexts->push_back(currentContext);
			currentContent->addContext(currentContext);
			currentContent = new Content{};
			contents->push_back(currentContent);
		} else if(currentContext->isCloser(currentChar)) {
			while(currentContext->getPrev() != (*contexts)[--vectorIndex]) {}

			currentContent = (*contents)[vectorIndex];
			currentContext = (*contexts)[vectorIndex];
		} else {
			currentContent->addChar(currentChar);
		}
	}

	for(int i = 0; i < contents->size(); ++i) {
		(*contexts)[i]->print();
		std::cout << "\n";
		(*contents)[i]->print();
		std::cout << "\n------------\n";
	}
}