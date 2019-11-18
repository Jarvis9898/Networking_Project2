#ifndef _BUFFER_HG_
#define _BUFFER_HG_

#include <string>
#include <vector>

typedef unsigned char uchar;
using namespace std;

class Buffer 
{
public:
	int readPointer;
	int writePointer;

	vector<uchar> v_Buffer;

	Buffer();
	Buffer(long len);
	
	void serializeInt(int x);
	void serializeInt(int x,int i);
	void serializeString(string x);

	int deserializeInt();
	string deserializeString(long len);
	
	void increase(int i, long len);
	void Clear();
	uchar& operator[] (uchar i);
};


#endif // !_BUFFER_HG_
