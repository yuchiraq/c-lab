Среда разработки всех тасков - Qt Creator. По согласованию с ментором можно использовать Visual Studio, если ментор согласен проверять в Visual Studio.

Решение должно быть загружено на отдельную ветку task7_interfaces вашего личного репозитория с задачами.

Это задание не является обязательным и выполняется по желанию.

Возможно выполнение части этапов, в таком случае сообщите ментору, сколько этапов вы выполнили.

Решение должно включать (для каждого проекта):
- Файл .gitignore (именно с таким именем!) под вашу среду разработки (https://github.com/github/gitignore)
- Папка с проектом и необходимыми файлами.

.gitignore может быть общим (лежать в корне репозитория) или внутри каждого проекта (место расположения .pro или .sln)

Необходимые файлы (Gitignore исключает всё лишнее автоматически, если правильно настроено):
- Для QT Creator    - файл с расширением .pro, файлы .cpp и .h
- Для Visual Studio - файлы с расширениями .sln, .vcxproj, .vcxproj.filters, файлы .cpp и .h

-------------------------------------------

Учимся работать с интерфейсами и паттернами.

Необходимо реализовать механизм, вызывающий несколько сервисов для обработки сообщения.

Используемый паттерн: Chain Of Responsibility (цепочка ответственности).

С паттерном можно ознакомиться по ссылке:
https://refactoring.guru/ru/design-patterns/chain-of-responsibility

Имя проекта: ChainOfResponsibility

-------------------------------------------

Этап первый: имеется интерфейс IMessage, описывающий сообщение

```
class IMessage
{
public:
    // Тип сообщения
	enum MessageType
	{
	    GET_DATA,
		UPDATE_DATA
	}
	
    // Сеттеры
    virtual void setFrom(const std::string& from) = 0;
    virtual void setTo(const std::string& to) = 0;
    virtual void setBody(const std::string& body) = 0;

    // Геттеры
    virtual const std::string& getFrom() = 0;
    virtual const std::string& getTo() = 0;
    virtual const std::string& getBody() = 0;

    // Вывод сообщения в консоль
    virtual void show() = 0;
	
	// Каждый наследник возвращает свой тип
	virtual MessageType getMessageType() const = 0;
};
```

Реализуйте два типа сообщений, наследуемых от IMessage:
- GetDataMessage
- UpdateDataMessage

-------------------------------------------

Этап второй: имеется интерфейс, описывающий сервис:

```
class IService
{
    enum Primitive
    {
        CONTINUE, // Если сервис вернул CONTINUE - управление передаётся следующему сервису
        STOP,     // Если сервис вернул STOP - выведите сообщение в лог и завершите обработку
		FAIL      // Если сервис вернул FAIL - выведите сообщение в лог и завершите обработку
    }

    // Точка входа в сервис для обработки сообщения
    Primitive handleMessage(IMessage* message) = 0;
}
```

Реализуйте 3 сервиса, унаследованные от IService:

- AuthService - проверяет, допустима ли обработка сообщения от данного пользователя
путём сравнения поля From в сообщении с заранее заданным вектором пользователей, хранящемся в сервисе.
Если сообщение от неразрешенного пользователя - сервис возвращает FAIL.
Если от разрешенного пользователя - сервис возвращает CONTINUE.

- GetDataService - Может обрабатывать только сообщения GetDataMessage. Для такого сообщения верните STOP.
Если сообщение другого типа - верните CONTINUE.

- UpdateDataMessage - Может обрабатывать только сообщения UpdateDataMessage. Для такого сообщения верните STOP.
Если сообщение другого типа - верните CONTINUE.

-------------------------------------------

Этап третий - реализуйте последовательную обработку сообщений сервисами с применением паттерна Chain Of Responsibility.

```
class ServiceContainer
{
public:
    // Добавляет сервис в контейнер
    void addService(IService);

    // Обрабатывает сообщение на контейнере сервисов
    void handleMessage(IMessage* message);

private:
    // переменная-контейнер с указателями на сервисы (используйте подходящий, известный вам STL контейнер)
}
```

Сервисы должны обрабатывать сообщение в следующем порядке: AuthService -> GetDataService -> UpdateDataService

Общий принцип обработки:
- Если сервис вернул CONTINUE - управление передаётся следующему сервису
- Если сервис вернул STOP - выведите сообщение в лог и завершите обработку
- Если сервис вернул FAIL - выведите сообщение в лог и завершите обработку

-------------------------------------------

Этап четверный: примеры работы вашего паттерна

Функция main должна содержать инициализацию сервис контейнера списком сервисов согласно указанному порядку обработки.

- Создайте несколько сообщений разных типов
- Инициализируйте сообщения таким образом, чтобы часть сообщений была от разрешенных пользователей (смотрите описание AuthService), а часть - нет.
- Убедитесь, что каждый сервис корректно обрабатывал сообщения согласно условию