PLAN DU JEU =


Si possible : récupération de différents collectibles dans un ordre précis (ordre affiché sur le côté).
Environ 4 collectible à récupérer.
Lancement du jeu = 4 collectibles, 4 ennemies
Quand on récupére le premier collectible 1 ennemie meurent etc etc. A la fin de la récupération la porte s'ouvre.
Ennemie = troue noir;
Collectible =
Porte = ordinateur eteint qui s'allume quand c'est ouvert;


Arguments : carte au format *.ber 
Fonctions autorisé :
open, close, read, write, malloc, free, perror, strerror, exit
fonction de la bibliotheque math (option de compilation -lm, man man 3 math)
fonction de MinilibX
ft_printf, libft etc 


Le jeu : 
Collecter tous les items et partir 
Deplacement = W A S D
Affichage compteur total de mouvement dans shell 
VUE 2D 
Le jeu n'a pas a être en temps réel ?

Gestion graphique : 
Affichage image dans une fenetre, fenetre doit être fluide
ESC/Croix = ferme le programme 
Utiliser les images de la MiniLibx est obligatoire 

Carte :
3 elements: murs, collectible, espace vide.
0 = vide
1 = mur
C = collectible
E = sortie
P = position de départ du joueur
Carte rectangulaire 
Carte doit être encadré par des murs

Message d'erreur de mon choix

Partie bonus =
Rajout ennemie 
Sprite d'animations
Compteur total de mouv est affiché dans l'écran du jeu

FONCTIONS DE MLX :

Fonctions de la minilibX

mlx_init()
    Paramètres : Aucun.
    Retour : Un pointeur sur la connexion avec le serveur X, ou NULL en cas d'erreur.
    Description : Initialise la bibliothèque MinilibX. C'est la première fonction à appeler avant toute interaction avec la fenêtre ou les événements.

mlx_new_window(void *mlx_ptr, int width, int height, char *title)
    Paramètres :
        mlx_ptr : Pointeur sur la connexion à la bibliothèque (généralement retourné par mlx_init()).
        width : Largeur de la fenêtre en pixels.
        height : Hauteur de la fenêtre en pixels.
        title : Le titre de la fenêtre (chaîne de caractères).
    Retour : Pointeur sur la fenêtre nouvellement créée, ou NULL en cas d'erreur.
    Description : Crée une nouvelle fenêtre avec les dimensions et le titre spécifiés.

mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color)
    Paramètres :
        mlx_ptr : Pointeur sur la connexion à la bibliothèque (généralement retourné par mlx_init()).
        win_ptr : Pointeur sur la fenêtre dans laquelle le pixel sera affiché.
        x : Position x du pixel.
        y : Position y du pixel.
        color : Couleur du pixel (en valeur hexadécimale).
    Retour : Aucun.
    Description : Affiche un pixel à la position (x, y) dans la fenêtre avec la couleur spécifiée.

mlx_new_image(void *mlx_ptr, int width, int height)
    Paramètres :
        mlx_ptr : Pointeur sur la connexion à la bibliothèque.
        width : Largeur de l'image.
        height : Hauteur de l'image.
    Retour : Pointeur sur l'image nouvellement créée.
    Description : Crée une nouvelle image vide avec les dimensions spécifiées. L'image peut ensuite être manipulée avec des fonctions comme mlx_get_data_addr().

mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y)
    Paramètres :
        mlx_ptr : Pointeur sur la connexion à la bibliothèque.
        win_ptr : Pointeur sur la fenêtre dans laquelle l'image sera affichée.
        img_ptr : Pointeur sur l'image à afficher.
        x : Position x de l'image dans la fenêtre.
        y : Position y de l'image dans la fenêtre.
    Retour : Aucun.
    Description : Affiche une image à la position (x, y) dans la fenêtre.

mlx_loop(void *mlx_ptr)
    Paramètres :
        mlx_ptr : Pointeur sur la connexion à la bibliothèque.
    Retour : Aucun.
    Description : Lance la boucle principale de gestion des événements. Elle attend et traite les événements de la fenêtre (clavier, souris, etc.).

