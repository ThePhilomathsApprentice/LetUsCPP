virtualInheritance: virtualInheritance.exe
	./virtualInheritance.exe
	
virtualInheritance.exe: virtualInheritance.cpp 
	g++ virtualInheritance.cpp -o virtualInheritance.exe
	
clean:
	del /S *.o
	del /S *.exe
