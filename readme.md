# TP IBM
Enunciado 101

### Obtencion de un archivo .390 y ejecución del mismo
Desde el emulador de z390, se debe correr:

```
ASMLG <directorio actual>/HANOI.MLC
```

### Sobre la entrada:
El programa pedirá por pantalla la cantidad de discos con la que trabajar.
La misma debe ser ingresada en formato de dos dígitos, por ejemplo `04` y se debe
corresponder con un número natural entre 3 y 10, inclusive.

### Sobre la salida:
La salida por pantalla puede estar mal formateada por el hecho de que el emulador no muestra las líneas en blanco.
Al correr el programa con `cmd.pl`, como está especificado en `run.sh`, muestra las líneas en blanco logrando un formato más agradable a la vista, pero no procesa bien los fines de línea en la entrada, por lo que para hacer uso de dicho script se debe saltear la entrada por pantalla hardcodeando la cantidad de discos en una constante.

#### Sobre `hanoi.c`
Es una solución en C que codifiqué para darme una idea de cómo era el algoritmo antes de hacerlo en assembler.
Si bien no es pedido, lo dejo en la entrega porque no veo cómo haría daño.

---
Realizado por Juan Pablo Capurro

Padrón 98194
