#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <clocale>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

class Flower { // базовый класс Flower
protected: // поля доступны в классе и наследниках
	string sort; // сорт
	string color; // цвет
	int health; // здоровье
	double price; // цена

public: // открытая часть класса
	Flower() {
		sort = "Обычный";
		color = "Белый";
		health = 50;
		price = 100;
	}

	Flower(string s, string c, int h, double p) {
		sort = s;
		color = c;
		health = h;
		price = p;
	}

	Flower(const Flower& other) { // конструктор копирования
		sort = other.sort; // копирование сорта
		color = other.color; // копирование цвета
		health = other.health; // копирование здоровья
		price = other.price; // копирование цены
	}

	virtual ~Flower() { // виртуальный деструктор
		cout << "Удаление объекта Flower" << endl; // сообщение при удалении
	}

	void setSort(string s) { sort = s; } // изменение сорта
	void setColor(string c) { color = c; } // изменение цвета
	void setHealth(int h) { health = h; } // изменение здоровья
	void setPrice(double p) { price = p; } // изменение цены

	string getSort() { return sort; } // получение сорта
	string getColor() { return color; } // получение цвета
	int getHealth() { return health; } // получение здоровья
	double getPrice() { return price; } // получение цены

	virtual void showClassName() = 0; // вывод имени класса
	virtual void showInfo() = 0; // вывод информации об объекте

	virtual void inhaleAroma() = 0; // общий метод вдохнуть аромат
	virtual void water() = 0; // общий метод полить
	virtual void enjoy() = 0; // общий метод насладиться
}; // конец класса Flower

// ---------------- ROSE ----------------
class Rose : public Flower { // класс Rose наследуется от Flower
private:
	int thorns; // количество шипов

public:
	Rose() : Flower() { // конструктор без параметров
		thorns = 10; // значение шипов по умолчанию
	}

	Rose(string s, string c, int h, double p, int t) : Flower(s, c, h, p) {
		thorns = t; // запись количества шипов
	}

	Rose(const Rose& other) : Flower(other) { // конструктор копирования
		thorns = other.thorns; // копирование шипов
	}

	~Rose() { // деструктор Rose
		cout << "Удаление объекта Rose" << endl; // сообщение при удалении
	}

	void setThorns(int t) { thorns = t; } // изменение количества шипов
	int getThorns() { return thorns; } // получение количества шипов

	void showClassName() { // вывод имени класса
		cout << "Класс: Роза" << endl;
	}

	void showInfo() { // вывод информации об объекте
		cout << "Тип: Роза, сорт: " << sort
			<< ", цвет: " << color
			<< ", здоровье: " << health
			<< ", цена: " << price
			<< ", шипов: " << thorns << endl;
	}

	void inhaleAroma() { // реализация общего метода
		cout << "Вы вдохнули приятный аромат розы." << endl;
	}

	void water() { // реализация метода полива
		health += 5; // увеличение здоровья на 5
		if (health > 100) health = 100; // ограничение максимального значения
		cout << "Роза полита. Здоровье: " << health << endl;
	}

	void enjoy() { // реализация общего метода
		cout << "Вы любуетесь розой." << endl;
	}

	void cutThorns() { // уникальный метод Rose
		if (thorns > 0) { // проверка наличия шипов
			thorns--; // уменьшение количества шипов на 1
			cout << "У розы убрали один шип. Осталось: " << thorns << endl;
		}
		else { // ситуация, когда шипов нет
			cout << "Шипов уже нет." << endl;
		}
	}
}; // конец класса Rose

// ---------------- GLADIOLUS ----------------
class Gladiolus : public Flower { // класс Gladiolus наследуется от Flower
private:
	double heightStem; // высота стебля

public:
	Gladiolus() : Flower() { // конструктор без параметров
		heightStem = 60; // значение высоты стебля по умолчанию
	}

	Gladiolus(string s, string c, int h, double p, double hs) : Flower(s, c, h, p) {
		heightStem = hs; // запись высоты стебля
	}

