
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

class Image {
private:
    vector<vector<int>> pixels;
    int width, height;

public:
    Image(int w, int h) : width(w), height(h) {
        pixels.resize(height, vector<int>(width, 255)); 
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename, ios::in);
        if (file.is_open()) {
            file >> width >> height;
            pixels.resize(height, vector<int>(width));
            for (int i = 0; i < height; ++i) {
                for (int j = 0; j < width; ++j) {
                    file >> pixels[i][j];
                }
            }
            file.close();
            cout << "Image loaded successfully!" << endl;
        } else {
            cout << "Error: Unable to open file!" << endl;
        }
    }

    void saveToFile(const string& filename) {
        ofstream file(filename, ios::out);
        if (file.is_open()) {
            file << width << " " << height << endl;
            for (const auto& row : pixels) {
                for (int pixel : row) {
                    file << pixel << " ";
                }
                file << endl;
            }
            file.close();
            cout << "Image saved successfully!" << endl;
        } else {
            cout << "Error: Unable to save file!" << endl;
        }
    }

    void applyGrayscale() {
        for (auto& row : pixels) {
            for (auto& pixel : row) {
                pixel = pixel / 3; 
            }
        }
        cout << "Grayscale filter applied!" << endl;
    }

    void adjustBrightness(int factor) {
        for (auto& row : pixels) {
            for (auto& pixel : row) {
                pixel = min(max(pixel + factor, 0), 255);
            }
        }
        cout << "Brightness adjusted!" << endl;
    }

    void resize(int newWidth, int newHeight) {
        pixels.resize(newHeight, vector<int>(newWidth, 255));
        width = newWidth;
        height = newHeight;
        cout << "Image resized!" << endl;
    }

    void display() {
        cout << "Image (" << width << "x" << height << ")" << endl;
        for (const auto& row : pixels) {
            for (int pixel : row) {
                cout << (pixel > 128 ? "#" : ".") << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Image img(10, 10);
    int choice;
    do {
        cout << "\nImage Processing Tool:" << endl;
        cout << "1. Load Image" << endl;
        cout << "2. Save Image" << endl;
        cout << "3. Apply Grayscale" << endl;
        cout << "4. Adjust Brightness" << endl;
        cout << "5. Resize Image" << endl;
        cout << "6. Display Image" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string filename;
                cout << "Enter filename: ";
                cin >> filename;
                img.loadFromFile(filename);
                break;
            }
            case 2: {
                string filename;
                cout << "Enter filename: ";
                cin >> filename;
                img.saveToFile(filename);
                break;
            }
            case 3:
                img.applyGrayscale();
                break;
            case 4: {
                int factor;
                cout << "Enter brightness adjustment factor: ";
                cin >> factor;
                img.adjustBrightness(factor);
                break;
            }
            case 5: {
                int newWidth, newHeight;
                cout << "Enter new width and height: ";
                cin >> newWidth >> newHeight;
                img.resize(newWidth, newHeight);
                break;
            }
            case 6:
                img.display();
                break;
            case 7:
                cout << "Exiting Image Processing Tool. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
