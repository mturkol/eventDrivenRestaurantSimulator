proj3.exe: proj3.o EventClass.o CustomerClass.o ServerClass.o SimHandleClass.o randomNumGenFuncs.o
	g++ proj3.o EventClass.o CustomerClass.o ServerClass.o SimHandleClass.o randomNumGenFuncs.o -o simRes.exe

proj3.o: proj3.cpp SortedListClass.h SortedListClass.inl ListNodeClass.h ListNodeClass.inl QueueClass.h QueueClass.inl EventClass.h CustomerClass.h ServerClass.h SimHandleClass.h randomNumGenFuncs.h StackClass.h StackClass.inl constants.h getInput.h
	g++ -c proj3.cpp -o proj3.o

randomNumGenFuncs.o: randomNumGenFuncs.cpp randomNumGenFuncs.h
	g++ -c randomNumGenFuncs.cpp -o randomNumGenFuncs.o

EventClass.o: EventClass.cpp EventClass.h CustomerClass.h constants.h
	g++ -c EventClass.cpp -o EventClass.o

CustomerClass.o: CustomerClass.cpp CustomerClass.h
	g++ -c CustomerClass.cpp -o CustomerClass.o

ServerClass.o: ServerClass.cpp ServerClass.h CustomerClass.h
	g++ -c ServerClass.cpp -o ServerClass.o

SimHandleClass.o: SimHandleClass.cpp SimHandleClass.h EventClass.h CustomerClass.h ServerClass.h randomNumGenFuncs.h constants.h
	g++ -c SimHandleClass.cpp -o SimHandleClass.o

clean:
	rm -rf proj3.o EventClass.o CustomerClass.o ServerClass.o SimHandleClass.o randomNumGenFuncs.o simRes.exe

