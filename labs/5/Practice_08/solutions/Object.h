#pragma once

class Object {
    int weight;
    int width;
    int length;
    int height;

protected:
	double getVolume();

public:
    Object(int = 0, int = 0, int = 0, int = 0);
    double getVolumetriWeight();
    int getWeight();
    void print();
};
