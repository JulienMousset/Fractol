# Fractol

Fractol is a small fractal exploration program. The project's goal is to discover the mathematical notion of complex numbers and to take a peek at the concept of optimization in computer graphics (multi-threading) by modelizing some fractals.

## How to use

- Compile : `make`
- Remove object files : `make clean`
- Remove object files and program : `make fclean`
- Start fresh and re-compile : `make re`

## Executing

Execute the program with the fractal name of your choice like this : `./fractol mandelbrot`

The fractals available are : `julia`, `mandelbrot`, `burning_ship`, `tricorn`, `celtic_mandelbar`, `celtic_mandelbrot`, `buffalo`, `celtic_heart`.

Press `TAB` to print the menu inside the program.

## Warning

This program is using the minilibx, a Mac OS graphic library developped at 42 school which we are using in our first graphic programming projects. Therefore, it won't compile if you are on a Linux OS.

## Screenshots

<p align="center">
  <img width="800" height="600" src="Screenshots/fractol.gif">
</p>

![](Screenshots/fractol1.png)
![](Screenshots/fractol2.png)
![](Screenshots/fractol3.png)
![](Screenshots/fractol4.png)
![](Screenshots/fractol5.png)
![](Screenshots/fractol6.png)
