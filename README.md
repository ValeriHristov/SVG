# SVG
Работа със SVG файлове
 
В рамките на този проект трябва да се разработи приложение, което работи със файлове във Scalable Vector Graphics (SVG) формат. Приложението трябва да може да зарежда фигури от файла, да извършва върху тях дадени операции, след което да може да записва промените обратно на диска.
 
За улеснение, в рамките на проекта ще работим само с основните фигури (basic shapes) в SVG. Приложението ви трябва да поддържа поне три от тях. Например можете да изберете да се поддържат линия, кръг и правоъгълник. За повече информация за това кои са базовите фигури, вижте https://www.w3.org/TR/SVG/shapes.html.
 
Също така, за улеснение считаме, че координатната система, в която работим е тази по подразбиране: положителната полуос X сочи надясно, а положителната полуос Y сочи надолу.
 
Дизайнът на приложението трябва да е такъв, че да позволява при нужда лесно да можете да добавите поддръжка на нови фигури.
 
Когато зареждате съдържанието на един SVG файл, трябва да прочетете само фигурите, които приложението ви поддържа и можете да игнорирате всички останали SVG елементи.
 
След като заредите фигурите, потребителят трябва да може да изпълнява дадените в следващия раздел команди, които добавят, изтриват или променят фигурите.
 
Когато записвате фигурите във файл, трябва да генерирате валиден SVG файл

Operations available:

- print - Prints all figures on the console.
- create \<rectangle/circle/line> \<params> - Creates the wanted figure. Parameters vary depending on the figure:
   - rectangle \<x> \<y> \<width> \<height> {\<fill>}
   - circle \<cx> \<cy> \<r> {\<fill>}
   - line \<x1> \<y1> \<x2> \<y2> \<stroke-width>
- erase \<index> - Erases the figure with the given index.
- translate vertical=\<value> horizontal=\<value> {\<index>} - Translates with the given values. If a figure index is not specified, all figures are translated.
- within \<rectangle/circle> \<params> - Prints all figures, located entirely in the given figure. The parameters are the same as when creating a figure 
   - rectangle \<x> \<y> \<width> \<height> 
   - circle \<cx> \<cy> \<r>
- save - Saves the changes to the opened file.
- saveas \<filename> - Saves the current figures loaded in the wanted file.
- open \<filename> - Openes the wanted file and loads all recognized figures from it.
- close - Closes the current file open without saving the changes and removes all loaded figures.
- exit - Closes the program without saving changes to files.
