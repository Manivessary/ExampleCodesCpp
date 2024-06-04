#include <memory>


class String
{
public:
	String(const char* string) {
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, string, m_Size);
		m_Buffer[m_Size] = 0;
	}
	String(const String& other)
		:m_Size(other.m_Size)
	{
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
		// we dont need to set null termination charecter
		// because we are copying another String object that 
		// sets cull termination charecter.
	}

	~String() {
		delete[] m_Buffer;
	}

	char& operator[] (int index) {
		return m_Buffer[index];
	}

private:
	friend std::ostream& operator<<(std::ostream& stream, const String& string);
	char* m_Buffer;
	unsigned int m_Size;
};

std::ostream& operator<<(std::ostream& stream, const String& string) {
	stream << string.m_Buffer;
	return stream;
}
#pragma once
