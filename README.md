# s21-containers
Проект School 21 на языке C++

Список реализованных классов: 
- `list` (список),
- `map` (словарь),
- `queue` (очередь),
- `set` (множество),
- `stack` (стек),
- `vector` (вектор).
- `array` (массив),
- `multiset` (мультимножество),
- `tree` (дерево).


Реализация методов `insert_many`
| Modifiers      | Definition                                      | Containers |
|----------------|-------------------------------------------------| -------------------------------------------|
| `iterator insert_many(const_iterator pos, Args&&... args)`          | Inserts new elements into the container directly before `pos`.  | List, Vector. |
| `void insert_many_back(Args&&... args)`          | Appends new elements to the end of the container.  | List, Vector, Queue, Stack. |
| `void insert_many_front(Args&&... args)`          | Appends new elements to the top of the container.  | List. |
| `vector<std::pair<iterator,bool>> insert_many(Args&&... args)`          | Inserts new elements into the container.  | Map, Set, Multiset. |

Диаграмма наследования контейнеров:
![](./images/STL_UML.png)