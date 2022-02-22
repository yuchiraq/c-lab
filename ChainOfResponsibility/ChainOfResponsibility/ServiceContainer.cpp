#include "ServiceContainer.h"

ServiceContainer::ServiceContainer()
{
	addService();
}

void ServiceContainer::addService()
{
	services = {
		{"AuthService", new(AuthService)},
		{"GetDataService", new(GetDataService)},
		{"UpdateDataService", new(UpdateDataService)}
	};
}

void ServiceContainer::handleMessage(IMessage* message)
{

	std::pair<std::string, IService*> cur;
	int resultService;

	for (auto it = services.begin(); it != services.end(); it++) {

		cur = it.operator*();
		resultService = cur.second->handleMessage(message);
		
		if (resultService == IService::CONTINUE) {
			std::cout << cur.first << " : CONTINUE" << std::endl;
			continue;
		} else {
			std::cout << cur.first << " : ";
			if(resultService == IService::FAIL)
				std::cout << "FAIL" << std::endl;
			else if (resultService == IService::STOP)
				std::cout << "STOP" << std::endl;
			return;
		}
	}
	std::cout << "Not processed" << std::endl;

}
