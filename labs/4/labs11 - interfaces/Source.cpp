#include <iostream>
#include <string>
#include <vector>

using namespace std;

class IStringManipulator {
public:
	virtual string manipulate(const string& text) = 0;
	virtual ~IStringManipulator() {}
};


class LetterAdd : public IStringManipulator {
	int numLetters;
	char letter;
public:
	LetterAdd(int numLetters, char letter)
	: numLetters(numLetters), letter(letter) {}

	string manipulate(const string& text) override {
		string result = text;
		for (int i = 0; i < numLetters; ++i) {
			result += letter;
		}
		return result;
	}
};

class LetterRemove : public IStringManipulator {
	int numLetters;
public:
	LetterRemove(int numLetters)
		: numLetters(numLetters) {}

	string manipulate(const string& text) override {
		return text.substr(0, text.length() - numLetters);
	}
};

class ReverseManupulator : public IStringManipulator {
public:
	string manipulate(const string& text) override {
		string result = text;
		int length = text.length();
		int halfLength = text.length() / 2;
		for (int i = 0; i < halfLength; ++i) {
			char temp = result[i];
			result[i] = result[length - i - 1];
			result[length - i - 1] = temp;
		}
		return result;
	}
};

class CaesarCipher : public IStringManipulator {
	int number;
public:
	CaesarCipher(int number) : number(number) {}

	string manipulate(const string& text) override {
		string result = text;
		int length = text.length();
		for (int i = 0; i < length; ++i) {
			result[i] = (result[i] + number) % 256;
		}
		return result;
	}
};

class CaesarCipherDecoder : public IStringManipulator {
	int number;
public:
	CaesarCipherDecoder(int number) : number(number) {}

	string manipulate(const string& text) override {
		string result = text;
		int length = text.length();
		for (int i = 0; i < length; ++i) {
			result[i] = ((result[i] - number) + 256) % 256;
		}
		return result;
	}
};

class ManipulationPipeline : public IStringManipulator {
	vector<IStringManipulator*> manipulators;
public:
	void addManipulator(IStringManipulator* manipulator) {
		manipulators.push_back(manipulator);
	}

	string manipulate(const string& text) override {
		string result = text;
		for (int i = 0; i < manipulators.size(); ++i) {
			result = manipulators[i]->manipulate(result);
		}
		return result;
	}
};


int main() {
	ReverseManupulator reverse;
	CaesarCipher cipher(3);
	CaesarCipherDecoder cipherDecoder(3);

	LetterAdd letterAdd(5, 'b');
	LetterRemove letterRemove(5);

	ManipulationPipeline encode;
	encode.addManipulator(&letterAdd);
	encode.addManipulator(&cipher);

	//encode.addManipulator(&letterAdd);
	//encode.addManipulator(&letterAdd);
	//encode.addManipulator(&reverse);

	ManipulationPipeline decoder;
	decoder.addManipulator(&letterRemove);
	decoder.addManipulator(&cipherDecoder);

	ManipulationPipeline identity;
	identity.addManipulator(&encode);
	identity.addManipulator(&decoder);

	string text = encode.manipulate("abcdefgh");
	cout << "Encoded: " << text << endl;
	cout << "Decoded: " << decoder.manipulate(text) << endl;
	cout << "Identity: " << identity.manipulate("TEXT");
}