This is your first programming project. It should be implemented in C++, on a Linux platform such as general.asu.edu. Your program will be graded on Gradescope, which uses a Linux platform. You will perform modular design, provide a Makefile to compile various modules to generate the executable file named run. Among other things, you need to have
1.	a main program, which coordinates all other modules;

2.	a module that provides utility services including command line interpretation;

3.	a module that implements the heap data structure (not all heap functions yet);

4.	a Makefile which compiles all modules and link them into the executable.

For each module other than the main program, you should have a header file which specifies the data structures and the prototypes of the functions in the module, and an implementation file which implements all of the functions specified in the header file. All programs will be compiled and graded on Gradescope. If your program works well on general.asu.edu, there should not be much problems. You will need to submit it electronically on Gradescope via the link on Canvas. Submission details have been posted as of 02/23/2021. If your program does not compile and work on Gradescope, you will receive 0 on this project.
You need to define the following data types.

•	ELEMENT is a struct that contains a field named key, which is of type int. In later assign- ments, you will add other fields to ELEMENT, without having to change the functions. Note that ELEMENT should not be of type int.
•	HEAP is a data type that contains three fields named capacity (of type int), size (of type int), and H (of type **ELEMENT). H will be pointing to an array of capacity + 1 of pointers of type *ELEMENT. Note that the size of HEAP should be equal to 12, regardless of the capacity or the size of the heap. In other words, sizeof(HEAP) should always return 12.

The functions that you are required to implement are:

•	Initialize(n) which creates an object of type HEAP with capacity n, size 0, and H points to a dynamically allocated array of n + 1 pointers. It then returns a pointer to this object. This function requires you to perform dynamic memory allocation, given the demand n.
 
•	printHeap(heap) which prints out the information of the heap pointed to by heap, including capacity, size, and the key fields of the elements in the array with index going from 1 to size.
You should implement a module that takes the following commands from stdin and feeds to the main program:
•	S
•	C n
•	R
•	W
•	P
The main program should react to each of the above command in the following way.

S: On reading S, the program

1.	Writes the following line to stdout: COMMAND: S
where S is the character S.
2.	Stops.

C: On reading C n, the program

1.	Writes the following line to stdout:
COMMAND: C n
where C is the character C and n is replaced by the value of n.

2.	Calls a function in the heap module to create a heap with capacity equal to n and size
equal to 0, and return a pointer to this heap object to the caller.

3.	Waits for the next command from stdin.

R: On reading R, the program

1.	Writes the following line to stdout:
 
COMMAND: R
where R is the character R.

2.	Opens the file ”HEAPinput.txt” in read mode. If the file is not opened successfully, writes the following line to stdout:
Error: cannot open file for reading
and waits for the next command from stdin.

3.	Reads in the first integer n from the file opened.
If heap is NULL or heap->capacity is smaller than n, writes the following line to stdout:
Error: heap overflow
and waits for the next command from stdin.

4.	Reads in the next n integers key1, key2, . . ., keyn from the file, dynamically allocates memory for an ELEMENT, sets it key to keyj, and let heap->H[j] points to this ELEMENT, for j = 1, 2, . . . , n.

5. Waits for the next command from stdin.

P: On reading P, the program

1.	Writes the following line to stdout: COMMAND: P
where P is the character P.

2.	If heap is NULL, writes the following line to stdout:
Error: heap  is NULL
and waits for the next command from stdin.

3.	Writes the information of the heap pointed to by heap to stdout. Refer to the posted test cases for the output format.

4.	Waits for the next command from stdin.

W: On reading W, the program

1.	Writes the following line to stdout: COMMAND: W

where W is the character W.

2.	Opens the file ”HEAPout.txt” in write mode. If the file is not opened successfully, writes the following line to stdout:
Error: cannot open file for writing
and waits for the next command from stdin.

3.	If heap is NULL, writes the following line to stdout:
Error: heap  is NULL
and waits for the next command from stdin.

4.	Writes the information of the heap pointed to by heap to the file ”HEAPoutput.txt”. ”HEAPoutput.txt” should have exactly the same format as ”HEAPinput.txt”.

5. Waits for the next command from stdin.

The file HEAPinput.txt is a text file. The first line of the file contains an integer n, which indicates the number of array elements. The next n lines contain n integers, one integer per line. These integers are the key values of the n array elements, from the first element to the nth element. Refer to the posted test cases for the exact format of ”HEAPinput.txt”.
