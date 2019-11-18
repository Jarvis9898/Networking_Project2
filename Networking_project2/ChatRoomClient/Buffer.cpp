#include"Buffer.h"

Buffer::Buffer()
{
	readPointer = 0;
	writePointer = 0;
}

Buffer::Buffer(long len)
{
	readPointer = 0;
	writePointer = 0;
	v_Buffer.resize(len);
}

void Buffer::Clear()
{
	readPointer = 0;
	writePointer = 0;
}

void Buffer::serializeInt(int x)
{
	increase(writePointer, sizeof(x));

	v_Buffer[writePointer] = x;
	v_Buffer[writePointer + 1] = x >> 8;
	v_Buffer[writePointer + 2] = x >> 16;
	v_Buffer[writePointer + 3] = x >> 24;
	
	writePointer += 4;

}

void Buffer::serializeInt(int x,int i)
{
	increase(i, sizeof(x));

	v_Buffer[i] = x;
	v_Buffer[i + 1] = x >> 8;
	v_Buffer[i + 2] = x >> 16;
	v_Buffer[i + 3] = x >> 24;
}

void Buffer::serializeString(string x)
{
	increase(writePointer, sizeof(x));
	int len = x.length();
	memcpy(&(v_Buffer[writePointer]), &(x[0]), len);

	writePointer += len;
}

int Buffer::deserializeInt()
{
	int x = 0;
	x |= v_Buffer[readPointer];
	x |= v_Buffer[readPointer + 1] << 8;
	x |= v_Buffer[readPointer + 2] << 16;
	x |= v_Buffer[readPointer + 3] << 24;

	readPointer += 4;

	return x;

}

string Buffer::deserializeString(long len)
{
	string x(' ', len);
	x.resize(len);

	for (int i = 0; i < len; i++)
	{
		x[i] = v_Buffer[readPointer + i];
	}

	readPointer += len;
	return x;

}

void Buffer::increase(int i, long len)
{
	if (i + len >= v_Buffer.size())
	{
		v_Buffer.resize(v_Buffer.size() * 2);
	}
}
uchar& Buffer::operator[] (uchar i)
{
	return v_Buffer[i];
}
