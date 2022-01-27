Среда разработки всех тасков - Qt Creator. По согласованию с ментором можно использовать Visual Studio, если ментор согласен проверять в Visual Studio.

Решение должно быть загружено на отдельную ветку task6_eventHandler вашего личного репозитория с задачами.

Решение должно включать (для каждого проекта):
- Файл .gitignore (именно с таким именем!) под вашу среду разработки (https://github.com/github/gitignore)
- Папка с проектом и необходимыми файлами.

.gitignore может быть общим (лежать в корне репозитория) или внутри проекта (место расположения .pro или .sln)

-------------------------------------------

Основное (создайте проект с именем EventHandler):

  ```
  class IAsyncEvent
  {
  public:
    virtual ~IAsyncEvent() = default
   
    virtual void executeEvent() = 0;
  };
  ```

  Используя IAsyncEvent, реализуйте два класса для асинхронных событий:
  - AddUserAsyncEvent - реализация executeEvent() выводит строку "User Added"
  - ModifyUserAsyncEvent - реализация executeEvent() выводит строку "User Modified"
  - RemoveUserAsyncEvent - реализация executeEvent() выводит строку "User Removed"
  
  Реализуйте EventHandler:
  
  ```
  class EventHandler
  {
  public:
    ///
	/// Add event to queue
	///
    void sceduleEvent(IAsyncEvent* asyncEvent);
	
	///
	/// @return number of sceduled events
	///
	size_t getNumberOfEvents() const;

  private:
    // Required private members
  };
  ```

  Функция `sceduleEvent()` добавляет событие в очередь на обработку.
  Для реализации очереди используйте известный вам контейнер из STL либо массив (рекомендуется: std::queue).
  Пока количество ивентов в очереди не достигнет 5 (пяти), функция лишь добавляет ивенты в очередь.
  При добавлении пятого ивента извлеките ивенты из очереди и вызовите на каждом `IAsyncEvent::executeEvent` для обработки.
  
  Функция `getNumberOfEvents()` возвращает текущее количество элементов в очереди.
  
  В функции `main` создайте EventHandler и заполните его 10 (десятью) ивентами разных типов, созданных ранее.
  Убедитесь, что обработка запускается каждые 5 ивентов.
  
  При реализации задания правильно разбейте проект на заголовочные файлы и файлы с исходным кодом.
  Решение, в котором все классы реализованы в main.cpp - не допускается.
  
-------------------------------------------

Дополнительно* (обновите проект EventHandler):

Преобразуйте класс EventHandler в Singleton. Обновите примеры работы с EventHandler в main.cpp.

Описание паттерна Singleton https://refactoring.guru/ru/design-patterns/singleton/cpp/example.

Поддержка синглтоном многопоточности: не требуется.

Реализация Singleton на шаблонах: не требуется, но допустима.
