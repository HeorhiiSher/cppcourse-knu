#include "TextBox.hpp"
#include <iostream>

int main() {
    // create a TextBox and call draw
    TextBox textbox("Text", 10, 1);

    // Fix the code to call both draws by using types
    textbox.draw();  // ambiguous

    Rectangle &rectangle = textbox;
    rectangle.draw();
    Text &text = textbox;
    text.draw();
    // try with virtual inheritance


}
