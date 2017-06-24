# SVG
Работа със SVG файлове
 
В рамките на този проект трябва да се разработи приложение, което работи със файлове във Scalable Vector Graphics (SVG) формат. Приложението трябва да може да зарежда фигури от файла, да извършва върху тях дадени операции, след което да може да записва промените обратно на диска.
 
За улеснение, в рамките на проекта ще работим само с основните фигури (basic shapes) в SVG. Приложението ви трябва да поддържа поне три от тях. Например можете да изберете да се поддържат линия, кръг и правоъгълник. За повече информация за това кои са базовите фигури, вижте https://www.w3.org/TR/SVG/shapes.html.
 
Също така, за улеснение считаме, че координатната система, в която работим е тази по подразбиране: положителната полуос X сочи надясно, а положителната полуос Y сочи надолу.
 
Дизайнът на приложението трябва да е такъв, че да позволява при нужда лесно да можете да добавите поддръжка на нови фигури.
 
Когато зареждате съдържанието на един SVG файл, трябва да прочетете само фигурите, които приложението ви поддържа и можете да игнорирате всички останали SVG елементи.
 
След като заредите фигурите, потребителят трябва да може да изпълнява дадените в следващия раздел команди, които добавят, изтриват или променят фигурите.
 
Когато записвате фигурите във файл, трябва да генерирате валиден SVG файл

Операции : 

Print -Извежда на екрана всички фигури.

Create-Създава нова фигура.

Erase-Изтрива фигура

Translate-Транслира една или всички фигури. Ако потребителят не посочи конкретна фигура, тогава се транслират всички фигури; ако се посочи конкретна – променя се само тя.

Within-Извежда на екрана всички фигури, които изцяло се съдържат в даден регион. Потребителят може да укаже какъв да бъде регионът – кръг или правоъгълник
