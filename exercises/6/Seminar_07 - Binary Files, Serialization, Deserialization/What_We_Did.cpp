#pragma warning(disable:4996)
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;


class PictureData
{
public:
	PictureData(const char* description = "", unsigned likes = 0, unsigned comments = 0)
		:f_likesCount(likes), f_commentsCount(comments)
	{
		f_description = new char[strlen(description) + 1];
		strcpy(f_description, description);
	}
	PictureData(const PictureData& other)
		: PictureData()
	{
		if (this != &other)
		{
			copy(other);
		}
	}
	PictureData& operator=(const PictureData& other)
	{
		if (this != &other)
		{
			del();
			copy(other);
		}

		return *this;
	}
	~PictureData()
	{
		del();
	}

	void setDescription(const char* newDescription)
	{
		if (f_description != nullptr)
			delete[] f_description;

		f_description = new char[strlen(newDescription) + 1];
		strcpy(f_description, newDescription);
	}

	friend std::ofstream& operator<<(std::ofstream& out, const PictureData& data);
	friend std::ifstream& operator>>(std::ifstream& in, PictureData& data);
private:
	void copy(const PictureData& other)
	{
		f_description = new char[strlen(other.f_description) + 1];

		strcpy(f_description, other.f_description);
		f_likesCount = other.f_likesCount;
		f_commentsCount = other.f_commentsCount;
	}
	void del()
	{
		delete[]f_description;
	}

private:
	char* f_description;
	unsigned f_likesCount;
	unsigned f_commentsCount;
};
// 3ABC2323
std::ofstream& operator<<(std::ofstream& out, const PictureData& data)
{
	size_t descriptionLength = strlen(data.f_description);
	out.write((const char*)&descriptionLength, sizeof(descriptionLength));
	out.write(data.f_description, descriptionLength);
	out.write((const char*)&data.f_commentsCount, sizeof(data.f_commentsCount));
	out.write((const char*)&data.f_likesCount, sizeof(data.f_likesCount));

	return out;
}

std::ifstream& operator>>(std::ifstream& in, PictureData& data)
{
	size_t descriptionLength = 0;

	in.read((char*)&descriptionLength, sizeof(descriptionLength));

	if (data.f_description != nullptr)
	{
		delete[] data.f_description;
	}

	data.f_description = new char[descriptionLength + 1];
	in.read(data.f_description, descriptionLength);
	data.f_description[descriptionLength] = '\0';

	in.read((char*)&data.f_commentsCount, sizeof(data.f_commentsCount));
	in.read((char*)&data.f_likesCount, sizeof(data.f_likesCount));

	return in;
}


class UserData {
	int age;
	PictureData data;

public:
	friend std::ofstream& operator<<(std::ofstream& out, const UserData& data);

};

std::ofstream& operator<<(std::ofstream& out, const UserData& userData)
{

	out.write((const char*)&userData.age, sizeof(userData.age));
	out << userData.data;

	return out;
}


int main()
{




	PictureData data("Beatiful description", 20, 0);


	std::ofstream out("PictureData.txt");

	if (!out.is_open())
	{
		return -1;
	}

	operator<<(operator<<(operator<<(operator<<(out, data), data), data), '\n');
	//same shit
	out << data << data << data << endl;


	std::ifstream in("PictureData.txt");
	operator>>(in, data);
	return 0;
}
