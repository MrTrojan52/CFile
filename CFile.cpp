#include "CFile.h"

const char CFile::modeRead[3] = "rb";
const char CFile::modeWrite[3] = "wb";
const char CFile::modeAppend[3] = "ab";

CFile::CFile()
{	
	Fp = NULL;
}

CFile::CFile(const char * filename,const char * mode = "rb" )
{
	if (filename != NULL)
		Open(filename, mode);
	
}


bool CFile::Open(const char * filename,const char * mode = "rb")
{
	
	if (Fp != NULL)
	{
		this->Close();
	}
	Fp = fopen(filename, mode);
	if (Fp != NULL)
	{
		rewind(Fp);
		return true;
	}
	else
		return false;
}

void CFile::Close()
{
	fclose(Fp);
	Fp = NULL;
}


int CFile::Seek(long int offset, int origin)
{
	if (!Fp)
		return -1;
	else
		return fseek(Fp, offset, origin);
}

fpos_t * CFile::GetPosition()
{
	
	if (Fp == NULL)
		return NULL;
	fpos_t  pos;
	
	if (!fgetpos(Fp, &pos))
		return &pos;
	else
		return NULL;
}

int CFile::SetPosition(const fpos_t * pos)
{
	if (pos != NULL && Fp != NULL)
		return fsetpos(Fp, pos);
	
}

long CFile::GetLength()
{
	if (Fp == NULL)
		return 0;
	long n;
	
	
	Seek(0, SEEK_END);
	n = ftell(Fp);
	Seek(0, SEEK_SET);
	return n;
}

size_t CFile::Read(void * buf, size_t size, size_t count)
{
	
	 return fread(buf, size, count, Fp);
}

size_t CFile::Write(void * buf, size_t size, size_t count)
{
	return fwrite(buf, size, count, Fp);
}



CFile::~CFile()
{
	if (Fp != NULL)
		Close();	
	Fp = NULL;

}

void CMyDataFile::setMyData(sMyData Data)
{
	MyData.n = Data.n;
	MyData.fk = Data.fk;
}

sMyData CMyDataFile::getMyData()
{
	return MyData;
}

void CMyDataFile::setTitle(char * title)
{
	delete[] _title;
	_title = new char[strlen(title) + 1];
	strcpy(_title, title);
}

const char * CMyDataFile::getTitle()
{
	return _title;
}



CMyDataFile::~CMyDataFile()
{
	if (Fp != NULL)
		Close();
	Fp = NULL;
	delete[] _title;
	MyData.n = NULL;
	MyData.fk = NULL;
}