mlx_loop_hook(void *mlx_ptr, int (*f)(), void *param)
    Paramètres :
        mlx_ptr : Pointeur sur la connexion à la bibliothèque.
        f : Fonction à appeler à chaque itération de la boucle (mlx_loop()).
        param : Paramètre qui sera passé à la fonction f à chaque itération.
    Retour : Aucun.
    Description : Permet de définir une fonction qui sera appelée à chaque itération de la boucle principale, utile pour des animations ou la mise à jour d'éléments.

mlx_hook(void *win_ptr, int x_event, int x_mask, int (*f)(), void *param)
    Paramètres :
        win_ptr : Pointeur sur la fenêtre.
        x_event : L'événement que l'on souhaite capturer (par exemple KeyPress pour une touche du clavier).
        x_mask : Masque des événements (généralement NoEventMask ou d'autres constantes).
        f : Fonction à appeler lors de l'événement spécifié.
        param : Paramètre à passer à la fonction f.
    Retour : Aucun.
    Description : Associe une fonction à un événement (par exemple, lorsqu'une touche est enfoncée).

mlx_key_hook(void *win_ptr, int (*f)(), void *param)
    Paramètres :
        win_ptr : Pointeur sur la fenêtre.
        f : Fonction à appeler lorsque l'utilisateur appuie sur une touche du clavier.
        param : Paramètre à passer à la fonction f.
    Retour : Aucun.
    Description : Permet d'associer une fonction à la pression d'une touche spécifique sur le clavier.

mlx_mouse_hook(void *win_ptr, int (*f)(), void *param)
    Paramètres :
        win_ptr : Pointeur sur la fenêtre.
        f : Fonction à appeler lorsqu'un événement de souris se produit (par exemple, un clic).
        param : Paramètre à passer à la fonction f.
    Retour : Aucun.
    Description : Permet d'associer une fonction à un événement de souris (comme un clic).

mlx_destroy_window(void *mlx_ptr, void *win_ptr)
    Paramètres :
        mlx_ptr : Pointeur sur la connexion à la bibliothèque.
        win_ptr : Pointeur sur la fenêtre à détruire.
    Retour : Aucun.
    Description : Détruit la fenêtre et libère les ressources associées.

mlx_destroy_image(void *mlx_ptr, void *img_ptr)
    Paramètres :
        mlx_ptr : Pointeur sur la connexion à la bibliothèque.
        img_ptr : Pointeur sur l'image à détruire.
    Retour : Aucun.
    Description : Libère la mémoire utilisée par l'image.

mlx_clear_window(void *mlx_ptr, void *win_ptr)
    Paramètres :
        mlx_ptr : Pointeur sur la connexion à la bibliothèque.
        win_ptr : Pointeur sur la fenêtre à nettoyer.
    Retour : Aucun.
    Description : Vide la fenêtre (utile pour effacer l'écran avant de redessiner dessus).

mlx_get_data_addr(void *img_ptr, int *bpp, int *size_line, int *endian)
    Paramètres :
        img_ptr : Pointeur sur l'image.
        bpp : Bits par pixel (c'est-à-dire le nombre de bits utilisés pour décrire la couleur d'un pixel).
        size_line : Taille d'une ligne d'image en octets.
        endian : Valeur indiquant l'ordre des octets dans le stockage des couleurs.
    Retour : L'adresse des données de l'image.
    Description : Retourne l'adresse du tableau de pixels de l'image, ce qui permet de manipuler directement les pixels de l'image.

mlx_get_color_value(void *mlx_ptr, int color)
    Paramètres :
        mlx_ptr : Pointeur sur la connexion à la bibliothèque.
        color : Couleur à convertir (en valeur hexadécimale).
    Retour : La couleur convertie au format attendu par la bibliothèque.
    Description : Convertit une couleur dans un format que MinilibX peut utiliser pour dessiner des pixels.

mlx_expose_hook(void *win_ptr, int (*f)(), void *param)
    Paramètres :
        win_ptr : Pointeur sur la fenêtre.
        f : Fonction à appeler lorsque la fenêtre a besoin d'être redessinée.
        param : Paramètre à passer à la fonction f.
    Retour : Aucun.
    Description : Gère l'événement "expose", qui se produit lorsque la fenêtre doit être redessinée.
