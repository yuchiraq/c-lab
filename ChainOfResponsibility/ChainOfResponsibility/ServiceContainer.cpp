#include "ServiceContainer.h"

ServiceContainer::ServiceContainer()
{
	/*IService* service = new(AuthService);
	addService(service);
	service = new(GetDataService);
	addService(service);
	service = new(UpdateDataService);
	addService(service);*/
	addService();
}

void ServiceContainer::addService()
{
	//services.push_back(service);
	services = {
		{"AuthService", new(AuthService)},
		{"GetDataService", new(GetDataService)},
		{"UpdateDataService", new(UpdateDataService)}
	};
	
}

void ServiceContainer::handleMessage(IMessage* message)
{
	/*IService* cur;
	int resultService;
	
	for (std::vector<IService*>::const_iterator it = services.begin(), end = services.end(); it != end; it++) {
		
		cur = it.operator*();
		resultService = cur->handleMessage(message);
		
		if (resultService != IService::CONTINUE) {
			continue;
		}
		else if(resultService == IService::FAIL) {
			std::cout << "—ервис AuthService вернул FAIL "
				"(обработка сообщени€ от пользовател€ недопустима)" << std::endl;
			return;
		}
		else {

		}
	}*/

	std::pair<std::string, IService*> cur;
	int resultService;

	for (auto it = services.begin(); it != services.end(); it++) {

		cur = it.operator*();
		resultService = cur.second->handleMessage(message);
		std::cout << "ѕередан в " << cur.first << std::endl;
		if (resultService == IService::CONTINUE) {
			continue;
		} else {
			std::cout << cur.first << " : " << resultService << std::endl;
			return;
		}
	}
	std::cout << "Not processed" << std::endl;

}
