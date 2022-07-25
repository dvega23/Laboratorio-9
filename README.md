# Laboratorio-9
Una empresa agrícola requiere controlar la temperatura del área de los huevos criollos, para poder
mantener la calidad de estos. Para ello se requiere medir la temperatura en 3puntos diferentes del
cuarto donde se almacenan los huevos, cada punto de medición debe tener un método de
enfriamiento en caso de que la temperatura se eleve demasiado, y un método de calentamiento en
caso de que la temperatura baje demasiado. Los valores de temperatura pueden ser visualizados
en una computadora que estará conectada de manera serial a dicho cuarto. El sistema debe contar
con un modo manual, y automático, en el modo manual el usuario que está monitoreando los
parámetros de temperatura puede encender el método de enfriamiento o de calentamiento
dependiendo de dicho valor (puede encender enviando comandos por serial), y en el modo
automático el usuario únicamente puede monitorear, para pasar de modo manual a automático se
cuenta con un interruptor.
En el cuarto de almacenamiento se tiene una luz que cambiará de color acorde a la siguiente tabla:
Color Condición
Verde   Temperatura dentro del rango 28‐34º
Azul   Sistema enfriándose  
Rojo Sistema calentándose
Amarillo Modo manual
Cian Modo automático
Tabla 2. Condiciones de luz
Los colores amarillo y Cian corresponden a una segunda luz que se mantiene en ese color mientras
se mantenga en ese modo.
