#pragma once
#include <stdio.h>
#include <cstring>

struct sMyData
{
	int n;
	float fk;
};

class CFile
{
	
public:
	static const char modeRead[3];
	static const char modeWrite[3];
	static const char modeAppend[3];
		
	
	CFile();
	CFile(const char * filename,const char * mode);
	
	~CFile();
	bool Open(const char * filename,const char * mode);
	void Close(); 
	int Seek(long int offset, int origin);
	fpos_t * GetPosition();
	int SetPosition(const fpos_t * pos);
	long GetLength();
	size_t Read(void * buf, size_t size, size_t count);
	size_t Write(void * buf, size_t size, size_t count);
	
protected:
	
	FILE * Fp;

};

class CMyDataFile : public CFile
{
public:
	CMyDataFile() : CFile()
	{ 
		_title = NULL; 
		MyData.fk = 0.0; 
		MyData.n = 0; 
	};
	CMyDataFile(const char * filename, const char * mode, sMyData Data,char * title = NULL) : CFile(filename, mode)
	{
		delete[] _title;
		_title = new char[strlen(title) + 1];
		strcpy(_title, title);
		
		MyData.n = Data.n;
		MyData.fk = Data.fk;
	};
	void setMyData(sMyData Data);
	sMyData getMyData();
	void setTitle(char * title);
	const char * getTitle();
	~CMyDataFile();

private:
	char * _title;
	sMyData  MyData;

};
