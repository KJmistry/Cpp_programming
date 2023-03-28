// C Program to demonstrate it
// doesn't support Name Mangling
// extern "C"{
int printf(const char* format, ...);
// }
// Driver Code
int main()
{
	printf("GeeksforGeeks");
	return 0;
}
