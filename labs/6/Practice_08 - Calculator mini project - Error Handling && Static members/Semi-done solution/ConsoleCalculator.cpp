#include "ConsoleCalculator.hpp"

void ConsoleCalculator::run()
{
	const unsigned MaxLineLength = 200;
	const char* startingMessage = "Welcome, please enter an expression: ";

	std::cout << startingMessage;
	while (true)
	{
		// TODO: Make line to be unlimited length
		char line[MaxLineLength + 1];
		std::cin.getline(line, MaxLineLength);

		try
		{
			const char* result = StringCalculatorEngine::evaluateExpression(line);
			writeLine(result);
			delete[] result;
		}
		catch (std::invalid_argument& e)
		{
			writeLine(e.what());
		}
		catch (...)
		{
			const char* unknownErrorMessage = "Unknown error occurred.";
			writeLine(unknownErrorMessage);
		}
	}

}

void ConsoleCalculator::readLine()
{
}

void ConsoleCalculator::writeLine(const char* output)
{
	std::cout << output << std::endl;
}
