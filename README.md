# Лабораторная работа №8. Жадные алгоритмы #
## Задание ##
Решить задачу с помощью жадных алгоритмов.

### Задача ###
Бычкам дают пищевые добавки, чтобы ускорить их рост. Каждая добавка содержит некоторые из N действующих веществ. Соотношенияколичеств веществ в добавках
могут отличаться. Воздействие добавки определяется как
<img src="https://render.githubusercontent.com/render/math?math=c_1a_1 + c_2 a_2 +···+c_N a_N">, где
<img src="https://render.githubusercontent.com/render/math?math=a_i"> количество <img src="https://render.githubusercontent.com/render/math?math=i">-го вещества в добавке,
<img src="https://render.githubusercontent.com/render/math?math=c_i"> — неизвестный коэффициент,
связанный с веществом и не зависящий от добавки. Чтобы найти неизвестные коэффициенты <img src="https://render.githubusercontent.com/render/math?math=c_i">,
Биолог может измерить воздействие любой добавки, использовав один
её мешок. Известна цена мешка каждой из <img src="https://render.githubusercontent.com/render/math?math=M (M ≥ N )"> различных добавок.
Нужно помочь Биологу подобрать самый дешевый наобор добавок, позволяющий
найти коэффициенты <img src="https://render.githubusercontent.com/render/math?math=c_i">.
Возможно, соотношения веществ в добавках таковы, что определить коэффициенты нельзя.

## Пример ##
### Входные данные ###
Первая строка содержит значениет N и M ; в каждой из следующих M строк записаны N чисел, задающих соотношение количеств веществ в ней,
а за ними — цена мешка добавки. Порядок веществ во всех описаниях добавок один и тот же, все числа — неотрицательные целые не больше 50.

```
3 3
1 0 2 3
1 0 2 4
2 0 1 2
```

### Результат работы ###
-1, если определить коэффциенты невозможно, иначе набор добавок (и их номеров по порядоку во входных данных). Если вариантов несколько, вывести какой-либо из них.
```
-1
```