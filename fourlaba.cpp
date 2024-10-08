
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

const double Pi = 3.14;
const double timeStep = 0.01; 
const double simulationTime = 10 * 60; 


class Krug {
public:
    double x, y;
    double radius;

    Krug(double x, double y, double radius) : x(x), y(y), radius(radius) {}

    double S() const {
        return radius * radius * Pi;  
    }

    double getRadius() const {
        return radius;
    }
};


class Shestiugolnik {
public:
    double x, y;
    double radius;

    Shestiugolnik(double x, double y, double radius) : x(x), y(y), radius(radius) {}

    double S() const {
        return (radius * radius * 3 * std::sqrt(3)) * 0.5; 
    }

    double getRadius() const {
        return radius;
    }
};


class Kvadrat {
public:
    double x, y;
    double storona;

    Kvadrat(double x, double y, double storona) : x(x), y(y), storona(storona) {}

    double S() const {
        return storona * storona; 
    }

    double getRadius() const {
        return storona * std::sqrt(2) / 2;  
    }
};


class Figure {
    void* shape;
    enum Type { KRUG, SHESTIUGOLNIK, KVADRAT } type;

public:
    double vx, vy;  

    Figure(Krug* krug) : shape(krug), type(KRUG) {
        vx = (rand() % 200 - 100) / 100.0;
        vy = (rand() % 200 - 100) / 100.0;
    }

    Figure(Shestiugolnik* shestiugolnik) : shape(shestiugolnik), type(SHESTIUGOLNIK) {
        vx = (rand() % 200 - 100) / 100.0;
        vy = (rand() % 200 - 100) / 100.0;
    }

    Figure(Kvadrat* kvadrat) : shape(kvadrat), type(KVADRAT) {
        vx = (rand() % 200 - 100) / 100.0;
        vy = (rand() % 200 - 100) / 100.0;
    }

    double S() const {
        switch (type) {
            case KRUG:
                return static_cast<Krug*>(shape)->S();
            case SHESTIUGOLNIK:
                return static_cast<Shestiugolnik*>(shape)->S();
            case KVADRAT:
                return static_cast<Kvadrat*>(shape)->S();
        }
        return 0;
    }


    double getRadius() const {
        switch (type) {
            case KRUG:
                return static_cast<Krug*>(shape)->getRadius();
            case SHESTIUGOLNIK:
                return static_cast<Shestiugolnik*>(shape)->getRadius();
            case KVADRAT:
                return static_cast<Kvadrat*>(shape)->getRadius();
        }
        return 0;
    }

   
    void move(double width, double height) {
        switch (type) {
            case KRUG:
                static_cast<Krug*>(shape)->x += vx * timeStep;
                static_cast<Krug*>(shape)->y += vy * timeStep;
                break;
            case SHESTIUGOLNIK:
                static_cast<Shestiugolnik*>(shape)->x += vx * timeStep;
                static_cast<Shestiugolnik*>(shape)->y += vy * timeStep;
                break;
            case KVADRAT:
                static_cast<Kvadrat*>(shape)->x += vx * timeStep;
                static_cast<Kvadrat*>(shape)->y += vy * timeStep;
                break;
        }

        

        double r = getRadius();
        if (getX() - r < 0 || getX() + r > width) {
            vx = -vx;
        }
        if (getY() - r < 0 || getY() + r > height) {
            vy = -vy;
        }
    }

 
    double getX() const {
        switch (type) {
            case KRUG:
                return static_cast<Krug*>(shape)->x;
            case SHESTIUGOLNIK:
                return static_cast<Shestiugolnik*>(shape)->x;
            case KVADRAT:
                return static_cast<Kvadrat*>(shape)->x;
        }
        return 0;
    }

double getY() const {
        switch (type) {
            case KRUG:
                return static_cast<Krug*>(shape)->y;
            case SHESTIUGOLNIK:
                return static_cast<Shestiugolnik*>(shape)->y;
            case KVADRAT:
                return static_cast<Kvadrat*>(shape)->y;
        }
        return 0;
    }

 
    bool intersects(const Figure& other) const {
        double dx = getX() - other.getX();
        double dy = getY() - other.getY();
        double dist = std::sqrt(dx * dx + dy * dy);

        return dist < (getRadius() + other.getRadius());
    }

    //int srand(time(0));

  
    void print() const {
        cout << "figura: " << (type == KRUG ? "krug" : type == SHESTIUGOLNIK ? "shestiug" : "kvadrat")
             << ", polozhen: (" << getX() << ", " << getY() << "), skorost: (" << vx << ", " << vy << ")\n";
    }
};


class Scene {
    vector<Figure> figures;
    double width, height;

public:
    Scene(double width, double height) : width(width), height(height) {}

    bool addFigure(Figure&& figure) {
        for (int attempt = 0; attempt < 100; ++attempt) {
            bool intersects = false;
            for (const auto& fig : figures) {
                if (figure.intersects(fig)) {
                    intersects = true;
                    break;
                }
            }
            if (!intersects) {
                figures.push_back(figure);
                return true;
            }
        }
        cout << "ne udalos so 100 popit" << endl;
        return false;
    }

    
    void update() {
        for (auto& figure : figures) {
            figure.move(width, height);
        }

       
        for (size_t i = 0; i < figures.size(); ++i) {
            for (size_t j = i + 1; j < figures.size(); ++j) {
                if (figures[i].intersects(figures[j])) {
                   
                    swap(figures[i].vx, figures[j].vx);
                    swap(figures[i].vy, figures[j].vy);
                }
            }
        }
    }

    double totalArea() const {
        double sum = 0;
        for (const auto& fig : figures) {
            sum += fig.S();
        }
        return sum;
    }

 
    void printFigures() const {
        for (const auto& figure : figures) {
            figure.print();
        }
    }
};


int main() {
    srand(static_cast<unsigned int>(time(0)));

    Scene scene(1000, 1000);  

    int numFigures;
    cout << "Colvo dli dobavlen: ";
    cin >> numFigures;

    for (int i = 0; i < numFigures; ++i) {
        int type = rand() % 3; 
        double x = rand() % 1000;
        double y = rand() % 1000;

        switch (type) {
            case 0: {  
                double radius = rand() % 50 + 10;  
                Krug* krug = new Krug(x, y, radius);
                if (!scene.addFigure(Figure(krug))) {
                    delete krug;
                }
                break;
            }
            case 1: {  
                double radius = rand() % 50 + 10;  
                Shestiugolnik* shestiugolnik = new Shestiugolnik(x, y, radius);
                if (!scene.addFigure(Figure(shestiugolnik))) {
                    delete shestiugolnik;
                }
                break;
            }
            case 2: {  
                double storona = rand() % 50 + 10;  
                Kvadrat* kvadrat = new Kvadrat(x, y, storona);
                if (!scene.addFigure(Figure(kvadrat))) {
                    delete kvadrat;
                }
                break;
            }
        }
    }


    double currentTime = 0;
    while (currentTime < simulationTime) {
        scene.update();
        scene.printFigures();  
        currentTime += timeStep;
        cout << fixed << setprecision(2) << "vrem: " << currentTime << " sec\n"; 
    }

    cout << "summarn s na scene: " << scene.totalArea() << endl;

    return 0;
}
