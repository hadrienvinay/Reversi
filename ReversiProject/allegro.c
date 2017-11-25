#include "header.h"

// Fonctionne comme load_bitmap sauf qu'il ne prend pas NULL en 2ème paramètre
// et qu'il termine le programme (avec message) en cas d'échec
//    Exemple de fonction wrapper (emballage d'une fct par une autre fct)
    BITMAP *chargerImage(char *nomFichierImage)
    {
        BITMAP *bmp;
        bmp=load_bitmap(nomFichierImage,NULL);
        if (bmp==NULL)
        {
            allegro_message("pas pu trouver %s",nomFichierImage);
            allegro_exit();
            exit(EXIT_FAILURE);
        }
        printf("Image charg\202e : %s\n", nomFichierImage);
        return bmp;
    }

    void lancerToutAllegro(int largeur, int hauteur)
    {
        allegro_init();
        install_keyboard();
        install_mouse();

        /// OUVERTURE MODE GRAPHIQUE (ouverture fenêtre allegro)
        set_color_depth(desktop_color_depth());
        if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,largeur,hauteur,0,0)!=0)
        {
            allegro_message("probleme mode graphique : %s", allegro_error);
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }
