dictionary: dictionary.o LabAss2.o
	g++ dictionary.o LabAss2.o -o dictionary

dictionary.o: dictionary.h dictionary.cpp
	g++ -std=c++11 -c dictionary.cpp

LabAss2.o: dictionary.h LabAss2.cpp
	g++ -std=c++11 -c LabAss2.cpp

clean:
	rm *.o dictionary
