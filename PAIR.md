pair.h
======

pair - базовый элемент, состоящий из пары <ключ, значение>. В качестве
шаблонов можно использовать как указатели, так и структуры.

Типы
----
Здесь определены два типа: сама структура и тип указателя на неё.
Обертка нужна для того, чтобы появилась возможность 
в качестве типа шаблона задать указатель на структуру pair.

К примеру: DECLARE_LINKED_LIST( pair_ptr_int_point_t ) - объявление двусвязного списка
содержащего указатели на структуры pair.

    typedef struct {
      key_t key;
      data_t data;
    } pair_##key_t##_##data_t;

    typedef pair_##key_t##_##data_t* pair_ptr_##key_t##_##data_t;

Функции
-------

    pair* create( key, data )

Создание новой пары <ключ, значение> в куче.

    void init( pair*, key, data )

Инициализация pair'а на уже выделенной памяти.

    pair factory( key, data )

Генерация нового pair'а с возвратом на стек.

    void destroy( pair** )

Деструктор. Обнулит указатель на pair.

Ссылки
------
> Исходник: <https://github.com/gysevvlad/CTL/blob/master/include/pair.h>

> Unit-test: <https://github.com/gysevvlad/CTL/blob/master/test/pair_test.c>

