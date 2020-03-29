#include <iostream>
#include <memory>

class BaseWindow {
    public:
        //pure virtual function
        virtual void update() = 0;
};

class DefaultWindow : public BaseWindow {
    public:
        void update() override {
            //update nothing because it's empty state
        }
};

class VoicePlotWindow : public BaseWindow {
    public:
        void update() override {
            //update voice data on plot window at any fps 
        }
};

class CameraImageWindow : public BaseWindow {
    public:
        void update() override {
            //update camera capture image at any fps
        }
};

class WindowManager {
    private:
        std::unique_ptr<BaseWindow> nowWindow;
    
    public:
        //constructor of WindowManager
        WindowManager() {
            nowWindow = std::make_unique<DefaultWindow>();
        }

        int run() {
            while(true) {
                //update corresponding window using porlymorphsim
                nowWindow->update();
            }
            return 0;
        }
};

int main() {
    return 0;
}