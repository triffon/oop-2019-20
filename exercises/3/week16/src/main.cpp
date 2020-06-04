#include<iostream>
#include<DivisionByZeroException.h>

using namespace std;

//we can throw any type of exceptions, even our own custom exceptions
float customExceptionDivide(float a, float b){
	if(b==0){
		throw DivisionByZeroException(a, b);
	}
	return a/b;
}
void customExceptionsDemo(){
	float result = 314;
	try{
		result = customExceptionDivide(14.0,1.0);
		//This code is executed if everything went fine(without exceptions)
		cout << "division went fine, result is " << result << endl;
		
	}catch (DivisionByZeroException& e){
		//calling the virtual function what() will give us more information about the exception
		//the information can obviously be much more detailed that the one of an error code since it is an string
		cout << e.what() << endl;
	}  
}

//By default functions handle thrown exception to those who called them
//Unless they are Function with specified throw 
//Any exception other than those of the parameterized type cause the program to stop/call std::unexepcted()
void func(int arg) throw (int);
//Every exception is unexpected
void func2(int arg) throw();
//handles every exception
void func3(int arg);

//Error code is the use of the return value of a function to indicate an error code
//Not flexible and we must know all error codes in advance
//It uses values of the returned values which could be legit(division by zero)
float errorCodeDivide(float a, float b){
	if(b==0)
		//We should return some code to indicate error 
		//But what should it be
		//How can we distinguish error from valid answer since every error code could actually be valid result
		//In this example a=-5 and b=1 we wouldn't know if there is an error or not
		return -5;
	return a/b;
}
void errorCodeDemo(){
	float division = errorCodeDivide(-5.0,1.0);
	if(division==-5){
		cout << "Division by zero error code" << endl;
	} else {
		cout << "Everything went fine, result: " << division << endl;
	}
}
//A simple divide function throwing an exception 
float divide(float a, float b){
	if(b==0)
		//Execution of current function stops and an exception is thrown
		//The calling function should handle the exception or rethrow it to its parent(this is done implicitly)
		throw -5;
	return a/b;
}
void exceptionDemo(){
	float result = 314;
	//When executing a code that may throw exception we write it in a try section
	try{
		result = divide(-5.0,1.0);
		//This code is executed if everything went fine(without exceptions)
		cout << "division went fine, result is " << result << endl;
		//We can do nested try catch blocks
		try {
      		// code here
  		}
		//we can rethrow the exception for outher catches
  		catch (int e) {
      			throw;
		}		
	//This is the exception handler block (the code between the curly braces after catch keyword
	//This handler is only executed if an exception is thrown and its type matches with the catch parameter
	//In our case we will catch only thrown ints
	}catch (int exception){
		cout << "An int exception has been caught, No=" << exception << endl; 
		//There is no returned value of the function that cause the exception 
		//Its exection was stopped when the exception was thrown 
		cout << "value of result is " << result << endl;
		
	//We can chain exception handlers(multiple catches)
	//Only the first who matches with the exception type is executed
	} catch (char exception){
		cout << "An char exception has been caught, No=" << exception << endl; 
	
	//This is the default catch if no exception matches 
	} catch (...) {
		cout << "default exception handler" << endl;
	}
	
	//The execution continues after the try catch block 
	cout << "completed exceptional code section" << endl;

}
int main(){
	//errorCodeDemo();
	//exceptionDemo();
	customExceptionsDemo();
	return 0;
}