	Gladiolus(const Gladiolus& other) : Flower(other) {
		heightStem = other.heightStem; // копирование высоты стебля
	}

	~Gladiolus() { // деструктор Gladiolus
		cout << "Удаление объекта Gladiolus" << endl;
	}

	void setHeightStem(double hs) { heightStem = hs; } // изменение высоты стебля
	double getHeightStem() { return heightStem; } // получение высоты стебля

	void showClassName() { // вывод имени класса
		cout << "Класс: Гладиолус" << endl;
	}

	void showInfo() { // вывод информации об объекте
		cout << "Тип: Гладиолус, сорт: " << sort
			<< ", цвет: " << color
			<< ", здоровье: " << health
			<< ", цена: " << price
			<< ", высота стебля: " << heightStem << endl;
	}

	void inhaleAroma() { // реализация общего метода
		cout << "Вы вдохнули легкий аромат гладиолуса." << endl;
	}

	void water() { // реализация метода полива
		health += 4; // увеличение здоровья на 4
		if (health > 100) health = 100; // ограничение максимального значения
		cout << "Гладиолус полит. Здоровье: " << health << endl;
	}

	void enjoy() { // реализация общего метода
		cout << "Вы смотрите на красивый гладиолус." << endl;
	}

	void tieFlower() { // уникальный метод Gladiolus
		cout << "Гладиолус подвязали к палочке." << endl;
	}
}; // конец класса Gladiolus

// ---------------- PEONY ----------------
class Peony : public Flower { // класс Peony наследуется от Flower
private:
	int petals; // количество лепестков

public:
	Peony() : Flower() { // конструктор без параметров
		petals = 30; // значение лепестков по умолчанию
	}

	Peony(string s, string c, int h, double p, int pet) : Flower(s, c, h, p) {
		petals = pet; // запись количества лепестков
	}

	Peony(const Peony& other) : Flower(other) {
		petals = other.petals; // копирование лепестков
	}

	~Peony() { // деструктор Peony
		cout << "Удаление объекта Peony" << endl;
	}

	void setPetals(int p) { petals = p; } // изменение количества лепестков
	int getPetals() { return petals; } // получение количества лепестков

	void showClassName() { // вывод имени класса
		cout << "Класс: Пион" << endl;
	}

	void showInfo() { // вывод информации об объекте
		cout << "Тип: Пион, сорт: " << sort
			<< ", цвет: " << color
			<< ", здоровье: " << health
			<< ", цена: " << price
			<< ", лепестков: " << petals << endl;
	}

	void inhaleAroma() { // реализация общего метода
		cout << "Вы вдохнули сладкий аромат пиона." << endl;
	}

	void water() { // реализация метода полива
		health += 6; // увеличение здоровья на 6
		if (health > 100) health = 100; // ограничение максимального значения
		cout << "Пион полит. Здоровье: " << health << endl;
	}

	void enjoy() { // реализация общего метода
		cout << "Вы наслаждаетесь видом пиона." << endl;
	}

	void openBud() { // уникальный метод Peony
		cout << "Бутон пиона раскрылся." << endl;
	}
}; // конец класса Peony

// ---------------- CHAMOMILE ----------------
class Chamomile : public Flower { // класс Chamomile наследуется от Flower
private:
	bool medicinal; // лечебная или нет

public:
	Chamomile() : Flower() { // конструктор без параметров
		medicinal = true; // значение по умолчанию
	}

	Chamomile(string s, string c, int h, double p, bool m) : Flower(s, c, h, p) {
		medicinal = m; // запись лечебности
	}

	Chamomile(const Chamomile& other) : Flower(other) {
		medicinal = other.medicinal; // копирование лечебности
	}

	~Chamomile() { // деструктор Chamomile
		cout << "Удаление объекта Chamomile" << endl;
	}

	void setMedicinal(bool m) { medicinal = m; } // изменение лечебности
	bool getMedicinal() { return medicinal; } // получение лечебности

