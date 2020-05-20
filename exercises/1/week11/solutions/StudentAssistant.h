
class StudentAssistant : public Student, public Teacher {
private:
	int groupsCount;

public:
	StudentAssistant(string name = "Unknown", int age = 0, double salary = 0.0, string subject = "Unknown", string fn = "Unknown", int course = 0, int group = 0, int groupsCount = 0);

	string activity();

	void print();
};


#include "StudentAssistant.cpp"