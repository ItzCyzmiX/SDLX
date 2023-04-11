#pragma once

static int * getRGB(const char* colorName) {
    
    static int returnColor[3] = {255, 255, 255};  
    
    if (colorName == "white") {
        returnColor[0] = 255;
        returnColor[1] = 255;
        returnColor[2] = 255;
    }
    if (colorName == "lightWhite") {
        returnColor[0] = 200;
        returnColor[1] = 200;
        returnColor[2] = 200;
    }
    if (colorName == "black") {
        returnColor[0] = 0;
        returnColor[1] = 0;
        returnColor[2] = 0;
    }
    if (colorName == "grey") {
        returnColor[0] = 50;
        returnColor[1] = 50;
        returnColor[2] = 50;
    }
    if (colorName == "lightGrey") {
        returnColor[0] = 75;
        returnColor[1] = 75;
        returnColor[2] = 75;
    }
    if (colorName == "blue") {
        returnColor[0] = 0;
        returnColor[1] = 0;
        returnColor[2] = 255;
    }
    if (colorName == "lightBlue") {
        returnColor[0] = 0;
        returnColor[1] = 0;
        returnColor[2] = 200;
    }
    if (colorName == "red") {
        returnColor[0] = 255;
        returnColor[1] = 0;
        returnColor[2] = 0;
    }
    if (colorName == "lightRed") {
        returnColor[0] = 200;
        returnColor[1] = 0;
        returnColor[2] = 0;
    }
    if (colorName == "green") {
        returnColor[0] = 0;
        returnColor[1] = 255;
        returnColor[2] = 0;
    }
    if (colorName == "lightGreen") {
        returnColor[0] = 0;
        returnColor[1] = 200;
        returnColor[2] = 0;
    }
    
    if (colorName == "yellow") {
        returnColor[0] = 255;
        returnColor[1] = 255;
        returnColor[2] = 0;
    }
    if (colorName == "lightYellow") {
        returnColor[0] = 200;
        returnColor[1] = 200;
        returnColor[2] = 0;
    }
    if (colorName == "pink") {
        returnColor[0] = 255;
        returnColor[1] = 0;
        returnColor[2] = 255;
    }
    if (colorName == "lightPink") {
        returnColor[0] = 200;
        returnColor[1] = 0;
        returnColor[2] = 200;
    }
    if (colorName == "lightPurple") {
        returnColor[0] = 155;
        returnColor[1] = 0;
        returnColor[2] = 155;
    }
    if (colorName == "purple") {
        returnColor[0] = 100;
        returnColor[1] = 0;
        returnColor[2] = 100;
    }
    if (colorName == "cyan") {
        returnColor[0] = 0;
        returnColor[1] = 215;
        returnColor[2] = 255;
    }
    
    return returnColor;
};

static int getRed(int color[3]) {

    return color[0];

};

static int getGreen(int color[3]) {

    return color[1];

};

static int getBlue(int color[3]) {

    return color[2];

};