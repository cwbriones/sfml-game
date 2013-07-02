#include <SFML/System/Keyboard.hpp>

#include <unordered_map>
#include <string>

typedef std::unordered_map<std::string, int> KeyMap;

class KeyBinding {
    public:
        void addMapping(std::string action, int keycode);
        int getKeycode(std::string action);
    private:
        KeyMap mapping;
};


