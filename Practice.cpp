#include<bits/stdc++.h>
using namespace std;

class Cuboid {
private:
    double length;
    double width;
    double height;

public:
 
    Cuboid() {
        length = width = height = 0;
    }


    Cuboid(double l, double w, double h) {
        length = l;
        width = w;
        height = h;
    }


    double getVolume() const {
        return length * width * height;
    }

 
    double getSurfaceArea() const {
        return 2 * (length * width + length * height + width * height);
    }

    
    void display() const {
        cout << "Cuboid(l=" << length 
             << ", w=" << width 
             << ", h=" << height 
             << ") | Volume = " << getVolume() 
             << " | Surface Area = " << getSurfaceArea() 
             << endl;
    }
};

bool compareByVolume(const Cuboid &c1, const Cuboid &c2) {
    return c1.getVolume() < c2.getVolume();
}

bool compareBySurfaceArea(const Cuboid &c1, const Cuboid &c2) {
    return c1.getSurfaceArea() < c2.getSurfaceArea();
}

int main() {
   
    vector<Cuboid> cuboids;
    cuboids.push_back(Cuboid(2, 3, 4));
    cuboids.push_back(Cuboid(1, 5, 6));
    cuboids.push_back(Cuboid(4, 4, 2));
    cuboids.push_back(Cuboid(3, 3, 3));
    cuboids.push_back(Cuboid(6, 2, 1));

    cout << "Original List of Cuboids:\n";
    for (const auto &c : cuboids) {
        c.display();
    }

   
    sort(cuboids.begin(), cuboids.end(), compareByVolume);
    cout << "\nCuboids Sorted by Volume:\n";
    for (const auto &c : cuboids) {
        c.display();
    }

    sort(cuboids.begin(), cuboids.end(), compareBySurfaceArea);
    cout << "\nCuboids Sorted by Surface Area:\n";
    for (const auto &c : cuboids) {
        c.display();
    }

    return 0;
}
