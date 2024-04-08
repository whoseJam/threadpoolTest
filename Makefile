
ROOT=..
FLAGS=-I $(ROOT)/thpool/include
OBJECTS=$(ROOT)/build/Task.o $(ROOT)/build/Worker.o $(ROOT)/build/Thpool.o

lightTaskProfile: lib
	g++ $(FLAGS) -c ./profile/lightTask.cpp -o $(ROOT)/build/lightTaskProfile.o
	g++ $(OBJECTS) $(ROOT)/build/lightTaskProfile.o -o $(ROOT)/build/lightTaskProfile.exe

normalTaskProfile: lib
	g++ $(FLAGS) -c ./profile/normalTask.cpp -o $(ROOT)/build/normalTaskProfile.o
	g++ $(OBJECTS) $(ROOT)/build/normalTaskProfile.o -o $(ROOT)/build/normalTaskProfile.exe

fewTaskProfile: lib
	g++ $(FLAGS) -c ./profile/fewTask.cpp -o $(ROOT)/build/fewTaskProfile.o
	g++ $(OBJECTS) $(ROOT)/build/fewTaskProfile.o -o $(ROOT)/build/fewTaskProfile.exe

waitTest: lib
	g++ $(FLAGS) -c ./test/wait.cpp -o $(ROOT)/build/waitTest.o
	g++ $(OBJECTS) $(ROOT)/build/waitTest.o -o $(ROOT)/build/waitTest.exe

task: lib
	g++ $(FLAGS) -c ./task/main.cpp -o $(ROOT)/build/taskTest.o
	g++ $(OBJECTS) $(ROOT)/build/taskTest.o -o $(ROOT)/build/task.exe

hello: lib
	g++ $(FLAGS) -c ./hello/main.cpp -o $(ROOT)/build/helloTest.o
	g++ $(OBJECTS) $(ROOT)/build/helloTest.o -o $(ROOT)/build/hello.exe

DAG: lib
	g++ $(FLAGS) -c ./DAG/main.cpp -o $(ROOT)/build/DAGTest.o
	g++ $(OBJECTS) $(ROOT)/build/DAGTest.o -o $(ROOT)/build/DAG.exe

lib: $(OBJECTS)
	echo "finish build lib"

./build/Task.o: $(ROOT)/thpool/src/Task.cpp
	g++ ${FLAGS} -c $(ROOT)/thpool/src/Task.cpp -o $(ROOT)/build/Task.o

./build/Worker.o: $(ROOT)/thpool/src/Worker.cpp
	g++ $(FLAGS) -c $(ROOT)/thpool/src/Worker.cpp -o $(ROOT)/build/Worker.o

./build/Thpool.o: $(ROOT)/thpool/src/Thpool.cpp
	g++ $(FLAGS) -c $(ROOT)/thpool/src/Thpool.cpp -o $(ROOT)/build/Thpool.o

clean:
	del /s "$(ROOT)/build/"