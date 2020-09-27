diamondProblem: diamondProblem.exe
	./diamondProblem.exe
	
diamondProblem.exe: DiamondProblem.cpp 
	g++ DiamondProblem.cpp -o diamondProblem.exe
	
clean:
	del /S *.o
	del /S *.exe
