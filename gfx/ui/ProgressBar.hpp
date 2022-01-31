#include "UiObject.hpp"

#ifndef PROGRESSBAR_HPP
#define PROGRESSBAR_HPP

class ProgressBar : public UiObject {
    private:
        int x,y; // Position der ProgressBar auf dem Bildschirm (oben links) (Pixeln)
        int width,height; // Breite und Höhe in Pixeln
        int margin; // Abstand nach innen zum Balken
    public:
        int maxProgress; // Maximal zu erreichner Fortschritt
        long progress; // Fortschritt aktuell
        ProgressBar(); // Constructor
        void render(char * imageBuffer, int lingeLength); // Rendermethode
        void setPos(int x, int y); // Position setzen
        void setDimensions(int width, int height);
};

#endif