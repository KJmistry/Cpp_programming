# I/O in C++

## I/O Redirection in C++

In C, we could use the function freopen() to redirect an existing FILE pointer to another stream.This method is still supported in C++.  
In C++, a stream is an object whose behavior is defined by a class. Thus, anything that behaves like a stream is also a stream.All these classes, as well as file stream classes, derived from the classes: ios and streambuf. Thus, filestream and IO stream objects behave similarly. 

All stream objects also have an associated data member of class streambuf. Simply put, streambuf object is the buffer for the stream. When we read data from a stream, we don’t read it directly from the source, but instead, we read it from the buffer which is linked to the source. Similarly, output operations are first performed on the buffer, and then the buffer is flushed (written to the physical device) when needed.  

C++ allows us to set the stream buffer for any stream, So the task of redirecting the stream simply reduces to changing the stream buffer associated with the stream.  

To redirect a Stream A to Stream B we need to do:

- Get the stream buffer of A and store it somewhere
- Set the stream buffer of A to the stream buffer of B
- If needed to reset the stream buffer of A to its previous stream buffer

Function prototype of rdbuf():

  1) __stream_object.rdbuf()__: Returns pointer to the stream buffer of stream_object
  2) __stream_object.rdbuf(streambuf * p)__: Sets the stream buffer to the object pointed by p


Example:
``` c++
    // Backup streambuffers of cout
    streambuf* stream_buffer_cout = cout.rdbuf();
    streambuf* stream_buffer_cin = cin.rdbuf();
 
    // Get the streambuffer of the file
    streambuf* stream_buffer_file = file.rdbuf();
 
    // Redirect cout to file
    cout.rdbuf(stream_buffer_file);
```

## Clearing The Input Buffer In C++

What is a buffer?  

A temporary storage area is called a buffer. All standard input and output devices contain an input and output buffer. In standard C/C++, streams are buffered. For example, in the case of standard input, when we press the key on the keyboard, it isn’t sent to your program, instead of that, it is sent to the buffer by the operating system, till the time is allotted to that program.

(reference link : https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/)

## getline()

when there are blanks in line

    getline(std::cin,string var);

If any function related to cin is executed before getline function, getline will take new line characer availabe inside the buffer and will be terminated.

## Buffer Flush - fflush()

A buffer flush is the transfer of computer data from a temporary storage area to the computer’s permanent memory.

## Basic I/O

- cin/cout  -> for taking input from user/to display data
  - cin will return false when entered input is differ from storing variable datatype.
- cerr(un-buffered)/clog(buffered) -> for printing err msg

```
    cout << setprecision(3) << fixed;   // to set precision of float number in cout  
```

## Difference Between std::endl vs \n in C++
  
std::cout << std::endl inserts a new line and flushes the stream(output buffer), whereas std::cout << “\n” just inserts a new line.  
(std::cout << std::endl; can be said equivalent to std::cout << ‘\n’ << flush;)

__Other Differences:__

__endl:__ It is a manipulator.It doesn’t occupy any memory.

__\n:__ It is a character.It occupies 1 byte memory as it is a character.
