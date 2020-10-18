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
(�ǽ� 1-1) �м���� : 
	exception�� throw���� �ʾ� �ۼ��� �ڵ��� �帧��� ����� �̷������.  
	�ۼ��� �ڵ��� �帧�̶� �Լ��ȿ��� �Լ��� call�ϰ� �ٽ� �����ϴ� ������ ���Ѵ�. �̴� ������ ���� �����Ѵ�.
	����, funcA(), funcB() ���� Excuted in A,B�� ���������� ����� �Ǹ�
	Destructor Exception�� ����� �ȴ�.
*/
/* (�ǽ� 1-2) �м���� : 
	funcB()���� ���ܸ� throw�߱� ������ �Լ� ȣ����� ��� ����Ǵ� ���� �ƴ� try catch�� catch������ �ٷ� ���ƿ� ����ó�� ����� ����� �ȴ�.
	�̸� Stack Unwinding�̶�� �Ѵ�. �Լ��� ȣ��� �� ���ÿ��� ���� ������ ����ǰ� �̸� �����������̶�� �Ѵ�. throw�� �ϸ� catch�� ã�� �������� �̷��� ������ �����ϸ� catch�� �ִ� ������ ����������.
	��������� Executed in A, Executed in B�� ��µ��� �ʴ´�.
*/
