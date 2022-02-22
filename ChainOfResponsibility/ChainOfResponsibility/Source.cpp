#include <iostream>
#include "IMessage.h"
#include "GetDataMessage.h"
#include "UpdateDataMessage.h"
#include "UnknownMessage.h"
#include "ServiceContainer.h"


/*
* ������� ������� ��������� ServiceContainer::addService()
		��������� 3 �������(�� ��������� ������ ��� ����������),
		������� � private, ���������� �������������

* � MessageType ������� UNKNOWN
		���������� ��� ����� � ����������� message
*/


int main()
{
	setlocale(LC_ALL, "rus");

	ServiceContainer* container = new(ServiceContainer);
	IMessage* message;

	message = new(GetDataMessage);
	message->setBody("body");
	message->setTo("listener");
	std::cout << "GetDataMessage:" << std::endl;

	message->setFrom("user");
	std::cout << "����������� ������������ \"user\" >> " << std::endl;
	container->handleMessage(message);

	message->setFrom("bsdah");
	std::cout << "����������� ������������ \"bsdah\" >> " << std::endl;
	container->handleMessage(message);

	message->setFrom("admin");
	std::cout << "����������� ������������ \"admin\" >> " << std::endl;
	container->handleMessage(message);

	delete(message);

	message = new(UpdateDataMessage);
	message->setBody("body");
	message->setTo("listener");

	std::cout << std::endl << "UpdateDataMessage:" << std::endl;

	message->setFrom("user");
	std::cout << "����������� ������������ \"user\" >> " << std::endl;
	container->handleMessage(message);

	message->setFrom("bsdah");
	std::cout << "����������� ������������ \"bsdah\" >> " << std::endl;
	container->handleMessage(message);

	message->setFrom("admin");
	std::cout << "����������� ������������ \"admin\" >> " << std::endl;
	container->handleMessage(message);

	delete(message);

	message = new(UnknownMessage);
	message->setBody("body");
	message->setTo("listener");

	std::cout << std::endl << "UnknownMessage:" << std::endl;

	message->setFrom("user");
	std::cout << "����������� ������������ \"user\" >> " << std::endl;
	container->handleMessage(message);

	return 1;
}