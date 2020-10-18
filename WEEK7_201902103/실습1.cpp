#include<iostream>
#include<stdexcept>

class Test {
public:
	Test(char id) :id_(id) {}
	~Test() {
		std::cout << "Destructor execution: "
			<< id_ << std::endl;
	}
private:
	char id_;
};

int  funcB() {
	Test r('B');
	throw std::runtime_error("Exception from funcB!\n");
	std::cout << "Executed in B" << std::endl;
	return 0;
}

int funcA() {
	Test r('A');
	funcB();
	std::cout << "Executed in A" << std::endl;
	return 0;
}

int main() {
	
		
	try {
		funcA();
	}
	catch (std::exception& e) {
		std::cout << "Exception : " << e.what();
	}
		
}

/*
(실습 1-1) 분석결과 : 
	exception이 throw되지 않아 작성한 코드의 흐름대로 출력이 이루어진다.  
	작성한 코드의 흐름이란 함수안에서 함수를 call하고 다시 복귀하는 과정을 말한다. 이는 스택을 통해 동작한다.
	따라서, funcA(), funcB() 안의 Excuted in A,B가 정상적으로 출력이 되며
	Destructor Exception도 출력이 된다.
*/
/* (실습 1-2) 분석결과 : 
	funcB()에서 예외를 throw했기 때문에 함수 호출과정 대로 실행되는 것이 아닌 try catch의 catch문으로 바로 돌아와 예외처리 결과가 출력이 된다.
	이를 Stack Unwinding이라고 한다. 함수가 호출될 때 스택에는 여러 정보가 저장되고 이를 스택프레임이라고 한다. throw를 하면 catch를 찾는 과정에서 이러한 스택을 정리하며 catch가 있는 곳으로 빠져나간다.
	결과적으로 Executed in A, Executed in B가 출력되지 않는다.
*/
