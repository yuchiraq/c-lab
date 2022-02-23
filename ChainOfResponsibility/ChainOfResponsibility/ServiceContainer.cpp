#include "ServiceContainer.h"

void ServiceContainer::addService(IService* service)
{
	services.push_back(service);
}

void ServiceContainer::handleMessage(IMessage* message)
{

    int resultService;
    IService* service;

    for (std::list<IService*>::iterator it = services.begin(); it != services.end(); it++) {

        service = it.operator*();

        resultService = service->handleMessage(message);

        if (resultService == IService::CONTINUE) {
            std::cout << "CONTINUE" << std::endl;
            continue;
        }
        else {
            if (resultService == IService::FAIL)
                std::cout << "FAIL" << std::endl;
            else if (resultService == IService::STOP)
                std::cout << "STOP" << std::endl;
            return;
        }
    }
    std::cout << "Not processed" << std::endl;

}
