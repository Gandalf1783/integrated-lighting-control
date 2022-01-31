#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

class InputManager {
    private:
        bool mouseLeft, mouseRight;
        int mouseScroll;
    public:
        InputManager();
        void startThread();
        void stopThread();
        
};

#endif
