PLAN DU JEU =

MENU du jeu = SO_LONG et selection d'une carte
Faire un truc succes si temps

But du jeu : récupération de différents collectibles dans un ordre précis (ordre affiché sur le côté ou dans le background caché ).
Environ 4 collectible à récupérer.
Lancement du jeu = 4 collectibles, 4 ennemies
Quand on récupére le premier collectible 1 ennemie meurent etc etc. A la fin de la récupération la porte s'ouvre.
Ennemie = troue noir;é
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

***** FONCTIONS DE MLX

| **Fonction**                        | **Paramètres**                                                                                   | **Description**                                                                                                                                                 |
|-------------------------------------|-------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `mlx_init()`                        | Aucun.                                                                                           | Initialise la bibliothèque minilibX. Cette fonction prépare l'environnement pour créer une fenêtre ou gérer des événements.                                    |
| `mlx_new_window()`                  | `void *mlx` (handle de la bibliothèque), `int width`, `int height`, `char *title`                 | Crée une nouvelle fenêtre avec les dimensions spécifiées et le titre. Renvoie un handle pour la fenêtre.                                                        |
| `mlx_pixel_put()`                   | `void *mlx` (handle de la bibliothèque), `void *win` (handle de la fenêtre), `int x`, `int y`, `int color` | Affiche un pixel à la position `(x, y)` avec la couleur spécifiée dans la fenêtre donnée.                                                                      |
| `mlx_new_image()`                   | `void *mlx` (handle de la bibliothèque), `int width`, `int height`                                 | Crée une nouvelle image vide avec les dimensions spécifiées. Renvoie un handle pour l'image.                                                                  |
| `mlx_put_image_to_window()`         | `void *mlx` (handle de la bibliothèque), `void *win` (handle de la fenêtre), `void *img` (handle de l'image), `int x`, `int y` | Affiche une image dans la fenêtre aux coordonnées `(x, y)`.                                                                                                   |
| `mlx_loop()`                        | `void *mlx` (handle de la bibliothèque)                                                           | Lance la boucle principale de la minilibX, qui gère les événements et maintient la fenêtre active.                                                            |
| `mlx_loop_hook()`                   | `void *mlx` (handle de la bibliothèque), `int (*funct)()` (pointeur vers la fonction à appeler à chaque itération) | Définit une fonction à appeler à chaque itération de la boucle pour des animations ou mises à jour à l'écran.                                                  |
| `mlx_hook()`                        | `void *win` (handle de la fenêtre), `int x_event`, `int (*funct)()` (pointeur vers la fonction à appeler pour cet événement) | Associe une fonction à un événement spécifique (comme une pression de touche) dans la fenêtre.                                                                  |
| `mlx_key_hook()`                    | `void *win` (handle de la fenêtre), `int (*funct)()` (pointeur vers la fonction à appeler pour les événements clavier) | Associe une fonction à une touche du clavier spécifique dans la fenêtre.                                                                                      |
| `mlx_mouse_hook()`                  | `void *win` (handle de la fenêtre), `int (*funct)()` (pointeur vers la fonction à appeler pour les événements souris) | Associe une fonction à un événement de souris dans la fenêtre (comme un clic).                                                                                 |
| `mlx_destroy_window()`              | `void *mlx` (handle de la bibliothèque), `void *win` (handle de la fenêtre)                       | Détruit la fenêtre spécifiée et libère les ressources associées.                                                                                                |
| `mlx_destroy_image()`               | `void *mlx` (handle de la bibliothèque), `void *img` (handle de l'image)                          | Libère la mémoire utilisée par l'image spécifiée.                                                                                                              |
| `mlx_clear_window()`                | `void *mlx` (handle de la bibliothèque), `void *win` (handle de la fenêtre)                       | Efface le contenu de la fenêtre.                                                                                                                                 |
| `mlx_get_data_addr()`               | `void *img` (handle de l'image)                                                                   | Renvoie l'adresse du tableau de pixels d'une image, permettant d'accéder et de modifier les pixels directement.                                                |
| `mlx_get_color_value()`             | `void *mlx` (handle de la bibliothèque), `int color`                                              | Convertit une couleur en un format utilisable par minilibX (généralement en hexadécimal).                                                                      |
| `mlx_expose_hook()`                 | `void *win` (handle de la fenêtre), `int (*funct)()` (pointeur vers la fonction à appeler lors de l'événement expose) | Gère l'événement "expose", qui se produit lorsque la fenêtre doit être redessinée (par exemple, après avoir été minimisée puis restaurée).                      |
| `mlx_int_anti_resize_win()`         | `void *win` (handle de la fenêtre)                                                                | Empêche le redimensionnement de la fenêtre (non souvent utilisé directement par l'utilisateur).                                                                 |
| `mlx_int_set_win_event_mask()`      | `void *win` (handle de la fenêtre), `long mask`                                                   | Gère les événements de la fenêtre (par exemple, les clics de souris ou les déplacements).                                                                     |

