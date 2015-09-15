#Assignment 1

* Autor:    Stefan Bieliauskas
* Date:     15.09.2015

You find the results in the ./../results folder as screenshots.
For further information read the ./../Readme.md.


## Task 1 - RegEx 
Handle strings with RegEx. 

![Image](../results/Result-1-1-1.png?raw=true)

For me personally RegEx are always hard to read after a few week so from the maintenance point not to recommend. 
But for some tasks they are necessary and very fast. 


##Task 2 - Sorting
 Sort Vector and QVector via sort functions 
 
![Image](../results/Result-1-1-2.png?raw=true)



##Task 3 - Map
 Handle classes in a Map structure 
 
![Image](../results/Result-1-1-3.png?raw=true)

After this task I was a little bit confused because QT did not delte the books before the program destroyed. 
So I decide to do this manual, in the [Task 4](#Task 4 - Classes)

In the example data is one key used twice this is the reason why on the screenshot only 4 books shown 

##Task 4 - Classes

Create a c++ class that inherits from GObject and separate definition and implementation of this class (.cpp- and .h file)

![Image](../results/Result-1-1-4.png?raw=true)

I'm confused about the output here, because the *qdebug()* output *Construcor* is direct before the deconstructors and not before the output of the dynamic object. 
I think it it because qDebug execute something in an other thread use some other async mechanismen. The next screenshot shows the result with *cout* instead of  *qDebug()*. The *constructor* output is always at the right position
![Image](../../blob/1-1-4-cout-test/results/Result-1-1-4.png?raw=true)