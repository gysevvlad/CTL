iterator.h
==========

iterator - базовый элемент контейнеров. Эта структура содержит два указателя 
(на следующий и предыдущий iterator) и поле data. 

Типы
----
Здесь определен лишь один тип:

    typedef struct iter_struct_##data_t {
	      struct iter_struct_##data_t *next, *prev;
	      data_t data;
    } iterator_##data_t;

Функции
-------
  
    iterator* create( iterator* next, iterator* prev, data_t data )

Создание iterator'а в куче.

    iterator factory( iterator* next, iterator* prev, data_t data )
  
Создание iterator'a с возвращением на стек.

    void destroy( iterator** )
  
Уничтожение iterator'a. Значение указателя изменится на NULL.


Для удобства, из названий функций и типов были исключены те части, 
которые определяются типом. Т.е.: 

    iterator* create ( ) => iterator_##data_t* iter_create_##data_t ( )


Примеры
-------

    DECLARE_ITERATOR( point_t ) 
    
    void main() {
      iterator_point_t *iter1, *iter2;
      #define create iter_create_point_t
      
      iter1 = iter_create( NULL, NULL, point_factory( 1, 2, 3));
      iter2 = iter_create( iter1, NULL, point_factory( 4, 5, 6));  
      ...

iter1 и iter2 автоматически станут ссылаться друг на друга.

    while( temp != NULL ) {
	    iter_action( temp );
	    temp = temp-> next;
	  }
	
Проход в одну сторону.

> Пример: <https://github.com/gysevvlad/CTL/blob/master/examples/iterator_example.c>

> Исходник: <https://github.com/gysevvlad/CTL/blob/master/include/iterator.h>