	void showClassName() { // вывод имени класса
		cout << "Класс: Ромашка" << endl;
	}

	void showInfo() { // вывод информации об объекте
		cout << "Тип: Ромашка, сорт: " << sort
			<< ", цвет: " << color
			<< ", здоровье: " << health
			<< ", цена: " << price
			<< ", лечебная: ";
		if (medicinal) // проверка значения true
			cout << "да" << endl;
		else // случай false
			cout << "нет" << endl;
	}

	void inhaleAroma() { // реализация общего метода
		cout << "Вы вдохнули спокойный аромат ромашки." << endl;
	}

	void water() { // реализация метода полива
		health += 3; // увеличение здоровья на 3
		if (health > 100) health = 100; // ограничение максимального значения
		cout << "Ромашка полита. Здоровье: " << health << endl;
	}

	void enjoy() { // реализация общего метода
		cout << "Вы наслаждаетесь видом ромашки." << endl;
	}

	void makeWreath() { // уникальный метод Chamomile
		cout << "Из ромашек сделали венок." << endl;
	}
}; // конец класса Chamomile

int main() { // главная функция программы
	#if defined(_WIN32)
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#elif defined(__linux__) || defined(__APPLE__)
    setlocale(LC_ALL, "");
#else
#error Unsupported operating system
#endif

	vector<Flower*> flowers(6, nullptr); // vector на 6 элементов, сначала везде nullptr

	int choice; // переменная для выбора пункта меню

	do { // цикл работы меню
		cout << "\n----- МЕНЮ -----" << endl; // заголовок меню
		cout << "1. Добавить объект" << endl; // пункт 1
		cout << "2. Выполнить общий метод для всех объектов" << endl; // пункт 2
		cout << "3. Вывести информацию обо всех объектах" << endl; // пункт 3
		cout << "4. Выполнить уникальный метод объекта" << endl; // пункт 4
		cout << "0. Выход" << endl; // пункт выхода
		cout << "Ваш выбор: "; // запрос выбора
		cin >> choice; // чтение выбора пользователя

		if (choice == 1) { // обработка добавления объекта
			int type; // переменная для типа цветка
			cout << "Выберите класс:" << endl; // вывод вариантов классов
			cout << "1. Роза" << endl;
			cout << "2. Гладиолус" << endl;
			cout << "3. Пион" << endl;
			cout << "4. Ромашка" << endl;
			cin >> type; // чтение типа

			string sort, color; // переменные для сорта и цвета
			int health; // переменная для здоровья
			double price; // переменная для цены

			cout << "Введите сорт: "; // запрос сорта
			cin >> sort; // чтение сорта
			cout << "Введите цвет: "; // запрос цвета
			cin >> color; // чтение цвета
			cout << "Введите здоровье: "; // запрос здоровья
			cin >> health; // чтение здоровья
			cout << "Введите цену: "; // запрос цены
			cin >> price; // чтение цены

			Flower* f = nullptr; // указатель на создаваемый объект

			if (type == 1) { // выбор Rose
				int thorns; // переменная для шипов
				cout << "Введите количество шипов: ";
				cin >> thorns; // чтение количества шипов
				f = new Rose(sort, color, health, price, thorns); // создание объекта Rose
			}
			else if (type == 2) { // выбор Gladiolus
				double heightStem; // переменная для высоты стебля
				cout << "Введите высоту стебля: ";
				cin >> heightStem; // чтение высоты стебля
				f = new Gladiolus(sort, color, health, price, heightStem); // создание объекта Gladiolus
			}
			else if (type == 3) { // выбор Peony
				int petals; // переменная для лепестков
				cout << "Введите количество лепестков: ";
				cin >> petals; // чтение количества лепестков
				f = new Peony(sort, color, health, price, petals); // создание объекта Peony
			}
			else if (type == 4) { // выбор Chamomile
				bool medicinal; // переменная для лечебности
				cout << "Лечебная? (1 - да, 0 - нет): ";
				cin >> medicinal; // чтение значения
				f = new Chamomile(sort, color, health, price, medicinal); // создание объекта Chamomile
			}

			bool added = false; // флаг успешного добавления
			for (int i = 0; i < flowers.size(); i++) { // проход по всему vector
				if (flowers[i] == nullptr) { // поиск пустой ячейки
					flowers[i] = f; // добавление объекта
					added = true; // отметка об успешном добавлении
					cout << "Объект добавлен в ячейку " << i << endl; // вывод индекса
					break; // выход из цикла
				}
			}

			if (!added && f != nullptr) { // случай заполненного массива
				flowers.push_back(f); // добавление объекта в конец vector
				cout << "Массив был заполнен, объект добавлен в конец." << endl;
			}
		}

		else if (choice == 2) { // обработка общего метода для всех объектов
			int methodChoice; // переменная для выбора метода
			cout << "Какой метод выполнить?" << endl;
			cout << "1. Вдохнуть аромат" << endl;
			cout << "2. Полить" << endl;
			cout << "3. Насладиться" << endl;
			cin >> methodChoice; // чтение выбора метода

			for (int i = 0; i < flowers.size(); i++) { // проход по всем объектам
				if (flowers[i] != nullptr) { // проверка существования объекта
					if (methodChoice == 1)
						flowers[i]->inhaleAroma(); // вызов метода inhaleAroma
					else if (methodChoice == 2)
						flowers[i]->water(); // вызов метода water
					else if (methodChoice == 3)
						flowers[i]->enjoy(); // вызов метода enjoy
				}
			}
		}

		else if (choice == 3) { // обработка вывода всех объектов
			for (int i = 0; i < flowers.size(); i++) { // проход по всему vector
				cout << "[" << i << "] "; // вывод индекса
				if (flowers[i] != nullptr) { // проверка существования объекта
					flowers[i]->showClassName(); // вывод имени класса
					flowers[i]->showInfo(); // вывод информации об объекте
				}
				else { // случай пустой ячейки
					cout << "Пусто" << endl;
				}
			}
		}

		else if (choice == 4) { // обработка уникального метода
			int index; // индекс объекта
			cout << "Введите индекс объекта: "; // запрос индекса
			cin >> index; // чтение индекса

			if (index >= 0 && index < flowers.size() && flowers[index] != nullptr) {
				// проверка корректности индекса и существования объекта

				if (typeid(*flowers[index]) == typeid(Rose)) {
					// проверка типа Rose
					Rose* r = dynamic_cast<Rose*>(flowers[index]); // приведение к Rose*
					if (r != nullptr) { // проверка успешного приведения
						r->cutThorns(); // вызов уникального метода Rose
					}
				}
				else if (typeid(*flowers[index]) == typeid(Gladiolus)) {
					// проверка типа Gladiolus
					Gladiolus* g = dynamic_cast<Gladiolus*>(flowers[index]); // приведение к Gladiolus*
					if (g != nullptr) { // проверка успешного приведения
						g->tieFlower(); // вызов уникального метода Gladiolus
					}
				}
				else if (typeid(*flowers[index]) == typeid(Peony)) {
					// проверка типа Peony
					Peony* p = dynamic_cast<Peony*>(flowers[index]); // приведение к Peony*
					if (p != nullptr) { // проверка успешного приведения
						p->openBud(); // вызов уникального метода Peony
					}
				}
				else if (typeid(*flowers[index]) == typeid(Chamomile)) {
					// проверка типа Chamomile
					Chamomile* c = dynamic_cast<Chamomile*>(flowers[index]); // приведение к Chamomile*
					if (c != nullptr) { // проверка успешного приведения
						c->makeWreath(); // вызов уникального метода Chamomile
					}
				}
			}
			else { // случай неверного индекса
				cout << "Неверный индекс." << endl;
			}
		}

	} while (choice != 0); // повторение цикла до ввода 0

	for (int i = 0; i < flowers.size(); i++) { // проход по всем элементам vector
		delete flowers[i]; // удаление объектов из памяти
	}

	return 0; // завершение программы
}