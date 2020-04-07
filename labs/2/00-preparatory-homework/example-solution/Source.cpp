#include <iostream>
#include <cstring>
#include "Matrix.h"
#include "Vector.h"

const size_t MAX_NAME_LEN = 32;

int findMatrixId(const Vector& vec, const char* name);

int main()
{
    Vector vec;

    char cmd;
    char name[MAX_NAME_LEN];
    int id;
    do {

        std::cout << ">> ";
        std::cin >> cmd;

        switch (cmd) {

            case 'c': {
                size_t rows, cols;
                std::cin >> rows >> cols >> name;
                vec.push_back(Matrix(rows, cols, name));
                std::cin >> vec[vec.size() - 1];
                std::cout << "Matrix " << vec[vec.size() - 1].name() << " created." << std::endl;
                break;
            }

            case 'p': {
                std::cin >> name;
                id = findMatrixId(vec, name);
                if (id != -1)
                    std::cout << vec[id];
                break;
            }

            case 'd': {
                std::cin >> name;
                id = findMatrixId(vec, name);
                if (id != -1) {
                    if (vec[id].rows() == vec[id].cols())
                        std::cout << vec[id].determinant() << std::endl;
                    else
                        std::cout << "Cannot calculate the determinant of a non-square matrix." << std::endl;
                }
                break;
            }

            case 'a': {
            case 'm': {
                char otherName[MAX_NAME_LEN];
                std::cin >> name >> otherName;
                id = findMatrixId(vec, name);
                int otherId = findMatrixId(vec, otherName);
                if (id != -1 && otherId != -1) {
                    Matrix result = (cmd == 'a') ? (vec[id] + vec[otherId]) : (vec[id] * vec[otherId]);
                    if (result.rows() > 0) {
                        vec.push_back(result);
                        std::cout << "Matrix " << vec[vec.size() - 1].name() << " created." << std::endl;
                    } else {
                        std::cout << "Cannot " << ((cmd == 'a') ? ("add") : ("multiply"))
                                  << " matrices of these sizes." << std::endl;
                    }
                }
                break;
            }}

            case 's': {
                size_t scalar;
                std::cin >> scalar >> name;
                id = findMatrixId(vec, name);
                if (id != -1) {
                    vec.push_back(scalar * vec[id]);
                    std::cout << "Matrix " << vec[vec.size() - 1].name() << " created." << std::endl;
                }
                break;
            }

            case 't': {
                std::cin >> name;
                id = findMatrixId(vec, name);
                if (id != -1) {
                    vec.push_back(~vec[id]);
                    std::cout << "Matrix " << vec[vec.size() - 1].name() << " created." << std::endl;
                }
                break;
            }

            case 'q': {
                std::cout << "Bye!" << std::endl;
                break;
            }

            default:
                std::cout << "Unknown command." << std::endl;

        }

    } while (cmd != 'q');

    return 0;
}


int findMatrixId(const Vector& vec, const char* name)
{
    for (int i = 0; i < vec.size(); i++)
        if (strcmp(name, vec[i].name()) == 0)
            return i;
    
    std::cout << "Matrix " << name << " not found." << std::endl;
    return -1;
}
